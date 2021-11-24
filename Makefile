.SUFFIXES:
prueba: main.o y.tab.o
	gcc -o prueba $^

y.tab.o: y.tab.c
	gcc -c -o y.tab.o y.tab.c -lfl -I ./ 

main.o: main.c 
	gcc -c main.c

y.tab.c: yacc.y lex.yy.c
	bison -v -d -o y.tab.c yacc.y

lex.yy.c: lexico.l y.tab.h
	flex lexico.l

y.tab.h: yacc.y
	yacc -d yacc.y

limpia:
	rm -f prueba main.o y.tab.o y.tab.c lex.yy.c y.tab.h

todo:
	make limpia
	make prueba