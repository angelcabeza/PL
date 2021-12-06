%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    void yyerror(const char * msg);

    int yylex();

    #include "estructura_datos.h"
    #define MAX_TS 500

    unsigned long int TOPE = 0;
    entradaTS TS [MAX_TS];
    dtipo tipoTmp;
    typedef struct {
        int atrib = 0;
        string lexema = "";
        bool lista = false;
        dtipo tipo = desconocido;
        string codigo = "";
    } atributos;

    #define YYSTYPE atributos

    int num_linea = 1;
    void TS_insertaID (atributos atrib);
    void comprobarExisteReturn(bool hayreturn, dtipo tipo, bool eslista);

    string tipo_to_string(dtipo tipo);
%}

%define parse.error verbose

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
%left CONCATENATE

%left ORLOG
%left ANDLOG
%left EXOR
%left EQUALS
%left COMPAR

%left ADDITION
%left MULTI
%right PLUSPLUS 
%left MINMIN
%right UNARI
%right LISTOP2
%right LISTOP1 
%right ATSIGN 

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
;

Lv  : Lv COMMA ID { TS_insertaID($3); $$.lexema = $1.lexema + ", " + $3.lexema;}
    | ID { TS_insertaID($1); $$.lexema = $1.lexema; }
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
    | ID INIPA Vle ENDPA
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


string tipo_to_string(dtipo tipo){
    string res = "desconocido";

	if ( tipo == real ) {
		res = "real";
	} else if (tipo == entero) {
		res = "entero";
	} else if ( tipo == booleano ) {
		res = "booleano";
	} else if ( tipo == caracter ) {
		res = "caracter";
	}

	return res;
}

void TS_insertaID(atributos atributo){
    printf("ID: %s\n\n", atributo.lexema.c_str());

    entradaTS nueva_entrada;
    nueva_entrada.entrada = variable;
    nueva_entrada.nombre = atributo.lexema;
    nueva_entrada.tipoDato = tipoTmp;

    int pos_id_buscado = TOPE -1;
    bool encontrado = false;

    while (pos_id_buscado >= 0 && TS[pos_id_buscado].entrada != marca && !encontrado) {
        if ( atributo.lexema == TS[pos_id_buscado].nombre ){
            encontrado = true;
        } else {
            pos_id_buscado--;
        }
    }

    if (!encontrado){
        TS[TOPE] = nueva_entrada;
    } else{
        printf("Semantico linea %d: Redeclaración de '%s'\n", num_linea, atributo.lexema.c_str());
    }
}
void comprobarExisteReturn(bool hayreturn, dtipo tipo, bool eslista){
    if (hayreturn && (tipo != entero || eslista))
        printf("Semantico: return recibe argumento tipo %s, se esperaba tipo entero", tipo_to_string(tipo));
}