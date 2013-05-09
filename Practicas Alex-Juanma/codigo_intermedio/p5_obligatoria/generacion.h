#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * nombre_fichero = "salida.c";
FILE *fichero1;
FILE *fichero2;
FILE *actual;
char  temp[11];
char  temp1[11];
char temp2[11];
char *tipo_actual;
unsigned int etiqueta_base =0;
unsigned int temporal_base =0;
unsigned int almacena_temp=0;
int main_llave=0;
int en_fun=0;

typedef struct{
char EtiquetaEntrada[15];
char EtiquetaSalida[15];
char EtiquetaElse[15];
char NombreVarControl[15];
}DescriptorControl;

typedef struct{
int num;
}Temporales;

DescriptorControl tablaControl[200];
int ind=-1;
Temporales temporales[500];
int indtemp=-1;

/******************************************************************************
																GESTION TEMPORALES
******************************************************************************/
void libera_temporales(){
	temporal_base=0;
}

void inserta_marcatemp(){
	indtemp++;
	
	temporales[indtemp].num = temporal_base;
	libera_temporales();
}

void elimina_marcatemp(){
	indtemp--;
	temporal_base=	temporales[indtemp].num;
}

int get_temp(){	
	return temporales[indtemp].num;
}

/******************************************************************************
																GESTION DESCRIPTORES
******************************************************************************/

void add_descriptor(DescriptorControl d){
	ind++;
	tablaControl[ind]=d;
}

void delete_descriptor(){
	ind--;
}

DescriptorControl get_descriptor(){
	DescriptorControl d=tablaControl[ind];
	return d;
}

/******************************************************************************
																ESCRITURA CODIGO
******************************************************************************/

/************************\
*     TIPOS SIMPLES      *
\************************/

void abrir_fichero1(){
	fichero1 = fopen(nombre_fichero,"w");
	fichero2 = fopen("dec_fun","w");
	fprintf(fichero2,"#include <stdio.h>\n\n");
}

void cerrar_fichero(){
	fclose(fichero1);
	fclose(fichero2);
}

void seleccionar_fichero1(){
	temporal_base=almacena_temp;
	fichero2=actual;
	actual = fichero1;	
}

void seleccionar_fichero2(){
	almacena_temp=temporal_base;
	fichero1=actual;
	actual = fichero2;
	printf("\nantes\n");
	//fprintf(actual,"#includ");
	printf("\ndesp\n");
}

void escribir_cabecera(){
	fprintf(fichero1,"/*#include \"dec_fun\"\n#include \"dec_dat\"*/\n#include <stdio.h>\n\nint main()");
}

void cerrar_main(){
	fprintf(fichero1,"return 0;\n");
}

void escribir_llaveA(){
	if(en_fun==0)
		fprintf(fichero1,"{\n");
	else
		fprintf(fichero2,"{\n");
	main_llave++;	
}

void escribir_llaveC(){
	main_llave--;
	if(en_fun==0){
		if(main_llave==0)
			fprintf(fichero1,"return 0;\n}\n");
		else
			fprintf(fichero1,"}\n");
	}
	else
		fprintf(fichero2,"}\n");
}

void escribir_1var(char *nombre){
	if(en_fun==0){
			fprintf(fichero1,"%s %s;\n",tipo_actual,nombre);
	}else{
		fprintf(fichero2,"%s %s;\n",tipo_actual,nombre);
	}
}

void actualiza_tipo(char* tipo){
	tipo_actual = tipo;
}

void escribe_elemento(char *el){
	fprintf(fichero1,"%s",el);
}

void escribe_coma(){
	fprintf(fichero1,", ");
}

void escribir_variables(char *tipo){
	actualiza_tipo(tipo);
	int i;
	
	for (i=tope; TS[i].tipoentrada==variable && TS[i].tipoDato == no_asignado; i--){
		
		escribir_1var(TS[i].lexema);
	}
	if(en_fun==0)
	fprintf(fichero1,"\n");
	else
	fprintf(fichero2,"\n");
}

void copiaToTemp(char *m){
	int i=0;
	for(i;i<11;i++){
		temp[i]=m[i];
	}
}

void genera_temporal(){
	char aux[11]= "temp";
	char aux2[3];
	sprintf(aux2,"%d",temporal_base);
	
	strcat(aux,aux2);

	temporal_base++;
	copiaToTemp(aux);
}

void genera_etiqueta(char * m){
	char aux[15]= "etiqueta";
	char aux2[5];
	sprintf(aux2,"%d",etiqueta_base);
	
	strcat(aux,aux2);

	etiqueta_base++;
	copiaTo(aux,m,15);
}

copiaTo(char *m1, char* m2,int n){
int i=0;
	for(i;i<=n;i++){
		m2[i]=m1[i];
	}
}

void copiaToTemp1(char *m){
	int i=0;
	for(i;i<11;i++){
		temp1[i]=m[i];
	}
}

void copiaToTemp2(char *m){
	int i=0;
	for(i;i<11;i++){
		temp2[i]=m[i];
	}
}

escribe_expresionBin(char *elem1, char*elem2, char*op, char*tip){
	copiaToTemp1(elem1);
	copiaToTemp2(elem2);
	genera_temporal();
		if(en_fun==0){
			fprintf(fichero1,"%s %s;\n",tip,temp);
			fprintf(fichero1,"%s = %s %s ",temp, temp1, op);	
			fprintf(fichero1,"%s;\n",temp2);
		}
		else{
			fprintf(fichero2,"%s %s;\n",tip,temp);
			fprintf(fichero2,"%s = %s %s ",temp, temp1, op);	
			fprintf(fichero2,"%s;\n",temp2);
		}
}

void escribe_asignacion(char *elem1, char*elem2){
	copiaToTemp1(elem1);
	copiaToTemp2(elem2);
	
	if(en_fun==0){
		fprintf(fichero1,"%s = ",temp1);

		fprintf(fichero1,"%s;\n\n",elem2);
	}
	else{
		fprintf(fichero2,"%s = ",temp1);

		fprintf(fichero2,"%s;\n\n",elem2);
	}
}

void escribe_if(char *elem1){
	DescriptorControl d;
	
	genera_etiqueta(d.EtiquetaSalida);
	genera_etiqueta(d.EtiquetaElse);	
	add_descriptor(d);
	copiaToTemp1(elem1);
	
	if(en_fun==0){
		fprintf(fichero1,"if(!%s)goto %s;\n\n",temp1,d.EtiquetaElse);
	}
	else{
		fprintf(fichero2,"if(!%s)goto %s;\n\n",temp1,d.EtiquetaElse);
	}
}

void escribe_else(){
	DescriptorControl d=get_descriptor();
	if(en_fun==0){
		fprintf(fichero1,"goto %s;\n\n",d.EtiquetaSalida);
		fprintf(fichero1,"%s:\n\n",d.EtiquetaElse);
	}
	else{
		fprintf(fichero2,"goto %s;\n\n",d.EtiquetaSalida);
		fprintf(fichero2,"%s:\n\n",d.EtiquetaElse);
	}
}

void escribe_expresionUna(char *elem1, char*op,char *tip){
	copiaToTemp1(elem1);
	genera_temporal();
	if(en_fun==0){	
		fprintf(fichero1,"%s %s;\n",tip,temp);
		fprintf(fichero1,"%s = %s %s;\n",temp,  op,temp1);
	}
	else{	
		fprintf(fichero2,"%s %s;\n",tip,temp);
		fprintf(fichero2,"%s = %s %s;\n",temp,  op,temp1);
	}
}

void escribe_while(char *elem1){
	DescriptorControl d;
	etiqueta_base--;
	genera_etiqueta(d.EtiquetaEntrada);
	genera_etiqueta(d.EtiquetaSalida);
	add_descriptor(d);
	copiaToTemp1(elem1);
	if(en_fun==0)
		fprintf(fichero1,"\nif(!%s)goto %s;\n\n",temp1,d.EtiquetaSalida);
	else
		fprintf(fichero2,"%s:\nif(!%s)goto %s;\n\n",d.EtiquetaEntrada,temp1,d.EtiquetaSalida);
}

void fin_while(){
	DescriptorControl d=get_descriptor();
	if(en_fun==0){
		fprintf(fichero1,"goto %s;\n",d.EtiquetaEntrada);
		fprintf(fichero1,"%s:\n\n",d.EtiquetaSalida);
	}
	else{
		fprintf(fichero2,"goto %s;\n",d.EtiquetaEntrada);
		fprintf(fichero2,"%s:\n\n",d.EtiquetaSalida);
	}
	delete_descriptor();
}

void escribe_void_vacio(char *iden ){
	fprintf(fichero1,"\nvoid %s()",iden ); 
}

void escribe_argumentos(){
	int args = tope-indiceProc();
	int i=0;
	int primero = 1;
	for(i=indiceProc()+1;i<=tope;i++){
		if(primero==1){
			fprintf(fichero1,"%s",TipoEscrito(TS[i].tipoDato)); 
			primero =0;
		}
		else{
			fprintf(fichero1,", %s",TipoEscrito(TS[i].tipoDato)); 	
		}
		fprintf(fichero1," %s",TS[i].lexema); 
	}
	fprintf(fichero1,")"); 
}

void escribe_void_argumentos(char *iden){
	fprintf(fichero1,"\nvoid %s(",iden); 
	escribe_argumentos();
}

void escribe_cout(dTipo tip, char *elem){
	if((tip==0)||(tip==3)){ //entero o booleano
		if(en_fun==0){
			fprintf(fichero1,"printf(\"%%d\",%s);\n",elem);
		}else{
			fprintf(fichero2,"printf(\"%%d\",%s);\n",elem);
		}
	}else{
		if(tip==1){ //reales
			if(en_fun==0){
				fprintf(fichero1,"printf(\"%%f\",%s);\n",elem);
			}
			else{
				fprintf(fichero2,"printf(\"%%f\",%s);\n",elem);
			}
		}
		else{
			if(tip==2){ //caracteres
				if(en_fun==0){
					fprintf(fichero1,"printf(\"%%c\",%s);\n",elem);
				}
				else{
					fprintf(fichero2,"printf(\"%%c\",%s);\n",elem);
				}
			}
			else{	//cadenas
				if(en_fun==0){
					fprintf(fichero1,"printf(\"%%s\",%s);\n",elem);
				}else{
					fprintf(fichero2,"printf(\"%%s\",%s);\n",elem);
				}
			}
		}
	}
}

void escribe_cin(dTipo tip, char *elem){
	if((tip==0)||(tip==3)){//entero o booleano
		if(en_fun==0){
			fprintf(fichero1,"scanf(\"%%i\",&%s);\n",elem);
		}
		else{
			fprintf(fichero2,"scanf(\"%%i\",&%s);\n",elem);
		}
	}
	if(tip==1){//reales
		if(en_fun==0){
			fprintf(fichero1,"scanf(\"%%f\",&%s);\n",elem);
		}
		else{
			fprintf(fichero2,"scanf(\"%%f\",&%s);\n",elem);
		}
	}
	if(tip==2){//caracteres
		if(en_fun==0){
			fprintf(fichero1,"scanf(\"%%c\",&%s);\n",elem);
		}
		else{
			fprintf(fichero2,"scanf(\"%%c\",&%s);\n",elem);
		}		
	}
}

/*********************\
 *     _PILAS_        *
\*********************/

