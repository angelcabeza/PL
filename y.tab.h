/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UNARI = 258,
    ADDITION = 259,
    LISTOP2 = 260,
    MINMIN = 261,
    PLUSPLUS = 262,
    ATSIGN = 263,
    MAIN = 264,
    INIBLO = 265,
    ENDBLO = 266,
    INIVAR = 267,
    ENDVAR = 268,
    TYPEVAR = 269,
    SEMICOLON = 270,
    COMMA = 271,
    ID = 272,
    INIPA = 273,
    ENDPA = 274,
    LIST = 275,
    IF = 276,
    ELSE = 277,
    FOR = 278,
    WHILE = 279,
    ASIGN = 280,
    ITEFOR = 281,
    DO = 282,
    READ = 283,
    PRINT = 284,
    RETURN = 285,
    CONSTANT = 286,
    WORD = 287,
    INISQR = 288,
    ENDSQR = 289,
    CONCATENATE = 290,
    ORLOG = 291,
    ANDLOG = 292,
    EXOR = 293,
    EQUALS = 294,
    COMPAR = 295,
    MULTI = 296,
    LISTOP1 = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
