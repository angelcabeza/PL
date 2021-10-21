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
    #define INISQR 264
    #define ENDSQR 265
    #define CONSTINT 266
    #define CONSTANT 267
    #define WORD 268
    #define LIST 269
    #define TYPEVAR 270
    #define IF 271
    #define ELSE 272
    #define WHILE 273
    #define READ 274
    #define PRINT 275
    #define RETURN 276
    #define FOR 277
    #define ITEFOR 278
    #define DO 279
    #define ASIGN 280
    #define SEMICOLON 281
    #define COMMA 282
    #define SIGN 283
    #define BINOP 284
    #define UNOP 284
    #define LISTOP1 285
    #define LISTOP2 286
    #define DOUBMIN 287
    #define ID 288
%}

%option yylineno
%option noyywrap

digit [0-9]
constint {digit}+
const_double {constint}.{constint}
leter '[a-zA-Z]'
word \"[^\"]*\"
id ([a-zA-Z]+{digit}*)+(_([a-zA-Z]*{digit}*)+)*

%%
"main" return MAIN;
"begin_local_var" return INIVAR;
"end_local_var" return ENDVAR;
"{" return INIBLO;
"}" return ENDBLO;
"(" return INIPA;
")" return ENDPA;
"[" return INISQR;
"]" return ENDSQR;
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
{word} return WORD;
{id} return ID;
[\n\r\t ] ECHO;
{leter} return CONSTANT;
. printf("\n\n \tERROR LEXICO: la palabra %s en la linea %d \n\n\t",yytext,yylineno);



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