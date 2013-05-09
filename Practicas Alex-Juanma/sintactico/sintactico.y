%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define YYERROR_VERBOSE

/** La siguiente declaracion permite que yyerror se pueda invocar desde el
*** fuente de lex (prueba.l)
**/

void yyerror( char* msg ) ;
/** La siguiente variable se usará para conocer el numero de la línea
*** que se esta leyendo en cada momento. También es posible usar la variable
*** yylineno que también nos muestra la línea actual. Para ello es necesario
*** invocar a flex con la opción -l (compatibilIDENTIFICADORad con lex).
**/

int nlineas = 1 ;

%}

/** Para uso de mensajes de error sintáctico con BISON.
*** La siguiente declaración provoca que bison, ante un error sintáctico,
*** visualice mensajes de error con indicación de los tokens que se esperaban
*** en el lugar en el que produjo el error (SÓLO FUNCIONA CON BISON>=2.1).
*** Para Bison<2.1 es mediante
***
*** #define YYERROR_VERBOSE
***
%error-verbose
*** En caso de usar mensajes de error mediante mes y mes2 (ver apéndice D)
*** nada de lo anterior debe tenerse en cuenta.
**/

%error-verbose

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

programa: cabecera_programa bloque;

cabecera_programa: CABPROG | error;

bloque: INIBLOQUE 
	variables_locales
	declar_de_subprogs
	sentencias
	FINBLOQUE;

variables_locales: variables_locales cuerpo_declar_variables
	|;

cuerpo_declar_variables: TIPO declar_variables FINLINEA;

declar_variables: IDENTIFICADOR|
	declar_variables COMA IDENTIFICADOR|IDENTIFICADOR igualdad|error;

identificadores: identificadores COMA IDENTIFICADOR|IDENTIFICADOR|error;

declar_de_subprogs: declar_de_subprogs declar_de_subprog
	|;

declara_args : TIPO IDENTIFICADOR
		|TIPO IDENTIFICADOR COMA declara_args
		|error;

declar_de_subprog: cabecera_subprog bloque;

cabecera_subprog: PROC IDENTIFICADOR PARIZQ declara_args PARDER;

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

sentencia_asignacion: IDENTIFICADOR igualdad FINLINEA;

igualdad: igualdad IGUAL IDENTIFICADOR|IGUAL expresion;

sentencia_if: COND PARIZQ expresion PARDER sentencia
	|COND PARIZQ expresion PARDER sentencia sentencia_else;

sentencia_else: ELSE sentencia;

sentencia_while: MIENT PARIZQ expresion PARDER sentencia;

sentencia_entrada: ENTRADA identificadores FINLINEA;

sentencia_salida: SALIDA lista_expresiones_o_letra FINLINEA;

lista_expresiones_o_letra: identificadores|CONST_CAD|literal;

sentencia_switch: COMP PARIZQ IDENTIFICADOR PARDER sentencia_case;

sentencia_case: CASO literal DOSPUNT sentencias FINCASO FINLINEA
	|CASO literal DOSPUNT sentencias FINCASO FINLINEA sentencia_default
	|sentencia_case CASO literal DOSPUNT sentencias FINCASO FINLINEA;

sentencia_default: DEFECTO DOSPUNT sentencias FINCASO FINLINEA;

llamada_proced: IDENTIFICADOR PARIZQ param_llamada PARDER FINLINEA;

param_llamada: expresion|param_llamada COMA expresion|;

expresion: PARIZQ expresion PARDER
	|OPUNA expresion 
	|OP_PILA expresion
	|expresion OPMULTDIV expresion
	|expresion OP_RELACIONAL expresion
	|expresion OR expresion
	|expresion AND expresion
	|expresion XOR expresion
	|expresion IGUALDAD expresion
	|expresion SUMRES expresion
	|expresion INS_ELEM expresion
	|IDENTIFICADOR
	|literal
	|agregados_pila
	|SUMRES expresion %prec OPUNA
	|error;

agregados_pila: INIBLOQUE FINBLOQUE
	|INIBLOQUE valores_pila FINBLOQUE;

valores_pila: IDENTIFICADOR
	|literal
	|valores_pila COMA literal;

literal: CONST_INT|CONST_REAL|CONST_CHAR|CONST_BOOLEAN;

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
