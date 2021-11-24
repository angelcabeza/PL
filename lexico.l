%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <y.tab.h>

%}

digit [0-9]
constint {digit}+
const_double {constint}.{constint}
leter '[a-zA-Z]'
word \"[^\"]*\"
id ([a-zA-Z]+{digit}*)+(_([a-zA-Z]*{digit}*)+)*

%option noyywrap
%option yylineno

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
{constint} return CONST_INT;
{const_double} return CONSTANT;
"true" return CONSTANT;
"false" return CONSTANT;
{leter} return CONSTANT;
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
"||" return ORLOG;
"&&" return ANDLOG;
"^" return EXOR;
"!=" return EQUALS; 
"==" return EQUALS; 
"<" return COMPAR;
">" return COMPAR;
"<=" return COMPAR;
">=" return COMPAR;
"+" return ADDITION;
"-" return ADDITION;
"*" return MULTI;
"/" return MULTI;
"%" return MULTI;
"~" return UNARI;
"!" return UNARI;
"#" return UNARI;
"?" return UNARI;
">>" return LISTOP1;
"<<" return LISTOP1;
"$" return LISTOP2;
"--" return MINMIN;
"++" return PLUSPLUS; 
"@" return ATSIGN; 
{word} return WORD;
{id} return ID;
[\n\r\t ] ECHO;
. printf("\n\n \tERROR LEXICO: la palabra %s en la linea %d \n\n\t",yytext,yylineno);

%%