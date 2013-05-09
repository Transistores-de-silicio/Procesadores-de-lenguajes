int yylineno;

typedef enum {
	marca, /* marca comienzo bloque */
	variable, /* si es variable */
	parametro, /* si es parametro */
	procedimiento, /* si es subprograma */
} entrada ;


typedef enum {
	entero,
	real,
	caracter,
	booleano,
	pila_entero,
	pila_real,
	pila_booleano,
	pila_caracter,
	vacio,
	desconocido,
	no_asignado
} dTipo ;


typedef struct {
	entrada tipoentrada ;
	char *lexema ;
	dTipo tipoDato ;
	int parametros ;
	int pila;
} entradaTS ;

typedef struct {
	int atrib ; /* Atributo del símbolo (si tiene) */
	char *lexema ; /* Nombre del lexema */
	dTipo tipo ; /* Tipo del símbolo */
	int nargumentos;
} atributos ;

#define MAX_TS 500
unsigned int tope=-1 ; /* tope de la pila */
entradaTS TS[MAX_TS] ; /* Pila de la tabla de símbolos */

#define YYSTYPE atributos 

/* A partir de ahora, cada símbolo tiene */
/* una estructura de tipo atributos */

/*********************************************************************************************************/
										/* Lista de funciones y procedimientos para manejo de la TS */
/*********************************************************************************************************/


char* MostrarTipo(dTipo tipo){
	if(tipo==0) return("entero");
	if(tipo==1) return("real");
	if(tipo==2) return("caracter");
	if(tipo==3) return("booleano");
	if(tipo==4) return("pila entero");
	if(tipo==5) return("pila real");
	if(tipo==6) return("pila booleano");
	if(tipo==7) return("pila caracter");
	if(tipo==8) return("vacio");
	if(tipo==9) return("desconocido");
	if(tipo==10) return("no asignado");
	
}

void imprimeTS () {
	/* Imprime por pantalla la tabla de simbolos */
	int i;
	int letra;
	for (i=0; i<=tope; i++) {
		if (TS[i].tipoentrada==marca)
			printf ("\n<<< MARCA >>>");
		if (TS[i].tipoentrada==procedimiento){
			printf ("\nProcedimiento: %s, Tipo: %d, Num. Parametros: %d", TS[i].lexema, TS[i].tipoDato, TS[i].parametros);
			//printf ("\nProcedimiento: %s, Num. Parametros: %d", TS[i].lexema, TS[i].parametros);
		}
		if (TS[i].tipoentrada == variable){
			printf ("\nVariable: %s, Tipo: %d , espila: %d", TS[i].lexema, TS[i].tipoDato,TS[i].pila);
		}	
		if (TS[i].tipoentrada==parametro)
			printf ("\nParametro: %s, Tipo: %d", TS[i].lexema, TS[i].tipoDato);
	}

	printf ("\n");
	getchar();

	printf("********************************************************************");
}

void espila(){
	TS[tope].pila = 1;
}

/* Asigna el tipo especificado al elemento en el tope de la TS*/
void asignarTipo (dTipo tipo) {
	
	TS[tope].tipoDato = tipo;
	if((tipo==entero)&&(TS[tope].pila==1)){
		TS[tope].tipoDato = pila_entero;
	}
	if((tipo==real)&&(TS[tope].pila==1)){
		TS[tope].tipoDato = pila_real;
	}
	if((tipo==booleano)&&(TS[tope].pila==1)){
		TS[tope].tipoDato = pila_booleano;
	}
	if((tipo==caracter)&&(TS[tope].pila==1)){
		TS[tope].tipoDato = pila_caracter;
	}		
	
}

/*Insertar un identificador en el tope de la pila*/
void insertarIDENT(entrada tipo, char* lexema){

	tope++;
	TS[tope].tipoentrada = tipo;
	TS[tope].lexema = strdup(lexema);
	TS[tope].tipoDato = no_asignado;
	TS[tope].pila=0;
	if( tipo == procedimiento)
		TS[tope].parametros = 0;
	//imprimeTS();
}

/* Inserta una entrada en la tabla de simbolo con una marca 
	y copia los parametros del procedimiento como si
	fueran variables */
void TS_InsertaMarca(){
	int i;
	tope++;

	TS[tope].tipoentrada = marca;

		for (i=tope-1; i>=0 && TS[i].tipoentrada != marca && TS[i].tipoentrada != procedimiento; i--){
			if (TS[i].tipoentrada == parametro) {
				/* Hemos encontrado un parametro, incluirlo como variable */
				insertarIDENT(variable, TS[i].lexema);
				asignarTipo(TS[i].tipoDato);
				if(TS[i].pila==1){
					espila();
				}
			}
		}
}

/* Elimina entradas de la tabla de simbolos hasta que se encuentra
	    una marca de comienzo de bloque o se queda la tabla de simbolos
	   vacia */
void TS_VaciarEntradas() {
	for (;tope>=0 && TS[tope].tipoentrada!=marca;tope--);
	if (tope!=0)
		tope--;
}

int es_pila(dTipo v){
	if((v==pila_booleano)||(v==pila_entero)||(v==pila_real)||(v==pila_caracter))
		return 1;
	else
		return 0;
}

/*Comprueba si existe un identificador en la pila igual al que se le pasa por parámetro*/
int es_repetida(char * lexema){
	/* Miramos que en la tabla de simbolos no exista otro identificador con el mismo lexema*/
	int i;
	int igual = 0;
	/* Comprobar si ya existe otro con el mismo lexema en el mismo
	   bloque */
	for (i=tope; TS[i].tipoentrada != marca; i--){
		igual = strcmp(TS[i].lexema, lexema);

		if (!igual && TS[i].tipoentrada != parametro) {
			printf ("\nError Semantico en la linea %d: Identificador %s ya esta declarado\n", yylineno, lexema);
			return 1;
		}
	}
	return 0;
}

/* Devuelve 1 si existe definida una variable con el nombre especificado
	o 0 en caso contrario */
int existe (char *lexema) {

	long int temp;

	for (temp=tope; temp>0;temp--){
		//printf("%i\n",TS[temp].tipoentrada);
		if ((TS[temp].tipoentrada == variable || TS[temp].tipoentrada == parametro) && !strcmp(TS[temp].lexema, lexema))
			return 1;
	}
	return 0;
}

/* Asigna el tipo vacio al procedimiento y  cuenta cuantos parametros tiene */
void CuentaParametros () {
	
	int i;
	int parametros=0;

	for (i=tope;TS[i].tipoentrada != procedimiento;i--){
		if (TS[i].tipoentrada == parametro) {
			parametros++;
		}
	}

	TS[i].tipoDato=vacio;
	TS[i].parametros=parametros;
}

/* Asigna el tipo especificado a todas las entradas consecutivas
		que sean variables de tipo no_asignado */
void asignarTipoCascada(dTipo tipo) {
	
	int i;

	for (i=tope; TS[i].tipoentrada==variable && TS[i].tipoDato == no_asignado; i--){
		TS[i].tipoDato = tipo;
		if((tipo==entero)&&(TS[i].pila==1)){
			TS[i].tipoDato = pila_entero;
		}
		if((tipo==real)&&(TS[i].pila==1)){
			TS[i].tipoDato = pila_real;
		}
		if((tipo==booleano)&&(TS[i].pila==1)){
			TS[i].tipoDato = pila_booleano;
		}
		if((tipo==caracter)&&(TS[i].pila==1)){
			TS[i].tipoDato = pila_caracter;
		}
		
	}
		
}

/* Comprobar si ya existe otro parametro con el mismo lexema en el mismo
	   procedimiento*/
int BuscarParametroRepetido(char *lexema){
	int i;
	int igual= 0;

	for (i=tope; TS[i].tipoentrada != procedimiento; i--){
		igual = strcmp(TS[i].lexema, lexema);
		if (!igual) {
			printf ("\nError Semantico en la linea %d: Parametro %s esta duplicado\n", yylineno, lexema);
			return 1;
		}
	}
	return 0;
}

/*Comprueba que existe un nombre de procedimiento declarado igual al que se le pasa*/
int existeProc(char *lexema) {
	int i;
	int igual=0;
	for (i=tope+1; i>=0 && TS[tope].tipoentrada!=marca; i--){
		if (TS[i].tipoentrada == procedimiento && !strcmp(TS[i].lexema, lexema))
			igual=1;
	}

	if(igual==0)
		printf ("\nError Semantico en la linea %d: El procedimiento %s no esta declarado\n", yylineno, lexema);
		
	return igual;
}

/*Devuelve el numero de parametros del procedimiento*/
int numParametros(char* lexema){
	int i;
	int igual=0;
	for (i=tope+1; i>=0; i--){
		if (TS[i].tipoentrada == procedimiento && !strcmp(TS[i].lexema, lexema)){
			return TS[i].parametros;
		}
	}

}

/*Devuelve el tipo de dato del parametro del procedimiento comparandolo con el que se pasa a la funcion*/
dTipo tipoParametro(int num, char* lexema){
	int i;
	int igual=0;
	for (i=tope; i>=0; i--){
		if (TS[i].tipoentrada == procedimiento && !strcmp(TS[i].lexema, lexema)){
			return (TS[i+num].tipoDato);
		}
	}
}

/* Devuelve el tipo si existe definida una variable con el nombre especificado*/
dTipo get_tipo (char *lexema) {
	
	long int temp;
	//imprimeTS();
	for (temp=tope; temp>0 && TS[tope].tipoentrada!=marca;temp--){
		if (TS[temp].tipoentrada == variable && !strcmp(TS[temp].lexema, lexema))
			return TS[temp].tipoDato;
	}
}

/*Devuelve el tipo de la pila*/
dTipo tipoEnPila(dTipo v){

	if(es_pila(v)){
		
		if(v==pila_booleano)
			return booleano;
		if(v==pila_entero)
			return entero;
		if(v==pila_real)
			return real;
		if(v==pila_caracter)
			return caracter;

	}
	else
		return v;

}

/*Devuelve el tipo de la pila*/
dTipo tipoPila(dTipo v){

	if(es_pila(v)==0){
		
		if(v==booleano)
			return pila_booleano;
		if(v==entero)
			return pila_entero;
		if(v==real)
			return pila_real;
		if(v==caracter)
			return pila_caracter;
	}
	else
		return v;
}

/* Fin de funciones y procedimientos para manejo de la TS */

