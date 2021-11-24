%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    void yyerror(const char * msg);

    int yylex();

%}

%error-verbose

%token UNARI
%token ADDITION
%token LISTOP2 MINMIN
%token PLUSPLUS
%token BINOP
%token ATSIGN 
%token MAIN 
%token INIBLO 
%token ENDBLO 
%token INIVAR 
%token ENDVAR 
%token TYPEVAR 
%token SEMICOLON 
%token COMMA  
%nonassoc ID 
%nonassoc INIPA 
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
%token CONSTANT 
%token CONSTANT_INT
%token WORD
%token INISQR 
%token ENDSQR

%left ORLOG
%left ANDLOG
%left EXOR
%left EQUALS
%left COMPAR

%left BINOP
%right PLUSPLUS
%right UNARI
%left ADDITION
%left MULTI

%right LISTOP2 MINMIN

%left ATSIGN 
%left INISQR 
%left ENDSQR

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
    | Exp Bin_op Exp %prec BINOP
    | Exp BINOP Exp
    | ID PLUSPLUS CONST_INT ATSIGN CONST_INT
    | ID INIPA Vle ENDPA
    | ID
    | Const
    | INISQR lc ENDSQR
;

Bin_op  : ADDITION
        | ATSIGN
        | MINMIN
        | COMPAR
        | EQUALS
        | ORLOG
        | ANDLOG
        | EXOR
        | MULTI
;

Const   : CONSTANT
        | CONST_INT

Con : CONSTANT 
    | CONSTANT_INT
;

lc  : lc COMMA Con 
    | Con
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

void yyerror(const char *msg )
{
fprintf(stderr,"[Linea %d]: %s\n", yylineno, msg) ;
}