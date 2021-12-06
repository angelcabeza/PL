.PHONY: all clean

all: prueba

prueba: main.o y.tab.o
	g++ -g -o $@ $^

main.o: main.c
	g++ -g -c -o main.o main.c -I.

lexico: lex.yy.c
	lex $^ -o $@ -I -lfl

y.tab.o: y.tab.c
	g++ -g -c -o $@ y.tab.c -lfl -I.

y.tab.c: lexico.l lex.yy.c
	bison -v -d -o $@ yacc.y

lex.yy.c: lexico.l
	flex -o $@ lexico.l


#$(INCLUDE)/y.tab.h: $(SRC)/sintactico.y
#	yacc -d $^ -o $@

clean:
	-rm /*.o
	-rm y.tab.c
	-rm lex.yy.c
	-rm y.tab.h