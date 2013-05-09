%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generacion.h"

#define YYERROR_VERBOSE

/** La siguiente declaracion permite que ?yyerror? se pueda invocar desde el
*** fuente de lex (prueba.l)
**/

void yyerror( char* msg ) ;
/** La siguiente variable se usará para conocer el numero de la línea
*** que se esta leyendo en cada momento. También es posible usar la variable
*** ?yylineno? que también nos muestra la línea actual. Para ello es necesario
*** invocar a flex con la opción '-l'(compatibilidad con lex).
**/

int linea_actual = 1;
dTipo tipoPorAsignar,tipoSwitch;
int pila=0;
int argumentos=1;
int correcto=1;
char *nomproc;
int numparam=0;


%}

/** Para uso de mensajes de error sintáctico con BISON.
*** La siguiente declaración provoca que ?bison?, ante un error sintáctico,
*** visualice mensajes de error con indicación de los tokens que se esperaban
*** en el lugar en el que produjo el error (SÓLO FUNCIONA CON BISON>=2.1).
*** Para Bison<2.1 es mediante
***
*** #define YYERROR_VERBOSE
***
//%error-verbose
*** En caso de usar mensajes de error mediante ?mes? y ?mes2? (ver apéndice D)
*** nada de lo anterior debe tenerse en cuenta.
**/

//%error-verbose

/** A continuación declaramos los nombres simbólicos de los tokens.
*** byacc se encarga de asociar a cada uno un código
**/

%token CABPROG

%token OP_RELACIONAL 

%token INIBLOQUE
%token FINBLOQUE
%token PARIZQ
%token PARDER

%token COMA
%token FINLINEA

%token COND
%token ELSE
%token MIENT

%token IGUAL

%token ENTRADA
%token SALIDA

%token OPUNA

%token OP_PILA

%token OPMULTDIV

%token IGUALDAD
%token AND
%token OR
%token XOR

%token SUMRES

%token INS_ELEM

%token PROC

%token COMP
%token CASO
%token DEFECTO
%token FINCASO

%token DOSPUNT

%token TIPO

%token IDENTIFICADOR

%token CONST_BOOLEAN
%token CONST_INT
%token CONST_REAL
%token CONST_CHAR
%token CONST_CAD

%left OR
%left AND
%left XOR
%left IGUALDAD
%left OP_RELACIONAL
%left SUMRES
%left OPMULTDIV
%right OPUNA
%left OP_PILA
%left INS_ELEM


%start programa

%%

programa: cabecera_programa {
	abrir_fichero1();
	escribir_cabecera();
	} bloque;

cabecera_programa: CABPROG | error;

bloque: INIBLOQUE {TS_InsertaMarca(); escribir_llaveA();}
	variables_locales
	declar_de_subprogs
	sentencias
	FINBLOQUE {TS_VaciarEntradas(); escribir_llaveC();};

variables_locales: variables_locales cuerpo_declar_variables
	|;

cuerpo_declar_variables: TIPO declar_variables FINLINEA {escribir_variables(TipoEscrito($1.tipo)); asignarTipoCascada($1.tipo);
	if(($1.tipo==4)||($1.tipo==5)||($1.tipo==6)||($1.tipo==7)){
		dec_cons_pila(TipoEscrito($1.tipo), $2.lexema);
	}};

declar_variables: IDENTIFICADOR {
		if(es_repetida($1.lexema)==0){
			insertarIDENT(variable,$1.lexema);
			$$.nombre=$1.lexema;
			$$.lexema=$1.lexema;
			if(pila==1){
				espila();
			}
		}
	}
	|declar_variables COMA IDENTIFICADOR {
		if(es_repetida($3.lexema)==0){
			insertarIDENT(variable,$3.lexema);
			if(pila==1){
				espila();
			}
		}
		}
	|error;

declar_de_subprogs: declar_de_subprogs declar_de_subprog
	|;

declar_de_subprog: cabecera_subprog bloque{ if(en_fun>0) en_fun=en_fun-1;};

cabecera_subprog: PROC IDENTIFICADOR PARIZQ {
	if(es_repetida($2.lexema)==0){
		insertarIDENT(procedimiento,$2.lexema); asignarTipo(vacio);}
	} 
	
	declara_args {
		CuentaParametros();
		} PARDER {
		en_fun=en_fun+1;
			escribe_void_argumentos($2.lexema);
		} 
	| PROC IDENTIFICADOR PARIZQ PARDER {
	en_fun=en_fun+1;
		if(es_repetida($2.lexema)==0){
			insertarIDENT(procedimiento,$2.lexema); asignarTipo(vacio);
			escribe_void_vacio($2.lexema);
			}
	};


declara_args : argumento {$$.nombre=$1.nombre;}
		|argumento COMA declara_args {strcat($1.nombre,$3.nombre);$$.nombre=$1.nombre;}
		|error;
	
argumento: TIPO IDENTIFICADOR {
	if(BuscarParametroRepetido($2.lexema)==0){
		insertarIDENT(parametro,$2.lexema);
		if(pila==1){
			asignarTipo(tipoEnPila($1.tipo));
			pila=0;
			espila();
		}
		else {asignarTipo($1.tipo);}
	}
};

sentencias: sentencias sentencia|;

sentencia: bloque
	|sentencia_asignacion
	|sentencia_if
	|sentencia_while
	|sentencia_entrada
	|sentencia_salida
	|sentencia_switch
	|llamada_proced
	|error;

sentencia_asignacion: IDENTIFICADOR IGUAL expresion FINLINEA {
	if(existe($1.lexema)==0){
		printf("\nError Semantico en la linea %d: Identificador %s no esta declarado\n",yylineno,$1.lexema);
	}
	else{
		$1.tipo=get_tipo($1.lexema);
		if($1.tipo!=$3.tipo){
			printf("\nError Semantico en la linea %d: Asignacion de tipos incompatibles, no se puede asignar un %s a un %s\n",yylineno, MostrarTipo($3.tipo),MostrarTipo($1.tipo));
		}
		else {
			escribe_asignacion($1.lexema,$3.nombre);
		}
	}
};

sentencia_if: COND PARIZQ expresion PARDER {
	if($3.tipo!=booleano){
		printf("\nError Semantico en la linea %d: Se esperaba una sentencia de tipo boolean, no de tipo %s\n",yylineno,MostrarTipo($3.tipo));
	}else{
		escribe_if($3.nombre);
	}
}sentencia sentencia_else {delete_descriptor();};

sentencia_else: ELSE {escribe_else();} sentencia {
	if(en_fun==0)
		fprintf(fichero1,"%s:\n",tablaControl[ind].EtiquetaSalida);
	else
		fprintf(fichero2,"%s:\n",tablaControl[ind].EtiquetaSalida);
	escribe_elemento(";");
	}
	|{
		if(en_fun==0)
			fprintf(fichero1,"%s:\n",tablaControl[ind].EtiquetaElse);
		else
			fprintf(fichero2,"%s:\n",tablaControl[ind].EtiquetaElse);
};

sentencia_while: MIENT PARIZQ {
	DescriptorControl d;
	genera_etiqueta(d.EtiquetaEntrada);
	escribe_elemento(d.EtiquetaEntrada); 
	escribe_elemento(":;");
	} expresion {
		if($4.tipo!=booleano){
			printf("\nError Semantico en la linea %d: Se esperaba una sentencia de tipo boolean, no de tipo %s\n",yylineno,MostrarTipo($4.tipo));
		}else{
			escribe_while($4.nombre);
		}
}PARDER sentencia{fin_while();};

sentencia_entrada: ENTRADA identificadores FINLINEA {
	if(existe($2.lexema)==0){
		printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,$2.lexema);}
	else{
		$2.tipo=get_tipo($2.lexema);
		escribe_cin($2.tipo,$2.nombre);
	}
	if(es_pila($2.tipo)==1){
		printf("\nError Semantico en la linea %d: No se puede introducir una pila.\n",yylineno);}
};

identificadores: IDENTIFICADOR {$$.lexema=$1.lexema;$$.nombre=$1.lexema}
|identificadores COMA IDENTIFICADOR {
	if(existe($3.lexema)==0){
		printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,$3.lexema);}
	else{
		$3.tipo=get_tipo($3.lexema);
	}
}
|error;

sentencia_salida: SALIDA lista_expresiones_o_cadena FINLINEA{
	if(es_pila($2.tipo)==1){
		printf("\nError Semantico en la linea %d: No se puede mostrar una pila\n",yylineno);
	}
};

lista_expresiones_o_cadena: lista_expresiones_o_cadena IDENTIFICADOR{
	if(es_pila($2.tipo)==1){
		printf("\nError Semantico en la linea %d: No se puede mostrar una pila\n",yylineno);
	}
	else{
		escribe_cout($2.tipo,$2.lexema);
	}
}
	|lista_expresiones_o_cadena CONST_CAD{$2.tipo=cadena; escribe_cout($2.tipo,$2.lexema);}
	|;

sentencia_switch: COMP PARIZQ IDENTIFICADOR PARDER sentencia_case{
	if($3.tipo!=entero && $3.tipo!=caracter){
		printf("\nError Semantico en la linea %d: Se esperaba un entero o caracter, no un %s\n",yylineno,MostrarTipo($3.tipo));
	}else{
		tipoSwitch=$3.tipo;}
};

sentencia_case: CASO literal DOSPUNT sentencias FINCASO FINLINEA {
		if($2.tipo!=tipoSwitch){
			printf("\nError Semantico en la linea %d: Se esperaba un %s, no un %s\n",yylineno,MostrarTipo(tipoSwitch),MostrarTipo($2.tipo));
		}
	}
	|CASO literal DOSPUNT sentencias FINCASO FINLINEA sentencia_default {
		if($2.tipo!=tipoSwitch){
			printf("\nError Semantico en la linea %d: Se esperaba un %s, no un %s\n",yylineno,MostrarTipo(tipoSwitch),MostrarTipo($2.tipo));
		}
	}
	|sentencia_case CASO literal DOSPUNT sentencias FINCASO FINLINEA {
		if($3.tipo!=tipoSwitch){
			printf("\nError Semantico en la linea %d: Se esperaba un %s, no un %s\n",yylineno,MostrarTipo(tipoSwitch),MostrarTipo($3.tipo));
		}
};

sentencia_default: DEFECTO DOSPUNT sentencias FINCASO FINLINEA;

llamada_proced: IDENTIFICADOR PARIZQ PARDER FINLINEA {
		if(existeProc($1.lexema)==1){
			if(numParametros($1.lexema)!=0){
				printf("\nError Semantico en la linea %d: El procedimiento %s esperaba %d argumentos.\n",yylineno,$1.lexema,numParametros($1.lexema));
			}else{
				escribe_elemento("\n");
				escribe_elemento($1.lexema);
				escribe_elemento("();\n");
			}
		}
	}
	|IDENTIFICADOR PARIZQ {
		nomproc=$1.lexema;
		if(existeProc($1.lexema)==1){
			numparam=numParametros($1.lexema);}
	}
	param_llamada PARDER FINLINEA{
		if(existeProc($1.lexema)==1){
			if(numParametros($1.lexema)!=argumentos){
					printf("\nError Semantico en la linea %d: El procedimiento %s esperaba %d argumentos.\n",yylineno,$1.lexema,numParametros($1.lexema));
			}
			else{
				escribe_elemento("\n");
				escribe_elemento($1.lexema);
				escribe_elemento("(");
				escribe_elemento($3.nombre);
				escribe_elemento(");\n");
			}
		}
		argumentos=1;
		numparam=0;
	};

param_llamada: param_llamada COMA expresion {
		$$.nargumentos=1+$1.nargumentos;
		strcat($1.nombre,",");
		strcat($1.nombre,$3.nombre);
		$$.nombre=$1.nombre;
		if($$.nargumentos<=numparam){
			if(tipoParametro($$.nargumentos,nomproc)!=$3.tipo){
				printf("\nError Semantico en la linea %d: El procedimiento %s esperaba un %s en el argumento %d.\n",yylineno,nomproc,MostrarTipo(tipoParametro($$.nargumentos,nomproc)),$$.nargumentos);
			}
		}
		argumentos++;	
	}
	|expresion{
		$$.nargumentos=1;
		$$.nombre=$1.nombre;
		if($$.nargumentos<=numparam){
			if(tipoParametro($$.nargumentos,nomproc)!=$1.tipo){
				printf("\nError Semantico en la linea %d: El procedimiento %s esperaba un %s en el argumento %d.\n",yylineno,nomproc,MostrarTipo(tipoParametro($$.nargumentos,nomproc)),$$.nargumentos);
			}
		}
	};

expresion: PARIZQ expresion PARDER {
		$$.tipo=$2.tipo;
		$$.nombre=$2.nombre;
	}
	|OPUNA expresion {
		if($2.tipo!=booleano && es_pila($2.tipo)==0){
			printf("\nError Semantico en la linea %d: El operador %s es incompatible con tipo: %s, se esperaba booleano o pila.\n",yylineno,$1.lexema,MostrarTipo($2.tipo));}
		else{
			$$.tipo=$2.tipo;
			escribe_expresionUna($2.nombre,$1.lexema,TipoEscrito($2.tipo));
			copiaTo(temp,$$.nombre,11);
	}}
	|OP_PILA expresion {
		if(tipoEnPila($2.tipo)!=entero && tipoEnPila($2.tipo)!=real && tipoEnPila($2.tipo)!=caracter && tipoEnPila($2.tipo)!=booleano) {
			printf("\nError Semantico en la linea %d: El operador %s es incompatible con las pilas.\n",yylineno,$1.lexema,MostrarTipo($2.tipo));}
		else{
			if($1.lexema!="#"){
				escribe_expresionUna($2.nombre,"sac",TipoEscrito($2.tipo));
			}else{
				$2.tipo=tipoEnPila($2.tipo);
				escribe_expresionUna($2.nombre,"top",TipoEscrito($2.tipo));
				}
			$$.tipo=$2.tipo;
			$$.nombre=$2.nombre;
			copiaTo(temp,$$.nombre,11);
	}}
	|expresion OPMULTDIV expresion {
	//Valor y pila (solo el *)
	if(es_pila($3.tipo)==0 && es_pila($3.tipo)==1){
		if($1.tipo!=tipoEnPila($3.tipo)){
			printf("\nError Semantico en la linea %d:Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
			correcto=0;
		}else{
			if($1.tipo!=entero && $1.tipo!=real){
				printf("\nError Semantico en la linea %d: No se puede aplicar el operador %s a %s%s%s.\n",yylineno,$2.lexema,MostrarTipo($1.tipo),$2.lexema,MostrarTipo($3.tipo));
			}
			else{
				$$.tipo=$1.tipo;
			}
		}
		correcto=1;
	}
	//Dos pilas
	if(es_pila($1.tipo)==1 && es_pila($3.tipo)==1){
		if(tipoEnPila($1.tipo)!=tipoEnPila($3.tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo(tipoEnPila($1.tipo)),MostrarTipo(tipoEnPila($3.tipo)));
		}
		else{
			$$.tipo=$1.tipo;
			correcto=1;
		}
	}
	//Pila y valor
	if(es_pila($1.tipo)==1 && es_pila($3.tipo)==0){
		if(tipoEnPila($1.tipo)!=$3.tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
		}
		else{
			$$.tipo=$1.tipo;
			correcto=1;
		}
	}
	//Dos Valores
	if(es_pila($1.tipo)==0 && es_pila($3.tipo)==0){
		if($1.tipo!=$3.tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
		}
		else{
			$$.tipo=$1.tipo;
			escribe_expresionBin($1.nombre,$3.nombre,$2.lexema,TipoEscrito($1.tipo));
			copiaTo(temp,$$.nombre,11);
			correcto=1;
		}
	}
	}
	|expresion SUMRES expresion{
	if(es_pila($3.tipo)==1){
		//Dos pilas
		if(es_pila($1.tipo)==1 && es_pila($3.tipo)==1){
			if(tipoEnPila($1.tipo)!=tipoEnPila($3.tipo)){
				printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo(tipoEnPila($1.tipo)),MostrarTipo(tipoEnPila($3.tipo)));
			}
			else{
				$$.tipo=$1.tipo;
				escribe_sumres_pp($1.nombre,$2.nombre,$1.tipo);
				copiaTo(temp, $$.nombre,11);
				correcto=1;
			}
		}
			//Valor y pila (solo el +)
		if($1.tipo!=tipoEnPila($3.tipo)){
			printf("\nError Semantico en la linea %d:Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
			correcto=0;
		}
	}else{
		if($1.tipo!=$3.tipo){
			printf("\nError Semantico en la linea %d: No se puede aplicar el operador %s a %s%s%s.\n",yylineno,$2.lexema,MostrarTipo($1.tipo),$2.lexema,MostrarTipo($3.tipo));
			}
			else{
				$$.tipo=$1.tipo;
			}
		}
		correcto=1;
	//Pila y valor
	if(es_pila($1.tipo)==1 && es_pila($3.tipo)==0){
		if(tipoEnPila($1.tipo)!=$3.tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
		}
		else{
			$$.tipo=$1.tipo;
			correcto=1;
		}
	}
	//Dos Valores
	if(es_pila($1.tipo)==0 && es_pila($3.tipo)==0){
		if($1.tipo!=$3.tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
		}
		else{
			$$.tipo=$1.tipo;
			escribe_expresionBin($1.nombre,$3.nombre,$2.lexema,TipoEscrito($1.tipo));
			copiaTo(temp,$$.nombre,11);
			correcto=1;
		}
	}
	}
	|expresion OP_RELACIONAL expresion{
		if((($1.tipo!=entero) && ($1.tipo!=real)) || (($3.tipo!=entero) && ($3.tipo!=real))){
			printf("\nError Semantico en la linea %d: El operador %s se esta utilizando como: %s%s%s, se esperaba int%sint o real%sreal.\n",yylineno,$2.lexema,MostrarTipo($1.tipo),$2.lexema,MostrarTipo($3.tipo),$2.lexema,$2.lexema);
			correcto=0;
		}
		else{
			if(($1.tipo)!=($3.tipo)){
				printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
				correcto=0;
			}
		}
		if(correcto==1){
			$$.tipo=booleano;
			escribe_expresionBin($1.nombre,$3.nombre,$2.lexema,"int");
			copiaTo(temp,$$.nombre,11);
		}
		else{
			correcto=1;
			$$.tipo=booleano;
		}
	}
	|expresion OR expresion {
		if(($1.tipo)!=($3.tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
				correcto=0;
		}
		if(correcto==1)
			$$.tipo=booleano;
		else{
			correcto=1;
			$$.tipo=booleano;
		}
	}
	|expresion AND expresion {
		if(($1.tipo)!=($3.tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
				correcto=0;
		}
		if(correcto==1){
			$$.tipo=booleano;
			escribe_expresionBin($1.nombre,$3.nombre,$2.lexema,"int");
			copiaTo(temp,$$.nombre,11);
		}else{
			correcto=1;
			$$.tipo=booleano;
		}
	}
	|expresion XOR expresion {
		if(($1.tipo)!=($3.tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
				correcto=0;
		}
		if(correcto==1){
			$$.tipo=booleano;
			escribe_expresionBin($1.nombre,$3.nombre,$2.lexema,"int");
			copiaTo(temp,$$.nombre,11);
		}else{
			correcto=1;
			$$.tipo=booleano;
		}
	}
	|expresion IGUALDAD expresion {
		if(($1.tipo)!=($3.tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo($1.tipo),MostrarTipo($3.tipo));
				correcto=0;
		}
		if(correcto==1){
			$$.tipo=booleano;
			escribe_expresionBin($1.nombre,$3.nombre,$2.lexema,"int");
			copiaTo(temp,$$.nombre,11);
		}else{
			correcto=1;
		}
	}
	|expresion INS_ELEM expresion {
		if(es_pila($1.tipo)==1){
			if(tipoEnPila($1.tipo)!=$3.tipo){
				printf("\nError Semantico en la linea %d: No se puede aplicar el operador %s a %s%s%s.\n",yylineno,$2.lexema,MostrarTipo(tipoEnPila($1.tipo)),$2.lexema,MostrarTipo(tipoEnPila($3.tipo)));
				correcto=0;
			}
		}
		else{
			printf("La expresion no es una pila \n");
		}
		correcto=1;
		$$.tipo=$1.tipo;
		escribe_expresionBin($1.nombre,$3.nombre,"ins",TipoEscrito($1.tipo));
		copiaTo(temp,$$.nombre,11);
	}
	|IDENTIFICADOR {
		if(existe($1.lexema)==0){
			printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,$1.lexema);}
		else{
			$$.tipo=get_tipo($1.lexema);
			$$.nombre=$1.lexema;
		}
	}
	|literal {$$.tipo=$1.tipo; $$.nombre=$1.nombre;}
	|agregados_pila {$$.tipo=tipoPila($1.tipo)}
	|SUMRES expresion %prec OPUNA {
		if(($2.tipo!=entero) && ($2.tipo!=real)){
			printf("\nError Semantico en la linea %d: El operador %s es incompatible con tipo %s, se esperaba entero o real.\n",yylineno,$1.lexema,MostrarTipo($2.tipo));
		}
		else{
			$$.tipo=$2.tipo;
			escribe_expresionUna($2.nombre,$1.lexema,TipoEscrito($2.tipo));
			copiaTo(temp,$$.nombre,11);
		}
	}
	|error;

agregados_pila: INIBLOQUE FINBLOQUE
	|INIBLOQUE valores_pila FINBLOQUE {
		if(es_pila($2.tipo)==1){
			printf("\nError Semantico en la linea %d: No se puede usar una pila dentro de otra pila.\n",yylineno);}
	};

valores_pila: IDENTIFICADOR {
		if(existe($1.lexema)==0){
			printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,$1.lexema);}
		else{
			$$.tipo=get_tipo($1.lexema);
		}
	}
	|literal {$$.tipo=$1.tipo; $$.nombre=$1.nombre;}
	|valores_pila COMA literal {
		if($3.tipo!=$1.tipo){
			printf("\nError Semantico en la linea %d: Incompatibilidad de tipos en la pila. Se esperaba %s y se introdujo %s.\n",yylineno,MostrarTipo($3.tipo),MostrarTipo($1.tipo));}
		else{
			$$.tipo=$3.tipo;
		}
	};

literal: CONST_INT {$$.tipo=$1.tipo;$$.nombre=$1.lexema;}
	|CONST_REAL {$$.tipo=$1.tipo;$$.nombre=$1.lexema;}
	|CONST_CHAR {$$.tipo=$1.tipo;$$.nombre=$1.lexema;}
	|CONST_BOOLEAN {$$.tipo=$1.tipo;
		if($1.atrib==0)
			$$.nombre="1";
		else
			$$.nombre="0";
	};

%%	
/** aqui incluimos el fichero generado por el 'lex'
*** que implementa la función 'yylex'
**/

#ifdef DOSWINDOWS /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

/** se debe implementar la función yyerror. En este caso
*** simplemente escribimos el mensaje de error en pantalla
**/

void yyerror( char *msg )
{
	fprintf(stderr,"[Linea %d]: %s\n", nlineas, msg);
}


