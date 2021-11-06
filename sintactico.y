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
%token ID 
%token INIPA 
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
%token LISTOP2 
%token ATSIGN 
%token CONSTANT 
%token WORD

%left ORLOG
%left ANDLOG
%left EXOR
%left EQUALS
%left COMPAR 
%left ADDITION
%left MULTI
%right UNARI
%right MINMIN
%right PLUSPLUS
%left INISQR ENDSQR

%start S

%%
S   : MAIN B
;

B   : INIBLO Dvl Dss Ses ENDBLO
;

Dvl : INIVAR Vl ENDVAR 
    | /* empty */
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
    | /* empty */
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
    | IF Exp Ses 
    | IF Exp Ses ELSE Ses 
    | WHILE Exp Ses 
    | FOR ID ASIGN CONST_INT ITEFOR CONST_INT DO Ses 
    | READ Lv SEMICOLON 
    | PRINT Lec SEMICOLON 
    | RETURN Exp SEMICOLON 
    | Exp LISTOP1 
    | LISTOP2 Exp
;

Exp : INIPA Exp ENDPA 
    | UNARI Exp 
    | PLUSPLUS Exp 
    | MINMIN Exp 
    | Exp Binop Exp 
    | Exp ATSIGN Exp 
    | ID PLUSPLUS ID ATSIGN ID 
    | ID MINMIN ID ATSIGN ID 
    | ID 
    | CONSTANT 
    | ID INIPA Le ENDPA 
    | ID INIPA ENDPA
;

Lec :  Lec COMMA Exp 
    | Lec COMMA WORD 
    | Exp 
    | WORD
;

Le  : Le COMMA Exp 
    | Exp
;

Binop   : ORLOG 
        | ANDLOG 
        | EXOR 
        | EQUALS 
        | COMPAR 
        | MULTI
;

%%

#include "lex.yy.c"
#include "error.y"

int main()
{
    yyparse();
}