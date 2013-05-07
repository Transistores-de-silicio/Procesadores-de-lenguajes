%{

#include "tabla.h"
    int linea_actual = 1 ;
    int atributo = -1;

%}

blanco [ \t]
letra [a-zA-Z]
digito [0-9]
otros .

%%

{blanco}+ ;
":" return DOSPUNTOS;
"," return COMA; 
"." return PUNTO;
"+" {atributo = 0; return OPDEBIL;};
"-" {atributo = 1; return OPDEBIL;};
"*" {atributo = 0; return OPFUERTE;};
"/" {atributo = 1; return OPFUERTE;};
"var" return VAR;
"END_VAR" return ENDVAR;
"stack" return PILA;
"{" return CORIZ;
"}" return CORDE;
"string" return TYPE;
"==" {atributo = 0; return OPLOGICO;};
"!=" {atributo = 1; return OPLOGICO;};
"<=" {atributo = 2; return OPLOGICO;};
"<" {atributo = 3; return OPLOGICO;};
">=" {atributo = 4; return OPLOGICO;};
">" {atributo = 5; return OPLOGICO;};
"and" {atributo = 6; return OPLOGICO;};
"or" {atributo = 7; return OPLOGICO;};
"not" {atributo = 8; return OPLOGICO;};
"=" return ASIG; 
"(" return PARI;
")" return PARD;
";" return PYC; 
"while" return WHILE; 
"do" return DO; 
"if" return IF; 
"then" return THEN;
"else" return ELSE;
"++" {atributo = 0; return OPUNARIO;};
"--" {atributo = 1; return OPUNARIO;};
"repeat" return REPEAT;
"until" return UNTIL;
"bool" {atributo = 0; return TYPE;};
"char" {atributo = 1; return TYPE;};
"integer" {atributo = 2; return TYPE;};
"real" {atributo = 3; return TYPE;};
"FUNTION" return FUNTION;
"Program" return PROGRAM;
"begin" return INICIO;
"Read" return READ;
"Write" return WRITE;
"const" return CONST;
"true" return TRUE;
"false" return FALSE;
"return" return RETURN;
"end" return FINAL;
{letra}({letra}|{digito})* return ID;
{digito}+.{digito}+ return REAL;
{digito}+ return NUMERO;
"\n" ++linea_actual;


{otros} printf ("\n(Linea %d) Error léxico: caracter %s\n", linea_actual, yytext);

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
