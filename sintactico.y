%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    void yyerror(char * msg);

    int linea_actual = 1
%}

%error-verbose



%token MAIN 
%token INIBLO 
%token ENDBLO 
%token INIVAR 
%token ENDVAR 
%token TYPEVAR 
%token SEMICOLON 
%token COMMA  
%nonassoc ID INIPA 
%token ENDPA 
%token LIST 
%token IF 
%token ELSE 
%token FOR 
%token WHILE 
%token ASIGN 
%token CONST_INT 
%token ITEFOR 
%token DO 
%token READ 
%token PRINT 
%token RETURN 
%token LISTOP1 
%nonassoc ATSIGN 
%token CONSTANT 
%token WORD
%token EQUALS
%token INISQR 
%token ENDSQR

%left BINOP
%left ADDITION

%right UNARI
%right LISTOP2 MINMIN
%right PLUSPLUS
%left INISQR ENDSQR

%start S

%%
S   : MAIN B
;

B   : INIBLO Dvl Dss Ses ENDBLO
;

Dvl : INIVAR Vl ENDVAR 
    |
;

Vl  : Vl Cdv 
    | Cdv
;

Cdv : TYPEVAR Lv SEMICOLON 
    | El SEMICOLON
;

Lv  : Lv COMMA ID 
    | ID
;

El  : LIST TYPEVAR Lv
;

Dss : Dss Ds 
    |
;

Ds  : Cs B
;

Cs  : Dc ID INIPA Pa ENDPA 
    | Dc ID INIPA ENDPA
;

Dc  : LIST TYPEVAR 
    | TYPEVAR
;

Pa  : Pa COMMA Dc ID 
    | Dc ID
;

Ses : Ses Se 
    | Se
;

Se  : B 
    | ID ASIGN Exp SEMICOLON 
    | IF INIPA Exp ENDPA Se
    | IF INIPA Exp ENDPA Se ELSE Se 
    | WHILE INIPA Exp ENDPA Se
    | FOR ID ASIGN CONST_INT ITEFOR CONST_INT DO Se
    | READ Lv SEMICOLON 
    | PRINT Lec SEMICOLON 
    | RETURN Exp SEMICOLON 
    | Exp LISTOP1 
    | LISTOP2 Exp
;

Exp : INIPA Exp ENDPA 
    | UNARI Exp 
    | ADDITION Exp 
    | PLUSPLUS Exp 
    | MINMIN Exp 
    | Exp BINOP Exp
    | Exp ATSIGN Exp 
    | Exp PLUSPLUS Exp ATSIGN Exp 
    | Exp MINMIN Exp
    | ID INIPA Vle ENDPA %prec ID
    | ID 
    | CONSTANT 
    | CONST_INT
;



Lec :  Lec COMMA Exp 
    | Lec COMMA WORD 
    | Exp 
    | WORD
;

Vle : Le
    |
;

Le  : Le COMMA Exp 
    | Exp
;

%%

#include "lex.yy.c"
#include "error.y"

int main()
{
    yyparse();
}