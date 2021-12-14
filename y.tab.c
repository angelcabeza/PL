/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

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


#line 147 "y.tab.c" /* yacc.c:339  */

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

#line 241 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

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
       0,   138,   138,   141,   141,   144,   145,   148,   149,   152,
     153,   156,   157,   159,   160,   161,   164,   165,   168,   168,
     171,   172,   173,   176,   177,   180,   181,   184,   185,   188,
     190,   192,   193,   194,   195,   197,   198,   199,   200,   201,
     204,   205,   208,   209,   210,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   234,   235,   238,   239,   240,   241,
     242
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
  "B", "$@1", "Dvl", "Vl", "Cdv", "tipo", "Lv", "Dss", "Ds", "$@2", "Cs",
  "Dc", "Pa", "Ses", "Se", "Lvread", "Lv2", "Exp", "lc", "Lec", YY_NULLPTR
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

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -71

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,     8,    23,   -40,   -40,   -40,    19,    71,   -40,   -40,
     -40,    11,     6,   -40,    75,   268,   -40,   -40,   -40,   -40,
     -40,    79,    26,   371,   371,   371,   -40,    -1,   371,    85,
      83,    91,   127,    66,   243,   371,   -40,    98,   -40,   -40,
     -40,   116,   299,   -40,     2,   -40,   136,   -40,   146,   -40,
     -40,   227,   361,   371,    74,   -40,   371,   129,   371,   -40,
     -40,   157,   147,   161,   -40,   191,   131,    82,   -40,    -2,
       8,   170,   -40,   -40,   371,   371,   155,   371,   371,   371,
     371,   371,   371,   371,   371,   -40,   -40,    68,   120,   -40,
     130,   371,   144,   115,   -40,   175,   -40,   338,   -40,   169,
     -40,   -40,   111,   160,   103,   194,   191,     9,   174,    24,
      30,    62,    12,   -40,   -40,   -40,   330,   168,   330,   161,
     -40,   -40,   191,   -40,   -40,   199,   177,   371,   195,   371,
     -40,   -40,     7,   -40,   191,   330,   183,   208,   -40,   330,
     -40,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     2,     1,     6,     0,    17,    10,
      11,     0,     0,     8,     0,     0,    12,     5,     7,    15,
      14,     0,    63,     0,     0,     0,    24,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,    29,    16,
      18,     0,     0,    28,     0,     9,     0,    63,    60,    46,
      47,    39,     0,     0,     0,    23,     0,     0,     0,    44,
      43,     0,     0,    41,    69,    68,     0,     0,    65,     0,
       0,     0,     4,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    13,     0,     0,    45,
       0,     0,     0,     0,    35,     0,    36,     0,    37,     0,
      62,    19,     0,    48,    50,     0,    49,    57,    53,    54,
      55,    52,    51,    56,    59,    30,     0,     0,     0,    40,
      42,    67,    66,    64,    21,     0,     0,     0,    31,     0,
      33,    26,     0,    20,    58,     0,     0,     0,    32,     0,
      25,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,     3,   -40,   -40,   -40,   224,   -40,   -40,   -40,
     -40,   -40,   -40,   -27,   -40,   -40,   -39,   -40,   145,   -23,
     -40,   185
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    38,     6,     8,    12,    13,    14,    21,    15,
      39,    70,    40,    41,   126,    42,    43,    62,    63,    44,
      69,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,    51,    73,     4,    54,    74,     9,    75,    76,
      77,    65,    67,    74,    99,    75,    74,    52,     3,    17,
      10,    26,     1,     5,    53,    16,    11,    29,    74,    65,
      88,     7,   100,    90,    74,    92,   -22,    78,    79,    80,
      81,    82,    83,    84,    85,    79,    80,    81,    82,    83,
      84,   103,   104,    84,   106,   107,   108,   109,   110,   111,
     112,   113,    81,    82,    83,    84,    74,    59,   117,    82,
      83,    84,     9,   101,   122,   125,    19,   128,    74,   130,
      75,    76,    77,    60,    97,    10,    74,   114,    75,    76,
      77,    11,    20,    89,    45,    46,   138,    98,    61,    55,
     141,    56,    83,    84,   134,   137,   136,    74,    57,    78,
      79,    80,    81,    82,    83,    84,    59,    78,    79,    80,
      81,    82,    83,    84,    74,    26,    75,    76,    77,    68,
     124,    29,    60,    71,    74,   115,    75,    76,    77,    79,
      80,    81,    82,    83,    84,    58,    96,    97,    74,   116,
      75,    76,    77,    86,    91,    78,    79,    80,    81,    82,
      83,    84,    94,   118,    52,    78,    79,    80,    81,    82,
      83,    84,    74,    93,    75,    76,    77,    95,    74,    78,
      79,    80,    81,    82,    83,    84,   105,    74,   102,    75,
      76,    77,   120,   132,   129,    74,   133,    75,    76,    77,
     123,    84,   127,    78,    79,    80,    81,    82,    83,    84,
     139,    80,    81,    82,    83,    84,   131,   135,    78,    79,
      80,    81,    82,    83,    84,   140,    78,    79,    80,    81,
      82,    83,    84,    75,    76,    77,    18,    87,   119,     0,
       0,     0,     0,     0,    47,     0,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -70,   -70,
      48,    28,    78,    79,    80,    81,    82,    83,    84,    22,
       0,    23,    24,    25,    36,    64,    37,     0,     3,     0,
       0,     0,    26,     0,     0,    27,    28,     0,    29,    30,
       0,    31,    32,     0,     0,     0,    33,    34,    35,    36,
      47,    37,    23,    24,    25,     0,     0,     0,     0,     3,
      72,     0,     0,     0,     0,     0,    27,    28,     0,     0,
      30,     0,    31,    32,     0,     0,     0,    33,    34,    35,
      36,    47,    37,    23,    24,    25,     0,     0,     0,    47,
       3,    23,    24,     0,     0,     0,     0,    27,    28,     0,
       0,    30,     0,    31,    32,    48,    28,     0,    33,    34,
      35,    36,    47,    37,    23,    24,     0,     0,     0,    36,
     121,    37,    47,     0,    23,    24,     0,   -70,    48,    28,
     -70,     0,     0,     0,     0,     0,     0,     0,    48,    28,
       0,     0,    36,    64,    37,     0,     0,     0,     0,     0,
       0,     0,    36,     0,    37
};

static const yytype_int16 yycheck[] =
{
      23,    24,    25,    42,     1,    28,     4,     1,     6,     7,
       8,    34,    35,     4,    16,     6,     4,    18,    10,    13,
      14,    14,     9,     0,    25,    14,    20,    20,     4,    52,
      53,    12,    34,    56,     4,    58,    10,    35,    36,    37,
      38,    39,    40,    41,    42,    36,    37,    38,    39,    40,
      41,    74,    75,    41,    77,    78,    79,    80,    81,    82,
      83,    84,    38,    39,    40,    41,     4,     1,    91,    39,
      40,    41,     1,    70,    97,   102,     1,   116,     4,   118,
       6,     7,     8,    17,    16,    14,     4,    19,     6,     7,
       8,    20,    17,    19,    15,    16,   135,    15,    32,    14,
     139,    18,    40,    41,   127,   132,   129,     4,    17,    35,
      36,    37,    38,    39,    40,    41,     1,    35,    36,    37,
      38,    39,    40,    41,     4,    14,     6,     7,     8,    31,
      19,    20,    17,    17,     4,    15,     6,     7,     8,    36,
      37,    38,    39,    40,    41,    18,    15,    16,     4,    19,
       6,     7,     8,    17,    25,    35,    36,    37,    38,    39,
      40,    41,    15,    19,    18,    35,    36,    37,    38,    39,
      40,    41,     4,    16,     6,     7,     8,    16,     4,    35,
      36,    37,    38,    39,    40,    41,    31,     4,    18,     6,
       7,     8,    17,    16,    26,     4,    19,     6,     7,     8,
      31,    41,     8,    35,    36,    37,    38,    39,    40,    41,
      27,    37,    38,    39,    40,    41,    17,    22,    35,    36,
      37,    38,    39,    40,    41,    17,    35,    36,    37,    38,
      39,    40,    41,     6,     7,     8,    12,    52,    93,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    35,    36,    37,    38,    39,    40,    41,     1,
      -1,     3,     4,     5,    31,    32,    33,    -1,    10,    -1,
      -1,    -1,    14,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
       1,    33,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,     1,    33,     3,     4,     5,    -1,    -1,    -1,     1,
      10,     3,     4,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    17,    18,    -1,    28,    29,
      30,    31,     1,    33,     3,     4,    -1,    -1,    -1,    31,
      32,    33,     1,    -1,     3,     4,    -1,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    44,    10,    45,     0,    46,    12,    47,     1,
      14,    20,    48,    49,    50,    52,    14,    13,    49,     1,
      17,    51,     1,     3,     4,     5,    14,    17,    18,    20,
      21,    23,    24,    28,    29,    30,    31,    33,    45,    53,
      55,    56,    58,    59,    62,    15,    16,     1,    17,    62,
      62,    62,    18,    25,    62,    14,    18,    17,    18,     1,
      17,    32,    60,    61,    32,    62,    64,    62,    31,    63,
      54,    17,    11,    59,     4,     6,     7,     8,    35,    36,
      37,    38,    39,    40,    41,    42,    17,    64,    62,    19,
      62,    25,    62,    16,    15,    16,    15,    16,    15,    16,
      34,    45,    18,    62,    62,    31,    62,    62,    62,    62,
      62,    62,    62,    62,    19,    15,    19,    62,    19,    61,
      17,    32,    62,    31,    19,    56,    57,     8,    59,    26,
      59,    17,    16,    19,    62,    22,    62,    56,    59,    27,
      17,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    46,    45,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    52,    52,    54,    53,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     6,     3,     0,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     2,     0,     0,     3,
       5,     4,     1,     2,     1,     4,     2,     2,     1,     1,
       4,     5,     7,     5,     8,     3,     3,     3,     2,     2,
       3,     1,     3,     1,     1,     3,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     1,
       0
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
#line 141 "yacc.y" /* yacc.c:1646  */
    {TS_insertaMarca();}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "yacc.y" /* yacc.c:1646  */
    {TS_vaciarEntradas();}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[0]).atrib); listaTmp=false; }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 157 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[0]).atrib); listaTmp=true; }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 159 "yacc.y" /* yacc.c:1646  */
    { TS_insertaID((yyvsp[0])); (yyval).lexema = (yyvsp[-2]).lexema + ", " + (yyvsp[0]).lexema;}
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 160 "yacc.y" /* yacc.c:1646  */
    { TS_insertaID((yyvsp[0])); (yyval).lexema = (yyvsp[0]).lexema; }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 168 "yacc.y" /* yacc.c:1646  */
    {subprog += 1;}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "yacc.y" /* yacc.c:1646  */
    {subprog -= 1;}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 171 "yacc.y" /* yacc.c:1646  */
    {TS_InsertaSubprog((yyvsp[-3]));}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 172 "yacc.y" /* yacc.c:1646  */
    {TS_InsertaSubprog(atribvacio);}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 176 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[0]).atrib); listaTmp=true; }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = atrATipo((yyvsp[0]).atrib); listaTmp=false; }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 180 "yacc.y" /* yacc.c:1646  */
    { TS_InsertaParam((yyvsp[0])); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 181 "yacc.y" /* yacc.c:1646  */
    { TS_InsertaParam((yyvsp[0])); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 190 "yacc.y" /* yacc.c:1646  */
    { entradaTS ent = encontrarEntrada((yyvsp[-3]).lexema, true); comprobarEsTipo(ent.tipoDato, (yyvsp[-1]).tipo);
                               comprobacionLista(ent.eslista, (yyvsp[-1]).lista); (yyval).lexema = (yyvsp[-3]).lexema; }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 192 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo(booleano, (yyvsp[-2]).tipo);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 193 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo(booleano, (yyvsp[-4]).tipo);}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 194 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo(booleano, (yyvsp[-2]).tipo);}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 195 "yacc.y" /* yacc.c:1646  */
    { entradaTS ent = encontrarEntrada((yyvsp[-7]).lexema, true); comprobarEsTipo(entero,ent.tipoDato);
                                          comprobarEsTipo(entero, (yyvsp[-4]).tipo); comprobarEsTipo(entero,(yyvsp[-2]).tipo);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 199 "yacc.y" /* yacc.c:1646  */
    {comprobarDevuelveSubprog((yyvsp[-1]));}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 200 "yacc.y" /* yacc.c:1646  */
    { comprobarEsLista((yyvsp[-1]));}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 201 "yacc.y" /* yacc.c:1646  */
    { comprobarEsLista((yyvsp[0]));}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 208 "yacc.y" /* yacc.c:1646  */
    {(yyval).lexema = (yyvsp[-2]).lexema + ", " + (yyvsp[0]).lexema;}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 209 "yacc.y" /* yacc.c:1646  */
    {(yyval).lexema = (yyvsp[0]).lexema; }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 213 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[-1]).tipo; (yyval).lista = (yyvsp[-1]).lista; (yyval).lexema = "( " + (yyvsp[-1]).lexema + " )";}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 215 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarAdicionUn((yyvsp[0])); (yyval).tipo=(yyvsp[0]).tipo; }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 216 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarAdicion((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=(yyvsp[-2]).tipo; }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 217 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarBinopListaInt((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=(yyvsp[-2]).tipo; }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 218 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarBinopListaInt((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=(yyvsp[-2]).tipo; }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 219 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarCompar((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=(yyvsp[-2]).tipo; }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 220 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarEquals((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=booleano; }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 221 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarLogOp((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=booleano; }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 222 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarLogOp((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=booleano; }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 223 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarLogOp((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=booleano; }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 224 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarMulti((yyvsp[-2]),(yyvsp[0]),(yyvsp[-1]).atrib); (yyval).tipo=(yyvsp[-2]).tipo; }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 225 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarConcatLista((yyvsp[-2]),(yyvsp[0])); (yyval).tipo=(yyvsp[-2]).tipo; }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 226 "yacc.y" /* yacc.c:1646  */
    { (yyval).lista=comprobarTernario((yyvsp[-4]),(yyvsp[-2]),(yyvsp[0])); (yyval).tipo=(yyvsp[-4]).tipo; }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 227 "yacc.y" /* yacc.c:1646  */
    { (yyval).tipo =  comprobar_llamada_a_funcion((yyvsp[-3])); (yyval).lexema = (yyvsp[-3]).lexema + "( " + (yyvsp[-1]).lexema + " )"; }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 228 "yacc.y" /* yacc.c:1646  */
    {entradaTS ent = encontrarEntrada((yyvsp[0]).lexema, true); (yyval).tipo = ent.tipoDato; (yyval).lista = ent.eslista; (yyval).lexema = (yyvsp[0]).lexema; }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 229 "yacc.y" /* yacc.c:1646  */
    { tipoTmp = (yyvsp[0]).tipo; (yyval).tipo = (yyvsp[0]).tipo; (yyval).lista = false; (yyval).lexema = (yyvsp[0]).lexema; }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 230 "yacc.y" /* yacc.c:1646  */
    {tipoTmp = (yyvsp[-1]).tipo; (yyval).tipo = (yyvsp[-1]).tipo; (yyval).lista = true; }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 234 "yacc.y" /* yacc.c:1646  */
    {comprobarEsTipo((yyvsp[0]).tipo, (yyvsp[-2]).tipo); (yyval).tipo = (yyvsp[-2]).tipo; }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 235 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[0]).tipo;}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 238 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[-2]).lexema + ", " + (yyvsp[0]).lexema;}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 239 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[-2]).lexema + ", " + (yyvsp[0]).lexema;}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 240 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[0]).lexema; }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 241 "yacc.y" /* yacc.c:1646  */
    { TS_subprog_inserta((yyvsp[0])); (yyval).lexema = (yyvsp[0]).lexema;}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1749 "y.tab.c" /* yacc.c:1646  */
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
#line 244 "yacc.y" /* yacc.c:1906  */


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



    if ( entrada == 0 ){
        printf("Error semantico en la linea %d: No se puede devolver un valor en la seccion principal\n", yylineno);
    } else {
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
