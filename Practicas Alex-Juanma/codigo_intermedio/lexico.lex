%{
	//#include "tabla.h"
	int nlineas=1;
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
{retorno} {nlineas++;}
{blanco} {;}

"inicio" {return (CABPROG);}

">" {yylval.lexema = strdup(yytext);
	yylval.atrib = 0;
	return (OP_RELACIONAL);}
	
"<" {yylval.lexema = strdup(yytext);
	yylval.atrib = 1;
	return (OP_RELACIONAL);}
	
">=" {yylval.lexema = strdup(yytext);
	yylval.atrib = 2;
	return (OP_RELACIONAL);}
	
"<=" {yylval.lexema = strdup(yytext);
	yylval.atrib = 3;
	return (OP_RELACIONAL);}

"{" {return (INIBLOQUE);}
"}" {return (FINBLOQUE);}
"(" {return (PARIZQ);}
")" {return (PARDER);}

"," {return (COMA);}
";" {return (FINLINEA);}

"si" {return (COND);}
"en otro caso" {return (ELSE);}
"mientras" {return (MIENT);}

"=" {yylval.lexema = strdup(yytext);
	return (IGUAL);}

"introducir" {yylval.lexema = strdup(yytext);
	return (ENTRADA);}
	
"imprimir" {yylval.lexema = strdup(yytext);
	return (SALIDA);}

"!" {yylval.lexema = strdup(yytext);
	return (OPUNA);}

"&" {yylval.lexema = strdup(yytext);
	yylval.atrib = 0;
	return (OP_PILA);}
	
"#" {yylval.lexema = strdup(yytext);
	yylval.atrib = 1;
	return (OP_PILA);}
	
"@" {yylval.lexema = strdup(yytext);
	yylval.atrib = 2;
	return (OP_PILA);}

"*" {yylval.lexema = strdup(yytext);
	yylval.atrib = 0;
	return (OPMULTDIV);}
	
"/" {yylval.lexema = strdup(yytext);
	yylval.atrib = 1;
	return (OPMULTDIV);}

"==" {yylval.lexema = strdup(yytext);
	yylval.atrib = 0;
	return (IGUALDAD);}
	
"!=" {yylval.lexema = strdup(yytext);
	yylval.atrib = 1;
	return (IGUALDAD);}
	
"&&" {yylval.lexema = strdup(yytext);
	return (AND);}
	
"||" {yylval.lexema = strdup(yytext);
	return (OR);}
	
"^" {yylval.lexema = strdup(yytext);
	return (XOR);}

"+" {yylval.lexema = strdup(yytext);
	yylval.atrib = 0;
	return (SUMRES);}
	
"-" {yylval.lexema = strdup(yytext);
	yylval.atrib = 1;
	return (SUMRES);}

"%%" {yylval.lexema = strdup(yytext);
	return (INS_ELEM);}

"proc" {yylval.lexema = strdup(yytext);
	return (PROC);}

"comprobar" {return (COMP);}
"caso" {return (CASO);}
"defecto" {return (DEFECTO);}
"fin_caso" {return (FINCASO);}

":" {return (DOSPUNT);}

"entero" {yylval.lexema = strdup(yytext);
	yylval.atrib = 0;
	pila=0;
	yylval.tipo = entero;
	return (TIPO);}
	
"real" {yylval.lexema = strdup(yytext);
	yylval.atrib = 1;
	pila=0;
	yylval.tipo = real;
	return (TIPO);}
	
"booleano" {yylval.lexema = strdup(yytext);
	yylval.atrib = 2;
	pila=0;
	yylval.tipo = booleano;
	return (TIPO);}

"caracter" {yylval.lexema = strdup(yytext);
	yylval.atrib = 3;
	pila=0;
	yylval.tipo = caracter;
	return (TIPO);}
	
"pila entero" {yylval.lexema = strdup(yytext);
	yylval.atrib = 4;
	pila=1;
	yylval.tipo = pila_entero;
	return (TIPO);}
	
"pila real" {yylval.lexema = strdup(yytext);
	yylval.atrib = 5;
	pila=1;
	yylval.tipo = pila_real;
	return (TIPO);}

"pila booleano" {yylval.lexema = strdup(yytext);
	yylval.atrib = 6;
	pila=1;
	yylval.tipo = pila_booleano;
	return (TIPO);}

"pila caracter" {yylval.lexema = strdup(yytext);
	yylval.atrib = 7;
	pila=1;
	yylval.tipo = pila_caracter;
	return (TIPO);}

"cierto" {yylval.lexema = strdup(yytext);
	yylval.tipo = booleano;
	yylval.atrib = 0;
	return (CONST_BOOLEAN);}
	
"falso" {yylval.lexema = strdup(yytext);
	yylval.tipo = booleano;
	yylval.atrib = 1;
	return (CONST_BOOLEAN);}

{letra}({letra}|{digito}|"_")* {yylval.lexema = strdup(yytext);
	return (IDENTIFICADOR);}

{digito}+ {yylval.lexema = strdup(yytext);
	yylval.tipo = entero;
	return (CONST_INT);}
	
{digito}+"."{digito}+ {yylval.lexema = strdup(yytext);
	yylval.tipo = real;
	return (CONST_REAL);}
	
\'{caracter}\' {yylval.lexema = strdup(yytext);
	yylval.tipo = caracter;
	return (CONST_CHAR);}
	
{cadena} {yylval.lexema = strdup(yytext);
	return (CONST_CAD);}

. {snprintf(buffer,MAXLONBUFFER, "El(Los) caracter(es) '%s' no forma(n) ningun token conocido",yytext); yyerror(buffer);}

%%


