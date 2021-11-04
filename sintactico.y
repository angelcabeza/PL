%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    void yyerror(char * msg);

    int linea_actual = 1
%}

%error-verbose

%token MAIN INIBLO ENDBLO INIVAR ENDVAR TYPEVAR SEMICOLON COMMA LIST VACIO ID INIPA ENDPA ASIGN IF ELSE WHILE FOR ITEFOR CONST_INT DO READ PRINT RETURN LISTOP1 LISTOP2 WORD BINOP UNOP PLUSPLUS CONSTANT
%start S

%%
S   : MAIN B
;
B   : INIBLO Dvl Dss Ses ENDBLO
;
Dvl : INIVAR Vl ENDVAR 
    | VACIO
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
    | VACIO
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
    | UNOP Exp 
    | PLUSPLUS Exp 
    | Exp BINOP Exp 
    | Exp ASIGN Exp 
    | ID PLUSPLUS ID ASIGN ID 
    | ID 
    | CONSTANT 
    | ID INIPA Le ENDPA 
    | ID INIPA ENDPA
;
Lec : Lec COMMA Exp 
    | Lec COMMA WORD 
    | Exp 
    | WORD
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