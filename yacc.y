%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    void yyerror(const char * msg);

    int yylex();

    #include "estructura_datos.h"
    #define MAX_TS 500

    unsigned long int TOPE = 0;
    unsigned long int TOPE_PARAMF = 0;
    int subprog = 0;
    entradaTS TS [MAX_TS];

    entradaTS TS_paramf[MAX_TS];

    dtipo tipoTmp;
    bool listaTmp;
    dtipo tipoSubprog;

    typedef struct {
        int atrib = 0;
        string lexema = "";
        bool lista = false;
        dtipo tipo = desconocido;
        string codigo = "";
    } atributos;

    atributos atribvacio;

    unsigned long TOPE_SUBPROG = 0;
    atributos TS_llamadas_subprog[MAX_TS];

    #define YYSTYPE atributos

    void TS_insertaID (atributos atrib);
    void comprobarExisteReturn(bool hayreturn, dtipo tipo, bool eslista);
    void TS_insertaMarca();
    void TS_vaciarEntradas();
    void TS_InsertaSubprog(atributos atributo);
    entradaTS encontrarEntrada(string nombre, bool debe_estar);
    dtipo comprobar_llamada_a_funcion(atributos atrib);

    string tipo_to_string(dtipo tipo);
    int incrementarTOPE();
    dtipo atrATipo(int atributo);
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

B   : INIBLO {TS_insertaMarca();} Dvl Dss Ses ENDBLO {TS_vaciarEntradas();}
;

Dvl : INIVAR Vl ENDVAR 
    | 
;

Vl  : Vl Cdv 
    | Cdv
;

Cdv : TYPEVAR Lv SEMICOLON { tipoTmp = atrATipo($1.atrib); listaTmp=false; }
    | LIST TYPEVAR Lv SEMICOLON { tipoTmp = atrATipo($2.atrib); listaTmp=true; }
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

Cs  : Dc ID INIPA Pa ENDPA {TS_InsertaSubprog($2);}
    | Dc ID INIPA ENDPA {TS_InsertaSubprog(atribvacio);}
    | error
;

Dc  : LIST TYPEVAR { tipoSubprog = atrATipo($2.atrib); listaTmp=true; }
    | TYPEVAR { tipoSubprog = atrATipo($1.atrib); listaTmp=false; }
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
    | ID INIPA Vle ENDPA { $$.tipo =  comprobar_llamada_a_funcion($1); $$.lexema = $1.lexema + "( " + $3.lexema + " )"; $$.codigo = ""; } ;
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
    entradaTS nueva_entrada;
    nueva_entrada.entrada = variable;
    nueva_entrada.nombre = atributo.lexema;
    nueva_entrada.tipoDato = tipoTmp;
    nueva_entrada.eslista = listaTmp;

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
        incrementarTOPE();
    } else{
        printf("Semantico linea %d: Redeclaración de '%s'\n", yylineno, atributo.lexema.c_str());
    }
}

int incrementarTOPE(){

    int salida = 1;

    if (TOPE == MAX_TS) {
        printf("ERROR: Tope de la pila alcanzado.");

        salida=0;
    } else {
        TOPE++;
    }

    return salida;
}

void comprobarExisteReturn(bool hayreturn, dtipo tipo, bool eslista){
    if (hayreturn && (tipo != entero || eslista))
        printf("Semantico: return recibe argumento tipo %s, se esperaba tipo entero", tipo_to_string(tipo));
}

void TS_insertaMarca() {
    entradaTS nueva_entrada;

    nueva_entrada.entrada = marca;

    nueva_entrada.nombre = "";
    TS[TOPE] = nueva_entrada;

    incrementarTOPE();

    if ( subprog != 0){

        while (TOPE_PARAMF > 0) {
            entradaTS entrada_tmp = TS_paramf[TOPE_PARAMF -1];
            entrada_tmp.entrada = variable;
            TS[TOPE] = entrada_tmp;

            TOPE_PARAMF--;
            incrementarTOPE();
        }
    }
}

void TS_vaciarEntradas(){
    while ( TS[TOPE -1 ].entrada != marca && TOPE > 0){
        TOPE--;
    }

    TS[TOPE - 1].entrada = fin_bloque;
}

void TS_InsertaSubprog(atributos atributo){
    entradaTS entrada = encontrarEntrada(atributo.lexema, false);
    dtipo tipo_buscar = entrada.tipoDato;

    if ( tipo_buscar == desconocido){
        entradaTS nueva_entrada;

        nueva_entrada.entrada = funcion;
        nueva_entrada.nombre = atributo.lexema;
        nueva_entrada.parametros = 0;
        nueva_entrada.tipoDato = tipoSubprog;
        nueva_entrada.eslista = listaTmp;
        TS[TOPE] = nueva_entrada;
        incrementarTOPE();
    } else {
        printf("\nSemantico: Linea %d. Redifinicion de '%s'",yylineno,atributo.lexema.c_str());
    }

    int num_params = TOPE_PARAMF;
    TS[TOPE -1].parametros = num_params;
    while (num_params > 0){
        TS[TOPE] = TS_paramf[num_params -1];

        num_params;
        incrementarTOPE();
    }
}

entradaTS encontrarEntrada(string nombre, bool debe_estar){
    int pos_actual = TOPE -1;
    entradaTS entrada;

    entrada.tipoDato = desconocido;

    while ((TS[pos_actual].nombre != nombre || TS[pos_actual].entrada == parametro_formal) && pos_actual >= 0) {
        pos_actual--;
    }

    if ( pos_actual != -1) {
        entrada = TS[pos_actual];
    } else if (debe_estar) {
        printf("\nSemantico: linea %d. Identificador '%s' no declarado",yylineno, nombre.c_str());
    }

    return entrada;
}

dtipo atrATipo(int atributo){
    if (atributo == 0){
        return entero;
    }
    else if (atributo == 1){
        return real;
    }
    else if (atributo == 2){
        return booleano;
    }
    else if (atributo == 3){
        return caracter;
    }
}

dtipo comprobar_llamada_a_funcion(atributos atrib) {

    dtipo tipo_funcion = desconocido;
    entradaTS entrada_funcion = encontrarEntrada(atrib.lexema, true);
    dtipo existe = entrada_funcion.tipoDato;

    // si existe la entrada, y no es una funcion, sacamos un error de llamada
    if ( existe != desconocido && entrada_funcion.entrada != funcion ){
        printf("Error semantico en la linea %d: %s no es una funcion\n", yylineno, entrada_funcion.nombre.c_str());
        

    } else if ( existe != desconocido ) {

        // buscamos la posicion donde comienzan los parametros formales
        int pos_entrada = TOPE - 1;
        while ( entrada_funcion.nombre != TS[pos_entrada].nombre || TS[pos_entrada].entrada != funcion ) {
            pos_entrada--;
        }

        int pos_funcion = pos_entrada;

        // Le damos la vuelta a la pila
        pos_entrada += TS[pos_funcion].parametros;

        // si el numero de parámetros de la definicion no coincide con el numero
        // de parametros dados en la llamada
        if (TS[pos_funcion].parametros != TOPE_SUBPROG){
            printf("Error semantico en la linea %d: La funcion %s necesita %d parámetros y se han proporcionado %d\n", yylineno, entrada_funcion.nombre.c_str(), entrada_funcion.parametros, TOPE_SUBPROG);
            
        } else {

            // pasamos al primer parámetro
            int num_parametros = 0;

            // para todos los parametros dados
            while ( num_parametros < TOPE_SUBPROG ) {

                entradaTS parametro_en_TS;

                parametro_en_TS.tipoDato = TS_llamadas_subprog[num_parametros].tipo;

                // Aqui he quitado el es_constante que se declara a falso y nunca jamas se vuelve a tocar
                // if ( !TS_llamadas_subprog[num_parametros].es_constante ){
                    // buscamos el parametro en la tabla de simbolos
                    // diciendo que es necesario que lo encuentre
                    parametro_en_TS = encontrarEntrada(TS_llamadas_subprog[num_parametros].lexema, true);
                // }

                // si el tipo encontrado no es del tipo esperado, sacamos el error
                // por pantalla
                if ( TS[pos_entrada].tipoDato != parametro_en_TS.tipoDato ){

                    string tipo_esperado = tipo_to_string(TS[pos_entrada].tipoDato);
                    string tipo_encontrado = tipo_to_string(parametro_en_TS.tipoDato);

                    printf("Error semantico en la linea %d: El parámetro %d es de tipo %s pero se espera un tipo %s en la llamada a %s\n", yylineno , num_parametros + 1, tipo_encontrado.c_str(), tipo_esperado.c_str(), entrada_funcion.nombre.c_str());
                    
                }

                // seguimos al siguiente parametro
                num_parametros++;
                pos_entrada--;
            }

            tipo_funcion = entrada_funcion.tipoDato;

        }

    }

    // una vez comprobados todos, vaciamos la pila de parametros
    TOPE_SUBPROG = 0;

    return tipo_funcion;

}