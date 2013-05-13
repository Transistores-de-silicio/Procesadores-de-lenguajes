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

/** A continuación declaramos los nombres simbólicos de los tokens.
*** byacc se encarga de asociar a cada uno un código
**/

%token TIPO

%token CONS
%token CONSEN
%token IDEN

%token CO
%token PAA
%token PAC
%token SALIDA
%token FRASE
%token ENTRADA
%token FOR
%token IGUAL
%token TO
%token DO
%token WHILE
%token IF
%token THEN
%token ELSE
%token PUNCO
%token FUNCION
%token BEGINN
%token END
%token VAR
%token PUN
%token PUN2
%token CORA
%token CORC
%token DOSPUN
%token PROGRAM

%left OR
%left AND
%left XOR
%left NOT
%left IN
%left OPREL
%left SUMRES
%left MULDIV


%start Programa

%%

Programa: Cabecera_programa bloque PUN;

Cabecera_programa: PROGRAM IDEN PUNCO
	| error;

bloque: Declar_de_variables_locales Declar_de_subprogs BEGINN Sentencias END;

Declar_de_variables_locales: VAR Variables_locales
	| ;

Variables_locales: Variables_locales Cuerpo_declar_variables
	| Cuerpo_declar_variables;
	
Cuerpo_declar_variables: lista_variables DOSPUN TIPO PUNCO;

lista_variables: IDEN
    | lista_variables CO IDEN
    | error;

Declar_de_subprogs: Declar_de_subprogs Declar_subprog
	| ;

Declar_subprog: Cabecera_subprog bloque PUNCO;

Cabecera_subprog: FUNCION IDEN PAA lista_argumentos PAC DOSPUN TIPO PUNCO;

lista_argumentos: lista_argumentos PUNCO Cuerpo_declar_argumentos
	| Cuerpo_declar_argumentos;

Cuerpo_declar_argumentos: lista_variables DOSPUN TIPO;

Sentencias: Sentencias Sentencia
	| ;
	
Sentencia: bloque PUNCO
	| sentencia_asignacion
	| sentencia_if
	| sentencia_while
	| sentencia_for
	| sentencia_entrada
	| sentencia_salida
	| error;
	
sentencia_asignacion: IDEN IGUAL expresion PUNCO;

sentencia_if: 
	  IF expresion THEN Sentencia
	| IF expresion THEN Sentencia ELSE Sentencia;

sentencia_while: WHILE expresion DO Sentencia;

sentencia_for: FOR IDEN IGUAL expresion TO expresion DO Sentencia;

sentencia_entrada: ENTRADA PAA lista_variables PAC PUNCO;

sentencia_salida: SALIDA PAA lista_expresiones_o_cadena PAC PUNCO;

lista_expresiones_o_cadena: expresion
    | lista_expresiones_o_cadena CO lista_expresiones_o_cadena_cont
    | FRASE;
lista_expresiones_o_cadena_cont: expresion
	| FRASE;

lista_expresiones: expresion
	| lista_expresiones CO expresion
	| ;


expresion: PAA expresion PAC
	| SUMRES expresion
	| expresion SUMRES expresion
	| expresion OPREL expresion
	| expresion MULDIV expresion
	| expresion OR expresion
	| expresion XOR expresion
	| expresion IN expresion
	| expresion AND expresion
	| NOT expresion
	| IDEN
	| constante
	| conjunto
	| funcion
	| error;

funcion: IDEN PAA lista_expresiones PAC;
 
conjunto: CORA restoConjunto CORC;

restoConjunto: restoConjunto CO expresion
    | constante PUN2 constante
    | expresion
	| ;

constante: CONS
	| CONSEN;
	
	
	
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

