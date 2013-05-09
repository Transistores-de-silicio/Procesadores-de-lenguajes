%{
#include "tabla.h"
	int numero_linea=1;
%}
blanco [ \t]
letra [a-zA-Z]
digito [0-9]
boolean ("true"|"false")
otros .
%%
{blanco}+ ;
":" return DOSPUN;
"set of integer" return TIPO;
"set of real" return TIPO; 
"set of character" return TIPO; 
"set of boolean" return TIPO;
"integer"  return TIPO;
"real" return TIPO;
"character" return TIPO;
"boolean" return TIPO;
">"		    return OPBI;
">="		return OPBI;
"<"		    return OPBI;
"<="		return OPBI; 
"="		    return OPBI;
"¬=" 		return OPBI;
"<>"		return OPBI;
"and"		return OPBI;
"or"		return OPBI;
"xor"		return OPBI;
"in"		return OPBI;
"*"		    return OPBI;
"/"		    return OPBI;
"+"			return OPUN;
"-"			return OPUN;
"not"		return NOT;
","			return CO;
"("			return PAA;
")"			return PAC;
"for"			return FOR;
":="			return IGUAL;
"to"			return TO;
"do"			return DO;
"while"			return WHILE;
"if"			return IF;
"then"			return THEN;
"else"			return ELSE;
"else if"			return ELIF;
";"			return PUNCO;
"function"			return FUNCION;
"begin"			return BEGIN;
"end"			return END;
"var"			return VAR;
"program"			return PROGRAM;
"."			return PUN;
".."			return PUN2;
"["			return CORA;
"]"			return CORC;
("writeln"|"write") return SALIDA;
("readln"|"read") return ENTRADA;


("'"[^"'"]"'"|{boolean}|{digito}+"."{digito}+)	  return CONS;

{digito}+    return CONSEN;
({letra}|"_")({letra}|{digito})* return IDEN;
\"[^\"]*\" return FRASE;
"\n" ++numero_linea;
{otros} printf("\nEn la linea %d, Detectado Error lexico: Lexema %s\n", numero_linea, yytext);

%%
main () {
int val;
val= yylex() ;
while (val != 0) {
	printf("lexema= %s, codigo de token= %d\n",yytext,val);
	val= yylex() ;
	}
exit (1);
}
int yywrap()
{
return(1);
}
