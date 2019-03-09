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
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
	extern FILE *yyin;
	int yydebug=1;
	extern int yylineno;
	void * root;

#line 76 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
/* "%code requires" blocks.  */
#line 15 "parser.y" /* yacc.c:355  */

	#include "ast.h"

#line 110 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    id = 258,
    STRINGLITERAL = 259,
    INTEGERLITERAL = 260,
    FOR = 261,
    CLASS = 262,
    PUBLIC = 263,
    STATIC = 264,
    VOID = 265,
    MAIN = 266,
    STRING = 267,
    EXTENDS = 268,
    RETURN = 269,
    INT = 270,
    BOOLEAN = 271,
    IF = 272,
    ELSE = 273,
    WHILE = 274,
    PRINT = 275,
    PRINTLN = 276,
    LENGTH = 277,
    TRUE = 278,
    FALSE = 279,
    THIS = 280,
    NEW = 281,
    AND = 282,
    OR = 283,
    LESSTHANEQ = 284,
    GREATTHANEQ = 285,
    EQ = 286,
    NOTEQ = 287
  };
#endif
/* Tokens.  */
#define id 258
#define STRINGLITERAL 259
#define INTEGERLITERAL 260
#define FOR 261
#define CLASS 262
#define PUBLIC 263
#define STATIC 264
#define VOID 265
#define MAIN 266
#define STRING 267
#define EXTENDS 268
#define RETURN 269
#define INT 270
#define BOOLEAN 271
#define IF 272
#define ELSE 273
#define WHILE 274
#define PRINT 275
#define PRINTLN 276
#define LENGTH 277
#define TRUE 278
#define FALSE 279
#define THIS 280
#define NEW 281
#define AND 282
#define OR 283
#define LESSTHANEQ 284
#define GREATTHANEQ 285
#define EQ 286
#define NOTEQ 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "parser.y" /* yacc.c:355  */

	AST_Node * node;

#line 190 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 207 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,     2,     2,
      41,    44,    35,    33,    47,    34,    49,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
      37,    48,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    41,    42,    46,    51,    52,    56,    57,
      61,    62,    66,    67,    71,    72,    76,    77,    81,    82,
      86,    90,    91,    95,    96,    97,   101,   102,   103,   107,
     108,   112,   113,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   131,   132,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   163,   164,   165,   166,   169,   170,   171,   174,   175,
     178,   179,   182
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "id", "STRINGLITERAL", "INTEGERLITERAL",
  "FOR", "CLASS", "PUBLIC", "STATIC", "VOID", "MAIN", "STRING", "EXTENDS",
  "RETURN", "INT", "BOOLEAN", "IF", "ELSE", "WHILE", "PRINT", "PRINTLN",
  "LENGTH", "TRUE", "FALSE", "THIS", "NEW", "AND", "OR", "LESSTHANEQ",
  "GREATTHANEQ", "EQ", "NOTEQ", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'",
  "'!'", "'{'", "'('", "'['", "']'", "')'", "'}'", "';'", "','", "'='",
  "'.'", "$accept", "Program", "ClassDeclList", "MainClass", "ClassDecl",
  "VarDeclList", "VarDecl", "MethodDeclList", "MethodDecl", "FormalList",
  "FormalRestList", "FormalRest", "Type", "PrimType", "TypePrime",
  "PrimTypePrime", "StatementList", "Statement", "Index", "Exp", "Object",
  "ObjectPrime", "ExpList", "ExpRestList", "ExpRest", YY_NULLPTR
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
     285,   286,   287,    43,    45,    42,    47,    60,    62,    33,
     123,    40,    91,    93,    41,   125,    59,    44,    61,    46
};
# endif

#define YYPACT_NINF -77

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    14,    39,   -77,    30,   -77,    57,    77,    89,   -77,
      78,    -9,    83,    93,   -77,    87,    61,    21,    65,   -77,
       3,   -77,   -77,   -77,    -3,     4,   -77,    90,    21,    80,
      81,    79,   -77,   -77,    92,    82,    97,    22,   -77,   -77,
     -77,   -77,   -77,     5,   -77,   -77,   -77,    86,   -77,    95,
      91,   127,    79,   -77,    96,   104,     6,   109,   110,   -77,
     203,   -77,   106,    23,   166,   113,   114,   115,   117,    60,
     116,   194,    79,   -77,   166,   166,    36,   -24,   -77,   -77,
     -77,   111,    88,   166,   166,   166,   166,   217,   -77,   121,
     166,   166,   118,   142,   -77,    69,   -77,   119,    20,   166,
     216,     7,   407,   237,   166,   166,    12,    24,   122,   120,
     453,   453,   -77,   317,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   -77,   169,   335,   353,
     129,   371,   130,   389,   -77,   -77,   -77,    94,   257,   166,
     -77,   -77,   -77,   424,   277,   136,   -77,   156,   135,    27,
     -77,   -18,   -18,    84,    84,   -77,   149,   453,   453,   465,
     465,   230,   230,   141,   203,   203,   138,   139,   140,   147,
     143,   297,   -77,   -77,   166,   -77,   145,   166,   177,   -77,
     -77,   -77,   -77,   -77,   -77,   151,   441,   154,   157,   203,
     -77,   155,   -77,   -77,   -77,   166,   -77,   441
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     0,     0,     3,
       0,     0,     0,     0,     9,     0,     0,    13,     0,     9,
       0,    29,    30,     8,     0,     0,    26,     0,    13,     0,
       0,     0,     6,    12,     0,     0,     0,     0,    11,    28,
      25,    23,    24,     0,    21,    10,    27,     0,     7,     0,
       0,     0,    17,    22,     0,     0,     0,     0,     0,    19,
       0,     9,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,    71,    61,    62,
      63,    72,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,    34,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    25,     0,
      60,    59,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,    33,    31,     5,     0,     0,     0,
      20,    44,    41,     0,     0,     0,    67,     0,     0,    74,
      65,    46,    47,    50,    51,    48,    49,    54,    55,    56,
      57,    52,    53,     0,     0,     0,     0,     0,     0,     0,
      43,     0,    45,    42,    79,    68,    73,    79,     0,    36,
      40,    39,    38,    37,    15,    43,    81,     0,     0,     0,
      14,    78,    69,    70,    35,     0,    80,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   -77,   -17,   -77,   159,   -77,   -77,
     -77,   -77,   -40,   134,   -77,   -77,   132,   -57,   -76,   -64,
     -77,   -77,    35,   -77,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     3,     9,    17,    23,    24,    33,    55,
      62,    73,    43,    44,    25,    26,    95,    96,    76,   102,
      88,    89,   187,   191,   196
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,   107,    28,    70,    13,    31,    29,    34,    49,    59,
     140,   103,    56,   118,   119,   145,     1,     4,    74,   110,
     111,   112,   113,    29,    20,   106,   128,   129,   131,   133,
      31,    14,   101,   149,   146,   138,    21,    22,   135,     5,
     143,   144,    32,   135,    71,    30,    35,    50,    50,    50,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   137,    63,     8,    74,   104,    48,    75,   104,
       7,    75,    63,   147,    64,   171,   -77,    65,   104,    66,
      67,    68,    40,    64,   105,    10,    65,    12,    66,    67,
      68,   108,    11,    15,    41,    42,    16,    77,    18,    78,
      69,    19,    36,    41,    42,    94,    27,   178,   179,    69,
     186,   114,   115,   186,   134,   118,   119,    79,    80,    81,
      82,    77,   130,    78,    39,    46,    38,    83,    84,    51,
      54,   197,   194,    85,    53,    86,    52,    39,    45,    47,
      57,    79,    80,    81,    82,    77,   132,    78,    58,    60,
      61,    83,    84,    72,    90,    91,    92,    85,    93,    86,
     -75,    97,    74,   148,   136,    79,    80,    81,    82,    77,
     127,    78,   163,   166,   168,    83,    84,   174,   175,   176,
     118,    85,   177,    86,   180,   181,   182,    37,   184,    79,
      80,    81,    82,   183,   -76,   189,   190,    98,   192,    83,
      84,   193,   195,   100,     0,    85,    63,    86,    99,    21,
      22,    65,   188,    66,    67,    68,   109,    64,     0,    63,
      65,     0,    66,    67,    68,     0,     0,     0,     0,     0,
     139,     0,     0,    65,    69,    66,    67,    68,     0,     0,
       0,     0,     0,    69,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    69,   114,   115,   116,
     117,   118,   119,   126,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,   142,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,   170,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,   173,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,   185,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,   150,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,     0,     0,   164,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     0,     0,     0,     0,     0,   165,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       0,     0,     0,     0,     0,   167,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     0,     0,
       0,     0,     0,   169,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
     141,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,   172,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     114,   115,   116,   117,   118,   119,     0,     0,   122,   123,
     124,   125,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,   124,   125
};

static const yytype_int16 yycheck[] =
{
      64,    77,    19,    60,    13,     8,     3,     3,     3,     3,
       3,    75,    52,    31,    32,     3,     7,     3,    42,    83,
      84,    85,    86,     3,     3,    49,    90,    91,    92,    93,
       8,    40,    72,   109,    22,    99,    15,    16,    95,     0,
     104,   105,    45,   100,    61,    42,    42,    42,    42,    42,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    42,     3,     7,    42,    42,    45,    48,    42,
      40,    48,     3,    49,    14,   139,    49,    17,    42,    19,
      20,    21,     3,    14,    48,     8,    17,     9,    19,    20,
      21,     3,     3,    10,    15,    16,     3,     3,    11,     5,
      40,    40,    12,    15,    16,    45,    41,   164,   165,    40,
     174,    27,    28,   177,    45,    31,    32,    23,    24,    25,
      26,     3,     4,     5,    43,    43,    46,    33,    34,    43,
       3,   195,   189,    39,    43,    41,    41,    43,    46,    42,
      44,    23,    24,    25,    26,     3,     4,     5,    44,    40,
      40,    33,    34,    47,    41,    41,    41,    39,    41,    41,
      49,    45,    42,    41,    45,    23,    24,    25,    26,     3,
      49,     5,     3,    44,    44,    33,    34,    41,    22,    44,
      31,    39,    41,    41,    46,    46,    46,    28,    45,    23,
      24,    25,    26,    46,    49,    18,    45,     3,    44,    33,
      34,    44,    47,    71,    -1,    39,     3,    41,    14,    15,
      16,    17,   177,    19,    20,    21,    82,    14,    -1,     3,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    17,    40,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    40,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    40,    27,    28,    29,
      30,    31,    32,    46,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    44,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    44,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      43,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    43,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      27,    28,    29,    30,    31,    32,    -1,    -1,    35,    36,
      37,    38,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    51,    53,     3,     0,    52,    40,     7,    54,
       8,     3,     9,    13,    40,    10,     3,    55,    11,    40,
       3,    15,    16,    56,    57,    64,    65,    41,    55,     3,
      42,     8,    45,    58,     3,    42,    12,    57,    46,    43,
       3,    15,    16,    62,    63,    46,    43,    42,    45,     3,
      42,    43,    41,    43,     3,    59,    62,    44,    44,     3,
      40,    40,    60,     3,    14,    17,    19,    20,    21,    40,
      67,    55,    47,    61,    42,    48,    68,     3,     5,    23,
      24,    25,    26,    33,    34,    39,    41,    69,    70,    71,
      41,    41,    41,    41,    45,    66,    67,    45,     3,    14,
      66,    62,    69,    69,    42,    48,    49,    68,     3,    63,
      69,    69,    69,    69,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    46,    49,    69,    69,
       4,    69,     4,    69,    45,    67,    45,    42,    69,    14,
       3,    43,    46,    69,    69,     3,    22,    49,    41,    68,
      44,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,     3,    44,    44,    44,    44,    44,    44,
      46,    69,    43,    46,    41,    22,    44,    41,    67,    67,
      46,    46,    46,    46,    45,    46,    69,    72,    72,    18,
      45,    73,    44,    44,    67,    47,    74,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,    17,     6,     8,     2,     0,
       3,     3,     2,     0,    13,    12,     3,     0,     2,     0,
       3,     1,     3,     1,     1,     1,     1,     3,     3,     1,
       1,     2,     1,     3,     2,     7,     5,     5,     5,     5,
       5,     4,     5,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     1,     1,     1,     1,     3,     2,     3,     4,     6,
       6,     1,     1,     4,     3,     1,     4,     3,     2,     0,
       2,     0,     2
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
        case 2:
#line 37 "parser.y" /* yacc.c:1646  */
    { root = mknode2(PROGRAM, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 41 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(CLASSDECLLIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 42 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(CLASSDECLLIST); }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 47 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode3(MAINCLASS, (yyvsp[-15].node), (yyvsp[-5].node), (yyvsp[-2].node)); }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 51 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode3(CLASSDECL, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 52 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode4(CLASSDECL, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 56 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(VARDECLLIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(VARDECLLIST); }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(VARDECL, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 62 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(VARDECL, mknode1(TYPE, mknode1(PRIMTYPE, (yyvsp[-2].node))), (yyvsp[-1].node)); }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 66 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(METHODDECLLIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 67 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(METHODDECLLIST); }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 71 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode6(METHODDECL, (yyvsp[-11].node), (yyvsp[-10].node), (yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node)); }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode5(METHODDECL, (yyvsp[-10].node), (yyvsp[-9].node), (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-2].node)); }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 76 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode3(FORMALLIST, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(FORMALLIST); }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 81 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(FORMALRESTLIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(FORMALRESTLIST); }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 86 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(FORMALREST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(TYPEPRIM, (yyvsp[0].node)); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(TYPEARR, (yyvsp[-2].node)); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(PRIMTYPEINT); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 96 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(PRIMTYPEBOOL); }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(PRIMTYPEID, (yyvsp[0].node)); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(TYPEPRIM, (yyvsp[0].node)); }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(TYPEARR, (yyvsp[-2].node)); }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(TYPEARR, mknode1(TYPEPRIM, mknode1(PRIMTYPEID, (yyvsp[-2].node)))); }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(PRIMTYPEINT); }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(PRIMTYPEBOOL); }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(STATEMENTLIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(STATEMENTLIST, (yyvsp[0].node)); }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(BLOCK, (yyvsp[-1].node)); }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(BLOCK); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode3(IF, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(WHILE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(PRINTLNEXP, (yyvsp[-2].node)); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(PRINTLNSTR, (yyvsp[-2].node)); }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(PRINTEXP, (yyvsp[-2].node)); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(PRINTSTR, (yyvsp[-2].node)); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(ASSGN, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode3(ARRASSGN, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(RET, (yyvsp[-1].node)); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(INDEX, (yyvsp[-1].node)); }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(INDEX, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(EQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(NOTEQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(LESSTHANEQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(GREATTHANEQ, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(LESSTHAN, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(GREATTHAN, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(PLUS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(MINUS, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(TIMES, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(DIVIDE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(NEGATE, (yyvsp[0].node)); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(MINUS, (yyvsp[0].node)); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(PLUS, (yyvsp[0].node)); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(EXPINT, (yyvsp[0].node)); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(TRUE); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(FALSE); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(EXPOBJECT, (yyvsp[0].node)); }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(PAREN, (yyvsp[-1].node)); }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(ARRLOOKUP, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(IDENTIFIERLEN, (yyvsp[-2].node)); }
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(ARRLEN, (yyvsp[-3].node), (yyvsp[-2].node)); }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode3(CALL, mknode1(OBJID, (yyvsp[-5].node)), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode3(CALL, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(OBJID, (yyvsp[0].node)); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(THIS); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(NEWOBJ, (yyvsp[-2].node)); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(NEWARR, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(THIS); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(NEWOBJ, (yyvsp[-2].node)); }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(NEWARR, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(EXPLIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(EXPLIST); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode2(EXPRESTLIST, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode0(EXPRESTLIST); }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = mknode1(EXPREST, (yyvsp[0].node)); }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1957 "y.tab.c" /* yacc.c:1646  */
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
#line 185 "parser.y" /* yacc.c:1906  */

#include "dfs.h"

void yyerror(char *s) {
	fprintf(stderr, "Syntax errors in %d\n", yylineno);
}

int main(int argc, char **argv) {
	++argv, --argc;
	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
	yyparse();
	dfs(root);
	return 0;
}
