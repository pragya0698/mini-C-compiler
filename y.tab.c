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
#line 1 "cd2Inter.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbol.c"

int yylex();
int yyerror();
int ob=0, cb=0; //opening bracket and closing bracket
int scope=0, scope_count = 0, line_no, op,op4,op1, for_loop_exp2 = 0, l, res = 0, valid=1;
char res2[10];

int recurse(char *text, int);
int search(char *text,int );
char keywords[8][7]={"char","int","float","void","main","for","if","else"};

void sym_init(struct symbol **second);
void change_line(char *id,int line_no,int scope);
void add_value(char *value, char *id_name,int scope);
void AddQuadruple(char op[5],char arg1[10],char arg2[10],char result[10],char res[10]);
int toInt(char *a);	
int check_type(char*);
void optimisation();
void checker(char *val1,char *val2);
void create_label(char op[5],char arg1[10],char arg2[10],char result[10]);
struct symbol *first;
char m[20], k[10], *id, *s, *id_val,lab[20];

struct quad
	{
		char op[5];
		char arg1[10];
		char arg2[10];
		char result[10];
	}QUAD[30];

struct stack 
	{
		int items[100];
		int top;
	}stk;


	int Index=0;
	int tIndex=0; 
	int lIndex=0;
	int StNo;
	int Ind; 
	int tInd;





#line 121 "y.tab.c" /* yacc.c:339  */

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IDENTIFIER = 258,
    T_CONSTANT = 259,
    T_STRINGLITERAL = 260,
    T_INCLUDE = 261,
    T_MAIN = 262,
    T_INC = 263,
    T_DEC = 264,
    T_LEFT_SHIFT = 265,
    T_RIGHT_SHIFT = 266,
    T_LE = 267,
    T_GE = 268,
    T_EQ = 269,
    T_NE = 270,
    T_AND = 271,
    T_OR = 272,
    T_SHORT_MUL = 273,
    T_SHORT_DIV = 274,
    T_SHORT_MOD = 275,
    T_SHORT_ADD = 276,
    T_SHORT_SUB = 277,
    T_SHORT_LEFT = 278,
    T_SHORT_SHIFT = 279,
    T_SHORT_AND = 280,
    T_SHORT_XOR = 281,
    T_SHORT_OR = 282,
    TYPE_NAME = 283,
    T_ELLIPSIS = 284,
    T_NEWLINE = 285,
    T_CHAR = 286,
    T_INT = 287,
    T_FLOAT = 288,
    T_DOUBLE = 289,
    T_VOID = 290,
    T_IF = 291,
    T_ELSE = 292,
    T_FOR = 293,
    T_BREAK = 294,
    T_RETURN = 295,
    T_CONTINUE = 296,
    T_WHILE = 297
  };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_CONSTANT 259
#define T_STRINGLITERAL 260
#define T_INCLUDE 261
#define T_MAIN 262
#define T_INC 263
#define T_DEC 264
#define T_LEFT_SHIFT 265
#define T_RIGHT_SHIFT 266
#define T_LE 267
#define T_GE 268
#define T_EQ 269
#define T_NE 270
#define T_AND 271
#define T_OR 272
#define T_SHORT_MUL 273
#define T_SHORT_DIV 274
#define T_SHORT_MOD 275
#define T_SHORT_ADD 276
#define T_SHORT_SUB 277
#define T_SHORT_LEFT 278
#define T_SHORT_SHIFT 279
#define T_SHORT_AND 280
#define T_SHORT_XOR 281
#define T_SHORT_OR 282
#define TYPE_NAME 283
#define T_ELLIPSIS 284
#define T_NEWLINE 285
#define T_CHAR 286
#define T_INT 287
#define T_FLOAT 288
#define T_DOUBLE 289
#define T_VOID 290
#define T_IF 291
#define T_ELSE 292
#define T_FOR 293
#define T_BREAK 294
#define T_RETURN 295
#define T_CONTINUE 296
#define T_WHILE 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 57 "cd2Inter.y" /* yacc.c:355  */

	int value;
	char *text;
	char *str;
	

#line 252 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 269 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

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
       2,     2,     2,    52,     2,     2,     2,    54,    48,     2,
      45,    46,    49,    43,    47,    50,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    61,
      55,    44,    56,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,    58,    63,    51,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    85,    89,    94,    97,   101,   103,   105,
     108,   146,   147,   148,   151,   152,   153,   154,   165,   178,
     179,   182,   183,   184,   185,   188,   189,   190,   191,   192,
     193,   196,   197,   200,   201,   208,   217,   224,   225,   230,
     237,   238,   239,   242,   243,   250,   261,   262,   272,   284,
     285,   287,   288,   291,   292,   295,   296,   299,   300,   303,
     304,   307,   308,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   328,   329,   331,   332,   335,   336,
     338,   339,   342,   343,   358,   359,   360,   361,   364,   365,
     368,   395,   396,   397,   398,   402,   403,   406,   407,   410,
     411,   414,   415,   418,   419,   420,   423,   424,   427,   428,
     429,   430,   431,   434,   435,   438,   447,   456,   457,   460,
     461,   465,   465,   468,   469,   472,   475,   478,   483,   483,
     483,   485,   485,   485,   485,   485,   485,   487,   488,   489,
     490
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENTIFIER", "T_CONSTANT",
  "T_STRINGLITERAL", "T_INCLUDE", "T_MAIN", "T_INC", "T_DEC",
  "T_LEFT_SHIFT", "T_RIGHT_SHIFT", "T_LE", "T_GE", "T_EQ", "T_NE", "T_AND",
  "T_OR", "T_SHORT_MUL", "T_SHORT_DIV", "T_SHORT_MOD", "T_SHORT_ADD",
  "T_SHORT_SUB", "T_SHORT_LEFT", "T_SHORT_SHIFT", "T_SHORT_AND",
  "T_SHORT_XOR", "T_SHORT_OR", "TYPE_NAME", "T_ELLIPSIS", "T_NEWLINE",
  "T_CHAR", "T_INT", "T_FLOAT", "T_DOUBLE", "T_VOID", "T_IF", "T_ELSE",
  "T_FOR", "T_BREAK", "T_RETURN", "T_CONTINUE", "T_WHILE", "'+'", "'='",
  "'('", "')'", "','", "'&'", "'*'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "';'", "'{'", "'}'", "$accept",
  "PROGRAM", "PREPROCESS", "S", "returntype", "fundef",
  "PRIMARYEXPRESSION", "POSTFIXEXPRESSION", "ARGUMENTEXPRESSIONLIST",
  "UNARYEXPRESSION", "UNARYOPERATOR", "CASTEXPRESSION",
  "MULTIPLICATIVEEXPRESSION", "ADDITIVEEXPRESSION", "SHIFTEXPRESSION",
  "RELATIONALEXPRESSION", "EQUALITYEXPRESSION", "ANDEXPRESSION",
  "EXCLUSIVEOREXPRESSION", "INCLUSIVEOREXPRESSION", "LOGICALANDEXPRESSION",
  "LOGICALOREXPRESSION", "CONDITIONALEXPRESSION", "ASSIGNMENTEXPRESSION",
  "ASSIGNMENTOPERATOR", "EXPRESSION", "DECLARATION",
  "DECLARATIONSPECIFIERS", "INITDECLARATORLIST", "INITDECLARATOR",
  "TYPESPECIFIER", "TYPENAME", "DECLARATOR", "PARAMETERTYPELIST",
  "PARAMETERLIST", "PARAMETERDECLARATION", "IDENTIFIERLIST", "INITIALIZER",
  "INITIALIZERLIST", "STATEMENT", "COMPOUNDSTATEMENT", "new_scope",
  "new_scope_end", "block_item_list", "block_item", "EXPRESSIONSTATEMENT",
  "SELECTIONSTATEMENT", "CREATE_LABEL1", "CREATE_LABEL2", "CREATE_LABEL3",
  "ITERATIONSTATEMENT", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "JUMPSTATEMENT", YY_NULLPTR
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
     295,   296,   297,    43,    61,    40,    41,    44,    38,    42,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    59,   123,   125
};
# endif

#define YYPACT_NINF -181

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-181)))

#define YYTABLE_NINF -9

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,  -181,    36,    61,  -181,  -181,    21,  -181,    26,  -181,
      42,  -181,  -181,     0,    87,  -181,   -20,  -181,    12,  -181,
     -23,  -181,    -4,  -181,  -181,  -181,     7,  -181,    90,    12,
    -181,   209,    44,  -181,   189,  -181,  -181,  -181,  -181,  -181,
     323,   323,  -181,   290,  -181,  -181,  -181,  -181,  -181,   209,
    -181,    18,   375,   340,  -181,    35,   -11,   129,    94,   131,
      24,    23,    28,    79,     1,  -181,  -181,  -181,  -181,  -181,
      12,    75,    76,  -181,   105,    82,    86,    72,   259,    96,
    -181,  -181,  -181,   -18,  -181,  -181,  -181,   139,  -181,  -181,
    -181,  -181,  -181,   340,  -181,  -181,   107,    87,    91,  -181,
     -33,  -181,  -181,   309,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,   340,  -181,  -181,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   123,  -181,    97,  -181,   173,
     340,   340,  -181,  -181,    -3,  -181,   138,   340,  -181,  -181,
    -181,  -181,  -181,   340,     3,  -181,  -181,   109,  -181,  -181,
    -181,  -181,  -181,    35,    35,   -11,   -11,   129,   129,    94,
      94,   131,    24,    23,    28,    79,    27,  -181,  -181,  -181,
     113,   340,    17,  -181,   340,  -181,  -181,  -181,  -181,  -181,
    -181,   340,   340,   239,   152,  -181,   116,  -181,  -181,  -181,
     157,   340,  -181,   239,   152,   239,  -181,   143,  -181,   168,
    -181,   239,   340,  -181,   152,   160,  -181,   239,  -181
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     1,    85,    86,    87,    84,     3,
       0,     6,     5,     0,    78,     2,     0,    90,     0,    76,
       0,    80,    82,    86,    84,    79,   115,     9,     0,     0,
      77,     0,     0,   113,     0,    91,    81,    10,    11,    12,
       0,     0,    27,     0,    25,    26,    28,    29,    30,     0,
      14,    21,    31,     0,    33,    37,    40,    43,    46,    49,
      51,    53,    55,    57,    59,    61,   103,    83,   101,    92,
     100,     0,    95,    97,     0,     0,     0,     0,     0,     0,
     128,   121,    74,     0,   119,   120,   108,     0,   117,   109,
     110,   111,   112,     0,    22,    23,     0,    88,     0,   106,
       0,    17,    18,     0,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    63,     0,    31,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,    93,     0,    94,     0,
       0,     0,   138,   139,     0,   137,     0,     0,   122,   116,
     118,    13,    89,     0,     0,   104,    15,     0,    19,    62,
      34,    35,    36,    38,    39,    41,    42,    44,    45,    47,
      48,    50,    52,    54,    56,    58,     0,    96,    98,   102,
       0,     0,     0,   140,     0,    75,   114,    32,   105,   107,
      16,     0,     0,     0,   126,   131,     0,    20,    60,   123,
       0,     0,   129,     0,   132,     0,   127,     0,   130,     0,
     133,     0,     0,   124,   134,     0,   135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,   204,  -181,  -181,  -181,  -181,  -181,   -19,
    -181,   -37,    43,    62,    41,    68,    80,    78,    84,   101,
      77,  -181,    19,   -30,  -181,   -43,   -25,   -12,  -181,   187,
     -38,   122,   -14,  -181,  -181,    89,  -181,   -39,  -181,  -180,
     207,  -181,  -181,  -181,   148,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    50,    51,   157,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    82,   115,    83,    12,    13,    20,    21,
      14,    98,    22,    71,    72,    73,    74,    67,   100,    85,
      86,    34,   186,    87,    88,    89,    90,   181,   200,   209,
      91,   146,   205,   201,   207,   212,   215,   217,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,    66,    25,    17,    28,    97,    37,    38,    39,    84,
      99,    40,    41,   199,   154,    17,   117,     1,   133,    66,
      70,    94,    95,   206,    29,   208,   101,   102,    -8,   147,
     155,   213,   121,    -7,   116,   144,     4,   218,    30,   122,
      31,    32,    26,   148,   147,    18,    42,    68,    43,    16,
      96,    44,    45,    46,    47,    48,   135,    18,   183,    97,
     134,    19,    84,   103,   147,    49,   188,     5,     6,     7,
      33,     8,   129,   158,   147,     5,    23,     7,   195,    24,
     130,   160,   161,   162,   118,   159,   131,   192,   119,   120,
      69,   176,     5,     6,     7,   132,     8,   180,   182,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   189,   187,   185,     5,    23,
       7,   136,    24,   137,    66,    70,   177,   140,     5,    23,
       7,   141,    24,   142,   116,    32,    35,   153,   194,   123,
     124,   196,    37,    38,    39,   127,   128,    40,    41,   125,
     126,   138,   139,   151,   147,   190,   191,   145,   204,   193,
     147,   197,   202,   147,   163,   164,   167,   168,    32,   214,
       5,    23,     7,   116,    24,    75,   179,    76,    77,    78,
      79,    80,    42,   184,    43,   165,   166,    44,    45,    46,
      47,    48,    37,    38,    39,   169,   170,    40,    41,   147,
      81,    26,   149,   203,   210,   211,   216,    15,   172,   171,
     175,   198,    37,    38,    39,   173,    36,    40,    41,   152,
       5,    23,     7,    27,    24,    75,   178,    76,    77,    78,
      79,    80,    42,   174,    43,   150,     0,    44,    45,    46,
      47,    48,    37,    38,    39,     0,     0,    40,    41,     0,
      81,    26,    42,     0,    43,     0,     0,    44,    45,    46,
      47,    48,    37,    38,    39,     0,     0,    40,    41,     0,
       0,    49,     0,     0,     0,    75,     0,    76,    77,    78,
      79,    80,    42,     0,    43,     0,     0,    44,    45,    46,
      47,    48,     0,    37,    38,    39,     0,     0,    40,    41,
      81,    26,    42,     0,    43,     0,     0,    44,    45,    46,
      47,    48,    37,    38,    39,     0,     0,    40,    41,     0,
     143,     5,    23,     7,     0,    24,    37,    38,    39,     0,
       0,    40,    41,    42,     0,    43,     0,     0,    44,    45,
      46,    47,    48,    37,    38,    39,     0,     0,    40,    41,
       0,     0,    42,     0,    43,   156,     0,    44,    45,    46,
      47,    48,     0,     0,     0,     0,    42,     0,    93,     0,
       0,    44,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,    42,     0,    43,     0,     0,    44,    45,
      46,    47,    48,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      43,    31,    14,     3,    18,    43,     3,     4,     5,    34,
      49,     8,     9,   193,    47,     3,    53,     6,    17,    49,
      32,    40,    41,   203,    47,   205,     8,     9,     7,    47,
      63,   211,    43,     7,    53,    78,     0,   217,    61,    50,
      44,    45,    62,    61,    47,    45,    43,     3,    45,     7,
      93,    48,    49,    50,    51,    52,    70,    45,    61,    97,
      59,    61,    87,    45,    47,    62,    63,    31,    32,    33,
      63,    35,    48,   103,    47,    31,    32,    33,    61,    35,
      57,   118,   119,   120,    49,   115,    58,    60,    53,    54,
      46,   134,    31,    32,    33,    16,    35,   140,   141,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   154,   153,   147,    31,    32,
      33,    46,    35,    47,   154,   137,    29,    45,    31,    32,
      33,    45,    35,    61,   153,    45,    46,    46,   181,    10,
      11,   184,     3,     4,     5,    14,    15,     8,     9,    55,
      56,    46,    47,    46,    47,    46,    47,    61,   201,    46,
      47,   191,    46,    47,   121,   122,   125,   126,    45,   212,
      31,    32,    33,   192,    35,    36,     3,    38,    39,    40,
      41,    42,    43,    45,    45,   123,   124,    48,    49,    50,
      51,    52,     3,     4,     5,   127,   128,     8,     9,    47,
      61,    62,    63,    46,    61,    37,    46,     3,   130,   129,
     133,   192,     3,     4,     5,   131,    29,     8,     9,    97,
      31,    32,    33,    16,    35,    36,   137,    38,    39,    40,
      41,    42,    43,   132,    45,    87,    -1,    48,    49,    50,
      51,    52,     3,     4,     5,    -1,    -1,     8,     9,    -1,
      61,    62,    43,    -1,    45,    -1,    -1,    48,    49,    50,
      51,    52,     3,     4,     5,    -1,    -1,     8,     9,    -1,
      -1,    62,    -1,    -1,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    -1,    45,    -1,    -1,    48,    49,    50,
      51,    52,    -1,     3,     4,     5,    -1,    -1,     8,     9,
      61,    62,    43,    -1,    45,    -1,    -1,    48,    49,    50,
      51,    52,     3,     4,     5,    -1,    -1,     8,     9,    -1,
      61,    31,    32,    33,    -1,    35,     3,     4,     5,    -1,
      -1,     8,     9,    43,    -1,    45,    -1,    -1,    48,    49,
      50,    51,    52,     3,     4,     5,    -1,    -1,     8,     9,
      -1,    -1,    43,    -1,    45,    46,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    43,    -1,    45,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    -1,    -1,    48,    49,
      50,    51,    52,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    65,    66,     0,    31,    32,    33,    35,    67,
      68,    69,    90,    91,    94,    67,     7,     3,    45,    61,
      92,    93,    96,    32,    35,    91,    62,   104,    96,    47,
      61,    44,    45,    63,   105,    46,    93,     3,     4,     5,
       8,     9,    43,    45,    48,    49,    50,    51,    52,    62,
      70,    71,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   101,     3,    46,
      91,    97,    98,    99,   100,    36,    38,    39,    40,    41,
      42,    61,    87,    89,    90,   103,   104,   107,   108,   109,
     110,   114,   122,    45,    73,    73,    89,    94,    95,   101,
     102,     8,     9,    45,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    44,    88,    73,    75,    49,    53,
      54,    43,    50,    10,    11,    55,    56,    14,    15,    48,
      57,    58,    16,    17,    59,    96,    46,    47,    46,    47,
      45,    45,    61,    61,    89,    61,   115,    47,    61,    63,
     108,    46,    95,    46,    47,    63,    46,    72,    87,    87,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    81,    82,    83,    84,    89,    29,    99,     3,
      89,   111,    89,    61,    45,    87,   106,    75,    63,   101,
      46,    47,    60,    46,    89,    61,    89,    87,    86,   103,
     112,   117,    46,    46,    89,   116,   103,   118,   103,   113,
      61,    37,   119,   103,    89,   120,    46,   121,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    67,    67,    68,    68,    69,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      78,    78,    78,    79,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   102,   102,   103,   103,
     103,   103,   103,   104,   104,   105,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   112,   113,   115,   116,
     114,   117,   118,   119,   120,   121,   114,   122,   122,   122,
     122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     3,     4,     2,     2,     1,
       3,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     4,     4,     1,     3,     1,     3,     2,
       1,     1,     3,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     2,     5,     0,     0,     1,     2,     1,
       1,     1,     2,     5,    10,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     0,    14,     2,     2,     2,
       3
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
#line 84 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("\n1\n");*/}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "cd2Inter.y" /* yacc.c:1646  */
    {//printf("2\n");
		}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "cd2Inter.y" /* yacc.c:1646  */
    {
					//printf("3\n");
					}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "cd2Inter.y" /* yacc.c:1646  */
    {
					//printf("4\n");
					}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "cd2Inter.y" /* yacc.c:1646  */
    {
			//printf("5\n");
			}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("6\n");*/}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 108 "cd2Inter.y" /* yacc.c:1646  */
    {//printf("PRIMARY EXPRESSION\n");
								extern int column;
								line_no = column;
								s=yylval.text;
								//printf("S:%s\n",s);
								if(ob>0 && cb ==0)
									scope_count=ob;
								else if(ob-cb==1)
									scope_count=scope;

								else
									scope_count=ob;
								
								l=recurse(s,scope_count);
								//printf("l:%d\n",l);
								char type[10];
								if(strcmp(s,"printf")==0)
								{
									strcpy(k,"printf");
									
									//printf("strcmp:%s\n",k);
									strcpy(type,"printf");
								}
								else
									strcpy(type,k);
								//printf("S: %s\n",type);
								if(l==-1 && !strcmp(s,"printf")){
									//printf("CREATING PRINTF\n");
									create_node(&first,"ID",type,s,10000,scope_count,line_no,"0",line_no); 
									}
								else if(l==-1)
								{
									printf("ERROR!!! at line %d unDECLARed IDENTIFIER %s\n",line_no,yylval.text);
									exit(1);
								}
								change_line(yylval.text,line_no,l);
								
							}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 146 "cd2Inter.y" /* yacc.c:1646  */
    {/*add_value(yylval.text,s,scope_count);*/ }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 147 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("9\n");*/ add_value(yylval.text,s,scope_count);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("10\n");*/}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "cd2Inter.y" /* yacc.c:1646  */
    {}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 152 "cd2Inter.y" /* yacc.c:1646  */
    {printf("12\n");}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "cd2Inter.y" /* yacc.c:1646  */
    {printf("13\n");}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "cd2Inter.y" /* yacc.c:1646  */
    {
				  							
				  							char res[40];
				  							strcpy(res,(yyvsp[-1].str));
				  							l=recurse((yyvsp[-1].str),scope_count);
				  							int op1=toInt(id_val);
				  							int op2=op1+1;
				  							sprintf((yyval.str),"%d",op2);
				  							if (l!=-1)
					  							add_value((yyval.str),res,l);
				  						}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "cd2Inter.y" /* yacc.c:1646  */
    {
				  							
				  							char res[40];
				  							strcpy(res,(yyvsp[-1].str));
				  							l=recurse((yyvsp[-1].str),scope_count);
				  							int op1=toInt(id_val);
				  							int op2=op1-1;
				  							sprintf((yyval.str),"%d",op2);
				  							if(l!=-1)
				  								add_value((yyval.str),res,l);
				  						}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 178 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("16\n");*/}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 179 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("17\n");*/}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("18\n");*/}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 183 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("19\n");*/}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 184 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("20\n");*/}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 185 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("21\n");*/}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 188 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("22\n");*/}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 189 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("23\n");*/}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 190 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("24\n");*/}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("25\n");*/}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 192 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("26\n");*/}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 193 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("27\n");*/}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 196 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("28\n");*/}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 197 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("29\n");*/}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 200 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("30\n");*/}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 201 "cd2Inter.y" /* yacc.c:1646  */
    { 
					 													checker((yyvsp[-2].str),(yyvsp[0].str));
																        	op4=op*op1;
																                sprintf(res2,"%d",op4); 
																		AddQuadruple("*",(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);														
																	    
						  /*printf("31\n");*/}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 208 "cd2Inter.y" /* yacc.c:1646  */
    { 		checker((yyvsp[-2].str),(yyvsp[0].str));								 																			if(op!=0)
																        	op4=op1/op;
																        	else{
																        	printf("divide by zero\n");
																        	exit(1);
																        	}
																		sprintf(res2,"%d",op4); 															        			AddQuadruple("/",(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);
																 }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 217 "cd2Inter.y" /* yacc.c:1646  */
    { 	
					 													checker((yyvsp[-2].str),(yyvsp[0].str));
																       	 	op4=op%op1;
																		sprintf(res2,"%d",op4);		
																										          																			AddQuadruple("%",(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2); 
																	   
																  }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 224 "cd2Inter.y" /* yacc.c:1646  */
    {}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 225 "cd2Inter.y" /* yacc.c:1646  */
    {		checker((yyvsp[-2].str),(yyvsp[0].str));
																	   	op4=op+op1;
																	   	sprintf(res2,"%d",op4); 															        		        AddQuadruple("+",(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);
																 }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 230 "cd2Inter.y" /* yacc.c:1646  */
    {		 checker((yyvsp[-2].str),(yyvsp[0].str));
																		 op4=op1-op;
																  		 sprintf(res2,"%d",op4);
									     								         AddQuadruple("-",(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);
																}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "cd2Inter.y" /* yacc.c:1646  */
    {/*AddQuadruple($2,$1,$3,$$);*/}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 239 "cd2Inter.y" /* yacc.c:1646  */
    {/*AddQuadruple($2,$1,$3,$$);*/}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 243 "cd2Inter.y" /* yacc.c:1646  */
    { 		checker((yyvsp[-2].str),(yyvsp[0].str));
																        if(op1<op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																        AddQuadruple("<",(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 250 "cd2Inter.y" /* yacc.c:1646  */
    {		checker((yyvsp[-2].str),(yyvsp[0].str));
																        if(op1>op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																        AddQuadruple(">",(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);
					 													
					 												}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 262 "cd2Inter.y" /* yacc.c:1646  */
    {	checker((yyvsp[-2].str),(yyvsp[0].str));
					 												  //op=toInt($3);
					 												 // printf("OP1 %d op %d \n",op1,op); 
																        if(op1==op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																      
					 												AddQuadruple((yyvsp[-1].str),(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 272 "cd2Inter.y" /* yacc.c:1646  */
    {	checker((yyvsp[-2].str),(yyvsp[0].str));
					 												printf("OP1 %d op %d \n",op1,op); 
					 												//op=toInt($3);
																        if(op1!=op)
																        	strcpy(res2,"True");
																        else
																        	strcpy(res2,"False");
																        printf("RESULT %s\n",res2);
					 												AddQuadruple((yyvsp[-1].str),(yyvsp[-2].str),(yyvsp[0].str),(yyval.str),res2);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 285 "cd2Inter.y" /* yacc.c:1646  */
    {/*AddQuadruple("&",$1,$3,$$);*/}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 288 "cd2Inter.y" /* yacc.c:1646  */
    {/*AddQuadruple("^",$1,$3,$$);*/}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 292 "cd2Inter.y" /* yacc.c:1646  */
    {/*AddQuadruple("|",$1,$3,$$);*/}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 296 "cd2Inter.y" /* yacc.c:1646  */
    {/*AddQuadruple($2,$1,$3,$$);*/}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 300 "cd2Inter.y" /* yacc.c:1646  */
    {/*AddQuadruple($2,$1,$3,$$);*/}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 307 "cd2Inter.y" /* yacc.c:1646  */
    {}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 308 "cd2Inter.y" /* yacc.c:1646  */
    {
					 	strcpy(QUAD[Index].op,"=");
						strcpy(QUAD[Index].arg1,(yyvsp[0].str));
						strcpy(QUAD[Index].arg2,"");
						strcpy(QUAD[Index].result,(yyvsp[-2].str));
						strcpy((yyval.str),QUAD[Index++].result);
					 	//printf("ASSIGNEMNT EXPRESSION $3 :%s %s \n",$3,$$);
					 	//int checl if its temp variable or value to be assigned.
					 	int check;
					 	check=check_type((yyvsp[0].str));
					 	if(check==0)
					 		strcpy((yyvsp[0].str),res2);
					 	//printf("ASSIGNEMNT EXPRESSION22 $3 :%s %s\n",$3,$$);
					 	l=recurse((yyvsp[-2].str), scope_count);
					 	if(l!=-1)
						 	add_value((yyvsp[0].str),(yyvsp[-2].str),l);
					 }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 326 "cd2Inter.y" /* yacc.c:1646  */
    {/*printf("146\n");*/}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 328 "cd2Inter.y" /* yacc.c:1646  */
    { /*printf("147\n");*/}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 342 "cd2Inter.y" /* yacc.c:1646  */
    {}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 343 "cd2Inter.y" /* yacc.c:1646  */
    {
			   		char *idname = (yyvsp[-2].str), *value = (yyvsp[0].str);
			   		add_value(value,idname,scope_count);
			   		strcpy(QUAD[Index].op,"=");
					strcpy(QUAD[Index].arg1,(yyvsp[0].str));
					strcpy(QUAD[Index].arg2,"");
					strcpy(QUAD[Index].result,(yyvsp[-2].str));
					strcpy((yyval.str),QUAD[Index++].result);
					//AddQuadruple("=",$1,$3,$$);
			   		}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 358 "cd2Inter.y" /* yacc.c:1646  */
    {strcpy(k,"void");/*k="void";*/}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 359 "cd2Inter.y" /* yacc.c:1646  */
    {strcpy(k,"char");/*k="char";*/}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 360 "cd2Inter.y" /* yacc.c:1646  */
    {strcpy(k,"int"); /*k="int";*/}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 361 "cd2Inter.y" /* yacc.c:1646  */
    {strcpy(k,"float");/*k="float";*/}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 368 "cd2Inter.y" /* yacc.c:1646  */
    {
								extern int column;
								line_no=column;	
								s=yylval.text;
								//printf("20000\n");
								if(ob>0 && cb ==0)
									scope_count=ob;
								else if(ob-cb==1)
									scope_count=scope;

								else
									scope_count=ob;

								l=search(s,scope_count);
								//printf("return of recurse is ------------------------%d\n",l );
								char type[10];
								strcpy(type,k);
								//printf("vlaue of k is ---------------%s\n", k);
								if(l==0){
								create_node(&first,"ID",type,s,1000,scope_count,line_no,"0",line_no);}
								else
									{	
										printf("ERROR!!! at line %d\n REDECLARATION of IDENTIFIER %s\n",line_no,yylval.text);
										exit(1);
									}

							}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 438 "cd2Inter.y" /* yacc.c:1646  */
    { //scope = NEWSCOPE;
			ob++;
			scope++;
			//scope_count++;
			//printf("scope started %d\n",scope_count);

			}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 447 "cd2Inter.y" /* yacc.c:1646  */
    {
					cb++;
					scope--;
					//
					//printf("scope ended\n");
					//write and pop (write the functions)
				}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 460 "cd2Inter.y" /* yacc.c:1646  */
    { /*printf("DECLARATION::  \n" );*/}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 461 "cd2Inter.y" /* yacc.c:1646  */
    { /*printf("STATEMENT::  \n" );*/}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 465 "cd2Inter.y" /* yacc.c:1646  */
    { /*res = $$ ; printf("200\n");*/}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 469 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("GOTO","","","");}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 472 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("LABEL","","","");}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 475 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("ifFalse",QUAD[Index-1].result,"","");create_label("GOTO","","","");create_label("LABEL","","","");}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 478 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("GOTO","","","");sprintf(lab,"%d",lIndex-3);create_label("LABEL","","",lab);}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 483 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("LABEL","","","");}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 483 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("ifFalse",QUAD[Index-1].result,"","");create_label("GOTO","","","");}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 483 "cd2Inter.y" /* yacc.c:1646  */
    {sprintf(lab,"%d",lIndex-3);create_label("GOTO","","",lab);sprintf(lab,"%d",lIndex-2);create_label("LABEL","","",lab);}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 485 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("LABEL","","","");}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 485 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("ifFalse",QUAD[Index-1].result,"","");create_label("GOTO","","","");}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 485 "cd2Inter.y" /* yacc.c:1646  */
    {create_label("LABEL","","","");}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 485 "cd2Inter.y" /* yacc.c:1646  */
    {sprintf(lab,"%d",lIndex-4);create_label("GOTO","","",lab);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 485 "cd2Inter.y" /* yacc.c:1646  */
    {sprintf(lab,"%d",lIndex-2);create_label("LABEL","","",lab);}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 485 "cd2Inter.y" /* yacc.c:1646  */
    {sprintf(lab,"%d",lIndex-3);create_label("LABEL","","",lab);}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2200 "y.tab.c" /* yacc.c:1646  */
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
#line 492 "cd2Inter.y" /* yacc.c:1906  */


extern int yylex();
extern int yyparse();
extern FILE *yyin;


int main()
{
	
first=NULL;
sym_init(&first);
display(first);
char *b = "123";
//printf("--------------------------------------------------------------------------------------------%d",toInt(b));

	FILE *in = fopen("test.c", "r");
	if(!in)
	{
		printf("Better Stop Cuz No Input!");
		return -1;
	}
	yyin = in;	
	do{
	yyparse();
	}while (!feof(yyin));
	printf("Done parsing\n");
	display(first);
	//printf("hello from the other side\n");
	printf("\n\n");
	printf("\n\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s","pos","op","arg1","arg2","result");
	printf("\n\t-----------------------------------------------------------------------");
	for(int i=0;i<Index;i++)
	{
		printf("\n\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s", i,QUAD[i].op, QUAD[i].arg1,QUAD[i].arg2,QUAD[i].result);
	}
	printf("\n\n\n");

	
}


int yyerror()
{
extern int column;
	if(column==1)
		printf("\n error at line 1\n");
	else
		printf("\n error at line %d\n",column-1);
	return 0;
}


int search(char *text,int scope_count)
{


	struct symbol *p;
	p=first;
	//display(first);
	int flag=0;
	while(p!=NULL)
	{
		if(strcmp(p->symb,text)==0)
		{
			//printf("symbol and scope_count %s %d\n",p->symb,p->var_scope );
			if(p->var_scope==scope_count) // already there and scope matches -> re
			{	
				//printf("symbol and scope_count %s %d\n",p->symb,p->var_scope );
				id_val=p->value;
				flag =1;
				break;
			}
			else  //there but scope doesnt match
			{
				//printf("elseeeeee\n");
				flag = 0;
				p=p->next;
			}
		}
		else{  //not found at all
			//printf("flaggggggg 22222222\n");
			p=p->next;
			flag = 2;
		}
		
	}

	if(flag == 0 || flag == 2)
		return 0;
	else
		return 1;

	
}
void sym_init(struct symbol **second)
{
	
	printf("label\t\ttype\t\value\t\taddr\t\tscope\t\tlineNo\t\tvalue\n");
	printf("------------------------------------------------------------");
	for(int i=0;i<8;i++)
	{ 
        create_node(second,"keyword","KEYWORD" ,keywords[i],1000+i+4,0,0,"0",0);
	}
	
}

void change_line(char *id,int line_no,int scope)
{
	struct symbol *p;
	p=first;
	while(p!=NULL)
	{
		if(strcmp(p->symb,id)==0){
			if(p->var_scope==scope)
			{p->live_line = line_no;
			return;}
			else
				p=p->next;
		}
		else
			p=p->next;
	}	
}



void add_value(char *value, char *id_name, int scope)
{
//printf("ADD VALUE VALUE %s\n",value);
	struct symbol *p;
	p = first;
	while(p!=NULL)
	{
		
		if(strcmp(p->symb,id_name)==0)
		{	

			if(p->var_scope==scope)
				{
					strcpy(p->value,value);
					return;
				}
			else
				{
					p = p->next;
				}
		}
		else
			p = p->next;
	}
}

int toInt(char *a) 
{
  int c, sign, offset, n;
 
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }
 
  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
 
  n = 0;
 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
 
  if (sign == -1) {
    n = -n;
  }
 
  return n;
}

int check_type(char *op1)	//return 1 if digit else return 0
{
	if(op1[0]>=48 && op1[0]<58)
		return 1;
	else 
		return 0;
}

void checker(char *val1,char *val2)
{
	printf(" -------------%s %s\n", val1,val2);
	int p=check_type(val2);
 	int p1=check_type(val1);
 
    if(p==0)
  	{//printf("in IF op val2 %d\n",op);
  		recurse(val2,scope_count);
		op =toInt(id_val);}
	else{
		//printf("in else op val2 %d\n",op);
		op=toInt(val2);
		}
	//printf("op val2 %d\n",op);
	if(p1==0){
		recurse(val1,scope_count);
		op1 =toInt(id_val);}	
	else
		op1=toInt(val1);
}

int recurse(char *text, int scope_count_func)
{
	int t=0;
	while(t!=1 && scope_count_func!=-1)
	{

		t=search(text, scope_count_func);

		scope_count_func--;
	}
	if(t==1)
		return scope_count_func+1;
	else
		return -1;
}

void AddQuadruple(char op[5],char arg1[10],char arg2[10],char result[10],char res[10])
{
	extern int column;
	strcpy(QUAD[Index].op,op);
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	sprintf(QUAD[Index].result,"t%d",tIndex++);
	strcpy(result,QUAD[Index++].result);
	create_node(&first,"temp","temp",result,10000,scope_count,-1,res,-1);
}
void create_label(char op[10],char arg1[10],char arg2[10],char result[10])
{
printf("Create label\n");
	strcpy(QUAD[Index].op,op);
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	if(strlen(result)==0)
		sprintf(QUAD[Index].result,"L%d",lIndex++);
	else
		sprintf(QUAD[Index].result,"L%d",toInt(result));
	Index++;
	
}


