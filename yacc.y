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
%token ITEFOR 
%token DO 
%token READ 
%token PRINT 
%token RETURN 
%token CONSTANT 
%token WORD
%token INISQR 
%token ENDSQR

%right ATSIGN 
%right PLUSPLUS
%left CONCATENATE
%left MINMIN
%left ORLOG
%left ANDLOG
%left EXOR
%left EQUALS
%left COMPAR
%left ADDITION
%left MULTI

%right UNARI
%right LISTOP2
%right LISTOP1 

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
    | LIST TYPEVAR Lv SEMICOLON
    | error
;

Lv  : Lv COMMA ID 
    | ID
    | error
;

Dss : Dss Ds 
    |
;

Ds  : Cs B
;

Cs  : Dc ID INIPA Pa ENDPA 
    | Dc ID INIPA ENDPA
    | error
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
    | FOR ID ASIGN Exp ITEFOR Exp DO Se
    | READ Lvread SEMICOLON 
    | PRINT Lec SEMICOLON 
    | RETURN Exp SEMICOLON 
    | Exp LISTOP1 
    | LISTOP2 Exp
    | ID INIPA Lec ENDPA SEMICOLON
;

Lvread  : WORD COMMA Lv
        |Lv

Exp : INIPA Exp ENDPA 
    | UNARI Exp 
    | ADDITION Exp %prec UNARI
    | Exp ADDITION Exp 
    | Exp ATSIGN Exp
    | Exp MINMIN Exp
    | Exp COMPAR Exp
    | Exp EQUALS Exp
    | Exp ORLOG Exp
    | Exp ANDLOG Exp
    | Exp EXOR Exp
    | Exp MULTI Exp
    | Exp CONCATENATE Exp    
    | Exp PLUSPLUS Exp ATSIGN Exp
    | ID INIPA Lec ENDPA
    | ID
    | CONSTANT
    | INISQR lc ENDSQR
    | error
;


lc  : lc COMMA CONSTANT
    | CONSTANT
;

Lec :  Lec COMMA Exp 
    | Lec COMMA WORD 
    | Exp 
    | WORD
    |
;


%%

#include "lex.yy.c"

void yyerror(const char *msg )
{
fprintf(stderr,"[Linea %d]: %s\n", yylineno, msg) ;
}