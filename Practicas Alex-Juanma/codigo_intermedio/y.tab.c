
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sintactico_semantico.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generacion.h"

#define YYERROR_VERBOSE

/** La siguiente declaracion permite que ?yyerror? se pueda invocar desde el
*** fuente de lex (prueba.l)
**/

void yyerror( char* msg ) ;
/** La siguiente variable se usará para conocer el numero de la línea
*** que se esta leyendo en cada momento. También es posible usar la variable
*** ?yylineno? que también nos muestra la línea actual. Para ello es necesario
*** invocar a flex con la opción '-l'(compatibilidad con lex).
**/

int linea_actual = 1;
dTipo tipoPorAsignar,tipoSwitch;
int pila=0;
int argumentos=1;
int correcto=1;
char *nomproc;
int numparam=0;




/* Line 189 of yacc.c  */
#line 105 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CABPROG = 258,
     OP_RELACIONAL = 259,
     INIBLOQUE = 260,
     FINBLOQUE = 261,
     PARIZQ = 262,
     PARDER = 263,
     COMA = 264,
     FINLINEA = 265,
     COND = 266,
     ELSE = 267,
     MIENT = 268,
     IGUAL = 269,
     ENTRADA = 270,
     SALIDA = 271,
     OPUNA = 272,
     OP_PILA = 273,
     OPMULTDIV = 274,
     IGUALDAD = 275,
     AND = 276,
     OR = 277,
     XOR = 278,
     SUMRES = 279,
     INS_ELEM = 280,
     PROC = 281,
     COMP = 282,
     CASO = 283,
     DEFECTO = 284,
     FINCASO = 285,
     DOSPUNT = 286,
     TIPO = 287,
     IDENTIFICADOR = 288,
     CONST_BOOLEAN = 289,
     CONST_INT = 290,
     CONST_REAL = 291,
     CONST_CHAR = 292,
     CONST_CAD = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 185 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,    10,    12,    13,    20,    23,
      24,    28,    30,    34,    36,    39,    40,    43,    44,    45,
      53,    58,    60,    64,    66,    69,    72,    73,    75,    77,
      79,    81,    83,    85,    87,    89,    91,    96,    97,   105,
     106,   110,   111,   112,   113,   121,   125,   127,   131,   133,
     137,   140,   143,   144,   150,   157,   165,   173,   179,   184,
     185,   192,   196,   198,   202,   205,   208,   212,   216,   220,
     224,   228,   232,   236,   240,   242,   244,   246,   249,   251,
     254,   258,   260,   262,   266,   268,   270,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    -1,    42,    41,    43,    -1,     3,    -1,
       1,    -1,    -1,     5,    44,    45,    48,    55,     6,    -1,
      45,    46,    -1,    -1,    32,    47,    10,    -1,    33,    -1,
      47,     9,    33,    -1,     1,    -1,    48,    49,    -1,    -1,
      50,    43,    -1,    -1,    -1,    26,    33,     7,    51,    53,
      52,     8,    -1,    26,    33,     7,     8,    -1,    54,    -1,
      54,     9,    53,    -1,     1,    -1,    32,    33,    -1,    55,
      56,    -1,    -1,    43,    -1,    57,    -1,    58,    -1,    62,
      -1,    65,    -1,    67,    -1,    69,    -1,    72,    -1,     1,
      -1,    33,    14,    75,    10,    -1,    -1,    11,     7,    75,
       8,    59,    56,    60,    -1,    -1,    12,    61,    56,    -1,
      -1,    -1,    -1,    13,     7,    63,    75,    64,     8,    56,
      -1,    15,    66,    10,    -1,    33,    -1,    66,     9,    33,
      -1,     1,    -1,    16,    68,    10,    -1,    68,    33,    -1,
      68,    38,    -1,    -1,    27,     7,    33,     8,    70,    -1,
      28,    78,    31,    55,    30,    10,    -1,    28,    78,    31,
      55,    30,    10,    71,    -1,    70,    28,    78,    31,    55,
      30,    10,    -1,    29,    31,    55,    30,    10,    -1,    33,
       7,     8,    10,    -1,    -1,    33,     7,    73,    74,     8,
      10,    -1,    74,     9,    75,    -1,    75,    -1,     7,    75,
       8,    -1,    17,    75,    -1,    18,    75,    -1,    75,    19,
      75,    -1,    75,    24,    75,    -1,    75,     4,    75,    -1,
      75,    22,    75,    -1,    75,    21,    75,    -1,    75,    23,
      75,    -1,    75,    20,    75,    -1,    75,    25,    75,    -1,
      33,    -1,    78,    -1,    76,    -1,    24,    75,    -1,     1,
      -1,     5,     6,    -1,     5,    77,     6,    -1,    33,    -1,
      78,    -1,    77,     9,    78,    -1,    35,    -1,    36,    -1,
      37,    -1,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   122,   127,   127,   129,   129,   135,   136,
     138,   143,   153,   161,   163,   164,   166,   168,   173,   168,
     179,   188,   189,   190,   192,   204,   204,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   216,   231,   231,   239,
     239,   246,   253,   258,   253,   266,   277,   278,   285,   287,
     293,   301,   302,   304,   311,   316,   321,   327,   329,   340,
     340,   362,   374,   384,   388,   396,   410,   459,   510,   531,
     543,   557,   571,   584,   599,   607,   608,   609,   619,   621,
     622,   627,   634,   635,   643,   644,   645,   646
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CABPROG", "OP_RELACIONAL", "INIBLOQUE",
  "FINBLOQUE", "PARIZQ", "PARDER", "COMA", "FINLINEA", "COND", "ELSE",
  "MIENT", "IGUAL", "ENTRADA", "SALIDA", "OPUNA", "OP_PILA", "OPMULTDIV",
  "IGUALDAD", "AND", "OR", "XOR", "SUMRES", "INS_ELEM", "PROC", "COMP",
  "CASO", "DEFECTO", "FINCASO", "DOSPUNT", "TIPO", "IDENTIFICADOR",
  "CONST_BOOLEAN", "CONST_INT", "CONST_REAL", "CONST_CHAR", "CONST_CAD",
  "$accept", "programa", "$@1", "cabecera_programa", "bloque", "$@2",
  "variables_locales", "cuerpo_declar_variables", "declar_variables",
  "declar_de_subprogs", "declar_de_subprog", "cabecera_subprog", "$@3",
  "$@4", "declara_args", "argumento", "sentencias", "sentencia",
  "sentencia_asignacion", "sentencia_if", "$@5", "sentencia_else", "$@6",
  "sentencia_while", "$@7", "$@8", "sentencia_entrada", "identificadores",
  "sentencia_salida", "lista_expresiones_o_cadena", "sentencia_switch",
  "sentencia_case", "sentencia_default", "llamada_proced", "@9",
  "param_llamada", "expresion", "agregados_pila", "valores_pila",
  "literal", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    44,    43,    45,    45,
      46,    47,    47,    47,    48,    48,    49,    51,    52,    50,
      50,    53,    53,    53,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    59,    58,    61,
      60,    60,    63,    64,    62,    65,    66,    66,    66,    67,
      68,    68,    68,    69,    70,    70,    70,    71,    72,    73,
      72,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    77,    77,    77,    78,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     1,     0,     6,     2,     0,
       3,     1,     3,     1,     2,     0,     2,     0,     0,     7,
       4,     1,     3,     1,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     7,     0,
       3,     0,     0,     0,     7,     3,     1,     3,     1,     3,
       2,     2,     0,     5,     6,     7,     7,     5,     4,     0,
       6,     3,     1,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     1,     2,
       3,     1,     1,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     4,     0,     2,     1,     0,     6,     3,     9,
      15,     0,     8,    26,    13,    11,     0,     0,    14,     0,
       0,     0,    10,     0,    16,    35,     7,     0,     0,     0,
      52,     0,     0,    27,    25,    28,    29,    30,    31,    32,
      33,    34,    12,    17,     0,    42,    48,    46,     0,     0,
       0,    59,     0,    20,     0,    78,     0,     0,     0,     0,
       0,    74,    87,    84,    85,    86,     0,    76,    75,     0,
       0,    45,    49,    50,    51,     0,     0,     0,     0,    23,
       0,    18,    21,    79,    81,     0,    82,     0,    64,    65,
      77,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      43,    47,     0,    58,     0,    62,    36,    24,     0,     0,
      80,     0,    63,    68,     0,    66,    72,    70,    69,    71,
      67,    73,     0,     0,    53,     0,     0,    19,    22,    83,
      41,     0,     0,     0,    60,    61,    39,    38,    44,    26,
       0,     0,     0,    26,    40,     0,     0,    54,     0,     0,
      55,    56,    26,     0,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     6,     4,    33,     9,    10,    12,    16,    13,
      18,    19,    54,   108,    81,    82,    20,    34,    35,    36,
     114,   137,   141,    37,    69,   122,    38,    48,    39,    49,
      40,   124,   150,    41,    77,   104,    66,    67,    85,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
      14,  -121,  -121,    51,  -121,  -121,    49,  -121,  -121,  -121,
      26,     2,  -121,    45,  -121,  -121,    56,    46,  -121,    49,
      23,    48,  -121,    77,  -121,  -121,  -121,    83,    85,     4,
    -121,    86,     6,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,    88,    52,  -121,  -121,  -121,    64,    -8,
      66,    96,    52,  -121,     9,  -121,    27,    52,    52,    52,
      52,  -121,  -121,  -121,  -121,  -121,   118,  -121,  -121,    52,
      74,  -121,  -121,  -121,  -121,   101,   104,    52,   140,  -121,
      78,  -121,   106,  -121,  -121,    43,  -121,   147,    91,    91,
      91,    52,  -121,    52,    52,    52,    52,    52,    52,    52,
     154,  -121,   100,  -121,     3,   154,  -121,  -121,   110,     9,
    -121,   180,  -121,   166,   120,    91,   194,   183,   176,   185,
      -3,  -121,   111,   180,   117,   119,    52,  -121,  -121,  -121,
     122,   120,   115,   180,  -121,   154,  -121,  -121,  -121,  -121,
     121,   120,    67,  -121,  -121,   138,    90,   103,   139,   123,
    -121,  -121,  -121,    97,   146,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -121,  -121,  -121,  -121,     8,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,    72,  -121,  -120,  -110,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,   -51,  -121,  -121,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      86,    78,    72,    14,   130,    46,    87,    88,    89,    90,
      79,   125,   126,    51,     8,     1,    93,     2,   100,   142,
      52,   138,    99,   146,    25,    73,   105,    24,     7,    26,
      74,   144,   153,    83,    27,    15,    28,    47,    29,    30,
     113,    80,   115,   116,   117,   118,   119,   120,   121,   110,
      31,     5,   111,    55,     7,   129,    32,    56,    11,    57,
      84,    62,    63,    64,    65,    21,    22,   132,    25,    58,
      59,    17,     7,    70,    71,   135,    60,   140,    27,    23,
      28,    42,    29,    30,    43,    61,    62,    63,    64,    65,
      44,    25,    45,    50,    31,     7,    53,   145,    25,    75,
      32,    27,     7,    28,    76,    29,    30,   101,    27,   102,
      28,   107,    29,    30,   103,   109,    99,    31,   127,   131,
     148,    25,    91,    32,    31,     7,    92,   154,   123,   134,
      32,    27,   149,    28,   136,    29,    30,    93,    94,    95,
      96,    97,    98,    99,    91,   133,   139,    31,   147,   151,
     106,    91,   143,    32,   152,   112,   155,     0,    91,    93,
      94,    95,    96,    97,    98,    99,    93,    94,    95,    96,
      97,    98,    99,    93,    94,    95,    96,    97,    98,    99,
      91,   128,     0,     0,     0,    93,     0,    91,     0,    91,
      98,    99,     0,     0,     0,    93,    94,    95,    91,    97,
      98,    99,    93,    94,    93,    94,    97,    98,    99,    98,
      99,     0,     0,    93,    62,    63,    64,    65,    98,    99
};

static const yytype_int16 yycheck[] =
{
      56,    52,    10,     1,   114,     1,    57,    58,    59,    60,
       1,     8,     9,     7,     6,     1,    19,     3,    69,   139,
      14,   131,    25,   143,     1,    33,    77,    19,     5,     6,
      38,   141,   152,     6,    11,    33,    13,    33,    15,    16,
      91,    32,    93,    94,    95,    96,    97,    98,    99,     6,
      27,     0,     9,     1,     5,   111,    33,     5,    32,     7,
      33,    34,    35,    36,    37,     9,    10,   123,     1,    17,
      18,    26,     5,     9,    10,   126,    24,   133,    11,    33,
      13,    33,    15,    16,     7,    33,    34,    35,    36,    37,
       7,     1,     7,     7,    27,     5,     8,    30,     1,    33,
      33,    11,     5,    13,     8,    15,    16,    33,    11,     8,
      13,    33,    15,    16,    10,     9,    25,    27,     8,     8,
      30,     1,     4,    33,    27,     5,     8,    30,    28,    10,
      33,    11,    29,    13,    12,    15,    16,    19,    20,    21,
      22,    23,    24,    25,     4,    28,    31,    27,    10,    10,
      10,     4,    31,    33,    31,     8,    10,    -1,     4,    19,
      20,    21,    22,    23,    24,    25,    19,    20,    21,    22,
      23,    24,    25,    19,    20,    21,    22,    23,    24,    25,
       4,   109,    -1,    -1,    -1,    19,    -1,     4,    -1,     4,
      24,    25,    -1,    -1,    -1,    19,    20,    21,     4,    23,
      24,    25,    19,    20,    19,    20,    23,    24,    25,    24,
      25,    -1,    -1,    19,    34,    35,    36,    37,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    40,    42,     0,    41,     5,    43,    44,
      45,    32,    46,    48,     1,    33,    47,    26,    49,    50,
      55,     9,    10,    33,    43,     1,     6,    11,    13,    15,
      16,    27,    33,    43,    56,    57,    58,    62,    65,    67,
      69,    72,    33,     7,     7,     7,     1,    33,    66,    68,
       7,     7,    14,     8,    51,     1,     5,     7,    17,    18,
      24,    33,    34,    35,    36,    37,    75,    76,    78,    63,
       9,    10,    10,    33,    38,    33,     8,    73,    75,     1,
      32,    53,    54,     6,    33,    77,    78,    75,    75,    75,
      75,     4,     8,    19,    20,    21,    22,    23,    24,    25,
      75,    33,     8,    10,    74,    75,    10,    33,    52,     9,
       6,     9,     8,    75,    59,    75,    75,    75,    75,    75,
      75,    75,    64,    28,    70,     8,     9,     8,    53,    78,
      56,     8,    78,    28,    10,    75,    12,    60,    56,    31,
      78,    61,    55,    31,    56,    30,    55,    10,    30,    29,
      71,    10,    31,    55,    30,    10
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 122 "sintactico_semantico.y"
    {
	abrir_fichero1();
	escribir_cabecera();
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 129 "sintactico_semantico.y"
    {TS_InsertaMarca(); escribir_llaveA();;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 133 "sintactico_semantico.y"
    {TS_VaciarEntradas(); escribir_llaveC();;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 138 "sintactico_semantico.y"
    {escribir_variables(TipoEscrito((yyvsp[(1) - (3)]).tipo)); asignarTipoCascada((yyvsp[(1) - (3)]).tipo);
	if(((yyvsp[(1) - (3)]).tipo==4)||((yyvsp[(1) - (3)]).tipo==5)||((yyvsp[(1) - (3)]).tipo==6)||((yyvsp[(1) - (3)]).tipo==7)){
		dec_cons_pila(TipoEscrito((yyvsp[(1) - (3)]).tipo), (yyvsp[(2) - (3)]).lexema);
	};}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 143 "sintactico_semantico.y"
    {
		if(es_repetida((yyvsp[(1) - (1)]).lexema)==0){
			insertarIDENT(variable,(yyvsp[(1) - (1)]).lexema);
			(yyval).nombre=(yyvsp[(1) - (1)]).lexema;
			(yyval).lexema=(yyvsp[(1) - (1)]).lexema;
			if(pila==1){
				espila();
			}
		}
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 153 "sintactico_semantico.y"
    {
		if(es_repetida((yyvsp[(3) - (3)]).lexema)==0){
			insertarIDENT(variable,(yyvsp[(3) - (3)]).lexema);
			if(pila==1){
				espila();
			}
		}
		;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 166 "sintactico_semantico.y"
    { if(en_fun>0) en_fun=en_fun-1;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 168 "sintactico_semantico.y"
    {
	if(es_repetida((yyvsp[(2) - (3)]).lexema)==0){
		insertarIDENT(procedimiento,(yyvsp[(2) - (3)]).lexema); asignarTipo(vacio);}
	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 173 "sintactico_semantico.y"
    {
		CuentaParametros();
		;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 175 "sintactico_semantico.y"
    {
		en_fun=en_fun+1;
			escribe_void_argumentos((yyvsp[(2) - (7)]).lexema);
		;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 179 "sintactico_semantico.y"
    {
	en_fun=en_fun+1;
		if(es_repetida((yyvsp[(2) - (4)]).lexema)==0){
			insertarIDENT(procedimiento,(yyvsp[(2) - (4)]).lexema); asignarTipo(vacio);
			escribe_void_vacio((yyvsp[(2) - (4)]).lexema);
			}
	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 188 "sintactico_semantico.y"
    {(yyval).nombre=(yyvsp[(1) - (1)]).nombre;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 189 "sintactico_semantico.y"
    {strcat((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre);(yyval).nombre=(yyvsp[(1) - (3)]).nombre;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 192 "sintactico_semantico.y"
    {
	if(BuscarParametroRepetido((yyvsp[(2) - (2)]).lexema)==0){
		insertarIDENT(parametro,(yyvsp[(2) - (2)]).lexema);
		if(pila==1){
			asignarTipo(tipoEnPila((yyvsp[(1) - (2)]).tipo));
			pila=0;
			espila();
		}
		else {asignarTipo((yyvsp[(1) - (2)]).tipo);}
	}
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 216 "sintactico_semantico.y"
    {
	if(existe((yyvsp[(1) - (4)]).lexema)==0){
		printf("\nError Semantico en la linea %d: Identificador %s no esta declarado\n",yylineno,(yyvsp[(1) - (4)]).lexema);
	}
	else{
		(yyvsp[(1) - (4)]).tipo=get_tipo((yyvsp[(1) - (4)]).lexema);
		if((yyvsp[(1) - (4)]).tipo!=(yyvsp[(3) - (4)]).tipo){
			printf("\nError Semantico en la linea %d: Asignacion de tipos incompatibles, no se puede asignar un %s a un %s\n",yylineno, MostrarTipo((yyvsp[(3) - (4)]).tipo),MostrarTipo((yyvsp[(1) - (4)]).tipo));
		}
		else {
			escribe_asignacion((yyvsp[(1) - (4)]).lexema,(yyvsp[(3) - (4)]).nombre);
		}
	}
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 231 "sintactico_semantico.y"
    {
	if((yyvsp[(3) - (4)]).tipo!=booleano){
		printf("\nError Semantico en la linea %d: Se esperaba una sentencia de tipo boolean, no de tipo %s\n",yylineno,MostrarTipo((yyvsp[(3) - (4)]).tipo));
	}else{
		escribe_if((yyvsp[(3) - (4)]).nombre);
	}
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 237 "sintactico_semantico.y"
    {delete_descriptor();;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 239 "sintactico_semantico.y"
    {escribe_else();;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 239 "sintactico_semantico.y"
    {
	if(en_fun==0)
		fprintf(fichero1,"%s:\n",tablaControl[ind].EtiquetaSalida);
	else
		fprintf(fichero2,"%s:\n",tablaControl[ind].EtiquetaSalida);
	escribe_elemento(";");
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 246 "sintactico_semantico.y"
    {
		if(en_fun==0)
			fprintf(fichero1,"%s:\n",tablaControl[ind].EtiquetaElse);
		else
			fprintf(fichero2,"%s:\n",tablaControl[ind].EtiquetaElse);
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 253 "sintactico_semantico.y"
    {
	DescriptorControl d;
	genera_etiqueta(d.EtiquetaEntrada);
	escribe_elemento(d.EtiquetaEntrada); 
	escribe_elemento(":;");
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 258 "sintactico_semantico.y"
    {
		if((yyvsp[(4) - (4)]).tipo!=booleano){
			printf("\nError Semantico en la linea %d: Se esperaba una sentencia de tipo boolean, no de tipo %s\n",yylineno,MostrarTipo((yyvsp[(4) - (4)]).tipo));
		}else{
			escribe_while((yyvsp[(4) - (4)]).nombre);
		}
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 264 "sintactico_semantico.y"
    {fin_while();;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 266 "sintactico_semantico.y"
    {
	if(existe((yyvsp[(2) - (3)]).lexema)==0){
		printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,(yyvsp[(2) - (3)]).lexema);}
	else{
		(yyvsp[(2) - (3)]).tipo=get_tipo((yyvsp[(2) - (3)]).lexema);
		escribe_cin((yyvsp[(2) - (3)]).tipo,(yyvsp[(2) - (3)]).nombre);
	}
	if(es_pila((yyvsp[(2) - (3)]).tipo)==1){
		printf("\nError Semantico en la linea %d: No se puede introducir una pila.\n",yylineno);}
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 277 "sintactico_semantico.y"
    {(yyval).lexema=(yyvsp[(1) - (1)]).lexema;(yyval).nombre=(yyvsp[(1) - (1)]).lexema;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 278 "sintactico_semantico.y"
    {
	if(existe((yyvsp[(3) - (3)]).lexema)==0){
		printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,(yyvsp[(3) - (3)]).lexema);}
	else{
		(yyvsp[(3) - (3)]).tipo=get_tipo((yyvsp[(3) - (3)]).lexema);
	}
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 287 "sintactico_semantico.y"
    {
	if(es_pila((yyvsp[(2) - (3)]).tipo)==1){
		printf("\nError Semantico en la linea %d: No se puede mostrar una pila\n",yylineno);
	}
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 293 "sintactico_semantico.y"
    {
	if(es_pila((yyvsp[(2) - (2)]).tipo)==1){
		printf("\nError Semantico en la linea %d: No se puede mostrar una pila\n",yylineno);
	}
	else{
		escribe_cout((yyvsp[(2) - (2)]).tipo,(yyvsp[(2) - (2)]).lexema);
	}
;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 301 "sintactico_semantico.y"
    {(yyvsp[(2) - (2)]).tipo=cadena; escribe_cout((yyvsp[(2) - (2)]).tipo,(yyvsp[(2) - (2)]).lexema);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 304 "sintactico_semantico.y"
    {
	if((yyvsp[(3) - (5)]).tipo!=entero && (yyvsp[(3) - (5)]).tipo!=caracter){
		printf("\nError Semantico en la linea %d: Se esperaba un entero o caracter, no un %s\n",yylineno,MostrarTipo((yyvsp[(3) - (5)]).tipo));
	}else{
		tipoSwitch=(yyvsp[(3) - (5)]).tipo;}
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 311 "sintactico_semantico.y"
    {
		if((yyvsp[(2) - (6)]).tipo!=tipoSwitch){
			printf("\nError Semantico en la linea %d: Se esperaba un %s, no un %s\n",yylineno,MostrarTipo(tipoSwitch),MostrarTipo((yyvsp[(2) - (6)]).tipo));
		}
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 316 "sintactico_semantico.y"
    {
		if((yyvsp[(2) - (7)]).tipo!=tipoSwitch){
			printf("\nError Semantico en la linea %d: Se esperaba un %s, no un %s\n",yylineno,MostrarTipo(tipoSwitch),MostrarTipo((yyvsp[(2) - (7)]).tipo));
		}
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 321 "sintactico_semantico.y"
    {
		if((yyvsp[(3) - (7)]).tipo!=tipoSwitch){
			printf("\nError Semantico en la linea %d: Se esperaba un %s, no un %s\n",yylineno,MostrarTipo(tipoSwitch),MostrarTipo((yyvsp[(3) - (7)]).tipo));
		}
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 329 "sintactico_semantico.y"
    {
		if(existeProc((yyvsp[(1) - (4)]).lexema)==1){
			if(numParametros((yyvsp[(1) - (4)]).lexema)!=0){
				printf("\nError Semantico en la linea %d: El procedimiento %s esperaba %d argumentos.\n",yylineno,(yyvsp[(1) - (4)]).lexema,numParametros((yyvsp[(1) - (4)]).lexema));
			}else{
				escribe_elemento("\n");
				escribe_elemento((yyvsp[(1) - (4)]).lexema);
				escribe_elemento("();\n");
			}
		}
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 340 "sintactico_semantico.y"
    {
		nomproc=(yyvsp[(1) - (2)]).lexema;
		if(existeProc((yyvsp[(1) - (2)]).lexema)==1){
			numparam=numParametros((yyvsp[(1) - (2)]).lexema);}
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 345 "sintactico_semantico.y"
    {
		if(existeProc((yyvsp[(1) - (6)]).lexema)==1){
			if(numParametros((yyvsp[(1) - (6)]).lexema)!=argumentos){
					printf("\nError Semantico en la linea %d: El procedimiento %s esperaba %d argumentos.\n",yylineno,(yyvsp[(1) - (6)]).lexema,numParametros((yyvsp[(1) - (6)]).lexema));
			}
			else{
				escribe_elemento("\n");
				escribe_elemento((yyvsp[(1) - (6)]).lexema);
				escribe_elemento("(");
				escribe_elemento((yyvsp[(3) - (6)]).nombre);
				escribe_elemento(");\n");
			}
		}
		argumentos=1;
		numparam=0;
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 362 "sintactico_semantico.y"
    {
		(yyval).nargumentos=1+(yyvsp[(1) - (3)]).nargumentos;
		strcat((yyvsp[(1) - (3)]).nombre,",");
		strcat((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre);
		(yyval).nombre=(yyvsp[(1) - (3)]).nombre;
		if((yyval).nargumentos<=numparam){
			if(tipoParametro((yyval).nargumentos,nomproc)!=(yyvsp[(3) - (3)]).tipo){
				printf("\nError Semantico en la linea %d: El procedimiento %s esperaba un %s en el argumento %d.\n",yylineno,nomproc,MostrarTipo(tipoParametro((yyval).nargumentos,nomproc)),(yyval).nargumentos);
			}
		}
		argumentos++;	
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 374 "sintactico_semantico.y"
    {
		(yyval).nargumentos=1;
		(yyval).nombre=(yyvsp[(1) - (1)]).nombre;
		if((yyval).nargumentos<=numparam){
			if(tipoParametro((yyval).nargumentos,nomproc)!=(yyvsp[(1) - (1)]).tipo){
				printf("\nError Semantico en la linea %d: El procedimiento %s esperaba un %s en el argumento %d.\n",yylineno,nomproc,MostrarTipo(tipoParametro((yyval).nargumentos,nomproc)),(yyval).nargumentos);
			}
		}
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 384 "sintactico_semantico.y"
    {
		(yyval).tipo=(yyvsp[(2) - (3)]).tipo;
		(yyval).nombre=(yyvsp[(2) - (3)]).nombre;
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 388 "sintactico_semantico.y"
    {
		if((yyvsp[(2) - (2)]).tipo!=booleano && es_pila((yyvsp[(2) - (2)]).tipo)==0){
			printf("\nError Semantico en la linea %d: El operador %s es incompatible con tipo: %s, se esperaba booleano o pila.\n",yylineno,(yyvsp[(1) - (2)]).lexema,MostrarTipo((yyvsp[(2) - (2)]).tipo));}
		else{
			(yyval).tipo=(yyvsp[(2) - (2)]).tipo;
			escribe_expresionUna((yyvsp[(2) - (2)]).nombre,(yyvsp[(1) - (2)]).lexema,TipoEscrito((yyvsp[(2) - (2)]).tipo));
			copiaTo(temp,(yyval).nombre,11);
	};}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 396 "sintactico_semantico.y"
    {
		if(tipoEnPila((yyvsp[(2) - (2)]).tipo)!=entero && tipoEnPila((yyvsp[(2) - (2)]).tipo)!=real && tipoEnPila((yyvsp[(2) - (2)]).tipo)!=caracter && tipoEnPila((yyvsp[(2) - (2)]).tipo)!=booleano) {
			printf("\nError Semantico en la linea %d: El operador %s es incompatible con las pilas.\n",yylineno,(yyvsp[(1) - (2)]).lexema,MostrarTipo((yyvsp[(2) - (2)]).tipo));}
		else{
			if((yyvsp[(1) - (2)]).lexema!="#"){
				escribe_expresionUna((yyvsp[(2) - (2)]).nombre,"sac",TipoEscrito((yyvsp[(2) - (2)]).tipo));
			}else{
				(yyvsp[(2) - (2)]).tipo=tipoEnPila((yyvsp[(2) - (2)]).tipo);
				escribe_expresionUna((yyvsp[(2) - (2)]).nombre,"top",TipoEscrito((yyvsp[(2) - (2)]).tipo));
				}
			(yyval).tipo=(yyvsp[(2) - (2)]).tipo;
			(yyval).nombre=(yyvsp[(2) - (2)]).nombre;
			copiaTo(temp,(yyval).nombre,11);
	};}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 410 "sintactico_semantico.y"
    {
	//Valor y pila (solo el *)
	if(es_pila((yyvsp[(3) - (3)]).tipo)==0 && es_pila((yyvsp[(3) - (3)]).tipo)==1){
		if((yyvsp[(1) - (3)]).tipo!=tipoEnPila((yyvsp[(3) - (3)]).tipo)){
			printf("\nError Semantico en la linea %d:Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
			correcto=0;
		}else{
			if((yyvsp[(1) - (3)]).tipo!=entero && (yyvsp[(1) - (3)]).tipo!=real){
				printf("\nError Semantico en la linea %d: No se puede aplicar el operador %s a %s%s%s.\n",yylineno,(yyvsp[(2) - (3)]).lexema,MostrarTipo((yyvsp[(1) - (3)]).tipo),(yyvsp[(2) - (3)]).lexema,MostrarTipo((yyvsp[(3) - (3)]).tipo));
			}
			else{
				(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
			}
		}
		correcto=1;
	}
	//Dos pilas
	if(es_pila((yyvsp[(1) - (3)]).tipo)==1 && es_pila((yyvsp[(3) - (3)]).tipo)==1){
		if(tipoEnPila((yyvsp[(1) - (3)]).tipo)!=tipoEnPila((yyvsp[(3) - (3)]).tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo(tipoEnPila((yyvsp[(1) - (3)]).tipo)),MostrarTipo(tipoEnPila((yyvsp[(3) - (3)]).tipo)));
		}
		else{
			(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
			correcto=1;
		}
	}
	//Pila y valor
	if(es_pila((yyvsp[(1) - (3)]).tipo)==1 && es_pila((yyvsp[(3) - (3)]).tipo)==0){
		if(tipoEnPila((yyvsp[(1) - (3)]).tipo)!=(yyvsp[(3) - (3)]).tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
		}
		else{
			(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
			correcto=1;
		}
	}
	//Dos Valores
	if(es_pila((yyvsp[(1) - (3)]).tipo)==0 && es_pila((yyvsp[(3) - (3)]).tipo)==0){
		if((yyvsp[(1) - (3)]).tipo!=(yyvsp[(3) - (3)]).tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
		}
		else{
			(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
			escribe_expresionBin((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre,(yyvsp[(2) - (3)]).lexema,TipoEscrito((yyvsp[(1) - (3)]).tipo));
			copiaTo(temp,(yyval).nombre,11);
			correcto=1;
		}
	}
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 459 "sintactico_semantico.y"
    {
	if(es_pila((yyvsp[(3) - (3)]).tipo)==1){
		//Dos pilas
		if(es_pila((yyvsp[(1) - (3)]).tipo)==1 && es_pila((yyvsp[(3) - (3)]).tipo)==1){
			if(tipoEnPila((yyvsp[(1) - (3)]).tipo)!=tipoEnPila((yyvsp[(3) - (3)]).tipo)){
				printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo(tipoEnPila((yyvsp[(1) - (3)]).tipo)),MostrarTipo(tipoEnPila((yyvsp[(3) - (3)]).tipo)));
			}
			else{
				(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
				escribe_sumres_pp((yyvsp[(1) - (3)]).nombre,(yyvsp[(2) - (3)]).nombre,(yyvsp[(1) - (3)]).tipo);
				copiaTo(temp, (yyval).nombre,11);
				correcto=1;
			}
		}
			//Valor y pila (solo el +)
		if((yyvsp[(1) - (3)]).tipo!=tipoEnPila((yyvsp[(3) - (3)]).tipo)){
			printf("\nError Semantico en la linea %d:Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
			correcto=0;
		}
	}else{
		if((yyvsp[(1) - (3)]).tipo!=(yyvsp[(3) - (3)]).tipo){
			printf("\nError Semantico en la linea %d: No se puede aplicar el operador %s a %s%s%s.\n",yylineno,(yyvsp[(2) - (3)]).lexema,MostrarTipo((yyvsp[(1) - (3)]).tipo),(yyvsp[(2) - (3)]).lexema,MostrarTipo((yyvsp[(3) - (3)]).tipo));
			}
			else{
				(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
			}
		}
		correcto=1;
	//Pila y valor
	if(es_pila((yyvsp[(1) - (3)]).tipo)==1 && es_pila((yyvsp[(3) - (3)]).tipo)==0){
		if(tipoEnPila((yyvsp[(1) - (3)]).tipo)!=(yyvsp[(3) - (3)]).tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
		}
		else{
			(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
			correcto=1;
		}
	}
	//Dos Valores
	if(es_pila((yyvsp[(1) - (3)]).tipo)==0 && es_pila((yyvsp[(3) - (3)]).tipo)==0){
		if((yyvsp[(1) - (3)]).tipo!=(yyvsp[(3) - (3)]).tipo){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
		}
		else{
			(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
			escribe_expresionBin((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre,(yyvsp[(2) - (3)]).lexema,TipoEscrito((yyvsp[(1) - (3)]).tipo));
			copiaTo(temp,(yyval).nombre,11);
			correcto=1;
		}
	}
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 510 "sintactico_semantico.y"
    {
		if((((yyvsp[(1) - (3)]).tipo!=entero) && ((yyvsp[(1) - (3)]).tipo!=real)) || (((yyvsp[(3) - (3)]).tipo!=entero) && ((yyvsp[(3) - (3)]).tipo!=real))){
			printf("\nError Semantico en la linea %d: El operador %s se esta utilizando como: %s%s%s, se esperaba int%sint o real%sreal.\n",yylineno,(yyvsp[(2) - (3)]).lexema,MostrarTipo((yyvsp[(1) - (3)]).tipo),(yyvsp[(2) - (3)]).lexema,MostrarTipo((yyvsp[(3) - (3)]).tipo),(yyvsp[(2) - (3)]).lexema,(yyvsp[(2) - (3)]).lexema);
			correcto=0;
		}
		else{
			if(((yyvsp[(1) - (3)]).tipo)!=((yyvsp[(3) - (3)]).tipo)){
				printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
				correcto=0;
			}
		}
		if(correcto==1){
			(yyval).tipo=booleano;
			escribe_expresionBin((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre,(yyvsp[(2) - (3)]).lexema,"int");
			copiaTo(temp,(yyval).nombre,11);
		}
		else{
			correcto=1;
			(yyval).tipo=booleano;
		}
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 531 "sintactico_semantico.y"
    {
		if(((yyvsp[(1) - (3)]).tipo)!=((yyvsp[(3) - (3)]).tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
				correcto=0;
		}
		if(correcto==1)
			(yyval).tipo=booleano;
		else{
			correcto=1;
			(yyval).tipo=booleano;
		}
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 543 "sintactico_semantico.y"
    {
		if(((yyvsp[(1) - (3)]).tipo)!=((yyvsp[(3) - (3)]).tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
				correcto=0;
		}
		if(correcto==1){
			(yyval).tipo=booleano;
			escribe_expresionBin((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre,(yyvsp[(2) - (3)]).lexema,"int");
			copiaTo(temp,(yyval).nombre,11);
		}else{
			correcto=1;
			(yyval).tipo=booleano;
		}
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 557 "sintactico_semantico.y"
    {
		if(((yyvsp[(1) - (3)]).tipo)!=((yyvsp[(3) - (3)]).tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
				correcto=0;
		}
		if(correcto==1){
			(yyval).tipo=booleano;
			escribe_expresionBin((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre,(yyvsp[(2) - (3)]).lexema,"int");
			copiaTo(temp,(yyval).nombre,11);
		}else{
			correcto=1;
			(yyval).tipo=booleano;
		}
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 571 "sintactico_semantico.y"
    {
		if(((yyvsp[(1) - (3)]).tipo)!=((yyvsp[(3) - (3)]).tipo)){
			printf("\nError Semantico en la linea %d: Tipos incompatibles: %s incompatible con %s.\n",yylineno,MostrarTipo((yyvsp[(1) - (3)]).tipo),MostrarTipo((yyvsp[(3) - (3)]).tipo));
				correcto=0;
		}
		if(correcto==1){
			(yyval).tipo=booleano;
			escribe_expresionBin((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre,(yyvsp[(2) - (3)]).lexema,"int");
			copiaTo(temp,(yyval).nombre,11);
		}else{
			correcto=1;
		}
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 584 "sintactico_semantico.y"
    {
		if(es_pila((yyvsp[(1) - (3)]).tipo)==1){
			if(tipoEnPila((yyvsp[(1) - (3)]).tipo)!=(yyvsp[(3) - (3)]).tipo){
				printf("\nError Semantico en la linea %d: No se puede aplicar el operador %s a %s%s%s.\n",yylineno,(yyvsp[(2) - (3)]).lexema,MostrarTipo(tipoEnPila((yyvsp[(1) - (3)]).tipo)),(yyvsp[(2) - (3)]).lexema,MostrarTipo(tipoEnPila((yyvsp[(3) - (3)]).tipo)));
				correcto=0;
			}
		}
		else{
			printf("La expresion no es una pila \n");
		}
		correcto=1;
		(yyval).tipo=(yyvsp[(1) - (3)]).tipo;
		escribe_expresionBin((yyvsp[(1) - (3)]).nombre,(yyvsp[(3) - (3)]).nombre,"ins",TipoEscrito((yyvsp[(1) - (3)]).tipo));
		copiaTo(temp,(yyval).nombre,11);
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 599 "sintactico_semantico.y"
    {
		if(existe((yyvsp[(1) - (1)]).lexema)==0){
			printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,(yyvsp[(1) - (1)]).lexema);}
		else{
			(yyval).tipo=get_tipo((yyvsp[(1) - (1)]).lexema);
			(yyval).nombre=(yyvsp[(1) - (1)]).lexema;
		}
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 607 "sintactico_semantico.y"
    {(yyval).tipo=(yyvsp[(1) - (1)]).tipo; (yyval).nombre=(yyvsp[(1) - (1)]).nombre;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 608 "sintactico_semantico.y"
    {(yyval).tipo=tipoPila((yyvsp[(1) - (1)]).tipo);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 609 "sintactico_semantico.y"
    {
		if(((yyvsp[(2) - (2)]).tipo!=entero) && ((yyvsp[(2) - (2)]).tipo!=real)){
			printf("\nError Semantico en la linea %d: El operador %s es incompatible con tipo %s, se esperaba entero o real.\n",yylineno,(yyvsp[(1) - (2)]).lexema,MostrarTipo((yyvsp[(2) - (2)]).tipo));
		}
		else{
			(yyval).tipo=(yyvsp[(2) - (2)]).tipo;
			escribe_expresionUna((yyvsp[(2) - (2)]).nombre,(yyvsp[(1) - (2)]).lexema,TipoEscrito((yyvsp[(2) - (2)]).tipo));
			copiaTo(temp,(yyval).nombre,11);
		}
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 622 "sintactico_semantico.y"
    {
		if(es_pila((yyvsp[(2) - (3)]).tipo)==1){
			printf("\nError Semantico en la linea %d: No se puede usar una pila dentro de otra pila.\n",yylineno);}
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 627 "sintactico_semantico.y"
    {
		if(existe((yyvsp[(1) - (1)]).lexema)==0){
			printf("\nError Semantico en la linea %d: Identificador %s no declarado\n",yylineno,(yyvsp[(1) - (1)]).lexema);}
		else{
			(yyval).tipo=get_tipo((yyvsp[(1) - (1)]).lexema);
		}
	;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 634 "sintactico_semantico.y"
    {(yyval).tipo=(yyvsp[(1) - (1)]).tipo; (yyval).nombre=(yyvsp[(1) - (1)]).nombre;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 635 "sintactico_semantico.y"
    {
		if((yyvsp[(3) - (3)]).tipo!=(yyvsp[(1) - (3)]).tipo){
			printf("\nError Semantico en la linea %d: Incompatibilidad de tipos en la pila. Se esperaba %s y se introdujo %s.\n",yylineno,MostrarTipo((yyvsp[(3) - (3)]).tipo),MostrarTipo((yyvsp[(1) - (3)]).tipo));}
		else{
			(yyval).tipo=(yyvsp[(3) - (3)]).tipo;
		}
	;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 643 "sintactico_semantico.y"
    {(yyval).tipo=(yyvsp[(1) - (1)]).tipo;(yyval).nombre=(yyvsp[(1) - (1)]).lexema;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 644 "sintactico_semantico.y"
    {(yyval).tipo=(yyvsp[(1) - (1)]).tipo;(yyval).nombre=(yyvsp[(1) - (1)]).lexema;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 645 "sintactico_semantico.y"
    {(yyval).tipo=(yyvsp[(1) - (1)]).tipo;(yyval).nombre=(yyvsp[(1) - (1)]).lexema;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 646 "sintactico_semantico.y"
    {(yyval).tipo=(yyvsp[(1) - (1)]).tipo;
		if((yyvsp[(1) - (1)]).atrib==0)
			(yyval).nombre="1";
		else
			(yyval).nombre="0";
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2380 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 653 "sintactico_semantico.y"
	
/** aqui incluimos el fichero generado por el 'lex'
*** que implementa la función 'yylex'
**/

#ifdef DOSWINDOWS /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

/** se debe implementar la función yyerror. En este caso
*** simplemente escribimos el mensaje de error en pantalla
**/

void yyerror( char *msg )
{
	fprintf(stderr,"[Linea %d]: %s\n", nlineas, msg);
}



