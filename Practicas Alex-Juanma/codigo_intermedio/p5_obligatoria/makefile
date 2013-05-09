.SUFFIXES: 

prueba: main.o y.tab.o 
	gcc -o prueba main.o y.tab.o 

y.tab.o: y.tab.c 
	gcc -c y.tab.c 

main.o: main.c 
	gcc -c main.c 

y.tab.c: sintactico_semantico.y lex.yy.c 
	bison -t -o y.tab.c sintactico_semantico.y 

lex.yy.c: lexico.lex 
	flex -l lexico.lex 
	
limpia: 
	rm -f prueba main.o y.tab.o y.tab.c lex.yy.c 

todo: 
	make limpia 
	make prueba
	make salida
	
salida: 
	./prueba prueba1
	gcc -o p salida.c
	./p
