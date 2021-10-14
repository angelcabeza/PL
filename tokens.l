%{
    #include <stdio.h>
    #include <stdlib.h>
    #define MAIN 257
    #define INIVAR 258
    #define ENDVAR 259
    #define INIBLO 260
    #define ENDBLO 261
    #define INIPA 262
    #define ENDPA 263
    #define CONSTINT 264
    #define CONSTANT 265
    #define WORD 266
    #define LIST 267
    #define TYPEVAR 268
    #define IF 269
    #define ELSE 270
    #define WHILE 271
    #define READ 272
    #define PRINT 273
    #define RETURN 274
    #define FOR 275
    #define ITEFOR 276
    #define DO 277
    #define ASIGN 278
    #define SEMICOLON 279
    #define COMMA 280
    #define SIGN 281
    #define BINOP 282
    #define UNOP 283
    #define LISTOP1 284
    #define LISTOP2 285
    #define DOUBMIN 286
    #define ID 287
%}

%option yylineno
%option noyywrap

digit [0-9]
constint {digit}+
const_double {digit}.{digit}
leter [a-zA-Z]
word {leter}+

%%
"main" return MAIN;
"begin_local_var" return INIVAR;
"end_local_var" return ENDVAR;
"{" return INIBLO;
"}" return ENDBLO;
"(" return INIPA;
")" return ENDPA;
{constint} return CONSTINT;
{const_double} return CONSTANT;
"true" return CONSTANT;
"false" return CONSTANT;
"list of" return LIST;
"int" return TYPEVAR;
"bool" return TYPEVAR;
"double" return TYPEVAR;
"char" return TYPEVAR;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"read" return READ;
"print" return PRINT;
"return" return RETURN;
"for" return FOR;
"down to" return ITEFOR;
"to" return ITEFOR;
"do" return DO;
"=" return ASIGN;
";" return SEMICOLON;
"," return COMMA;
"+" return SIGN;
"-" return SIGN;
"*" return BINOP; 
"/" return BINOP; 
"==" return BINOP; 
"!=" return BINOP; 
"<=" return BINOP; 
">=" return BINOP; 
"<" return BINOP; 
">" return BINOP; 
"&&" return BINOP; 
"||" return BINOP; 
"@" return BINOP; 
"%" return BINOP; 
"**" return BINOP; 
"^" return BINOP; 
"&" return UNOP; 
"~" return UNOP; 
"!" return UNOP; 
"++" return UNOP; 
"#" return UNOP; 
"?" return UNOP; 
">>" return LISTOP1;
"<<" return LISTOP1;
"$" return LISTOP2;
"--" return DOUBMIN;
[\n\r\t ] ECHO;
{leter} return CONSTANT;
{word} return WORD;
. {
    printf("La palabra %s en la linea %d no es un identificador válido",yytext,yylineno);
}


%%

/************************************************************/
int main( int argc, char *argv[] )
{
    if(argc <= 1){
        
        printf("Error: Faltan argumentos\n");
        printf("Uso: %s <fichero>\n",argv[0]);

        return -1;
    }
    
    yyin = fopen(argv[1],"r");
    
    if (yyin == NULL){
        printf("Error: Archivo no encontrado\n");
        return -2;
    }
    
    int token=0;
    while ((token = yylex()) != 0){
        printf("__%d__",token);
    }

    return 1;
    
}