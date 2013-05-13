%{
	#define MAXLONBUFFER 200
	char buffer[MAXLONBUFFER];
%}
retorno \n
blanco " "|\t
letra [a-zA-Z]
digito [0-9]
boolean ("true"|"false")
otros .

%option noyywrap
%%
{retorno} {nlineas ++;}
{blanco}+ ;

":" return DOSPUN;
"set of integer" return TIPO;
"set of real" return TIPO; 
"set of char" return TIPO; 
"set of boolean" return TIPO;
"integer"  return TIPO;
"real" return TIPO;
"char" return TIPO;
"boolean" return TIPO;
">"		    return OPREL;
">="		return OPREL;
"<"		    return OPREL;
"<="		return OPREL; 
"="		    return OPREL;
"¬=" 		return OPREL;
"<>"		return OPREL;
"and"		return AND;
"or"		return OR;
"xor"		return XOR;
"in"		return IN;
"*"		    return MULDIV;
"/"		    return MULDIV;
"+"			return SUMRES;
"-"			return SUMRES;
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
\;			{return (PUNCO);}
"function"		{return (FUNCION);}
"begin"			return BEGINN;
"end"			{return (END);}
"var"			return VAR;
"program"		return PROGRAM;
".."			return PUN2;
"."			return PUN;
"["			return CORA;
"]"			return CORC;
("writeln"|"write") return SALIDA;
("readln"|"read") return ENTRADA;


("'"[^"'"]"'"|{boolean}|{digito}+"."{digito}+)	  return CONS;

{digito}+    return CONSEN;
({letra}|"_")({letra}|{digito})* return IDEN;
\'[^\']*\' return FRASE;

{otros} {snprintf(buffer,MAXLONBUFFER, "Los caracteres '%s' no forman ningun token conocido",yytext);
		 yyerror(buffer);}

%%
