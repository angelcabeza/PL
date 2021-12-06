%{
    #include <string>
    #include <cstdlib.h>
    #include <y.tab.h>

%}

digit [0-9]
constint {digit}+
const_double {constint}.{constint}
leter \'[a-zA-Z]*'
word \"[^\"]*\"
id ([a-zA-Z]+{digit}*)+(_([a-zA-Z]*{digit}*)+)*

%option noyywrap
%option yylineno

%%
"main"                                                  yylval.lexema = "main"; return MAIN;
"begin_local_var" return INIVAR;
"end_local_var" return ENDVAR;
"{" return INIBLO;
"}" return ENDBLO;
"(" return INIPA;
")" return ENDPA;
"[" return INISQR;
"]" return ENDSQR;
{constint}                                              yyval.atrib = 0; yylval.tipo = entero; yylval.lexema = string(strdup(yytext)); return CONSTANT;
{const_double}                                          yyval.atrib = 1; yylval.tipo = real; yylval.lexema = string(strdup(yytext)); return CONSTANT;
"true"                                                  yyval.atrib = 2; yylval.tipo = booleano; yylval.lexema = string(strdup(yytext)); return CONSTANT;
"false" return CONSTANT;                                yyval.atrib = 2; yylval.tipo = booleano; yylval.lexema = string(strdup(yytext)); return CONSTANT;
{leter} return CONSTANT;                                yyval.atrib = 3; yylval.tipo = caracter; yylval.lexema = string(strdup(yytext)); return CONSTANT;
"list of" return LIST;
"int"                                                   yyval.atrib = 0; yylval.tipo = entero; return TYPEVAR;
"bool"                                                  yyval.atrib = 2; yylval.tipo = booleano; return TYPEVAR;
"double"                                                yyval.atrib = 1; yylval.tipo = real; return TYPEVAR;
"char"                                                  yyval.atrib = 3; yylval.tipo = caracter;return TYPEVAR;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"read" return READ;
"print" return PRINT;
"return" return RETURN;yyyyy
"for" return FOR;
"down to" return ITEFOR;
"to" return ITEFOR;
"do" return DO;
"=" return ASIGN;
";" return SEMICOLON;
"," return COMMA;
"||"                                                    yylval.atrib = 0; yylval.lexema = string(strdup(yytext)); return ORLOG;
"&&"                                                    yylval.atrib = 1; yylval.lexema = string(strdup(yytext));return ANDLOG;
"^"                                                     yylval.atrib = 2; yylval.lexema = string(strdup(yytext));return EXOR;
"!="                                                    yylval.atrib = 3; yylval.lexema = string(strdup(yytext));return EQUALS; 
"=="                                                    yylval.atrib = 4; yylval.lexema = string(strdup(yytext));return EQUALS; 
"<"                                                     yylval.atrib = 5; yylval.lexema = string(strdup(yytext));return COMPAR;
">"                                                     yylval.atrib = 6; yylval.lexema = string(strdup(yytext));return COMPAR;
"<="                                                    yylval.atrib = 7; yylval.lexema = string(strdup(yytext));return COMPAR;
">="                                                    yylval.atrib = 8; yylval.lexema = string(strdup(yytext));return COMPAR;
"+"                                                     yylval.atrib = 9; yylval.lexema = string(strdup(yytext));return ADDITION;
"-"                                                     yylval.atrib = 10; yylval.lexema = string(strdup(yytext));return ADDITION;
"**"                                                    yylval.atrib = 11; yylval.lexema = string(strdup(yytext));return CONCATENATE;
"*"                                                     yylval.atrib = 12; yylval.lexema = string(strdup(yytext));return MULTI;
"/"                                                     yylval.atrib = 13; yylval.lexema = string(strdup(yytext));return MULTI;
"%"                                                     yylval.atrib = 14; yylval.lexema = string(strdup(yytext));return MULTI;
"~"                                                     yylval.atrib = 0; yylval.lexema = string(strdup(yytext));return UNARI;
"!"                                                     yylval.atrib = 1; yylval.lexema = string(strdup(yytext));return UNARI;
"#"                                                     yylval.atrib = 2; yylval.lexema = string(strdup(yytext));return UNARI;
"?" r                                                   yylval.atrib = 3; yylval.lexema = string(strdup(yytext));eturn UNARI;
">>" return LISTOP1;
"<<" return LISTOP1;
"$" return LISTOP2;
"--" return MINMIN;
"++" return PLUSPLUS; 
"@" return ATSIGN; 
{word}                                                  yylval.lexma = string(strdup(yytext)); yylval.lexema = yylval.lexema.substr(1, yylval.lexema.size()-2); return WORD;
{id}                                                    yylval.lexema = string(strdup(yytext)); return ID;
[\n\r\t ] ECHO;
. printf("\n\n \tERROR LEXICO: la palabra %s en la linea %d \n\n\t",yytext,yylineno);

%%