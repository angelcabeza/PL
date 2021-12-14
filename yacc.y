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
    string codigoFunc = "";

    entradaTS TS_paramf[MAX_TS];

    dtipo tipoTmp;
    bool listaTmp;
    dtipo tipoSubprog;

    typedef struct {
        int atrib = 0;
        string lexema = "";
        bool lista = false;
        dtipo tipo = desconocido;
        bool constante = false;
    } atributos;

    atributos atribvacio;

    unsigned long TOPE_SUBPROG = 0;
    atributos TS_llamadas_subprog[MAX_TS];

    #define YYSTYPE atributos

    void TS_insertaID (atributos atrib);
    void TS_insertaMarca();
    void TS_vaciarEntradas();
    void TS_InsertaSubprog(atributos atributo);
    void TS_InsertaParam(atributos atributo);
    void TS_subprog_inserta(atributos atrib);

    void comprobarExisteReturn(bool hayreturn, dtipo tipo, bool eslista);
    bool esFuncion(string nombre);
    void comprobarEsVarOParamametroFormal(atributos atrib);
    void comprobarEsTipo(dtipo tipo, dtipo tipo2);
    void comprobarEsLista(atributos atrib);
    void comprobarAsignacionListas(atributos id, atributos exp);
    void comprobarDevuelveSubprog(atributos atrib);
    string tipoDatoToString(dtipo tipo);
    void comprobacionLista(bool lista1, bool lista2);

    dtipo comprobar_llamada_a_funcion(atributos atrib);

    entradaTS encontrarEntrada(string nombre, bool debe_estar);
    

    //Aparte
    dtipo comprobarEsEnteroReal (atributos atrib);
    bool comprobarAdicionUn (atributos atr1);
    bool comprobarAdicion (atributos atr1, atributos atr2);
    bool comprobarBinopListaInt (atributos atr1, atributos atr2);
    bool comprobarCompar (atributos atr1, atributos atr2);
    bool comprobarEquals (atributos atr1, atributos atr2);
    bool comprobarLogOp (atributos atr1, atributos atr2);
    bool comprobarMulti (atributos atr1, atributos atr2, int atr_multi);
    bool comprobarConcatLista (atributos atr1, atributos atr2);
    bool comprobarTernario (atributos atr1, atributos atr2, atributos atr3);

    void printErrorOperador (atributos atr1, atributos atr2, string operador);

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

B   : INIBLO {TS_insertaMarca();} Dvl Dss Ses ENDBLO {TS_vaciarEntradas();}
;

Dvl : INIVAR Vl ENDVAR 
    | 
;

Vl  : Vl Cdv 
    | Cdv
;

Cdv : tipo Lv SEMICOLON 
    | error
;

tipo : TYPEVAR { tipoTmp = atrATipo($1.atrib); listaTmp=false; }
    | LIST TYPEVAR { tipoTmp = atrATipo($2.atrib); listaTmp=true; }

Lv  : Lv COMMA ID { TS_insertaID($3); $$.lexema = $1.lexema + ", " + $3.lexema;}
    | ID { TS_insertaID($1); $$.lexema = $1.lexema; }
    | error
;

Dss : Dss Ds 
    |
;

Ds  : Cs {subprog += 1;} B {subprog -= 1;} ;
;

Cs  : Dc2 ID INIPA Pa ENDPA {TS_InsertaSubprog($2);}
    | Dc2 ID INIPA ENDPA {TS_InsertaSubprog(atribvacio);}
    | error
;

Dc  : LIST TYPEVAR { tipoTmp = atrATipo($2.atrib); listaTmp=true; }
    | TYPEVAR { tipoTmp = atrATipo($1.atrib); listaTmp=false; }
;

Dc2 : LIST TYPEVAR { tipoSubprog = atrATipo($2.atrib); listaTmp=true; }
    | TYPEVAR { tipoSubprog = atrATipo($1.atrib); listaTmp=false; }
;

Pa  : Pa COMMA Dc ID { TS_InsertaParam($4); };
    | Dc ID { TS_InsertaParam($2); };
;

Ses : Ses Se 
    | Se
;

Se  : B 
    //| ID ASIGN Exp SEMICOLON { comprobarEsTipo($1.tipo, $3.tipo); comprobarAsignacionListas($1, $3); $$.lexema = $1.lexema; }
    | ID ASIGN Exp SEMICOLON { entradaTS ent = encontrarEntrada($1.lexema, true); comprobarEsTipo(ent.tipoDato, $3.tipo);
                               comprobacionLista(ent.eslista, $3.lista); $$.lexema = $1.lexema; }
    | IF INIPA Exp ENDPA Se {comprobarEsTipo(booleano, $3.tipo);}
    | IF INIPA Exp ENDPA Se ELSE Se {comprobarEsTipo(booleano, $3.tipo);}
    | WHILE INIPA Exp ENDPA Se {comprobarEsTipo(booleano, $3.tipo);}
    | FOR ID ASIGN Exp ITEFOR Exp DO Se { entradaTS ent = encontrarEntrada($1.lexema, true); comprobarEsTipo(entero,ent.tipoDato);
                                          comprobarEsTipo(entero, $4.tipo); comprobarEsTipo(entero,$6.tipo);}
    | READ Lvread SEMICOLON 
    | PRINT Lec SEMICOLON 
    | RETURN Exp SEMICOLON {comprobarDevuelveSubprog($2);}
    | Exp LISTOP1 { comprobarEsLista($1);}
    | LISTOP2 Exp { comprobarEsLista($2);}
;

Lvread  : WORD COMMA Lv2
        | Lv2
;

//Este Lv2 es util, porque es para una lista de variables que estan siendo llamadas
//No se si es la mejor forma de hacerlo, pero la anterior daba errores
Lv2  : Lv2 COMMA ID {$$.lexema = $1.lexema + ", " + $3.lexema;}
    | ID {$$.lexema = $1.lexema; }
    | error
;

Exp : INIPA Exp ENDPA {$$.tipo = $2.tipo; $$.lista = $2.lista; $$.lexema = "( " + $2.lexema + " )";}
    | UNARI Exp 
    | ADDITION Exp %prec UNARI { $$.lista=comprobarAdicionUn($2); $$.tipo=$2.tipo; }
    | Exp ADDITION Exp { $$.lista=comprobarAdicion($1,$3); $$.tipo=$1.tipo; }
    | Exp ATSIGN Exp { $$.lista=comprobarBinopListaInt($1,$3); $$.tipo=$1.tipo; }
    | Exp MINMIN Exp { $$.lista=comprobarBinopListaInt($1,$3); $$.tipo=$1.tipo; }
    | Exp COMPAR Exp { $$.lista=comprobarCompar($1,$3); $$.tipo=booleano; }
    | Exp EQUALS Exp { $$.lista=comprobarEquals($1,$3); $$.tipo=booleano; }
    | Exp ORLOG Exp { $$.lista=comprobarLogOp($1,$3); $$.tipo=booleano; }
    | Exp ANDLOG Exp { $$.lista=comprobarLogOp($1,$3); $$.tipo=booleano; }
    | Exp EXOR Exp { $$.lista=comprobarLogOp($1,$3); $$.tipo=booleano; }
    | Exp MULTI Exp { $$.lista=comprobarMulti($1,$3,$2.atrib); $$.tipo=$1.tipo; }
    | Exp CONCATENATE Exp { $$.lista=comprobarConcatLista($1,$3); $$.tipo=$1.tipo; }
    | Exp PLUSPLUS CONSTANT ATSIGN Exp { $$.lista=comprobarTernario($1,$3,$5); $$.tipo=$1.tipo; }
    | ID INIPA Lec ENDPA { $$.tipo =  comprobar_llamada_a_funcion($1); $$.lexema = $1.lexema + "( " + $3.lexema + " )"; }
    | ID {entradaTS ent = encontrarEntrada($1.lexema, true); $$.tipo = ent.tipoDato; $$.lista = ent.eslista; $$.lexema = $1.lexema; }
    | CONSTANT { tipoTmp = $1.tipo; $$.tipo = $1.tipo; $$.lista = false; $$.lexema = $1.lexema; } //El error tiene que andar por aquí
    | INISQR lc ENDSQR {tipoTmp = $2.tipo; $$.tipo = $2.tipo; $$.lista = true; }
    | error
;

lc  : lc COMMA CONSTANT {comprobarEsTipo($3.tipo, $1.tipo); $$.tipo = $1.tipo; }
    | CONSTANT {$$.tipo = $1.tipo;}
;

Lec :  Lec COMMA Exp { TS_subprog_inserta($3); $$.lexema = $1.lexema + ", " + $3.lexema;}
    | Lec COMMA WORD { TS_subprog_inserta($3); $$.lexema = $1.lexema + ", " + $3.lexema;}
    | Exp  { TS_subprog_inserta($1); $$.lexema = $1.lexema; }
    | WORD { TS_subprog_inserta($1); $$.lexema = $1.lexema;}
    |
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

    //printf("\nDeclarando %s: tipo %s\n", atributo.lexema.c_str(), tipoDatoToString(tipoTmp).c_str() );

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

        num_params--;
        incrementarTOPE();
    }
}

void TS_InsertaParam(atributos atributo){

    bool encontrado = false;

    int n_params = TOPE_PARAMF - 1;

    // buscamos si ya existe un parametro con ese nombre
    while ( n_params > 0 && !encontrado ) {

        encontrado = atributo.lexema == TS_paramf[n_params].nombre;

        n_params--;
    }


    // si no existe lo añadimos
    if ( !encontrado ) {


        entradaTS nueva_entrada;

        nueva_entrada.entrada = parametro_formal;

        nueva_entrada.nombre = atributo.lexema;

        nueva_entrada.parametros = 0;

        nueva_entrada.tipoDato = tipoTmp;

        TS_paramf[TOPE_PARAMF] = nueva_entrada;

        TOPE_PARAMF++;

        //printf("Tipo: '%s'",tipoDatoToString(nueva_entrada.tipoDato).c_str());

    } else {
        // si existe damos error
        printf("Error semantico en la linea %d: El parámetro %s ya existe\n", yylineno, atributo.lexema.c_str());
    }

}


void comprobacionLista(bool lista1, bool lista2){
    if (lista1 != lista2){
        printf("Error semantico en la linea %d: Elemento no lista y elemento lista\n", yylineno);
    }
}

void TS_subprog_inserta(atributos atrib) {

    if ( TOPE_SUBPROG == MAX_TS ) {
        printf("ERROR: Tope de la pila alcanzado. Demasiadas entradas en la tabla de símbolos. Abortando compilación");
    } else {
        TS_llamadas_subprog[TOPE_SUBPROG] = atrib;

        TOPE_SUBPROG++;

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
        printf("\nSemantico: linea %d. Identificador '%s' no declarado\n",yylineno, nombre.c_str());
    }

    return entrada;
}

dtipo atrATipo(int atributo){
    dtipo tipo = desconocido;
    if (atributo == 0){
        tipo = entero;
    }
    else if (atributo == 1){
        tipo = real;
    }
    else if (atributo == 2){
        tipo = booleano;
    }
    else if (atributo == 3){
        tipo = caracter;
    }

    return tipo;
}

// comprobamos si un lexema es de una función o no
bool esFuncion(string nombre){
    bool es_funcion = false;
    bool encontrado = false;

    int pos = TOPE - 1;

    while ( pos > 0 && !encontrado ) {
        if ( nombre == TS[pos].nombre ) {
            encontrado = true;
            es_funcion = TS[pos].entrada == funcion;
        }

        pos --;
    }

    return es_funcion;

}

// comprobamos si es una variable o parametro formal, si no lo es damos un error
void comprobarEsVarOParamametroFormal(atributos atrib) {

    // simplemente buscamos en la pila
    dtipo t = encontrarEntrada(atrib.lexema, true).tipoDato;

    // y si es desconocido, no asignado, o una funcion, damos el error
    if ( t == desconocido || esFuncion(atrib.lexema) ){
        printf("Error semantico en la linea %d: Esperado variables, parametro formal o constante.\n", yylineno);
        
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

                
                if ( !TS_llamadas_subprog[num_parametros].constante ){
                    // buscamos el parametro en la tabla de simbolos
                    // diciendo que es necesario que lo encuentre
                    parametro_en_TS = encontrarEntrada(TS_llamadas_subprog[num_parametros].lexema, true);
                }

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

void comprobarEsTipo(dtipo tipo, dtipo tipo2){
    if (tipo != tipo2) {

        printf("Error semantico en la linea %d: Esperado tipo %s, encontrado tipo %s\n", yylineno, tipo_to_string(tipo).c_str(), tipo_to_string(tipo2).c_str());
    }
}

void comprobarEsLista(atributos atrib) {


    entradaTS entrada = encontrarEntrada(atrib.lexema, true);

    if ( !entrada.eslista ) {
        printf("Error semantico en la linea %d: Operación solo aplicable a una lista.\n", yylineno);

    }

}

void comprobarAsignacionListas(atributos id, atributos exp){
    entradaTS entrada_id = encontrarEntrada(id.lexema, true);

    if ( entrada_id.eslista && !exp.lista ){
        printf("Error semantico en la linea %d: Asignando tipo basico a una lista\n", yylineno);

    } else if ( !entrada_id.eslista && exp.lista ){
        printf("Error semantico en la linea %d: Asignando lista a un tipo basico\n", yylineno);

    }

}

void comprobarDevuelveSubprog(atributos atrib) {

    entradaTS funcion_actual;

    int entrada = TOPE - 1;

    bool parar = TS[entrada].entrada == marca && (TS[entrada - 1].entrada == parametro_formal || TS[entrada - 1].entrada == funcion);

    // nos vamos hasta la ultima marca
    while ( entrada > 0 && !parar )  {
        entrada--;
        parar = TS[entrada].entrada == marca && (TS[entrada - 1].entrada == parametro_formal || TS[entrada - 1].entrada == funcion);
    }

    // nos vamos a la funcion de justo antes la marca
    while ( entrada > 0 && TS[entrada].entrada != funcion) {
        entrada--;
    }



    if ( entrada != 0 ){
        comprobarEsTipo(TS[entrada].tipoDato, atrib.tipo);
    }

}


dtipo comprobarEsEnteroReal (atributos atrib){
    if ( atrib.tipo != entero && atrib.tipo != real){
        string t = tipo_to_string(atrib.tipo);
        printf("Error semantico en la linea %d: Operador solo aplicable a enteros o reales, encontrado tipo %s\n", yylineno, t.c_str());
    }
    return atrib.tipo;
}


bool comprobarAdicionUn (atributos atr1){
    if ( (atr1.tipo != entero && atr1.tipo != real) ||
         (atr1.lista == true) ) {
        string tipo_atr1 = tipoDatoToString(atr1.tipo);
        if (atr1.lista){
            tipo_atr1 = "Lista " + tipo_atr1;
        }

        printf("Error semantico en la linea %d: Operador adicion unaria error %s\n", yylineno, tipo_atr1.c_str());
    }

    return false;
}


bool comprobarAdicion (atributos atr1, atributos atr2){
    bool lista_retorno = atr1.lista != atr2.lista;

    if ( (atr1.tipo != atr2.tipo) || (atr1.tipo != entero && atr1.tipo != real) ||
         (atr1.lista == atr2.lista && atr1.lista == true) ) {
        printErrorOperador(atr1, atr2, "Adicion binaria");
    }

    return lista_retorno;
}

bool comprobarBinopListaInt (atributos atr1, atributos atr2){
    if ( (atr2.tipo != entero) || (atr1.lista == false) ||
         (atr2.lista == true) ) {

        printErrorOperador(atr1, atr2, "binario lista con entero");
    }

    return false;
}


bool comprobarCompar (atributos atr1, atributos atr2){
    if ( (atr1.tipo != atr2.tipo) || (atr1.tipo != entero && atr1.tipo != real) ||
         (atr1.lista == true) || (atr2.lista == true) ) {

        printErrorOperador(atr1, atr2, "de comparacion");
    }

    return false;
}


bool comprobarEquals (atributos atr1, atributos atr2){
    if ( (atr1.tipo != atr2.tipo) || (atr1.lista == true) ||
         (atr2.lista == true) ) {

        printErrorOperador(atr1, atr2, "Igual");
    }

    return false;
}


bool comprobarLogOp (atributos atr1, atributos atr2){
    if ( (atr1.tipo != atr2.tipo) || (atr1.tipo != booleano) || 
         (atr1.lista == true) || (atr2.lista == true) ) {

        printErrorOperador(atr1, atr2, "logico");
    }

    return false;
}


bool comprobarMulti (atributos atr1, atributos atr2, int atr_multi){
    // atr_multi: 12 *    13 /    14 %
    bool lista_retorno = false;

    if (atr_multi == 12){
        if ( (atr1.tipo != atr2.tipo) || (atr1.tipo != entero && atr1.tipo != real) ||
             (atr1.lista == true && atr2.lista == true) ){
                printErrorOperador(atr1, atr2, "Multiplicacion");
        }
        lista_retorno = atr1.lista != atr2.lista;
    }
    else if (atr_multi == 13){
        if ( (atr1.tipo != atr2.tipo) || (atr1.tipo != entero && atr1.tipo != real) ||
             (atr2.lista == true) ){
                printErrorOperador(atr1, atr2, "Division");
        }
        lista_retorno = atr1.lista != atr2.lista;
    }
    else if (atr_multi == 14){
        if ( (atr1.tipo != atr2.tipo) || (atr1.tipo != entero && atr1.tipo != real) ||
             (atr1.lista == true) || (atr2.lista == true) ){
                printErrorOperador(atr1, atr2, "Modulo");
        }
    }

    return lista_retorno;
}


bool comprobarConcatLista (atributos atr1, atributos atr2){
    if ( (atr1.tipo != atr2.tipo) ||
         (atr1.lista == false) || (atr2.lista == false) ){
            printErrorOperador(atr1, atr2, "Concatenacion de lista");
    }

    return true;
}


bool comprobarTernario (atributos atr1, atributos atr2, atributos atr3){
    if ( (atr1.tipo != atr2.tipo) ||
         (atr1.lista == false) || (atr2.lista == true) || (atr3.lista == true) ||
         (atr3.tipo != entero) ){

        string tipo_atr1 = tipoDatoToString(atr1.tipo);
        string tipo_atr2 = tipoDatoToString(atr2.tipo);
        string tipo_atr3 = tipoDatoToString(atr3.tipo);
        if (atr1.lista){
            tipo_atr1 = "Lista " + tipo_atr1;
        }
        if (atr2.lista){
            tipo_atr2 = "Lista " + tipo_atr2;
        }
        if (atr3.lista){
            tipo_atr3 = "Lista " + tipo_atr3;
        }

        printf("Error semantico en la linea %d: Operador ternario error -> %s %s y %s\n", yylineno, tipo_atr1.c_str(), tipo_atr2.c_str(), tipo_atr3.c_str());
    }

    return true;
}


void printErrorOperador(atributos atr1, atributos atr2, string operador){
    string tipo_atr1 = tipoDatoToString(atr1.tipo);
    string tipo_atr2 = tipoDatoToString(atr2.tipo);
    if (atr1.lista){
        tipo_atr1 = "Lista " + tipo_atr1;
    }
    if (atr2.lista){
        tipo_atr2 = "Lista " + tipo_atr2;
    }

    printf("Error semantico en la linea %d: Operador %s error: %s y %s\n", yylineno, operador.c_str(), tipo_atr1.c_str(), tipo_atr2.c_str());
}


string tipoDatoToString(dtipo tipo){
    string datoString = "desconocido";

    if (entero == tipo){
        datoString = "entero";
    } else if (real == tipo){
        datoString = "real";
    } else if (caracter == tipo){
        datoString = "caracter";
    } else if (vacio == tipo){
        datoString = "vacio";
    } else if (booleano == tipo){
        datoString = "booleano";
    }

    return datoString;
}