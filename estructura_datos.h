#ifndef ESTRUCTURAS_DATOS
#define ESTRUCTURAS_DATOS
#include <string>

using namespace std;


typedef enum {
    marca,
    funcion,
    variable,
    parametro_formal,
    fin_bloque
} tipoEntrada;

typedef enum {
	entero,
	real,
	caracter,
	booleano,
	vacio,
    desconocido
} dtipo;

typedef struct {
    tipoEntrada entrada;
    string nombre = "";
    dtipo tipoDato = desconocido;
    int parametros = 0;
    bool eslista = false;
} entradaTS;

#endif