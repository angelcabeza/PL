/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

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

    dtipo comprobar_llamada_a_funcion(atributos atrib);

    entradaTS encontrarEntrada(string nombre, bool debe_estar);
    

    //Aparte
    dtipo comprobarOpBinario(atributos izq, atributos operador, atributos der);
    dtipo comprobarOpBinarioMenos(atributos izq, atributos der);
    dtipo comprobarEsEnteroReal (atributos atrib);
    dtipo comprobarOpUnarios( atributos atrib );
    void comprobarAdicion (atributos atr1, atributos atr2);

    string tipo_to_string(dtipo tipo);
    int incrementarTOPE();
    dtipo atrATipo(int atributo);


#line 138 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 232 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   129,   129,   132,   132,   135,   136,   139,   140,   143,
     144,   145,   148,   149,   150,   153,   154,   157,   157,   160,
     161,   162,   165,   166,   169,   170,   173,   174,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   190,
     191,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     215,   216,   219,   220,   221,   222,   223
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNARI", "ADDITION", "LISTOP2", "MINMIN",
  "PLUSPLUS", "ATSIGN", "MAIN", "INIBLO", "ENDBLO", "INIVAR", "ENDVAR",
  "TYPEVAR", "SEMICOLON", "COMMA", "ID", "INIPA", "ENDPA", "LIST", "IF",
  "ELSE", "FOR", "WHILE", "ASIGN", "ITEFOR", "DO", "READ", "PRINT",
  "RETURN", "CONSTANT", "WORD", "INISQR", "ENDSQR", "CONCATENATE", "ORLOG",
  "ANDLOG", "EXOR", "EQUALS", "COMPAR", "MULTI", "LISTOP1", "$accept", "S",
  "B", "$@1", "Dvl", "Vl", "Cdv", "Lv", "Dss", "Ds", "$@2", "Cs", "Dc",
  "Pa", "Ses", "Se", "Lvread", "Exp", "lc", "Lec", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,    38,    14,   -83,   -83,   -83,    27,    73,   -83,   -83,
      20,    53,    12,   -83,   257,   -83,   -83,    80,    20,   -83,
     -83,    42,   376,   376,   376,   -83,    -3,   376,    58,    57,
      60,    71,     6,   350,   376,   -83,    78,   -83,   -83,   -83,
     119,   288,   -83,    75,   -83,   133,    90,   -83,   147,   -83,
     -83,   216,   354,   376,    84,   -83,   376,   148,   376,   159,
     168,   173,   -83,   202,   111,    93,   -83,     1,    38,   171,
     -83,   -83,   376,   376,   166,   376,   376,   376,   376,   376,
     376,   376,   376,   -83,   -83,   -83,     0,   131,   -83,   141,
     376,   155,    20,   -83,   -83,   358,   -83,   172,   -83,   -83,
     137,   158,    25,   196,   202,     4,   103,   114,    45,    29,
       5,   -83,   -83,   -83,   319,   179,   319,   168,   -83,   202,
     -83,   -83,   190,     8,   376,   189,   376,   -83,   -83,   144,
     -83,   202,   319,   194,   195,   -83,   319,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     2,     1,     6,     0,    16,    11,
       0,     0,     0,     8,     0,    14,    13,     0,     0,     5,
       7,    59,     0,     0,     0,    23,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,    28,    15,    17,
       0,     0,    27,     0,     9,     0,     0,    59,    56,    42,
      43,    38,     0,     0,     0,    22,     0,     0,     0,     0,
      40,     0,    65,    64,     0,     0,    61,     0,     0,     0,
       4,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    12,    10,     0,     0,    41,     0,
       0,     0,     0,    34,    35,     0,    36,     0,    58,    18,
       0,    44,    46,     0,    45,    53,    49,    50,    51,    48,
      47,    52,    55,    29,     0,     0,     0,    39,    63,    62,
      60,    20,     0,     0,     0,    30,     0,    32,    25,     0,
      19,    54,     0,     0,     0,    31,     0,    24,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,     3,   -83,   -83,   -83,   201,   -12,   -83,   -83,
     -83,   -83,   -82,   -83,   -83,   -38,   -83,   -22,   -83,   174
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    37,     6,     8,    12,    13,    17,    14,    38,
      68,    39,    40,   123,    41,    42,    61,    43,    67,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    51,    71,     4,    54,    46,    15,    72,    72,
      73,    63,    65,     9,     5,    52,    95,    97,   122,   112,
      60,    15,    53,    16,   129,    19,    10,   130,     1,    72,
      63,    87,    11,    72,    89,    98,    91,    16,    59,     7,
      77,    78,    79,    80,    81,    82,    82,   134,     3,    72,
     101,   102,   -21,   104,   105,   106,   107,   108,   109,   110,
     111,    77,    78,    79,    80,    81,    82,    18,   115,    81,
      82,    99,    55,   119,     9,    56,   125,    57,   127,    72,
     117,    73,    74,    75,    80,    81,    82,    10,    72,    58,
      73,    74,    75,    11,   135,    44,    45,    72,   138,    73,
      74,    75,   131,    88,   133,    85,    45,    72,    96,    66,
      76,    77,    78,    79,    80,    81,    82,    83,    72,    76,
      77,    78,    79,    80,    81,    82,    94,    95,    76,    77,
      78,    79,    80,    81,    82,    72,    69,    73,    74,    75,
      78,    79,    80,    81,    82,    72,   113,    73,    74,    75,
      84,    25,    79,    80,    81,    82,   121,    28,    25,    72,
     114,    73,    74,    75,    28,    52,    76,    77,    78,    79,
      80,    81,    82,    90,   116,    92,    76,    77,    78,    79,
      80,    81,    82,    72,    45,    73,    74,    75,    93,   100,
      76,    77,    78,    79,    80,    81,    82,   103,    72,    82,
      73,    74,    75,   120,   124,   126,    72,   128,    73,    74,
      75,   132,   137,    20,    76,    77,    78,    79,    80,    81,
      82,   136,    73,    74,    75,     0,    86,     0,     0,    76,
      77,    78,    79,    80,    81,    82,     0,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    21,     0,
      22,    23,    24,     0,     0,     0,     0,     3,     0,     0,
       0,    25,     0,     0,    26,    27,     0,    28,    29,     0,
      30,    31,     0,     0,     0,    32,    33,    34,    35,    47,
      36,    22,    23,    24,     0,     0,     0,     0,     3,    70,
       0,     0,     0,     0,     0,    26,    27,     0,     0,    29,
       0,    30,    31,     0,     0,     0,    32,    33,    34,    35,
      47,    36,    22,    23,    24,     0,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
      29,     0,    30,    31,     0,     0,     0,    32,    33,    34,
      35,    47,    36,    22,    23,    47,     0,    22,    23,    47,
       0,    22,    23,     0,     0,   -66,   -66,    48,    27,     0,
     -66,    48,    27,   -66,     0,    48,    27,    47,     0,    22,
      23,    35,    62,    36,     0,    35,    62,    36,     0,    35,
     118,    36,     0,    48,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     0,    36
};

static const yytype_int16 yycheck[] =
{
      22,    23,    24,    41,     1,    27,    18,     1,     4,     4,
       6,    33,    34,     1,     0,    18,    16,    16,   100,    19,
      32,     1,    25,    17,    16,    13,    14,    19,     9,     4,
      52,    53,    20,     4,    56,    34,    58,    17,    32,    12,
      36,    37,    38,    39,    40,    41,    41,   129,    10,     4,
      72,    73,    10,    75,    76,    77,    78,    79,    80,    81,
      82,    36,    37,    38,    39,    40,    41,    14,    90,    40,
      41,    68,    14,    95,     1,    18,   114,    17,   116,     4,
      92,     6,     7,     8,    39,    40,    41,    14,     4,    18,
       6,     7,     8,    20,   132,    15,    16,     4,   136,     6,
       7,     8,   124,    19,   126,    15,    16,     4,    15,    31,
      35,    36,    37,    38,    39,    40,    41,    42,     4,    35,
      36,    37,    38,    39,    40,    41,    15,    16,    35,    36,
      37,    38,    39,    40,    41,     4,    17,     6,     7,     8,
      37,    38,    39,    40,    41,     4,    15,     6,     7,     8,
      17,    14,    38,    39,    40,    41,    19,    20,    14,     4,
      19,     6,     7,     8,    20,    18,    35,    36,    37,    38,
      39,    40,    41,    25,    19,    16,    35,    36,    37,    38,
      39,    40,    41,     4,    16,     6,     7,     8,    15,    18,
      35,    36,    37,    38,    39,    40,    41,    31,     4,    41,
       6,     7,     8,    31,     8,    26,     4,    17,     6,     7,
       8,    22,    17,    12,    35,    36,    37,    38,    39,    40,
      41,    27,     6,     7,     8,    -1,    52,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,     1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    14,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    28,    29,    30,    31,     1,
      33,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
       1,    33,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,     1,    33,     3,     4,     1,    -1,     3,     4,     1,
      -1,     3,     4,    -1,    -1,    15,    16,    17,    18,    -1,
      16,    17,    18,    19,    -1,    17,    18,     1,    -1,     3,
       4,    31,    32,    33,    -1,    31,    32,    33,    -1,    31,
      32,    33,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    44,    10,    45,     0,    46,    12,    47,     1,
      14,    20,    48,    49,    51,     1,    17,    50,    14,    13,
      49,     1,     3,     4,     5,    14,    17,    18,    20,    21,
      23,    24,    28,    29,    30,    31,    33,    45,    52,    54,
      55,    57,    58,    60,    15,    16,    50,     1,    17,    60,
      60,    60,    18,    25,    60,    14,    18,    17,    18,    32,
      50,    59,    32,    60,    62,    60,    31,    61,    53,    17,
      11,    58,     4,     6,     7,     8,    35,    36,    37,    38,
      39,    40,    41,    42,    17,    15,    62,    60,    19,    60,
      25,    60,    16,    15,    15,    16,    15,    16,    34,    45,
      18,    60,    60,    31,    60,    60,    60,    60,    60,    60,
      60,    60,    19,    15,    19,    60,    19,    50,    32,    60,
      31,    19,    55,    56,     8,    58,    26,    58,    17,    16,
      19,    60,    22,    60,    55,    58,    27,    17,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    46,    45,    47,    47,    48,    48,    49,
      49,    49,    50,    50,    50,    51,    51,    53,    52,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     6,     3,     0,     2,     1,     3,
       4,     1,     3,     1,     1,     2,     0,     0,     3,     5,
       4,     1,     2,     1,     4,     2,     2,     1,     1,     4,
       5,     7,     5,     8,     3,     3,     3,     2,     2,     3,
       1,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 132 "yacc.y" /* yacc.c:1646  */
    {TS_insertaMarca();}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 132 "yacc.y" /* yacc.c:1646  */
    {TS_vaciarEntradas();}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[-2]).atrib); listaTmp=false; }
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[-2]).atrib); listaTmp=true; }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 148 "yacc.y" /* yacc.c:1646  */
    { TS_insertaID((yyvsp[0])); (yyval).lexema = (yyvsp[-2]).lexema + ", " + (yyvsp[0]).lexema;}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 149 "yacc.y" /* yacc.c:1646  */
    { TS_insertaID((yyvsp[0])); (yyval).lexema = (yyvsp[0]).lexema; }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "yacc.y" /* yacc.c:1646  */
    {subprog += 1;}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "yacc.y" /* yacc.c:1646  */
    {subprog -= 1;}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 160 "yacc.y" /* yacc.c:1646  */
    {TS_InsertaSubprog((yyvsp[-3]));}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 161 "yacc.y" /* yacc.c:1646  */
    {TS_InsertaSubprog(atribvacio);}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 165 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[0]).atrib); listaTmp=true; }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 166 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[0]).atrib); listaTmp=false; }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 169 "yacc.y" /* yacc.c:1646  */
    { TS_InsertaParam((yyvsp[0])); }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 170 "yacc.y" /* yacc.c:1646  */
    { TS_InsertaParam((yyvsp[0])); }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 178 "yacc.y" /* yacc.c:1646  */
    { comprobarEsTipo((yyvsp[-3]).tipo, (yyvsp[-1]).tipo); comprobarAsignacionListas((yyvsp[-3]), (yyvsp[-1])); (yyval).lexema = (yyvsp[-3]).lexema;}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo(booleano, (yyvsp[-2]).tipo);}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 180 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo(booleano, (yyvsp[-4]).tipo);}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo(booleano, (yyvsp[-2]).tipo);}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 182 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo(entero,(yyvsp[-6]).tipo);comprobarEsTipo(entero, (yyvsp[-4]).tipo); comprobarEsTipo(entero,(yyvsp[-2]).tipo);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 185 "yacc.y" /* yacc.c:1646  */
    {comprobarDevuelveSubprog((yyvsp[-1]));}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 186 "yacc.y" /* yacc.c:1646  */
    { comprobarEsLista((yyvsp[-1]));}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 187 "yacc.y" /* yacc.c:1646  */
    { comprobarEsLista((yyvsp[0]));}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 193 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[-1]).tipo; (yyval).lista = (yyvsp[-1]).lista; (yyval).lexema = "( " + (yyvsp[-1]).lexema + " )";}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 196 "yacc.y" /* yacc.c:1646  */
    { comprobarAdicion((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=(yyvsp[-2]).tipo, (yyval).lista=(yyvsp[-2]).lista; }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 197 "yacc.y" /* yacc.c:1646  */
    {  (yyval).tipo=(yyvsp[-2]).tipo, (yyval).lista=0; }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 207 "yacc.y" /* yacc.c:1646  */
    { (yyval).tipo =  comprobar_llamada_a_funcion((yyvsp[-3])); (yyval).lexema = (yyvsp[-3]).lexema + "( " + (yyvsp[-1]).lexema + " )"; }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 208 "yacc.y" /* yacc.c:1646  */
    {entradaTS ent = encontrarEntrada((yyvsp[0]).lexema, true); (yyval).tipo = ent.tipoDato; (yyval).lista = ent.eslista; (yyval).lexema = (yyvsp[0]).lexema;}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 209 "yacc.y" /* yacc.c:1646  */
    {tipoTmp = (yyvsp[0]).tipo; (yyval).tipo = (yyvsp[0]).tipo; (yyval).lista = false; (yyval).lexema = (yyvsp[0]).lexema;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 210 "yacc.y" /* yacc.c:1646  */
    {tipoTmp = (yyvsp[-1]).tipo; (yyval).tipo = (yyvsp[-1]).tipo; (yyval).lista = true;}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 215 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo((yyvsp[0]).tipo, (yyvsp[-2]).tipo); (yyval).tipo = (yyvsp[-2]).tipo;}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 216 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[0]).tipo;}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 219 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[-2]).lexema + ", " + (yyvsp[0]).lexema;}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 220 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[-2]).lexema + ", " + (yyvsp[0]).lexema;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 221 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[0]).lexema; }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 222 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[0]).lexema;}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1658 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 225 "yacc.y" /* yacc.c:1906  */


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
        nueva_entrada.tipoDato = tipoTmp;
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

        printf("Tipo: '%s'",tipoDatoToString(nueva_entrada.tipoDato).c_str());

    } else {
        // si existe damos error
        printf("Error semantico en la linea %d: El parámetro %s ya existe\n", yylineno, atributo.lexema.c_str());
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



    if ( entrada == 0 ){
        printf("Error semantico en la linea %d: No se puede devolver un valor en la seccion principal\n", yylineno);
    } else {
        comprobarEsTipo(TS[entrada].tipoDato, atrib.tipo);
    }

}


dtipo comprobarOpBinario(atributos izq, atributos operador, atributos der) {

    dtipo tipo_exp = desconocido;

    string t_izq = tipo_to_string(izq.tipo);
    string t_der = tipo_to_string(der.tipo);

    // operadores de + * / y relacion
    if ( (operador.atrib >= 0 && operador.atrib <= 2) ||
          ( operador.atrib >= 6 && operador.atrib <= 9  )) {

        if ( izq.lista ) {
            if ( der.lista ) {
                printf("Error semantico en la linea %d: No se puede aplicar el operador entre dos listas\n", yylineno);
            } if ( der.tipo != entero && der.tipo != real) {
                printf("Error semantico en la linea %d: Operador solo aplicable a enteros o reales, encontrados tipos lista de %s y %s\n", yylineno, t_izq.c_str(), t_der.c_str());
            }

        } else if ( der.lista ){

             if ( izq.tipo != entero && izq.tipo != real ) {
                printf("Error semantico en la linea %d: Operador solo aplicable a enteros o reales, encontrados tipos %s y lista de %s\n", yylineno, t_izq.c_str(), t_der.c_str());
            }

        } else {
            // tiene que ser entero o real y del mismo tipo
            if ( (izq.tipo != entero && izq.tipo != real) || (der.tipo != entero && der.tipo != real) ) {
                printf("Error semantico en la linea %d: Operador solo aplicable a enteros o reales, encontrados tipos %s y %s\n", yylineno, t_izq.c_str(), t_der.c_str());
            } else {
                // comprobamos que izq y der son del mismo tipo
                comprobarEsTipo(izq.tipo, der.tipo);
            }
        }

    } else if (operador.atrib == 10 || operador.atrib == 11){
        // operaciones de comprobar si son iguales o distintos, aplicables a todos los tipos
        comprobarEsTipo(izq.tipo, der.tipo);

    } else if ( operador.atrib >= 3 && operador.atrib <= 5 ) {
        if ( izq.tipo != booleano && der.tipo != booleano ){
            printf("Error semantico en la linea %d: Operador solo aplicable a booleanos, encontrados tipos %s y %s\n", yylineno, t_izq.c_str(), t_der.c_str());
        } else {
            // comprobamos que izq y der son del mismo tipo
            comprobarEsTipo(izq.tipo, der.tipo);
        }

    // operador l--x l%x
    } else if ( operador.atrib == 12 || operador.atrib == 13){
        comprobarEsLista(izq);
        comprobarEsTipo(entero, der.tipo);
    } else if ( operador.atrib == 14 ) {
        comprobarEsLista(izq);
        comprobarEsLista(der);
    }

    if ( operador.atrib >= 3 && operador.atrib <= 11 ){
        tipo_exp = booleano;

    } else {
        tipo_exp = izq.tipo;

    }

    return tipo_exp;

}

dtipo comprobarOpBinarioMenos(atributos izq, atributos der) {
    if ( (izq.tipo != entero && izq.tipo != real) || (der.tipo != entero && der.tipo != real) ){
        string t_izq = tipo_to_string(izq.tipo);
        string t_der = tipo_to_string(der.tipo);
        printf("Error semantico en la linea %d: Operador solo aplicable a enteros o reales, encontrados tipos %s y %s\n", yylineno, t_izq.c_str(), t_der.c_str());
    } else {
        // comprobamos que izq y der son del mismo tipo
        comprobarEsTipo(izq.tipo, der.tipo);
    }

    return izq.tipo;

}

dtipo comprobarEsEnteroReal (atributos atrib){
    if ( atrib.tipo != entero && atrib.tipo != real){
        string t = tipo_to_string(atrib.tipo);
        printf("Error semantico en la linea %d: Operador solo aplicable a enteros o reales, encontrado tipo %s\n", yylineno, t.c_str());
    }
    return atrib.tipo;
}

void comprobarAdicion (atributos atr1, atributos atr2){
    if ( (atr1.tipo != atr2.tipo) || (atr1.tipo != entero && atr1.tipo != real) ||
         (atr1.tipo != entero && atr2.tipo != real ) || (atr1.lista != atr2.lista) ) {

        string tipo_atr1 = tipoDatoToString(atr1.tipo);;
        string tipo_atr2 = tipoDatoToString(atr2.tipo);;
        if (atr1.lista){
            tipo_atr1 = "Lista " + tipo_atr1;
        }
        if (atr2.lista){
            tipo_atr2 = "Lista " + tipo_atr2;
        }

        printf("Error semantico en la linea %d: Operador solo aplicable a variables del mismo tipo, encontrados tipos diferentes %s y %s\n", yylineno, tipo_atr1.c_str(), tipo_atr2.c_str());
    }
}

void comprobarAtsign (atributos atr1, atributos atr2){
    if ( (atr2.tipo != entero) || (atr1.lista == 0) ||
         (atr2.lista == 1) ) {

        string tipo_atr1 = tipoDatoToString(atr1.tipo);;
        string tipo_atr2 = tipoDatoToString(atr2.tipo);;
        if (atr1.lista){
            tipo_atr1 = "Lista " + tipo_atr1;
        }
        if (atr2.lista){
            tipo_atr2 = "Lista " + tipo_atr2;
        }

        printf("Error semantico en la linea %d: Operador solo aplicable a variables del mismo tipo, encontrados tipos diferentes %s y %s\n", yylineno, tipo_atr1.c_str(), tipo_atr2.c_str());
    }
}



dtipo comprobarOpUnarios( atributos exp ){

    entradaTS entrada;
    dtipo tipo_a_devolver;

    //es_constante
    entrada = encontrarEntrada(exp.lexema, true);

    // operador !
    if ( exp.atrib == 0 ) {
        comprobarEsTipo(booleano, exp.tipo);
        tipo_a_devolver = booleano;
    // operador # y ?
    } else {
        comprobarEsLista(exp);
        tipo_a_devolver = exp.tipo;
    }

    return tipo_a_devolver;

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
