/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

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

    string tipo_to_string(dtipo tipo);
    int incrementarTOPE();
    dtipo atrATipo(int atributo);


#line 141 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
       0,   128,   128,   131,   131,   134,   135,   138,   139,   142,
     143,   146,   147,   148,   151,   152,   155,   155,   158,   159,
     160,   163,   164,   167,   168,   171,   172,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   188,   189,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   213,
     214,   217,   218,   219,   220,   221
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
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    12,    24,   -65,   -65,   -65,    51,    57,   -65,     6,
      19,    52,   -65,   288,   -65,   -65,    80,     6,   -65,   -65,
      79,   270,   270,   270,   -65,    -4,   270,    53,    91,   101,
     118,    15,   381,   270,   -65,   112,   -65,   -65,   -65,   127,
     319,   -65,    75,   -65,   133,   111,   -65,   134,   143,   143,
       2,   385,   270,    84,   -65,   270,   128,   270,   138,   139,
     142,   -65,   202,   126,    93,   -65,    10,    12,   140,   -65,
     -65,   270,   270,   125,   270,   270,   270,   270,   270,   270,
     270,   270,   -65,   -65,   -65,    29,   131,   -65,   141,   270,
     155,     6,   -65,   -65,   389,   -65,   144,   -65,   -65,    55,
      99,   143,   156,   143,   218,   240,   245,   256,    21,    11,
      78,   -65,   -65,   350,   179,   350,   139,   -65,   202,   -65,
     -65,   148,    30,   270,   151,   270,   -65,   -65,    73,   -65,
     143,   350,   194,   167,   -65,   350,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     2,     1,     6,     0,    15,     0,
       0,     0,     8,     0,    13,    12,     0,     0,     5,     7,
      58,     0,     0,     0,    22,    55,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,    27,    14,    16,     0,
       0,    26,     0,     9,     0,     0,    58,    55,    41,    42,
      37,     0,     0,     0,    21,     0,     0,     0,     0,    39,
       0,    64,    63,     0,     0,    60,     0,     0,     0,     4,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    11,    10,     0,     0,    40,     0,     0,
       0,     0,    33,    34,     0,    35,     0,    57,    17,     0,
      43,    45,     0,    44,    52,    48,    49,    50,    47,    46,
      51,    54,    28,     0,     0,     0,    38,    62,    61,    59,
      19,     0,     0,     0,    29,     0,    31,    24,     0,    18,
      53,     0,     0,     0,    30,     0,    23,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,     3,   -65,   -65,   -65,   177,   -11,   -65,   -65,
     -65,   -65,   -64,   -65,   -65,   -37,   -65,   -21,   -65,   146
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    36,     6,     8,    11,    12,    16,    13,    37,
      67,    38,    39,   122,    40,    41,    60,    42,    66,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    49,    50,    70,     4,    53,    45,    14,    72,    73,
      74,    62,    64,     1,    51,    71,    14,    72,    73,    74,
      59,    52,     3,    15,     5,    71,    96,    72,    73,    74,
      62,    86,    15,    17,    88,   121,    90,    75,    76,    77,
      78,    79,    80,    81,    97,    94,   128,    58,   111,   129,
     100,   101,    81,   103,   104,   105,   106,   107,   108,   109,
     110,    80,    81,     7,   133,    18,     9,    54,   114,    24,
      98,     9,    10,   118,   120,    27,   124,    10,   126,    71,
     116,    72,    73,    74,    72,    73,    74,    24,    71,   -20,
      72,    73,    74,    27,   134,    43,    44,    71,   137,    72,
      73,    74,   130,    87,   132,    72,    73,    74,    95,    55,
      75,    76,    77,    78,    79,    80,    81,    82,    56,    75,
      76,    77,    78,    79,    80,    81,    84,    44,    75,    76,
      77,    78,    79,    80,    81,    71,    57,    72,    73,    74,
      81,    93,    94,    65,    68,    71,   112,    72,    73,    74,
      83,    74,    51,    89,    91,    44,   102,    92,    99,    71,
     113,    72,    73,    74,   123,   127,    75,    76,    77,    78,
      79,    80,    81,   131,   115,   119,    75,    76,    77,    78,
      79,    80,    81,    71,   136,    72,    73,    74,    19,     0,
      75,    76,    77,    78,    79,    80,    81,    85,    71,     0,
      72,    73,    74,     0,     0,   125,    71,     0,    72,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,   135,    71,     0,    72,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,     0,    75,    76,    77,
      78,    79,    80,    81,    71,     0,    72,    73,    74,    71,
       0,    72,    73,    74,    76,    77,    78,    79,    80,    81,
      71,     0,    72,    73,    74,     0,     0,     0,     0,     0,
       0,    46,     0,    21,    22,     0,     0,    77,    78,    79,
      80,    81,     0,    78,    79,    80,    81,    47,    26,    20,
       0,    21,    22,    23,     0,    79,    80,    81,     3,     0,
       0,    34,    24,    35,     0,    25,    26,     0,    27,    28,
       0,    29,    30,     0,     0,     0,    31,    32,    33,    34,
      46,    35,    21,    22,    23,     0,     0,     0,     0,     3,
      69,     0,     0,     0,     0,     0,    25,    26,     0,     0,
      28,     0,    29,    30,     0,     0,     0,    31,    32,    33,
      34,    46,    35,    21,    22,    23,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,    28,     0,    29,    30,     0,     0,     0,    31,    32,
      33,    34,    46,    35,    21,    22,    46,     0,    21,    22,
      46,     0,    21,    22,     0,     0,   -65,   -65,    47,    26,
       0,   -65,    47,    26,   -65,     0,    47,    26,     0,     0,
       0,     0,    34,    61,    35,     0,    34,    61,    35,     0,
      34,   117,    35
};

static const yytype_int16 yycheck[] =
{
      21,    22,    23,    40,     1,    26,    17,     1,     6,     7,
       8,    32,    33,     9,    18,     4,     1,     6,     7,     8,
      31,    25,    10,    17,     0,     4,    16,     6,     7,     8,
      51,    52,    17,    14,    55,    99,    57,    35,    36,    37,
      38,    39,    40,    41,    34,    16,    16,    32,    19,    19,
      71,    72,    41,    74,    75,    76,    77,    78,    79,    80,
      81,    40,    41,    12,   128,    13,    14,    14,    89,    14,
      67,    14,    20,    94,    19,    20,   113,    20,   115,     4,
      91,     6,     7,     8,     6,     7,     8,    14,     4,    10,
       6,     7,     8,    20,   131,    15,    16,     4,   135,     6,
       7,     8,   123,    19,   125,     6,     7,     8,    15,    18,
      35,    36,    37,    38,    39,    40,    41,    42,    17,    35,
      36,    37,    38,    39,    40,    41,    15,    16,    35,    36,
      37,    38,    39,    40,    41,     4,    18,     6,     7,     8,
      41,    15,    16,    31,    17,     4,    15,     6,     7,     8,
      17,     8,    18,    25,    16,    16,    31,    15,    18,     4,
      19,     6,     7,     8,     8,    17,    35,    36,    37,    38,
      39,    40,    41,    22,    19,    31,    35,    36,    37,    38,
      39,    40,    41,     4,    17,     6,     7,     8,    11,    -1,
      35,    36,    37,    38,    39,    40,    41,    51,     4,    -1,
       6,     7,     8,    -1,    -1,    26,     4,    -1,     6,     7,
       8,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    27,     4,    -1,     6,     7,     8,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    35,    36,    37,
      38,    39,    40,    41,     4,    -1,     6,     7,     8,     4,
      -1,     6,     7,     8,    36,    37,    38,    39,    40,    41,
       4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,    -1,    -1,    37,    38,    39,
      40,    41,    -1,    38,    39,    40,    41,    17,    18,     1,
      -1,     3,     4,     5,    -1,    39,    40,    41,    10,    -1,
      -1,    31,    14,    33,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,    31,
       1,    33,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    -1,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,     1,    33,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,     1,    33,     3,     4,     1,    -1,     3,     4,
       1,    -1,     3,     4,    -1,    -1,    15,    16,    17,    18,
      -1,    16,    17,    18,    19,    -1,    17,    18,    -1,    -1,
      -1,    -1,    31,    32,    33,    -1,    31,    32,    33,    -1,
      31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    44,    10,    45,     0,    46,    12,    47,    14,
      20,    48,    49,    51,     1,    17,    50,    14,    13,    49,
       1,     3,     4,     5,    14,    17,    18,    20,    21,    23,
      24,    28,    29,    30,    31,    33,    45,    52,    54,    55,
      57,    58,    60,    15,    16,    50,     1,    17,    60,    60,
      60,    18,    25,    60,    14,    18,    17,    18,    32,    50,
      59,    32,    60,    62,    60,    31,    61,    53,    17,    11,
      58,     4,     6,     7,     8,    35,    36,    37,    38,    39,
      40,    41,    42,    17,    15,    62,    60,    19,    60,    25,
      60,    16,    15,    15,    16,    15,    16,    34,    45,    18,
      60,    60,    31,    60,    60,    60,    60,    60,    60,    60,
      60,    19,    15,    19,    60,    19,    50,    32,    60,    31,
      19,    55,    56,     8,    58,    26,    58,    17,    16,    19,
      60,    22,    60,    55,    58,    27,    17,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    46,    45,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    51,    51,    53,    52,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     6,     3,     0,     2,     1,     3,
       4,     3,     1,     1,     2,     0,     0,     3,     5,     4,
       1,     2,     1,     4,     2,     2,     1,     1,     4,     5,
       7,     5,     8,     3,     3,     3,     2,     2,     3,     1,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 131 "yacc.y"
             {TS_insertaMarca();}
#line 1550 "y.tab.c"
    break;

  case 4:
#line 131 "yacc.y"
                                                     {TS_vaciarEntradas();}
#line 1556 "y.tab.c"
    break;

  case 9:
#line 142 "yacc.y"
                           { tipoTmp = atrATipo(yyvsp[-2].atrib); listaTmp=false; }
#line 1562 "y.tab.c"
    break;

  case 10:
#line 143 "yacc.y"
                                { tipoTmp = atrATipo(yyvsp[-2].atrib); listaTmp=true; }
#line 1568 "y.tab.c"
    break;

  case 11:
#line 146 "yacc.y"
                  { TS_insertaID(yyvsp[0]); yyval.lexema = yyvsp[-2].lexema + ", " + yyvsp[0].lexema;}
#line 1574 "y.tab.c"
    break;

  case 12:
#line 147 "yacc.y"
         { TS_insertaID(yyvsp[0]); yyval.lexema = yyvsp[0].lexema; }
#line 1580 "y.tab.c"
    break;

  case 16:
#line 155 "yacc.y"
         {subprog += 1;}
#line 1586 "y.tab.c"
    break;

  case 17:
#line 155 "yacc.y"
                           {subprog -= 1;}
#line 1592 "y.tab.c"
    break;

  case 18:
#line 158 "yacc.y"
                           {TS_InsertaSubprog(yyvsp[-3]);}
#line 1598 "y.tab.c"
    break;

  case 19:
#line 159 "yacc.y"
                        {TS_InsertaSubprog(atribvacio);}
#line 1604 "y.tab.c"
    break;

  case 21:
#line 163 "yacc.y"
                   { tipoTmp = atrATipo(yyvsp[0].atrib); listaTmp=true; }
#line 1610 "y.tab.c"
    break;

  case 22:
#line 164 "yacc.y"
              { tipoTmp = atrATipo(yyvsp[0].atrib); listaTmp=false; }
#line 1616 "y.tab.c"
    break;

  case 23:
#line 167 "yacc.y"
                     { TS_InsertaParam(yyvsp[0]); }
#line 1622 "y.tab.c"
    break;

  case 24:
#line 168 "yacc.y"
            { TS_InsertaParam(yyvsp[0]); }
#line 1628 "y.tab.c"
    break;

  case 28:
#line 176 "yacc.y"
                             { comprobarEsTipo(yyvsp[-3].tipo, yyvsp[-1].tipo); comprobarAsignacionListas(yyvsp[-3], yyvsp[-1]); yyval.lexema = yyvsp[-3].lexema;}
#line 1634 "y.tab.c"
    break;

  case 29:
#line 177 "yacc.y"
                            {comprobarEsTipo(booleano, yyvsp[-2].tipo);}
#line 1640 "y.tab.c"
    break;

  case 30:
#line 178 "yacc.y"
                                    {comprobarEsTipo(booleano, yyvsp[-4].tipo);}
#line 1646 "y.tab.c"
    break;

  case 31:
#line 179 "yacc.y"
                               {comprobarEsTipo(booleano, yyvsp[-2].tipo);}
#line 1652 "y.tab.c"
    break;

  case 32:
#line 180 "yacc.y"
                                        {comprobarEsTipo(entero,yyvsp[-6].tipo);comprobarEsTipo(entero, yyvsp[-4].tipo); comprobarEsTipo(entero,yyvsp[-2].tipo);}
#line 1658 "y.tab.c"
    break;

  case 35:
#line 183 "yacc.y"
                           {comprobarDevuelveSubprog(yyvsp[-1]);}
#line 1664 "y.tab.c"
    break;

  case 36:
#line 184 "yacc.y"
                  { comprobarEsLista(yyvsp[-1]);}
#line 1670 "y.tab.c"
    break;

  case 37:
#line 185 "yacc.y"
                  { comprobarEsLista(yyvsp[0]);}
#line 1676 "y.tab.c"
    break;

  case 40:
#line 191 "yacc.y"
                      {yyval.tipo = yyvsp[-1].tipo; yyval.lista = yyvsp[-1].lista; yyval.lexema = "( " + yyvsp[-1].lexema + " )";}
#line 1682 "y.tab.c"
    break;

  case 54:
#line 205 "yacc.y"
                         { yyval.tipo =  comprobar_llamada_a_funcion(yyvsp[-3]); yyval.lexema = yyvsp[-3].lexema + "( " + yyvsp[-1].lexema + " )"; }
#line 1688 "y.tab.c"
    break;

  case 55:
#line 206 "yacc.y"
         {entradaTS ent = encontrarEntrada(yyvsp[0].lexema, true); yyval.tipo = ent.tipoDato; yyval.lista = ent.eslista; yyval.lexema = yyvsp[0].lexema;}
#line 1694 "y.tab.c"
    break;

  case 56:
#line 207 "yacc.y"
               {tipoTmp = yyvsp[0].tipo; yyval.tipo = yyvsp[0].tipo; yyval.lista = false; yyval.lexema = yyvsp[0].lexema;}
#line 1700 "y.tab.c"
    break;

  case 57:
#line 208 "yacc.y"
                       {tipoTmp = yyvsp[-1].tipo; yyval.tipo = yyvsp[-1].tipo; yyval.lista = true;}
#line 1706 "y.tab.c"
    break;

  case 59:
#line 213 "yacc.y"
                        {comprobarEsTipo(yyvsp[0].tipo, yyvsp[-2].tipo); yyval.tipo = yyvsp[-2].tipo;}
#line 1712 "y.tab.c"
    break;

  case 60:
#line 214 "yacc.y"
               {yyval.tipo = yyvsp[0].tipo;}
#line 1718 "y.tab.c"
    break;

  case 61:
#line 217 "yacc.y"
                     { TS_subprog_inserta(yyvsp[0]); yyval.lexema = yyvsp[-2].lexema + ", " + yyvsp[0].lexema;}
#line 1724 "y.tab.c"
    break;

  case 62:
#line 218 "yacc.y"
                     { TS_subprog_inserta(yyvsp[0]); yyval.lexema = yyvsp[-2].lexema + ", " + yyvsp[0].lexema;}
#line 1730 "y.tab.c"
    break;

  case 63:
#line 219 "yacc.y"
          { TS_subprog_inserta(yyvsp[0]); yyval.lexema = yyvsp[0].lexema; }
#line 1736 "y.tab.c"
    break;

  case 64:
#line 220 "yacc.y"
           { TS_subprog_inserta(yyvsp[0]); yyval.lexema = yyvsp[0].lexema;}
#line 1742 "y.tab.c"
    break;


#line 1746 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 224 "yacc.y"


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
