%{
	//ALEXXXXXXXXXXXXXXXXXXXXXX
	//#include "tabla.h"
	#define MAXLONBUFFER 200
	char buffer[MAXLONBUFFER];
%}

digito [0-9]
letra [a-zA-Z]
caracter [^"\a]
retorno \n
blanco " "|\t
cadena \"[^"\a]*\"

%option noyywrap
%%
{retorno} {nlineas ++;}
{blanco} {;}

"inicio" {return (CABPROG);}

">" {return (OP_RELACIONAL);}
"<" {return (OP_RELACIONAL);}
">=" {return (OP_RELACIONAL);}
"<=" {return (OP_RELACIONAL);}

"{" {return (INIBLOQUE);}
"}" {return (FINBLOQUE);}
"(" {return (PARIZQ);}
")" {return (PARDER);}

"," {return (COMA);}
";" {return (FINLINEA);}

"si" {return (COND);}
"en otro caso" {return (ELSE);}
"mientras" {return (MIENT);}

"=" {return (IGUAL);}

"introducir" {return (ENTRADA);}
"imprimir" {return (SALIDA);}

"!" {return (OPUNA);}

"&" {return (OP_PILA);}
"#" {return (OP_PILA);}
"@" {return (OP_PILA);}

"*" {return (OPMULTDIV);}
"/" {return (OPMULTDIV);}

"==" {return (IGUALDAD);}
"!=" {return (IGUALDAD);}
"&&" {return (AND);}
"||" {return (OR);}
"^" {return (XOR);}

"+" {return (SUMRES);}
"-" {return (SUMRES);}

"%%" {return (INS_ELEM);}

"proc" {return (PROC);}

"comprobar" {return (COMP);}
"caso" {return (CASO);}
"defecto" {return (DEFECTO);}
"fin_caso" {return (FINCASO);}

":" {return (DOSPUNT);}

"entero" {return (TIPO);}
"real" {return (TIPO);}
"booleano" {return (TIPO);}
"caracter" {return (TIPO);}
"pila entero" {return (TIPO);}
"pila real" {return (TIPO);}
"pila booleano" {return (TIPO);}
"pila caracter" {return (TIPO);}

"cierto" {return (CONST_BOOLEAN);}
"falso" {return (CONST_BOOLEAN);}

{letra}({letra}|{digito}|"_")* {return (IDENTIFICADOR);}

{digito}+ {return (CONST_INT);}
{digito}+"."{digito}+ {return (CONST_REAL);}
'{caracter}' {return (CONST_CHAR);}
{cadena} {return (CONST_CAD);}

. {snprintf(buffer,MAXLONBUFFER, "El(Los) caracter(es) '%s' no forma(n) ningun token conocido",yytext);
		yyerror(buffer);}

%%
