/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AADD = 258,
     ASUB = 259,
     AMUL = 260,
     ADIV = 261,
     AAND = 262,
     AOR = 263,
     INC = 264,
     DEC = 265,
     PREINC = 266,
     POSTINC = 267,
     PREDEC = 268,
     POSTDEC = 269,
     ASSIGN = 270,
     LOR = 271,
     LAND = 272,
     IS = 273,
     EQ = 274,
     NEQ = 275,
     GE = 276,
     LE = 277,
     NEG = 278,
     SUFFIX = 279,
     PREFIX = 280,
     POSTFIX = 281,
     INTEGER = 282,
     RESTYPE = 283,
     STRING = 284,
     STRVAR = 285,
     SYM = 286,
     TYPE = 287,
     NUL = 288,
     BRANCH = 289,
     RETURN = 290,
     ROOM = 291,
     OBJECT = 292,
     NS = 293,
     SCRIPT = 294,
     VERB = 295,
     ACTOR = 296,
     VOICE = 297,
     CYCL = 298,
     IF = 299,
     ELSE = 300,
     FOR = 301,
     WHILE = 302,
     DO = 303,
     SWITCH = 304,
     CASE = 305,
     DEFAULT = 306,
     CUTSCENE = 307,
     CLASS = 308,
     TRY = 309,
     OVERRIDE = 310,
     SCRTYPE = 311,
     ERROR = 312
   };
#endif
/* Tokens.  */
#define AADD 258
#define ASUB 259
#define AMUL 260
#define ADIV 261
#define AAND 262
#define AOR 263
#define INC 264
#define DEC 265
#define PREINC 266
#define POSTINC 267
#define PREDEC 268
#define POSTDEC 269
#define ASSIGN 270
#define LOR 271
#define LAND 272
#define IS 273
#define EQ 274
#define NEQ 275
#define GE 276
#define LE 277
#define NEG 278
#define SUFFIX 279
#define PREFIX 280
#define POSTFIX 281
#define INTEGER 282
#define RESTYPE 283
#define STRING 284
#define STRVAR 285
#define SYM 286
#define TYPE 287
#define NUL 288
#define BRANCH 289
#define RETURN 290
#define ROOM 291
#define OBJECT 292
#define NS 293
#define SCRIPT 294
#define VERB 295
#define ACTOR 296
#define VOICE 297
#define CYCL 298
#define IF 299
#define ELSE 300
#define FOR 301
#define WHILE 302
#define DO 303
#define SWITCH 304
#define CASE 305
#define DEFAULT 306
#define CUTSCENE 307
#define CLASS 308
#define TRY 309
#define OVERRIDE 310
#define SCRTYPE 311
#define ERROR 312




/* Copy the first part of user declarations.  */
#line 26 "/usr/tmp/scc_parse.y"

#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "scc_fd.h"
#include "scc_util.h"

#include "scc_parse.h"
#include "scc_ns.h"
#include "scc_img.h"
#include "scc_cost.h"
#include "scc.h"
#include "scc_roobj.h"
#include "scc_code.h"
#include "scc_param.h"

#include "scc_parse.tab.h"

#include "scc_lex.h"

#include "scc_help.h"

#define YYERROR_VERBOSE 1

typedef struct scc_parser {
  // targeted vm version
  scc_target_t* target;;
  scc_lex_t* lex;
  scc_ns_t* ns;
  scc_roobj_t* roobj_list;
  scc_roobj_t* roobj;
  scc_roobj_obj_t* obj;
  int local_vars;
  int local_scr;
  int cycl;
  // ressources include paths
  char** res_path;
  // deps
  char do_deps;
  int num_deps;
  char** deps;
} scc_parser_t;

#define YYPARSE_PARAM v_sccp
#define sccp ((scc_parser_t*)v_sccp)
#define YYLEX_PARAM sccp->lex

// redefined the function names
#define yyparse scc_parser_parse_internal
#define yylex scc_lex_lex
#define yyerror(msg) scc_parser_error(sccp,&yyloc,msg)

int scc_parser_error (scc_parser_t* p,YYLTYPE *llocp, const char *s);
void scc_parser_add_dep(scc_parser_t* p, char* dep);

static void scc_parser_find_res(scc_parser_t* p, char** file_ptr);


#define SCC_LIST_ADD(list,last,c) if(c){                  \
  if(last) last->next = c;                                \
  else list = c;                                          \
  for(last = c ; last && last->next ; last = last->next); \
}

#define SCC_BOP(d,bop,a,cop,b) {                              \
  if(a->type == SCC_ST_VAL &&                                 \
     b->type == SCC_ST_VAL) {                                 \
    a->val.i = ((int16_t)a->val.i) bop ((int16_t)b->val.i);   \
    free(b);                                                  \
    d = a;                                                    \
  } else {                                                    \
    d = calloc(1,sizeof(scc_statement_t));                    \
    d->type = SCC_ST_OP;                                      \
    d->val.o.type = SCC_OT_BINARY;                            \
    d->val.o.op = cop;                                        \
    d->val.o.argc = 2;                                        \
    d->val.o.argv = a;                                        \
    a->next = b;                                              \
  }                                                           \
}

#define SCC_ABORT(at,msg...)  { \
  scc_log(LOG_ERR,"%s: ",scc_lex_get_file(sccp->lex));        \
  scc_log(LOG_ERR,msg); \
  YYABORT; \
}

  // output filename
  static char* scc_output = NULL;

  scc_func_t* scc_get_func(scc_parser_t* p, char* sym) {
    int i,j;

    if(!sym) return NULL;

    for(i = 0 ; p->target->func_list[i] ; i++) {
      scc_func_t* list = p->target->func_list[i];
      for(j = 0 ; list[j].sym ; j++) {
        if(strcmp(sym,list[j].sym)) continue;
        return &list[j];
      }
    }

    return NULL;
  }

  char* scc_statement_check_func(scc_call_t* c) {
    int n,min_argc = c->func->argc;
    scc_statement_t* a;
    // should be big enouth
    static char func_err[2048];

    while(min_argc > 0 && (c->func->argt[min_argc-1] & SCC_FA_DEFAULT))
      min_argc--;

    if(c->argc > c->func->argc || c->argc < min_argc) {
      sprintf(func_err,"Function %s needs %d args, %d found.\n",
	      c->func->sym,c->func->argc,c->argc);
      return func_err;
    }
      
    for(n = 0, a = c->argv ; a ; n++, a = a->next) {
      if(c->func->argt[n] == SCC_FA_VAL) {
	if(a->type == SCC_ST_STR ||
	   a->type == SCC_ST_LIST) {
	  sprintf(func_err,"Argument %d of call to %s is of the wrong type.\n",
		  n+1,c->func->sym);
	  return func_err;
	}
      } else if(c->func->argt[n] == SCC_FA_ARRAY) {
	if(a->type != SCC_ST_VAR ||
	   !(a->val.v.r->subtype & SCC_VAR_ARRAY)) {
	  sprintf(func_err,"Argument %d of call to %s must be an array variable.\n",
		  n+1,c->func->sym);
	  return func_err;
	}

      } else if(c->func->argt[n] == SCC_FA_LIST &&
		a->type != SCC_ST_LIST) {
	sprintf(func_err,"Argument %d of %s must be a list.\n",
		n+1,c->func->sym);
	return func_err;
      } else if(c->func->argt[n] == SCC_FA_STR &&
		a->type != SCC_ST_STR) {
	sprintf(func_err,"Argument %d of %s must be a string.\n",
		n+1,c->func->sym);
	return func_err;
      }
	
    }

    return NULL;
  }



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 193 "/usr/tmp/scc_parse.y"
{
  int integer;
  char* str;
  char** strlist;
  scc_symbol_t* sym;
  scc_statement_t* st;
  scc_instruct_t* inst;
  scc_scr_arg_t* arg;
  scc_script_t* scr;
  scc_str_t* strvar;
  int* intlist;
  scc_verb_script_t* vscr;
}
/* Line 187 of yacc.c.  */
#line 389 "scc_parse.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 414 "scc_parse.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   856

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNRULES -- Number of states.  */
#define YYNSTATES  402

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,     2,    22,     2,
      73,    74,    31,    30,    70,    29,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    17,    69,
      27,     2,    25,    16,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    21,    72,     2,     2,     2,     2,
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
      15,    18,    19,    20,    23,    24,    26,    28,    33,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    18,
      21,    24,    27,    32,    38,    39,    41,    45,    50,    54,
      59,    61,    63,    65,    71,    78,    80,    82,    84,    86,
      88,    92,    95,    98,   102,   107,   109,   112,   117,   120,
     126,   129,   132,   135,   138,   141,   144,   147,   155,   159,
     161,   164,   169,   176,   181,   193,   197,   205,   211,   214,
     216,   220,   225,   231,   232,   235,   238,   242,   246,   250,
     256,   260,   266,   268,   272,   274,   278,   286,   298,   300,
     304,   305,   311,   316,   319,   323,   324,   326,   330,   333,
     334,   336,   337,   341,   347,   348,   351,   352,   355,   356,
     358,   361,   365,   369,   374,   376,   380,   382,   385,   388,
     390,   392,   394,   397,   399,   402,   404,   408,   410,   412,
     414,   417,   425,   430,   440,   446,   449,   455,   456,   459,
     465,   468,   473,   476,   480,   482,   485,   489,   494,   500,
     508,   510,   514,   515,   517,   519,   521,   526,   533,   535,
     539,   543,   549,   553,   557,   561,   565,   569,   573,   577,
     581,   585,   589,   593,   597,   601,   605,   609,   612,   615,
     618,   621,   625,   627,   631,   636,   643,   644,   646,   650,
     652,   656,   658,   662,   664,   667,   669,   671,   673,   676,
     678,   680,   682
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      79,     0,    -1,    -1,    80,    -1,    81,    -1,    80,    81,
      -1,    91,    -1,    82,    -1,    83,    69,    -1,    86,    69,
      -1,    88,    69,    -1,    85,    69,    -1,    43,    84,    42,
     119,    -1,    83,    70,    84,    42,   119,    -1,    -1,    31,
      -1,    47,    42,   119,    -1,    85,    70,    42,   119,    -1,
      87,    42,   119,    -1,    86,    70,    42,   119,    -1,    52,
      -1,    51,    -1,    64,    -1,    89,    42,    49,    42,   119,
      -1,    88,    70,    42,    49,    42,   119,    -1,    39,    -1,
      48,    -1,    50,    -1,    53,    -1,    54,    -1,    47,    42,
     119,    -1,    90,    92,    -1,    71,    72,    -1,    71,    93,
      72,    -1,    71,    97,    93,    72,    -1,    94,    -1,    93,
      94,    -1,    95,    71,   120,    72,    -1,    95,    69,    -1,
      96,    71,   106,   112,    72,    -1,    96,    69,    -1,   101,
      69,    -1,   102,    69,    -1,    99,    69,    -1,   100,    69,
      -1,   104,    69,    -1,    83,    69,    -1,   117,    50,    42,
      73,   118,    74,   119,    -1,    48,    42,   119,    -1,    98,
      -1,    97,    98,    -1,    42,    15,    40,    69,    -1,    42,
      15,    71,   111,    72,    69,    -1,    42,    15,    38,    69,
      -1,   100,    15,    71,    38,    70,    38,    70,    38,    70,
      38,    72,    -1,    54,    42,   119,    -1,   102,    15,    71,
      40,    70,   103,    72,    -1,   102,    15,    71,    40,    72,
      -1,    53,    42,    -1,    38,    -1,   103,    70,    38,    -1,
      39,    42,   119,   105,    -1,   104,    70,    42,   119,   105,
      -1,    -1,    15,    40,    -1,   107,    69,    -1,   106,   107,
      69,    -1,    42,    15,    40,    -1,    42,    15,   152,    -1,
      42,    15,    71,   109,    72,    -1,    42,    15,    42,    -1,
      64,    15,    71,   108,    72,    -1,    42,    -1,   108,    70,
      42,    -1,   110,    -1,   109,    70,   110,    -1,    71,   152,
      70,   152,    70,    40,    72,    -1,    71,   152,    70,   152,
      70,    40,    70,    71,   111,    72,    72,    -1,    40,    -1,
     111,    70,    40,    -1,    -1,   113,    71,   121,   114,    72,
      -1,    51,    73,   118,    74,    -1,   116,   115,    -1,   114,
     116,   115,    -1,    -1,   125,    -1,    61,    42,    17,    -1,
      62,    17,    -1,    -1,    67,    -1,    -1,    43,    84,    42,
      -1,   118,    70,    43,    84,    42,    -1,    -1,    75,    38,
      -1,    -1,   121,   125,    -1,    -1,   122,    -1,   123,    69,
      -1,   122,   123,    69,    -1,    43,    84,    42,    -1,   123,
      70,    84,    42,    -1,   126,    -1,    71,   125,    72,    -1,
     126,    -1,   125,   126,    -1,   127,    69,    -1,   129,    -1,
     140,    -1,    45,    -1,    45,    42,    -1,    46,    -1,    46,
     140,    -1,   127,    -1,    71,   125,    72,    -1,   139,    -1,
     135,    -1,   130,    -1,   131,   124,    -1,   132,   128,    58,
      73,   140,    74,    69,    -1,   133,    71,   136,    72,    -1,
     134,    57,    73,   141,    69,   140,    69,   141,    74,    -1,
     134,    58,    73,   140,    74,    -1,   134,    59,    -1,   134,
      60,    73,   140,    74,    -1,    -1,    42,    17,    -1,    63,
      73,   145,    74,   124,    -1,    65,   124,    -1,    65,   124,
      66,   124,    -1,   137,   125,    -1,   136,   137,   125,    -1,
     138,    -1,    62,    17,    -1,    61,   142,    17,    -1,   138,
      61,   142,    17,    -1,    55,    73,   140,    74,   124,    -1,
      55,    73,   140,    74,   124,    56,   124,    -1,   142,    -1,
     140,    70,   142,    -1,    -1,   140,    -1,   149,    -1,   143,
      -1,   143,    76,   142,    77,    -1,   143,    76,   142,    70,
     142,    77,    -1,   144,    -1,    76,   145,    77,    -1,   142,
      15,   142,    -1,   142,    16,   142,    17,   142,    -1,   142,
      18,   142,    -1,   142,    19,   142,    -1,   142,    20,   146,
      -1,   142,    21,   142,    -1,   142,    22,   142,    -1,   142,
      24,   142,    -1,   142,    23,   142,    -1,   142,    26,   142,
      -1,   142,    25,   142,    -1,   142,    28,   142,    -1,   142,
      27,   142,    -1,   142,    29,   142,    -1,   142,    30,   142,
      -1,   142,    32,   142,    -1,   142,    31,   142,    -1,    29,
     142,    -1,    34,   142,    -1,    35,   142,    -1,   142,    35,
      -1,    73,   140,    74,    -1,    42,    -1,    42,    49,    42,
      -1,    42,    73,   145,    74,    -1,    42,    49,    42,    73,
     145,    74,    -1,    -1,   142,    -1,   145,    70,   142,    -1,
     148,    -1,    76,   147,    77,    -1,   148,    -1,   147,    70,
     148,    -1,    42,    -1,    34,    42,    -1,    38,    -1,   150,
      -1,   151,    -1,   150,   151,    -1,    40,    -1,    41,    -1,
      38,    -1,    29,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   337,   337,   338,   341,   342,   345,   346,   349,   351,
     353,   355,   358,   367,   379,   382,   390,   394,   400,   404,
     410,   414,   418,   425,   430,   436,   437,   441,   445,   449,
     457,   467,   492,   493,   495,   498,   499,   503,   515,   522,
     530,   535,   537,   539,   541,   543,   545,   549,   575,   593,
     594,   597,   609,   621,   637,   647,   656,   671,   686,   693,
     699,   709,   724,   742,   745,   755,   756,   760,   768,   777,
     785,   815,   822,   839,   857,   858,   861,   868,   877,   885,
     898,   900,   919,   935,   942,   959,   962,   965,   979,   988,
     991,   998,  1001,  1011,  1025,  1028,  1035,  1039,  1053,  1054,
    1057,  1060,  1064,  1074,  1082,  1087,  1093,  1098,  1106,  1107,
    1110,  1117,  1127,  1138,  1145,  1160,  1165,  1171,  1175,  1177,
    1183,  1189,  1197,  1206,  1217,  1228,  1237,  1248,  1251,  1257,
    1265,  1272,  1281,  1289,  1308,  1313,  1318,  1323,  1332,  1341,
    1353,  1358,  1379,  1382,  1388,  1393,  1398,  1412,  1427,  1432,
    1447,  1470,  1482,  1487,  1492,  1524,  1529,  1534,  1539,  1544,
    1549,  1554,  1559,  1564,  1569,  1574,  1579,  1584,  1599,  1614,
    1627,  1640,  1646,  1667,  1691,  1741,  1785,  1789,  1794,  1805,
    1810,  1816,  1821,  1832,  1858,  1878,  1885,  1892,  1896,  1905,
    1911,  1945,  1949
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AADD", "ASUB", "AMUL", "ADIV", "AAND",
  "AOR", "INC", "DEC", "PREINC", "POSTINC", "PREDEC", "POSTDEC", "ASSIGN",
  "'?'", "':'", "LOR", "LAND", "IS", "'|'", "'&'", "EQ", "NEQ", "'>'",
  "GE", "'<'", "LE", "'-'", "'+'", "'*'", "'/'", "NEG", "'!'", "SUFFIX",
  "PREFIX", "POSTFIX", "INTEGER", "RESTYPE", "STRING", "STRVAR", "SYM",
  "TYPE", "NUL", "BRANCH", "RETURN", "ROOM", "OBJECT", "NS", "SCRIPT",
  "VERB", "ACTOR", "VOICE", "CYCL", "IF", "ELSE", "FOR", "WHILE", "DO",
  "SWITCH", "CASE", "DEFAULT", "CUTSCENE", "CLASS", "TRY", "OVERRIDE",
  "SCRTYPE", "ERROR", "';'", "','", "'{'", "'}'", "'('", "')'", "'@'",
  "'['", "']'", "$accept", "srcfile", "srcs", "src", "gdecl", "gvardecl",
  "typemod", "groomdecl", "gresdecl", "globalres", "groomresdecl",
  "roomres", "roombdecl", "room", "roombody", "roombodyentries",
  "roombodyentry", "roomscrdecl", "roomobjdecl", "roomdecls", "roomdecl",
  "cycledef", "cycledecl", "voicedef", "voicedecl", "synclist", "resdecl",
  "resdef", "objectparams", "objectparam", "classlist", "imgdecls",
  "imgdecl", "zbufs", "objectverbs", "verbentrydecl", "verbsblock",
  "verbcode", "verbentry", "scripttype", "scriptargs", "location",
  "scriptbody", "vardecl", "vardec", "vdecl", "body", "instructions",
  "instruct", "oneinstruct", "dobody", "block", "loopblock", "loophead",
  "dohead", "switchhead", "label", "cutsceneblock", "switchblock",
  "caseblock", "caseval", "ifblock", "statements", "opt_statements",
  "statement", "var", "call", "cargs", "isargs", "isarglist", "isarg",
  "dval", "string", "str", "natural", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    63,    58,   271,   272,
     273,   124,    38,   274,   275,    62,   276,    60,   277,    45,
      43,    42,    47,   278,    33,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    59,
      44,   123,   125,    40,    41,    64,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      90,    91,    92,    92,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    95,    96,    97,
      97,    98,    98,    98,    99,   100,   101,   101,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   129,
     130,   130,   130,   131,   131,   132,   133,   134,   134,   135,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   143,   143,   144,   144,   145,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     2,     2,
       2,     2,     4,     5,     0,     1,     3,     4,     3,     4,
       1,     1,     1,     5,     6,     1,     1,     1,     1,     1,
       3,     2,     2,     3,     4,     1,     2,     4,     2,     5,
       2,     2,     2,     2,     2,     2,     2,     7,     3,     1,
       2,     4,     6,     4,    11,     3,     7,     5,     2,     1,
       3,     4,     5,     0,     2,     2,     3,     3,     3,     5,
       3,     5,     1,     3,     1,     3,     7,    11,     1,     3,
       0,     5,     4,     2,     3,     0,     1,     3,     2,     0,
       1,     0,     3,     5,     0,     2,     0,     2,     0,     1,
       2,     3,     3,     4,     1,     3,     1,     2,     2,     1,
       1,     1,     2,     1,     2,     1,     3,     1,     1,     1,
       2,     7,     4,     9,     5,     2,     5,     0,     2,     5,
       2,     4,     2,     3,     1,     2,     3,     4,     5,     7,
       1,     3,     0,     1,     1,     1,     4,     6,     1,     3,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     1,     3,     4,     6,     0,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    25,    14,     0,    26,    27,    21,    20,    28,    29,
      22,     0,     3,     4,     7,     0,     0,     0,     0,     0,
       0,     0,     6,    15,     0,    94,     1,     5,     8,    14,
      11,     0,     9,     0,    94,    10,     0,     0,    89,    31,
      94,     0,    16,     0,    94,    94,    18,     0,     0,     0,
       0,     0,     0,     0,    90,    32,     0,    89,    35,     0,
       0,    89,    49,     0,     0,     0,     0,     0,     0,    12,
      95,    94,    17,    19,     0,    94,    94,     0,    94,    58,
      94,    46,    33,    36,    38,    98,    40,     0,    89,    50,
      43,     0,    44,    41,     0,    42,    45,     0,     0,    13,
      94,    23,    63,     0,     0,     0,    48,    55,    14,     0,
     127,    99,     0,     0,     0,    80,     0,    34,     0,     0,
      94,     0,    24,     0,    61,    53,    51,    78,     0,     0,
      37,     0,     0,     0,   185,   189,   190,   172,   111,   113,
       0,     0,   127,     0,   176,   127,   106,     0,   109,   119,
     127,     0,     0,     0,   118,   117,   110,   140,   145,   148,
     144,   186,   187,     0,   100,    14,     0,     0,     0,     0,
       0,     0,    65,     0,     0,    63,    91,    64,     0,     0,
     102,   172,   167,   168,   169,   128,     0,   176,   112,   114,
       0,   176,   127,   130,   104,     0,   177,     0,   107,   108,
     120,   127,   115,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,     0,   188,
     101,     0,     0,   191,    67,    70,     0,    68,     0,    91,
      66,    39,    98,     0,     0,    57,    62,    14,     0,    79,
      52,   173,     0,     0,     0,   127,   127,   171,     0,   149,
     127,     0,     0,     0,     0,   127,   134,   142,     0,     0,
     141,   150,     0,   152,   153,     0,   183,     0,   154,   179,
     155,   156,   158,   157,   160,   159,   162,   161,   163,   164,
     166,   165,     0,   103,   192,     0,     0,    74,    72,     0,
       0,     0,     0,    59,     0,     0,     0,    94,   176,   174,
     127,   127,   105,   131,   178,   116,     0,     0,   135,   122,
     127,   127,     0,   143,     0,     0,     0,     0,   184,     0,
     181,     0,   146,     0,     0,    69,     0,    71,    82,     0,
       0,     0,   127,     0,     0,    56,    92,    14,    47,     0,
     138,   129,     0,   136,   127,     0,     0,   124,   126,   151,
       0,   180,     0,     0,    75,    73,     0,    88,    81,   127,
      83,   127,     0,    60,     0,   175,   127,     0,   137,     0,
     182,   147,     0,    87,    84,     0,    93,   139,   121,   142,
       0,     0,     0,     0,    54,   123,     0,    76,     0,     0,
       0,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    56,    24,    16,    17,    18,
      19,    20,    21,    22,    39,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   304,    67,   124,   115,   116,
     299,   296,   297,   128,   170,   171,   341,   370,   342,    68,
     248,    42,   109,   110,   111,   112,   193,   371,   146,   147,
     203,   148,   149,   150,   151,   152,   153,   154,   264,   265,
     266,   155,   156,   324,   157,   158,   159,   197,   278,   329,
     279,   160,   161,   162,   237
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -286
static const yytype_int16 yypact[] =
{
     625,  -286,    35,   -20,  -286,  -286,  -286,  -286,  -286,  -286,
    -286,    69,   625,  -286,  -286,    33,    65,   119,    32,   165,
      75,    13,  -286,  -286,   100,    80,  -286,  -286,  -286,    35,
    -286,   125,  -286,   168,    80,  -286,   174,   202,    46,  -286,
      80,   185,   159,   203,    80,    80,  -286,   204,   215,   229,
     252,   261,   273,   274,  -286,  -286,   200,    53,  -286,     6,
      99,   118,  -286,   248,     2,   251,     4,   221,   271,  -286,
    -286,    80,  -286,  -286,   280,    80,    80,    -9,    80,  -286,
      80,  -286,  -286,  -286,  -286,   -23,  -286,    -7,   189,  -286,
    -286,   253,  -286,  -286,   259,  -286,  -286,   281,   286,  -286,
      80,  -286,   316,   263,   266,   301,  -286,  -286,    35,   275,
     584,   300,   225,   333,   345,    12,   293,  -286,   325,   324,
      80,   295,  -286,   330,  -286,  -286,  -286,  -286,   110,   329,
    -286,    -8,    -8,    -8,  -286,  -286,  -286,    -3,   332,    -8,
     299,   302,   424,    -8,    -8,   464,  -286,   312,  -286,  -286,
     424,   621,   317,   181,  -286,  -286,   313,   743,   311,  -286,
    -286,   256,  -286,   231,  -286,    35,    10,   320,   319,   327,
     321,   323,  -286,   328,   161,   316,   352,  -286,   357,   331,
    -286,     7,   366,   366,  -286,  -286,   360,    -8,  -286,   313,
      -8,    -8,   584,   337,  -286,    34,   743,    20,  -286,  -286,
    -286,   584,  -286,   346,   246,   335,   338,  -286,   339,    -8,
      -8,    -8,    -8,    -8,   -18,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,  -286,    -8,  -286,
    -286,   368,   376,  -286,  -286,  -286,   350,  -286,   373,   352,
    -286,  -286,   300,   385,   389,  -286,  -286,    35,    42,  -286,
    -286,   355,    88,    95,   117,   504,   424,  -286,    -8,  -286,
     544,   358,    -8,   415,   -21,   584,   372,    -8,    -8,    -8,
     743,   743,   683,   778,   794,   392,  -286,    -6,  -286,  -286,
     808,   821,   326,   326,   146,   146,    92,    92,    79,    79,
     366,   366,   177,  -286,  -286,    26,   176,  -286,  -286,   188,
     141,   250,   365,  -286,   192,   394,   395,    80,    -8,  -286,
     424,   424,  -286,  -286,   743,  -286,    -8,   704,  -286,  -286,
     584,   264,    -8,   313,   371,   143,   150,    -8,  -286,    28,
    -286,    -8,  -286,   367,   350,  -286,   399,  -286,  -286,   400,
     426,    21,   304,   406,   410,  -286,  -286,    35,  -286,   151,
     396,  -286,   152,  -286,   344,   725,    -8,  -286,  -286,   761,
      -6,  -286,   257,    26,  -286,  -286,   433,  -286,  -286,   304,
    -286,   384,   381,  -286,   412,  -286,   424,   386,  -286,   244,
    -286,  -286,   391,  -286,  -286,   425,  -286,  -286,  -286,    -8,
     427,   401,   397,   193,  -286,  -286,   403,  -286,   301,   196,
     404,  -286
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -286,  -286,  -286,   456,  -286,    25,   -29,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,   411,   -44,  -286,  -286,  -286,
     414,  -286,  -286,  -286,  -286,  -286,  -286,   303,  -286,   362,
    -286,  -286,   147,    82,  -286,  -286,  -286,   113,   142,  -286,
     245,   -33,  -286,   243,  -286,   375,  -147,  -106,  -127,   340,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,   224,
    -286,  -286,  -137,   101,   -72,  -286,  -286,  -182,  -286,  -286,
    -269,  -286,  -286,   342,  -285
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -134
static const yytype_int16 yytable[] =
{
      43,    46,   189,   200,   145,   252,   195,    69,   330,   254,
     333,    72,    73,    83,   185,   194,   275,    91,   198,    94,
     108,   131,    25,   194,   276,    15,   132,   133,   275,   103,
     134,   104,   135,   136,   181,   113,   276,    15,    99,   232,
     262,   263,   101,   102,    83,   106,   186,   107,   233,   -96,
     234,   319,   235,   253,   113,   232,   186,   114,   277,   182,
     183,   184,   105,   168,   233,   143,    23,   122,   144,    26,
     187,    92,   196,    95,    34,    84,   114,    85,   382,   129,
     187,   236,   339,   340,    38,    49,   255,   175,    50,     2,
     258,   380,    49,   368,    51,   260,     2,   259,   360,    52,
      53,    51,    28,    29,   209,   361,    52,    53,   257,   313,
     225,   226,   306,    54,   227,   196,   307,    37,    55,   196,
      54,   223,   224,   225,   226,    82,   349,   227,   198,   194,
     323,   325,   326,   198,    30,    31,   231,   270,   271,   272,
     273,   274,    40,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,    41,   292,    49,   258,   321,
      50,     2,   309,   350,   351,   209,    51,    44,    86,   310,
      87,    52,    53,   221,   222,   223,   224,   225,   226,   352,
     178,   227,   179,   194,   194,    54,   314,   258,    32,    33,
     317,   311,   210,   211,   198,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      45,   306,   227,   209,   354,   338,    47,   357,   305,   379,
     209,   258,   209,    70,   358,   375,   377,   198,    49,   387,
     -30,   244,     2,   245,    35,    36,   196,    51,   205,   206,
     207,   208,    52,    53,   198,    71,   334,   331,   335,   194,
     355,    48,   323,    74,   332,   359,    54,    75,   336,   362,
     337,   117,   344,   396,   345,   397,   178,    77,   400,    81,
      29,    76,   210,   211,   348,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      96,    97,   227,   131,   164,   165,   135,   136,   132,   133,
     230,   165,   134,    78,   135,   136,   137,   262,   263,   138,
     139,   339,   340,   389,   209,    79,    80,    90,   374,   140,
      93,    98,   100,   120,   118,  -132,  -132,   141,   121,   142,
     119,   123,   125,   131,   381,   126,  -132,   143,   132,   133,
     144,   127,   134,   108,   135,   136,   137,   130,   166,   138,
     139,   219,   220,   221,   222,   223,   224,   225,   226,   140,
     167,   227,   172,   173,   174,   -85,   -85,   141,   176,   142,
     177,   180,   190,   131,   188,   191,   -85,   143,   132,   133,
     144,   199,   134,   209,   135,   136,   137,   228,   204,   138,
     139,   238,   239,   241,   242,   247,   240,   249,   243,   140,
     250,   227,   251,   256,   261,  -133,  -133,   141,   267,   142,
     293,   268,   269,   131,   294,   298,  -133,   143,   132,   133,
     144,   295,   134,   302,   135,   136,   137,   303,   308,   138,
     139,   316,   318,   322,   328,   343,   346,   363,   347,   140,
     356,   365,   366,   367,   372,   -86,   -86,   141,   373,   142,
     383,   385,   376,   131,   386,   388,   -86,   143,   132,   133,
     144,   390,   134,   391,   135,   136,   137,   393,    27,   138,
     139,   395,    88,   394,   398,    89,   401,   169,   246,   140,
     399,   364,   384,   369,   300,   301,   163,   141,   320,   142,
     392,   202,     0,   131,     0,   192,     0,   143,   132,   133,
     144,     0,   134,   229,   135,   136,   137,     0,     0,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,   141,     0,   142,
       0,     0,     0,   131,     0,     0,   -97,   143,   132,   133,
     144,     0,   134,     0,   135,   136,   137,     0,     0,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,   141,     0,   142,
       0,     0,     0,   131,     0,     0,   312,   143,   132,   133,
     144,     0,   134,     0,   135,   136,   137,     0,     0,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,   141,     0,   142,
       0,     0,     0,   131,     0,     0,   315,   143,   132,   133,
     144,     0,   134,     0,   135,   136,   137,     0,     0,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,   141,     0,   142,
     131,     0,     0,     0,     0,   132,   133,   143,     0,   134,
     144,   135,   136,   181,     1,     0,   138,   139,     2,     0,
       0,     0,     3,     4,     0,     5,     6,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,   201,     0,   143,     0,     0,   144,   210,   211,
     327,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,     0,   227,   210,
     211,   353,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,     0,   227,
     210,   211,   378,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   210,   211,
     227,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,     0,   211,   227,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,   227,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,     0,     0,   227,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,     0,   227,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,     0,     0,   227,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,     0,   227
};

static const yytype_int16 yycheck[] =
{
      29,    34,   139,   150,   110,   187,   143,    40,   277,   191,
     295,    44,    45,    57,    17,   142,    34,    15,   145,    15,
      43,    29,    42,   150,    42,     0,    34,    35,    34,    38,
      38,    40,    40,    41,    42,    42,    42,    12,    71,    29,
      61,    62,    75,    76,    88,    78,    49,    80,    38,    72,
      40,    72,    42,   190,    42,    29,    49,    64,    76,   131,
     132,   133,    71,    51,    38,    73,    31,   100,    76,     0,
      73,    69,   144,    69,    42,    69,    64,    71,   363,   108,
      73,    71,    61,    62,    71,    39,   192,   120,    42,    43,
      70,   360,    39,    72,    48,   201,    43,    77,    70,    53,
      54,    48,    69,    70,    70,    77,    53,    54,    74,   256,
      31,    32,    70,    67,    35,   187,    74,    42,    72,   191,
      67,    29,    30,    31,    32,    72,   308,    35,   255,   256,
     267,   268,   269,   260,    69,    70,   165,   209,   210,   211,
     212,   213,    42,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,    75,   228,    39,    70,   265,
      42,    43,    74,   310,   311,    70,    48,    42,    69,    74,
      71,    53,    54,    27,    28,    29,    30,    31,    32,   316,
      70,    35,    72,   310,   311,    67,   258,    70,    69,    70,
     262,    74,    15,    16,   321,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      42,    70,    35,    70,   320,    74,    42,    74,   247,   356,
      70,    70,    70,    38,    74,    74,    74,   354,    39,   376,
      71,    70,    43,    72,    69,    70,   308,    48,    57,    58,
      59,    60,    53,    54,   371,    42,    70,    70,    72,   376,
     322,    49,   389,    49,    77,   327,    67,    42,    70,   331,
      72,    72,    70,    70,    72,    72,    70,    15,    72,    69,
      70,    42,    15,    16,   307,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      69,    70,    35,    29,    69,    70,    40,    41,    34,    35,
      69,    70,    38,    42,    40,    41,    42,    61,    62,    45,
      46,    61,    62,    69,    70,    42,    42,    69,   347,    55,
      69,    50,    42,    42,    71,    61,    62,    63,    42,    65,
      71,    15,    69,    29,    77,    69,    72,    73,    34,    35,
      76,    40,    38,    43,    40,    41,    42,    72,    15,    45,
      46,    25,    26,    27,    28,    29,    30,    31,    32,    55,
      15,    35,    69,    38,    40,    61,    62,    63,    73,    65,
      40,    42,    73,    29,    42,    73,    72,    73,    34,    35,
      76,    69,    38,    70,    40,    41,    42,    76,    71,    45,
      46,    71,    73,    72,    71,    43,    69,    40,    70,    55,
      69,    35,    42,    66,    58,    61,    62,    63,    73,    65,
      42,    73,    73,    29,    38,    42,    72,    73,    34,    35,
      76,    71,    38,    38,    40,    41,    42,    38,    73,    45,
      46,    73,    17,    61,    42,    70,    42,    70,    43,    55,
      69,    42,    42,    17,    38,    61,    62,    63,    38,    65,
      17,    70,    56,    29,    42,    69,    72,    73,    34,    35,
      76,    70,    38,    38,    40,    41,    42,    40,    12,    45,
      46,    74,    61,    72,    71,    61,    72,   115,   175,    55,
     398,   334,   369,   341,   239,   242,   111,    63,   264,    65,
     389,   151,    -1,    29,    -1,    71,    -1,    73,    34,    35,
      76,    -1,    38,   161,    40,    41,    42,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    -1,    -1,    29,    -1,    -1,    72,    73,    34,    35,
      76,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    -1,    -1,    29,    -1,    -1,    72,    73,    34,    35,
      76,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      -1,    -1,    -1,    29,    -1,    -1,    72,    73,    34,    35,
      76,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      29,    -1,    -1,    -1,    -1,    34,    35,    73,    -1,    38,
      76,    40,    41,    42,    39,    -1,    45,    46,    43,    -1,
      -1,    -1,    47,    48,    -1,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    71,    -1,    73,    -1,    -1,    76,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    35,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    35,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    15,    16,
      35,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    16,    35,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    35,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    35,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    35,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    35,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    43,    47,    48,    50,    51,    52,    53,    54,
      64,    79,    80,    81,    82,    83,    85,    86,    87,    88,
      89,    90,    91,    31,    84,    42,     0,    81,    69,    70,
      69,    70,    69,    70,    42,    69,    70,    42,    71,    92,
      42,    75,   119,    84,    42,    42,   119,    42,    49,    39,
      42,    48,    53,    54,    67,    72,    83,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   104,   117,   119,
      38,    42,   119,   119,    49,    42,    42,    15,    42,    42,
      42,    69,    72,    94,    69,    71,    69,    71,    93,    98,
      69,    15,    69,    69,    15,    69,    69,    70,    50,   119,
      42,   119,   119,    38,    40,    71,   119,   119,    43,   120,
     121,   122,   123,    42,    64,   106,   107,    72,    71,    71,
      42,    42,   119,    15,   105,    69,    69,    40,   111,    84,
      72,    29,    34,    35,    38,    40,    41,    42,    45,    46,
      55,    63,    65,    73,    76,   125,   126,   127,   129,   130,
     131,   132,   133,   134,   135,   139,   140,   142,   143,   144,
     149,   150,   151,   123,    69,    70,    15,    15,    51,   107,
     112,   113,    69,    38,    40,   119,    73,    40,    70,    72,
      42,    42,   142,   142,   142,    17,    49,    73,    42,   140,
      73,    73,    71,   124,   126,   140,   142,   145,   126,    69,
     124,    71,   127,   128,    71,    57,    58,    59,    60,    70,
      15,    16,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    35,    76,   151,
      69,    84,    29,    38,    40,    42,    71,   152,    71,    73,
      69,    72,    71,    70,    70,    72,   105,    43,   118,    40,
      69,    42,   145,   140,   145,   125,    66,    74,    70,    77,
     125,    58,    61,    62,   136,   137,   138,    73,    73,    73,
     142,   142,   142,   142,   142,    34,    42,    76,   146,   148,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,    42,    38,    71,   109,   110,    42,   108,
     118,   121,    38,    38,   103,    84,    70,    74,    73,    74,
      74,    74,    72,   124,   142,    72,    73,   142,    17,    72,
     137,   125,    61,   140,   141,   140,   140,    17,    42,   147,
     148,    70,    77,   152,    70,    72,    70,    72,    74,    61,
      62,   114,   116,    70,    70,    72,    42,    43,   119,   145,
     124,   124,   140,    17,   125,   142,    69,    74,    74,   142,
      70,    77,   142,    70,   110,    42,    42,    17,    72,   116,
     115,   125,    38,    38,    84,    74,    56,    74,    17,   140,
     148,    77,   152,    17,   115,    70,    42,   124,    69,    69,
      70,    38,   141,    40,    72,    74,    70,    72,    71,   111,
      72,    72
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
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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






/*----------.
| yyparse.  |
`----------*/

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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 350 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 9:
#line 352 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 10:
#line 354 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 12:
#line 359 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(1) - (4)].integer) == SCC_VAR_BIT && !(yyvsp[(2) - (4)].integer))
    scc_ns_decl(sccp->ns,NULL,(yyvsp[(3) - (4)].str),SCC_RES_BVAR,(yyvsp[(1) - (4)].integer),(yyvsp[(4) - (4)].integer));
  else
    scc_ns_decl(sccp->ns,NULL,(yyvsp[(3) - (4)].str),SCC_RES_VAR,(yyvsp[(1) - (4)].integer) | (yyvsp[(2) - (4)].integer),(yyvsp[(4) - (4)].integer));

  (yyval.integer) = (yyvsp[(1) - (4)].integer);
;}
    break;

  case 13:
#line 368 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(1) - (5)].integer) == SCC_VAR_BIT && !(yyvsp[(3) - (5)].integer))
    scc_ns_decl(sccp->ns,NULL,(yyvsp[(4) - (5)].str),SCC_RES_BVAR,(yyvsp[(1) - (5)].integer),(yyvsp[(5) - (5)].integer));
  else
    scc_ns_decl(sccp->ns,NULL,(yyvsp[(4) - (5)].str),SCC_RES_VAR,(yyvsp[(1) - (5)].integer) | (yyvsp[(3) - (5)].integer),(yyvsp[(5) - (5)].integer));

  (yyval.integer) = (yyvsp[(1) - (5)].integer);
;}
    break;

  case 14:
#line 379 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = 0;
;}
    break;

  case 15:
#line 383 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = SCC_VAR_ARRAY;
;}
    break;

  case 16:
#line 391 "/usr/tmp/scc_parse.y"
    {
  scc_ns_decl(sccp->ns,NULL,(yyvsp[(2) - (3)].str),SCC_RES_ROOM,0,(yyvsp[(3) - (3)].integer));
;}
    break;

  case 17:
#line 395 "/usr/tmp/scc_parse.y"
    {
  scc_ns_decl(sccp->ns,NULL,(yyvsp[(3) - (4)].str),SCC_RES_ROOM,0,(yyvsp[(4) - (4)].integer));
;}
    break;

  case 18:
#line 401 "/usr/tmp/scc_parse.y"
    {
  scc_ns_decl(sccp->ns,NULL,(yyvsp[(2) - (3)].str),(yyvsp[(1) - (3)].integer),0,(yyvsp[(3) - (3)].integer));
;}
    break;

  case 19:
#line 405 "/usr/tmp/scc_parse.y"
    {
  scc_ns_decl(sccp->ns,NULL,(yyvsp[(3) - (4)].str),(yyvsp[(1) - (4)].integer),0,(yyvsp[(4) - (4)].integer));
;}
    break;

  case 20:
#line 411 "/usr/tmp/scc_parse.y"
    { 
  (yyval.integer) = SCC_RES_ACTOR;
;}
    break;

  case 21:
#line 415 "/usr/tmp/scc_parse.y"
    { 
  (yyval.integer) = SCC_RES_VERB;
;}
    break;

  case 22:
#line 419 "/usr/tmp/scc_parse.y"
    { 
  (yyval.integer) = SCC_RES_CLASS;
;}
    break;

  case 23:
#line 426 "/usr/tmp/scc_parse.y"
    {
  scc_ns_decl(sccp->ns,(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(1) - (5)].integer),0,(yyvsp[(5) - (5)].integer));
  (yyval.integer) = (yyvsp[(1) - (5)].integer); // hack to propagte the type
;}
    break;

  case 24:
#line 431 "/usr/tmp/scc_parse.y"
    {
  scc_ns_decl(sccp->ns,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(1) - (6)].integer),0,(yyvsp[(6) - (6)].integer));
;}
    break;

  case 26:
#line 438 "/usr/tmp/scc_parse.y"
    { 
  (yyval.integer) = SCC_RES_OBJ;
;}
    break;

  case 27:
#line 442 "/usr/tmp/scc_parse.y"
    { 
  (yyval.integer) = SCC_RES_SCR;
;}
    break;

  case 28:
#line 446 "/usr/tmp/scc_parse.y"
    { 
  (yyval.integer) = SCC_RES_VOICE;
;}
    break;

  case 29:
#line 450 "/usr/tmp/scc_parse.y"
    { 
  (yyval.integer) = SCC_RES_CYCL;
;}
    break;

  case 30:
#line 458 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym = scc_ns_decl(sccp->ns,NULL,(yyvsp[(2) - (3)].str),SCC_RES_ROOM,0,(yyvsp[(3) - (3)].integer));
  scc_ns_get_rid(sccp->ns,sym);
  scc_ns_push(sccp->ns,sym);
  sccp->roobj = scc_roobj_new(sccp->target,sym);
;}
    break;

  case 31:
#line 468 "/usr/tmp/scc_parse.y"
    {
  scc_log(LOG_DBG,"Room done :)\n");
  sccp->local_scr = sccp->target->max_global_scr;
  memset(&sccp->ns->as[SCC_RES_LSCR],0,0x10000/8);
  sccp->cycl = 1;
  scc_ns_clear(sccp->ns,SCC_RES_CYCL);
  scc_ns_pop(sccp->ns);

  if(!sccp->roobj->scr &&
     !sccp->roobj->lscr &&
     !sccp->roobj->obj &&
     !sccp->roobj->res &&
     !sccp->roobj->cycl &&
     !sccp->roobj->image) {
    scc_log(LOG_DBG,"Room is empty, only declarations.\n");
    scc_roobj_free(sccp->roobj);
  } else {
    sccp->roobj->next = sccp->roobj_list;
    sccp->roobj_list = sccp->roobj;
  }
  sccp->roobj = NULL;
;}
    break;

  case 37:
#line 504 "/usr/tmp/scc_parse.y"
    {
  if(!(yyvsp[(1) - (4)].sym)->rid) scc_ns_get_rid(sccp->ns,(yyvsp[(1) - (4)].sym));
  if((yyvsp[(3) - (4)].scr)) {
    (yyvsp[(3) - (4)].scr)->sym = (yyvsp[(1) - (4)].sym);
    scc_roobj_add_scr(sccp->roobj,(yyvsp[(3) - (4)].scr));
  }

  scc_ns_clear(sccp->ns,SCC_RES_LVAR);
  scc_ns_pop(sccp->ns);
;}
    break;

  case 38:
#line 516 "/usr/tmp/scc_parse.y"
    {
  // well :)
  scc_ns_clear(sccp->ns,SCC_RES_LVAR);
  scc_ns_pop(sccp->ns);
;}
    break;

  case 39:
#line 523 "/usr/tmp/scc_parse.y"
    {
  if(!(yyvsp[(1) - (5)].sym)->rid) scc_ns_get_rid(sccp->ns,(yyvsp[(1) - (5)].sym));
  // add the obj to the room
  scc_roobj_add_obj(sccp->roobj,sccp->obj);
  sccp->obj = NULL;
;}
    break;

  case 40:
#line 531 "/usr/tmp/scc_parse.y"
    {
  scc_roobj_obj_free(sccp->obj);
  sccp->obj = NULL;
;}
    break;

  case 41:
#line 536 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 42:
#line 538 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 43:
#line 540 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 44:
#line 542 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 45:
#line 544 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 46:
#line 546 "/usr/tmp/scc_parse.y"
    {;}
    break;

  case 47:
#line 550 "/usr/tmp/scc_parse.y"
    {
  scc_scr_arg_t* a = (yyvsp[(5) - (7)].arg);
  scc_symbol_t* s;

  s = scc_ns_decl(sccp->ns,NULL,(yyvsp[(3) - (7)].str),(yyvsp[(1) - (7)].integer),0,(yyvsp[(7) - (7)].integer));
  if(!s) SCC_ABORT((yylsp[(3) - (7)]),"Failed to declare script %s.\n",(yyvsp[(3) - (7)].str));

  if((yyvsp[(1) - (7)].integer) == SCC_RES_LSCR && s->addr < 0 &&
     strcmp((yyvsp[(3) - (7)].str),"entry") && strcmp((yyvsp[(3) - (7)].str),"exit"))
    if(!scc_ns_alloc_sym_addr(sccp->ns,s,&sccp->local_scr))
      SCC_ABORT((yylsp[(3) - (7)]),"Failed to allocate local script address.\n");

  scc_ns_push(sccp->ns,s);

  // declare the arguments
  sccp->local_vars = 0;
  while(a) {
    scc_ns_decl(sccp->ns,NULL,a->sym,SCC_RES_LVAR,a->type,sccp->local_vars);
    sccp->local_vars++;
    a = a->next;
  }
  (yyval.sym) = s;
;}
    break;

  case 48:
#line 576 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym;

  if(sccp->obj)
    SCC_ABORT((yylsp[(1) - (3)]),"Something went wrong with object declarations.\n");


  sym = scc_ns_decl(sccp->ns,NULL,(yyvsp[(2) - (3)].str),SCC_RES_OBJ,0,(yyvsp[(3) - (3)].integer));
  if(!sym) SCC_ABORT((yylsp[(1) - (3)]),"Failed to declare object %s.\n",(yyvsp[(2) - (3)].str));
  
  sccp->obj = scc_roobj_obj_new(sym);
  (yyval.sym) = sym;
;}
    break;

  case 51:
#line 598 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (4)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (4)]),"Invalid operator for parameter setting.\n");

  scc_parser_find_res(sccp,&(yyvsp[(3) - (4)].str));
  if(!scc_roobj_set_param(sccp->roobj,sccp->ns,(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str)))
    SCC_ABORT((yylsp[(1) - (4)]),"Failed to set room %s.\n",(yyvsp[(1) - (4)].str));

  // add dep
  if(sccp->do_deps) scc_parser_add_dep(sccp,(yyvsp[(3) - (4)].str));
;}
    break;

  case 52:
#line 610 "/usr/tmp/scc_parse.y"
    {
  int i;
  if((yyvsp[(2) - (6)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (6)]),"Invalid operator for parameter setting.\n");

  for(i = 0 ; (yyvsp[(4) - (6)].strlist)[i] ; i++) {
    if((yyvsp[(4) - (6)].strlist)[i][0] == '\0') continue;
    if(!scc_roobj_set_zplane(sccp->roobj,i+1,(yyvsp[(4) - (6)].strlist)[i]))
      SCC_ABORT((yylsp[(1) - (6)]),"Failed to set room zplane %d.\n",i+1);
  }
;}
    break;

  case 53:
#line 622 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (4)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (4)]),"Invalid operator for parameter setting.\n");

  if(strcmp((yyvsp[(1) - (4)].str),"trans"))
    SCC_ABORT((yylsp[(1) - (4)]),"Rooms have no parameter named %s.\n",(yyvsp[(1) - (4)].str));

  if((yyvsp[(3) - (4)].integer) < 0 || (yyvsp[(3) - (4)].integer) > 255)
    SCC_ABORT((yylsp[(3) - (4)]),"Invalid transparent color index: %d\n",(yyvsp[(3) - (4)].integer));

  sccp->roobj->trans = (yyvsp[(3) - (4)].integer);
;}
    break;

  case 54:
#line 638 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (11)].integer) != '=')
    SCC_ABORT((yylsp[(3) - (11)]),"Invalid operator for cycle declaration.\n");

  if(!scc_roobj_add_cycl(sccp->roobj,(yyvsp[(1) - (11)].sym),(yyvsp[(4) - (11)].integer),(yyvsp[(6) - (11)].integer),(yyvsp[(8) - (11)].integer),(yyvsp[(10) - (11)].integer)))
    SCC_ABORT((yylsp[(1) - (11)]),"Failed to add cycl.\n");
;}
    break;

  case 55:
#line 648 "/usr/tmp/scc_parse.y"
    {
  (yyval.sym) = scc_ns_decl(sccp->ns,NULL,(yyvsp[(2) - (3)].str),SCC_RES_CYCL,0,(yyvsp[(3) - (3)].integer));
  if(!(yyval.sym)) SCC_ABORT((yylsp[(1) - (3)]),"Cycl declaration failed.\n");
  if((yyval.sym)->addr < 0 && !scc_ns_alloc_sym_addr(sccp->ns,(yyval.sym),&sccp->cycl))
      SCC_ABORT((yylsp[(1) - (3)]),"Failed to allocate cycle address.\n");
;}
    break;

  case 56:
#line 657 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (7)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (7)]),"Invalid operator for voice declaration.\n");

  if(!(yyvsp[(1) - (7)].sym)->rid) scc_ns_get_rid(sccp->ns,(yyvsp[(1) - (7)].sym));

  scc_parser_find_res(sccp,&(yyvsp[(4) - (7)].str));
  if(!scc_roobj_add_voice(sccp->roobj,(yyvsp[(1) - (7)].sym),(yyvsp[(4) - (7)].str),(yyvsp[(6) - (7)].intlist)[0],(yyvsp[(6) - (7)].intlist)+1))
    SCC_ABORT((yylsp[(1) - (7)]),"Failed to add voice.");

  if(sccp->do_deps) scc_parser_add_dep(sccp,(yyvsp[(4) - (7)].str));

  free((yyvsp[(6) - (7)].intlist));
;}
    break;

  case 57:
#line 672 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (5)].integer) != '=')
    SCC_ABORT((yylsp[(3) - (5)]),"Invalid operator for voice declaration.\n");

  if(!(yyvsp[(1) - (5)].sym)->rid) scc_ns_get_rid(sccp->ns,(yyvsp[(1) - (5)].sym));

  scc_parser_find_res(sccp,&(yyvsp[(4) - (5)].str));
  if(!scc_roobj_add_voice(sccp->roobj,(yyvsp[(1) - (5)].sym),(yyvsp[(4) - (5)].str),0,NULL))
    SCC_ABORT((yylsp[(1) - (5)]),"Failed to add voice.");

  if(sccp->do_deps) scc_parser_add_dep(sccp,(yyvsp[(4) - (5)].str));
;}
    break;

  case 58:
#line 687 "/usr/tmp/scc_parse.y"
    {
  (yyval.sym) = scc_ns_decl(sccp->ns,NULL,(yyvsp[(2) - (2)].str),SCC_RES_VOICE,0,-1);
  if(!(yyval.sym)) SCC_ABORT((yylsp[(1) - (2)]),"Declaration failed.\n");
;}
    break;

  case 59:
#line 694 "/usr/tmp/scc_parse.y"
    {
  (yyval.intlist) = malloc(2*sizeof(int));
  (yyval.intlist)[0] = 1;
  (yyval.intlist)[1] = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 60:
#line 700 "/usr/tmp/scc_parse.y"
    {
  int l = (yyvsp[(1) - (3)].intlist)[0]+1;
  (yyval.intlist) = realloc((yyvsp[(1) - (3)].intlist),(l+1)*sizeof(int));
  (yyval.intlist)[l] = (yyvsp[(3) - (3)].integer);
  (yyval.intlist)[0] = l;
;}
    break;

  case 61:
#line 710 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* r = scc_ns_decl(sccp->ns,NULL,(yyvsp[(2) - (4)].str),(yyvsp[(1) - (4)].integer),0,(yyvsp[(3) - (4)].integer));
  
  if((yyvsp[(4) - (4)].str)) {
    scc_parser_find_res(sccp,&(yyvsp[(4) - (4)].str));
    // then we need to add that to the roobj
    if(!sccp->do_deps && !scc_roobj_add_res(sccp->roobj,r,(yyvsp[(4) - (4)].str)))
      SCC_ABORT((yylsp[(2) - (4)]),"Failed to declare %s.\n",(yyvsp[(2) - (4)].str));
    if(sccp->do_deps) scc_parser_add_dep(sccp,(yyvsp[(4) - (4)].str));

    if(!r->rid) scc_ns_get_rid(sccp->ns,r);
  }
  (yyval.integer) = (yyvsp[(1) - (4)].integer); // propagate type  
;}
    break;

  case 62:
#line 725 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* r = scc_ns_decl(sccp->ns,NULL,(yyvsp[(3) - (5)].str),(yyvsp[(1) - (5)].integer),0,(yyvsp[(4) - (5)].integer));
  
  if((yyvsp[(5) - (5)].str)) {
    scc_parser_find_res(sccp,&(yyvsp[(5) - (5)].str));
    // then we need to add that to the roobj
    if(!sccp->do_deps && !scc_roobj_add_res(sccp->roobj,r,(yyvsp[(5) - (5)].str)))
      SCC_ABORT((yylsp[(3) - (5)]),"Failed to declare %s.\n",(yyvsp[(3) - (5)].str));
    if(sccp->do_deps) scc_parser_add_dep(sccp,(yyvsp[(5) - (5)].str));

    if(!r->rid) scc_ns_get_rid(sccp->ns,r);
  }
  (yyval.integer) = (yyvsp[(1) - (5)].integer); // propagate type
;}
    break;

  case 63:
#line 742 "/usr/tmp/scc_parse.y"
    {
  (yyval.str) = NULL;
;}
    break;

  case 64:
#line 746 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(1) - (2)].integer) != '=')
    SCC_ABORT((yylsp[(1) - (2)]),"Invalid operator for resource definition.\n");
  (yyval.str) = (yyvsp[(2) - (2)].str);
;}
    break;

  case 67:
#line 761 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (3)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (3)]),"Invalid operator for parameter setting.\n");

  if(!scc_roobj_obj_set_param(sccp->obj,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)))
    SCC_ABORT((yylsp[(1) - (3)]),"Failed to set object parameter.\n");
;}
    break;

  case 68:
#line 769 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (3)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (3)]),"Invalid operator for parameter setting.\n");

  if(!scc_roobj_obj_set_int_param(sccp->obj,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].integer)))
    SCC_ABORT((yylsp[(1) - (3)]),"Failed to set object parameter.\n");

;}
    break;

  case 69:
#line 778 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (5)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (5)]),"Invalid operator for parameter setting.\n");
  // bitch on the keyword
  if(strcmp((yyvsp[(1) - (5)].str),"states"))
    SCC_ABORT((yylsp[(1) - (5)]),"Expected \"images\".\n");
;}
    break;

  case 70:
#line 786 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym;

  if((yyvsp[(2) - (3)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (3)]),"Invalid operator for parameter setting.\n");

  if(!strcmp((yyvsp[(1) - (3)].str),"owner")) {
    sym = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(3) - (3)].str));
    if(!sym)
      SCC_ABORT((yylsp[(3) - (3)]),"%s is not a declared actor.\n",(yyvsp[(3) - (3)].str));
    if(sym->type != SCC_RES_ACTOR)
      SCC_ABORT((yylsp[(3) - (3)]),"%s is not an actor.\n",sym->sym);
  
    sccp->obj->owner = sym;

  } else if(!strcmp((yyvsp[(1) - (3)].str),"parent")) {
    sym = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(3) - (3)].str));
    if(!sym)
      SCC_ABORT((yylsp[(3) - (3)]),"%s is not a declared object.\n",(yyvsp[(3) - (3)].str));
    if(sym->type != SCC_RES_OBJ)
      SCC_ABORT((yylsp[(3) - (3)]),"%s is not an object.\n",sym->sym);
    if(sym->parent != sccp->roobj->sym)
      SCC_ABORT((yylsp[(3) - (3)]),"%s doesn't belong to room %s.\n",sym->sym,sccp->roobj->sym->sym);

    sccp->obj->parent = sym;
  } else
    SCC_ABORT((yylsp[(1) - (3)]),"Expected 'owner' or 'parent'.\n");
    
;}
    break;

  case 71:
#line 816 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (5)].integer) != '=')
    SCC_ABORT((yylsp[(2) - (5)]),"Invalid operator for parameter setting.\n");
;}
    break;

  case 72:
#line 823 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(1) - (1)].str));

  if(!sym)
    SCC_ABORT((yylsp[(1) - (1)]),"%s is not a declared class.\n",(yyvsp[(1) - (1)].str));

  if(sym->type != SCC_RES_CLASS)
    SCC_ABORT((yylsp[(1) - (1)]),"%s is not a class in the current context.\n",(yyvsp[(1) - (1)].str));

  // allocate an rid
  if(!sym->rid) scc_ns_get_rid(sccp->ns,sym);

  if(!scc_roobj_obj_set_class(sccp->obj,sym))
    SCC_ABORT((yylsp[(1) - (1)]),"Failed to set object class.\n");

;}
    break;

  case 73:
#line 840 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(3) - (3)].str));

  if(!sym)
    SCC_ABORT((yylsp[(3) - (3)]),"%s is not a declared class.\n",(yyvsp[(3) - (3)].str));

  if(sym->type != SCC_RES_CLASS)
    SCC_ABORT((yylsp[(3) - (3)]),"%s is not a class in the current context.\n",(yyvsp[(3) - (3)].str));

  // allocate an rid
  if(!sym->rid) scc_ns_get_rid(sccp->ns,sym);

  if(!scc_roobj_obj_set_class(sccp->obj,sym))
    SCC_ABORT((yylsp[(3) - (3)]),"Failed to set object class.\n");
;}
    break;

  case 76:
#line 862 "/usr/tmp/scc_parse.y"
    {
  scc_parser_find_res(sccp,&(yyvsp[(6) - (7)].str));
  if(!scc_roobj_obj_add_state(sccp->obj,(yyvsp[(2) - (7)].integer),(yyvsp[(4) - (7)].integer),(yyvsp[(6) - (7)].str),NULL))
    SCC_ABORT((yylsp[(1) - (7)]),"Failed to add room state\n");
  if(sccp->do_deps) scc_parser_add_dep(sccp,(yyvsp[(6) - (7)].str));
;}
    break;

  case 77:
#line 869 "/usr/tmp/scc_parse.y"
    {
  scc_parser_find_res(sccp,&(yyvsp[(6) - (11)].str));
  if(!scc_roobj_obj_add_state(sccp->obj,(yyvsp[(2) - (11)].integer),(yyvsp[(4) - (11)].integer),(yyvsp[(6) - (11)].str),(yyvsp[(9) - (11)].strlist)))
    SCC_ABORT((yylsp[(2) - (11)]),"Failed to add room state.\n");
  if(sccp->do_deps) scc_parser_add_dep(sccp,(yyvsp[(6) - (11)].str));
;}
    break;

  case 78:
#line 878 "/usr/tmp/scc_parse.y"
    {
  scc_parser_find_res(sccp,&(yyvsp[(1) - (1)].str));
  scc_parser_add_dep(sccp,(yyvsp[(1) - (1)].str));
  (yyval.strlist) = malloc(2*sizeof(char*));
  (yyval.strlist)[0] = (yyvsp[(1) - (1)].str);
  (yyval.strlist)[1] = NULL;
;}
    break;

  case 79:
#line 886 "/usr/tmp/scc_parse.y"
    {
  int l;
  scc_parser_find_res(sccp,&(yyvsp[(3) - (3)].str));
  scc_parser_add_dep(sccp,(yyvsp[(3) - (3)].str));
  for(l = 0 ; (yyvsp[(1) - (3)].strlist)[l] ; l++);
  (yyval.strlist) = realloc((yyvsp[(1) - (3)].strlist),(l+2)*sizeof(char*));
  (yyval.strlist)[l] = (yyvsp[(3) - (3)].str);
  (yyval.strlist)[l+1] = NULL;
;}
    break;

  case 80:
#line 898 "/usr/tmp/scc_parse.y"
    {
;}
    break;

  case 81:
#line 901 "/usr/tmp/scc_parse.y"
    {
  scc_verb_script_t* v,*l;
  scc_script_t* scr;

  for(v = (yyvsp[(4) - (5)].vscr) ; v ; l = v, v = v->next,free(l) ) {
    if(!sccp->do_deps && v->inst)
      scr = scc_script_new(sccp->ns,v->inst,SCC_OP_VERB_RET,v->next ? 0 : 1);
    else
      scr = calloc(1,sizeof(scc_script_t));
    scr->sym = v->sym;
    if(!scc_roobj_obj_add_verb(sccp->obj,scr))
      SCC_ABORT((yylsp[(1) - (5)]),"Failed to add verb %s.\n",v->sym ? v->sym->sym : "default");
  }    
  scc_ns_clear(sccp->ns,SCC_RES_LVAR);
  scc_ns_pop(sccp->ns);
;}
    break;

  case 82:
#line 920 "/usr/tmp/scc_parse.y"
    {
  scc_scr_arg_t* a = (yyvsp[(3) - (4)].arg);
  // push the obj for the local vars
  scc_ns_push(sccp->ns,sccp->obj->sym);

  // declare the arguments
  sccp->local_vars = 0;
  while(a) {
    scc_ns_decl(sccp->ns,NULL,a->sym,SCC_RES_LVAR,a->type,sccp->local_vars);
    sccp->local_vars++;
    a = a->next;
  }
;}
    break;

  case 83:
#line 936 "/usr/tmp/scc_parse.y"
    {
  (yyval.vscr) = calloc(1,sizeof(scc_verb_script_t));
  (yyval.vscr)->sym = (yyvsp[(1) - (2)].sym);
  (yyval.vscr)->inst = (yyvsp[(2) - (2)].inst);
;}
    break;

  case 84:
#line 943 "/usr/tmp/scc_parse.y"
    {
  (yyval.vscr) = (yyvsp[(1) - (3)].vscr);
  for(; (yyvsp[(1) - (3)].vscr) ; (yyvsp[(1) - (3)].vscr) = (yyvsp[(1) - (3)].vscr)->next) {
    if((yyvsp[(1) - (3)].vscr)->sym == (yyvsp[(2) - (3)].sym))
      SCC_ABORT((yylsp[(2) - (3)]),"Verb %s is already defined.\n",
                (yyvsp[(2) - (3)].sym) ? (yyvsp[(2) - (3)].sym)->sym : "default");
    if(!(yyvsp[(1) - (3)].vscr)->next) break;
  }
  (yyvsp[(1) - (3)].vscr)->next = calloc(1,sizeof(scc_verb_script_t));
  (yyvsp[(1) - (3)].vscr) = (yyvsp[(1) - (3)].vscr)->next;
  (yyvsp[(1) - (3)].vscr)->sym = (yyvsp[(2) - (3)].sym);
  (yyvsp[(1) - (3)].vscr)->inst = (yyvsp[(3) - (3)].inst);
;}
    break;

  case 85:
#line 959 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = NULL;
;}
    break;

  case 87:
#line 966 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(2) - (3)].str));
  if(!sym)
    SCC_ABORT((yylsp[(1) - (3)]),"%s is not a declared verb.\n",(yyvsp[(2) - (3)].str));
  
  if(sym->type != SCC_RES_VERB)
    SCC_ABORT((yylsp[(1) - (3)]),"%s is not a verb in the current context.\n",(yyvsp[(2) - (3)].str));

  // allocate an rid
  if(!sym->rid) scc_ns_get_rid(sccp->ns,sym);

  (yyval.sym) = sym;
;}
    break;

  case 88:
#line 980 "/usr/tmp/scc_parse.y"
    {
  (yyval.sym) = NULL;
;}
    break;

  case 89:
#line 988 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = SCC_RES_SCR;
;}
    break;

  case 90:
#line 992 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 91:
#line 998 "/usr/tmp/scc_parse.y"
    {
  (yyval.arg) = NULL;
;}
    break;

  case 92:
#line 1002 "/usr/tmp/scc_parse.y"
    {
  //if($1 == SCC_VAR_BIT)
  //  SCC_ABORT(@1,"Script argument can't be of bit type.\n");

  (yyval.arg) = malloc(sizeof(scc_scr_arg_t));
  (yyval.arg)->next = NULL;
  (yyval.arg)->type = (yyvsp[(1) - (3)].integer) | (yyvsp[(2) - (3)].integer);
  (yyval.arg)->sym = (yyvsp[(3) - (3)].str);
;}
    break;

  case 93:
#line 1012 "/usr/tmp/scc_parse.y"
    {
  scc_scr_arg_t *i,*a = malloc(sizeof(scc_scr_arg_t));
  a->next = NULL;
  a->type = (yyvsp[(3) - (5)].integer) | (yyvsp[(4) - (5)].integer);
  a->sym = (yyvsp[(5) - (5)].str);

  for(i = (yyvsp[(1) - (5)].arg) ; i->next ; i = i->next);
  i->next = a;
  (yyval.arg) = (yyvsp[(1) - (5)].arg);
;}
    break;

  case 94:
#line 1025 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = -1;
;}
    break;

  case 95:
#line 1029 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = (yyvsp[(2) - (2)].integer);
;}
    break;

  case 96:
#line 1035 "/usr/tmp/scc_parse.y"
    {
  (yyval.scr) = NULL;
;}
    break;

  case 97:
#line 1040 "/usr/tmp/scc_parse.y"
    {
  if(sccp->do_deps)
    (yyval.scr) = NULL;
  else {
    (yyval.scr) = scc_script_new(sccp->ns,(yyvsp[(2) - (2)].inst),SCC_OP_SCR_RET,1);
    if(!(yyval.scr))
      SCC_ABORT((yylsp[(1) - (2)]),"Code generation failed.\n");
  }
;}
    break;

  case 100:
#line 1058 "/usr/tmp/scc_parse.y"
    {
;}
    break;

  case 102:
#line 1065 "/usr/tmp/scc_parse.y"
    {
  //if($1 == SCC_VAR_BIT)
  //  SCC_ABORT(@1,"Local bit variable are not possible.\n");

  (yyval.sym) = scc_ns_decl(sccp->ns,NULL,(yyvsp[(3) - (3)].str),SCC_RES_LVAR,(yyvsp[(1) - (3)].integer) | (yyvsp[(2) - (3)].integer),sccp->local_vars);
  if(!(yyval.sym)) SCC_ABORT((yylsp[(1) - (3)]),"Declaration failed.\n");
  sccp->local_vars++;
;}
    break;

  case 103:
#line 1075 "/usr/tmp/scc_parse.y"
    {
  (yyval.sym) = scc_ns_decl(sccp->ns,NULL,(yyvsp[(4) - (4)].str),SCC_RES_LVAR,(yyvsp[(1) - (4)].sym)->subtype | (yyvsp[(3) - (4)].integer),sccp->local_vars);
  if(!(yyval.sym)) SCC_ABORT((yylsp[(4) - (4)]),"Declaration failed.\n");
  sccp->local_vars++;
  (yyval.sym) = (yyvsp[(1) - (4)].sym);
;}
    break;

  case 104:
#line 1083 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (1)].inst);
;}
    break;

  case 105:
#line 1088 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(2) - (3)].inst);
;}
    break;

  case 106:
#line 1094 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (1)].inst);
;}
    break;

  case 107:
#line 1099 "/usr/tmp/scc_parse.y"
    {
  scc_instruct_t* i;
  for(i = (yyvsp[(1) - (2)].inst) ; i->next ; i = i->next);
  i->next = (yyvsp[(2) - (2)].inst);
;}
    break;

  case 110:
#line 1111 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_ST;
  (yyval.inst)->pre = (yyvsp[(1) - (1)].st);
;}
    break;

  case 111:
#line 1118 "/usr/tmp/scc_parse.y"
    {
  scc_loop_t* l = scc_loop_get((yyvsp[(1) - (1)].integer),NULL);
  if(!l)
    SCC_ABORT((yylsp[(1) - (1)]),"Invalid branch instruction.\n");
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_BRANCH;
  (yyval.inst)->subtype = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 112:
#line 1128 "/usr/tmp/scc_parse.y"
    {
  scc_loop_t* l = scc_loop_get((yyvsp[(1) - (2)].integer),(yyvsp[(2) - (2)].str));
  if(!l)
    SCC_ABORT((yylsp[(1) - (2)]),"Invalid branch instruction.\n");
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_BRANCH;
  (yyval.inst)->subtype = (yyvsp[(1) - (2)].integer);
  (yyval.inst)->sym = (yyvsp[(2) - (2)].str);
;}
    break;

  case 113:
#line 1139 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_BRANCH;
  (yyval.inst)->subtype = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 114:
#line 1146 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(1) - (2)].integer) != SCC_BRANCH_RETURN) {
    scc_loop_t* l = scc_loop_get((yyvsp[(1) - (2)].integer),NULL);
    if(!l)
      SCC_ABORT((yylsp[(1) - (2)]),"Invalid branch instruction.\n");
  }
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_BRANCH;
  (yyval.inst)->subtype = (yyvsp[(1) - (2)].integer);
  (yyval.inst)->pre = (yyvsp[(2) - (2)].st);
;}
    break;

  case 115:
#line 1161 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (1)].inst);
;}
    break;

  case 116:
#line 1166 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(2) - (3)].inst);
;}
    break;

  case 117:
#line 1172 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (1)].inst);
;}
    break;

  case 119:
#line 1178 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (1)].inst);
;}
    break;

  case 120:
#line 1184 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (2)].inst);
  (yyval.inst)->body = (yyvsp[(2) - (2)].inst);
  free(scc_loop_pop());
;}
    break;

  case 121:
#line 1190 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (7)].inst);
  (yyval.inst)->subtype = (yyvsp[(3) - (7)].integer);
  (yyval.inst)->cond = (yyvsp[(5) - (7)].st);
  (yyval.inst)->body = (yyvsp[(2) - (7)].inst);
  free(scc_loop_pop());
;}
    break;

  case 122:
#line 1198 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = (yyvsp[(1) - (4)].inst);
  (yyval.inst)->body = (yyvsp[(3) - (4)].inst);
  free(scc_loop_pop());
;}
    break;

  case 123:
#line 1207 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_FOR;
  (yyval.inst)->sym = (yyvsp[(1) - (9)].str);
  (yyval.inst)->pre = (yyvsp[(4) - (9)].st);
  (yyval.inst)->cond = (yyvsp[(6) - (9)].st);
  (yyval.inst)->post = (yyvsp[(8) - (9)].st);
  scc_loop_push((yyval.inst)->type,(yyval.inst)->sym);
;}
    break;

  case 124:
#line 1218 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_WHILE;
  (yyval.inst)->sym = (yyvsp[(1) - (5)].str);
  (yyval.inst)->subtype = (yyvsp[(2) - (5)].integer);
  (yyval.inst)->cond = (yyvsp[(4) - (5)].st);
  scc_loop_push((yyval.inst)->type,(yyval.inst)->sym);
;}
    break;

  case 125:
#line 1229 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_DO;
  (yyval.inst)->sym = (yyvsp[(1) - (2)].str);
  scc_loop_push((yyval.inst)->type,(yyval.inst)->sym);
;}
    break;

  case 126:
#line 1238 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_SWITCH;
  (yyval.inst)->sym = (yyvsp[(1) - (5)].str);
  (yyval.inst)->cond = (yyvsp[(4) - (5)].st);
  scc_loop_push((yyval.inst)->type,(yyval.inst)->sym);
;}
    break;

  case 127:
#line 1248 "/usr/tmp/scc_parse.y"
    {
  (yyval.str) = NULL;
;}
    break;

  case 128:
#line 1252 "/usr/tmp/scc_parse.y"
    {
  (yyval.str) = (yyvsp[(1) - (2)].str);
;}
    break;

  case 129:
#line 1258 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_CUTSCENE;
  (yyval.inst)->cond = (yyvsp[(3) - (5)].st);
  (yyval.inst)->body = (yyvsp[(5) - (5)].inst);
;}
    break;

  case 130:
#line 1266 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_OVERRIDE;
  (yyval.inst)->body = (yyvsp[(2) - (2)].inst);
;}
    break;

  case 131:
#line 1273 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_OVERRIDE;
  (yyval.inst)->body = (yyvsp[(2) - (4)].inst);
  (yyval.inst)->body2 = (yyvsp[(4) - (4)].inst);
;}
    break;

  case 132:
#line 1282 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_CASE;
  (yyval.inst)->cond = (yyvsp[(1) - (2)].st);
  (yyval.inst)->body = (yyvsp[(2) - (2)].inst); 
;}
    break;

  case 133:
#line 1290 "/usr/tmp/scc_parse.y"
    {
  scc_instruct_t *n,*i;

  for(i = (yyvsp[(1) - (3)].inst) ; i->next ; i = i->next);
  if(!i->cond)
    SCC_ABORT((yylsp[(2) - (3)]),"Case statements can't be added after a default.\n");

  n = calloc(1,sizeof(scc_instruct_t));
  n->type = SCC_INST_CASE;
  n->cond = (yyvsp[(2) - (3)].st);
  n->body = (yyvsp[(3) - (3)].inst);

  i->next = n;
  
  (yyval.inst) = (yyvsp[(1) - (3)].inst);
;}
    break;

  case 134:
#line 1309 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 135:
#line 1314 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = NULL;
;}
    break;

  case 136:
#line 1319 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(2) - (3)].st);
;}
    break;

  case 137:
#line 1324 "/usr/tmp/scc_parse.y"
    {
  scc_statement_t* a;
  for(a = (yyvsp[(1) - (4)].st) ; a->next ; a = a->next);
  a->next = (yyvsp[(3) - (4)].st);
  (yyval.st) = (yyvsp[(1) - (4)].st);
;}
    break;

  case 138:
#line 1333 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_IF;
  (yyval.inst)->subtype = (yyvsp[(1) - (5)].integer);
  (yyval.inst)->cond = (yyvsp[(3) - (5)].st);
  (yyval.inst)->body = (yyvsp[(5) - (5)].inst);
;}
    break;

  case 139:
#line 1342 "/usr/tmp/scc_parse.y"
    {
  (yyval.inst) = calloc(1,sizeof(scc_instruct_t));
  (yyval.inst)->type = SCC_INST_IF;
  (yyval.inst)->subtype = (yyvsp[(1) - (7)].integer);
  (yyval.inst)->cond = (yyvsp[(3) - (7)].st);
  (yyval.inst)->body = (yyvsp[(5) - (7)].inst);
  (yyval.inst)->body2 = (yyvsp[(7) - (7)].inst);
;}
    break;

  case 140:
#line 1354 "/usr/tmp/scc_parse.y"
    {
  // single statement stay as-is
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 141:
#line 1359 "/usr/tmp/scc_parse.y"
    {
  scc_statement_t* i;

  // no chain yet, create it
  if((yyvsp[(1) - (3)].st)->type != SCC_ST_CHAIN) {
    (yyval.st) = calloc(1,sizeof(scc_statement_t));
    (yyval.st)->type = SCC_ST_CHAIN;
    // init the chain
    (yyval.st)->val.l = (yyvsp[(1) - (3)].st);
  } else
    (yyval.st) = (yyvsp[(1) - (3)].st);

  // append the new element
  for(i = (yyval.st)->val.l ; i->next ; i = i->next);
  i->next = (yyvsp[(3) - (3)].st);
;}
    break;

  case 142:
#line 1379 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = NULL;
;}
    break;

  case 143:
#line 1383 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 144:
#line 1389 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 145:
#line 1394 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 146:
#line 1399 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* v;

  if((yyvsp[(1) - (4)].st)->type != SCC_ST_VAR)
    SCC_ABORT((yylsp[(1) - (4)]),"%s is not a variable, so it can't be subscripted.\n",
	      (yyvsp[(1) - (4)].st)->val.r->sym);
  v = (yyvsp[(1) - (4)].st)->val.v.r;
  if(!(v->subtype & SCC_VAR_ARRAY))
    SCC_ABORT((yylsp[(1) - (4)]),"%s is not an array variable, so it can't be subscripted.\n",v->sym);
  (yyval.st) = (yyvsp[(1) - (4)].st);
  (yyval.st)->val.v.y = (yyvsp[(3) - (4)].st);
;}
    break;

  case 147:
#line 1413 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* v;

  if((yyvsp[(1) - (6)].st)->type != SCC_ST_VAR)
    SCC_ABORT((yylsp[(1) - (6)]),"%s is not a variable, so it can't be subscripted.\n",
	      (yyvsp[(1) - (6)].st)->val.r->sym);
  v = (yyvsp[(1) - (6)].st)->val.v.r;
  if(!(v->subtype & SCC_VAR_ARRAY))
    SCC_ABORT((yylsp[(1) - (6)]),"%s is not an array variable, so it can't be subscripted.\n",v->sym);
  (yyval.st) = (yyvsp[(1) - (6)].st);
  (yyval.st)->val.v.x = (yyvsp[(3) - (6)].st);
  (yyval.st)->val.v.y = (yyvsp[(5) - (6)].st);
;}
    break;

  case 148:
#line 1428 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 149:
#line 1433 "/usr/tmp/scc_parse.y"
    {
  scc_statement_t* a;
  
  for(a = (yyvsp[(2) - (3)].st) ; a ; a = a->next) {
    if(a->type == SCC_ST_STR ||
       a->type == SCC_ST_LIST)
      SCC_ABORT((yylsp[(2) - (3)]),"Strings and lists can't be used inside a list.\n");
  }

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_LIST;
  (yyval.st)->val.l = (yyvsp[(2) - (3)].st);
;}
    break;

  case 150:
#line 1448 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(1) - (3)].st)->type != SCC_ST_VAR)
    SCC_ABORT((yylsp[(1) - (3)]),"rvalue is not a variable, so it can't be assigned.\n");

  if(!((yyvsp[(1) - (3)].st)->val.v.r->subtype & SCC_VAR_ARRAY) &&
     ((yyvsp[(3) - (3)].st)->type == SCC_ST_STR ||
      (yyvsp[(3) - (3)].st)->type == SCC_ST_LIST))
      SCC_ABORT((yylsp[(1) - (3)]),"list and strings can only be assigned to "
                "array variables.\n");

  if((yyvsp[(1) - (3)].st)->val.v.x && (yyvsp[(3) - (3)].st)->type == SCC_ST_STR)
    SCC_ABORT((yylsp[(1) - (3)]),"Strings can't be assigned to 2-dim arrays.\n");

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_OP;
  (yyval.st)->val.o.type = SCC_OT_ASSIGN;
  (yyval.st)->val.o.op = (yyvsp[(2) - (3)].integer);
  (yyval.st)->val.o.argc = 2;
  (yyval.st)->val.o.argv = (yyvsp[(1) - (3)].st);
  (yyvsp[(1) - (3)].st)->next = (yyvsp[(3) - (3)].st);
;}
    break;

  case 151:
#line 1471 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_OP;
  (yyval.st)->val.o.type = SCC_OT_TERNARY;
  (yyval.st)->val.o.op = (yyvsp[(2) - (5)].integer);
  (yyval.st)->val.o.argc = 3;
  (yyval.st)->val.o.argv = (yyvsp[(1) - (5)].st);
  (yyvsp[(1) - (5)].st)->next = (yyvsp[(3) - (5)].st);
  (yyvsp[(3) - (5)].st)->next = (yyvsp[(5) - (5)].st);
;}
    break;

  case 152:
#line 1483 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),||,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 153:
#line 1488 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),&&,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 154:
#line 1493 "/usr/tmp/scc_parse.y"
    {
  scc_func_t* f;
  scc_statement_t *a,*list;
  char* err;
  
  f = scc_get_func(sccp,"isObjectOfClass");
  if(!f)
    SCC_ABORT((yylsp[(1) - (3)]),"Internal error: isObjectOfClass not found.\n");
  
  // create the arguments
  list = calloc(1,sizeof(scc_statement_t));
  list->type = SCC_ST_LIST;
  list->val.l = (yyvsp[(3) - (3)].st);
  
  (yyvsp[(1) - (3)].st)->next = list;
  
  // create the call
  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_CALL;
  
  (yyval.st)->val.c.func = f;
  (yyval.st)->val.c.argv = (yyvsp[(1) - (3)].st);
  
  for(a = (yyvsp[(1) - (3)].st) ; a ; a = a->next)
    (yyval.st)->val.c.argc++;
  
  err = scc_statement_check_func(&(yyval.st)->val.c);
  if(err)
    SCC_ABORT((yylsp[(1) - (3)]),"%s",err);
;}
    break;

  case 155:
#line 1525 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),|,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 156:
#line 1530 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),&,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 157:
#line 1535 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),!=,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 158:
#line 1540 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),==,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 159:
#line 1545 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),>=,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 160:
#line 1550 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),>,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 161:
#line 1555 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),<=,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 162:
#line 1560 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),<,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 163:
#line 1565 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),-,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 164:
#line 1570 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),+,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 165:
#line 1575 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),/,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 166:
#line 1580 "/usr/tmp/scc_parse.y"
    {
  SCC_BOP((yyval.st),*,(yyvsp[(1) - (3)].st),(yyvsp[(2) - (3)].integer),(yyvsp[(3) - (3)].st));
;}
    break;

  case 167:
#line 1585 "/usr/tmp/scc_parse.y"
    {
   if((yyvsp[(2) - (2)].st)->type == SCC_ST_VAL) {
    (yyvsp[(2) - (2)].st)->val.i = -(yyvsp[(2) - (2)].st)->val.i;
    (yyval.st) = (yyvsp[(2) - (2)].st);
  } else { 
    (yyval.st) = calloc(1,sizeof(scc_statement_t));
    (yyval.st)->type = SCC_ST_OP;
    (yyval.st)->val.o.type = SCC_OT_UNARY;
    (yyval.st)->val.o.op = (yyvsp[(1) - (2)].integer);
    (yyval.st)->val.o.argc = 1;
    (yyval.st)->val.o.argv = (yyvsp[(2) - (2)].st);
  }
;}
    break;

  case 168:
#line 1600 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (2)].st)->type == SCC_ST_VAL) {
    (yyvsp[(2) - (2)].st)->val.i = ! (yyvsp[(2) - (2)].st)->val.i;
    (yyval.st) = (yyvsp[(2) - (2)].st);
  } else { // we call not
    (yyval.st) = calloc(1,sizeof(scc_statement_t));
    (yyval.st)->type = SCC_ST_OP;
    (yyval.st)->val.o.type = SCC_OT_UNARY;
    (yyval.st)->val.o.op = (yyvsp[(1) - (2)].integer);
    (yyval.st)->val.o.argc = 1;
    (yyval.st)->val.o.argv = (yyvsp[(2) - (2)].st);
  }
;}
    break;

  case 169:
#line 1615 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(2) - (2)].st)->type != SCC_ST_VAR)
    SCC_ABORT((yylsp[(1) - (2)]),"Suffix operators can only be used on variables.\n");

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_OP;
  (yyval.st)->val.o.type = SCC_OT_UNARY;
  (yyval.st)->val.o.op = ((yyvsp[(1) - (2)].integer) == INC ? PREINC : PREDEC);
  (yyval.st)->val.o.argc = 1;
  (yyval.st)->val.o.argv = (yyvsp[(2) - (2)].st);
;}
    break;

  case 170:
#line 1628 "/usr/tmp/scc_parse.y"
    {
  if((yyvsp[(1) - (2)].st)->type != SCC_ST_VAR)
    SCC_ABORT((yylsp[(1) - (2)]),"Suffix operators can only be used on variables.\n");

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_OP;
  (yyval.st)->val.o.type = SCC_OT_UNARY;
  (yyval.st)->val.o.op = ((yyvsp[(2) - (2)].integer) == INC) ? POSTINC : POSTDEC;
  (yyval.st)->val.o.argc = 1;
  (yyval.st)->val.o.argv = (yyvsp[(1) - (2)].st);
;}
    break;

  case 171:
#line 1641 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(2) - (3)].st);
;}
    break;

  case 172:
#line 1647 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* v = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(1) - (1)].str));

  if(sccp->do_deps && !v)
    v = scc_ns_decl(sccp->ns,NULL,(yyvsp[(1) - (1)].str),SCC_RES_VAR,SCC_VAR_WORD,-1);

  if(!v)
    SCC_ABORT((yylsp[(1) - (1)]),"%s is not a declared resource.\n",(yyvsp[(1) - (1)].str));

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  if(scc_sym_is_var(v->type)) {
    (yyval.st)->type = SCC_ST_VAR;
    (yyval.st)->val.v.r = v;
  } else {
    (yyval.st)->type = SCC_ST_RES;
    (yyval.st)->val.r = v;
  }
  // allocate rid
  if(!v->rid) scc_ns_get_rid(sccp->ns,v);
;}
    break;

  case 173:
#line 1668 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* v = scc_ns_get_sym(sccp->ns,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));

  if(sccp->do_deps && !v)
    v = scc_ns_decl(sccp->ns,(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),SCC_RES_VAR,SCC_VAR_WORD,-1);

  if(!v)
    SCC_ABORT((yylsp[(1) - (3)]),"%s::%s is not a declared resource.\n",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  if(scc_sym_is_var(v->type)) {
    (yyval.st)->type = SCC_ST_VAR;
    (yyval.st)->val.v.r = v;
  } else {
    (yyval.st)->type = SCC_ST_RES;
    (yyval.st)->val.r = v;
  }
  // allocate rid
  if(!v->rid) scc_ns_get_rid(sccp->ns,v);

;}
    break;

  case 174:
#line 1692 "/usr/tmp/scc_parse.y"
    {
  scc_statement_t *a,*scr,*list;
  scc_func_t* f;
  scc_symbol_t* s;
  char* err;
  int user_script = 0;

  f = scc_get_func(sccp,(yyvsp[(1) - (4)].str));
  if(!f) {
    s = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(1) - (4)].str));
    if(!s || (s->type != SCC_RES_SCR && s->type != SCC_RES_LSCR))
      SCC_ABORT((yylsp[(1) - (4)]),"%s is not a known function or script.\n",(yyvsp[(1) - (4)].str));

    f = scc_get_func(sccp,"startScript0");
    if(!f)
      SCC_ABORT((yylsp[(1) - (4)]),"Internal error: startScriptQuick not found.\n");

    if(!s->rid) scc_ns_get_rid(sccp->ns,s);

    // create the arguments
    scr = calloc(1,sizeof(scc_statement_t));
    scr->type = SCC_ST_RES;
    scr->val.r = s;

    list = calloc(1,sizeof(scc_statement_t));
    list->type = SCC_ST_LIST;
    list->val.l = (yyvsp[(3) - (4)].st);

    scr->next = list;

    (yyvsp[(3) - (4)].st) = scr;
    user_script = 1;
  }

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_CALL;

  (yyval.st)->val.c.func = f;
  (yyval.st)->val.c.user_script = user_script;
  (yyval.st)->val.c.argv = (yyvsp[(3) - (4)].st);

  for(a = (yyvsp[(3) - (4)].st) ; a ; a = a->next)
    (yyval.st)->val.c.argc++;

  err = scc_statement_check_func(&(yyval.st)->val.c);
  if(err)
    SCC_ABORT((yylsp[(1) - (4)]),"%s",err);
;}
    break;

  case 175:
#line 1742 "/usr/tmp/scc_parse.y"
    {
  scc_statement_t *scr,*list;
  scc_func_t* f;
  scc_symbol_t* s;

  s = scc_ns_get_sym(sccp->ns,(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str));
  if(!s || (s->type != SCC_RES_SCR && s->type != SCC_RES_LSCR))
    SCC_ABORT((yylsp[(1) - (6)]),"%s::%s is not a known function or script.\n",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str));

  if(s->type == SCC_RES_LSCR &&
     s->parent != sccp->roobj->sym)
    SCC_ABORT((yylsp[(1) - (6)]),"%s is a local script and %s is not the current room.\n",
              (yyvsp[(3) - (6)].str),(yyvsp[(1) - (6)].str));

  f = scc_get_func(sccp,"startScript0");
  if(!f)
    SCC_ABORT((yylsp[(1) - (6)]),"Internal error: startScript0 not found.\n");

  if(!s->rid) scc_ns_get_rid(sccp->ns,s);

  // create the arguments
  scr = calloc(1,sizeof(scc_statement_t));
  scr->type = SCC_ST_RES;
  scr->val.r = s;
  
  list = calloc(1,sizeof(scc_statement_t));
  list->type = SCC_ST_LIST;
  list->val.l = (yyvsp[(5) - (6)].st);
  
  scr->next = list;

  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_CALL;

  (yyval.st)->val.c.func = f;
  (yyval.st)->val.c.user_script = 1;
  (yyval.st)->val.c.argv = scr;
  (yyval.st)->val.c.argc = 2;
;}
    break;

  case 176:
#line 1785 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = NULL;
;}
    break;

  case 177:
#line 1790 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 178:
#line 1795 "/usr/tmp/scc_parse.y"
    {
  scc_statement_t* i;

  (yyval.st) = (yyvsp[(1) - (3)].st);

  for(i = (yyval.st) ; i->next ; i = i->next);

  i->next = (yyvsp[(3) - (3)].st);
;}
    break;

  case 179:
#line 1806 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 180:
#line 1811 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(2) - (3)].st);
;}
    break;

  case 181:
#line 1817 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = (yyvsp[(1) - (1)].st);
;}
    break;

  case 182:
#line 1822 "/usr/tmp/scc_parse.y"
    {
  scc_statement_t* i;
  
  (yyval.st) = (yyvsp[(1) - (3)].st);
  for(i = (yyval.st) ; i->next ; i = i->next);
  
  i->next = (yyvsp[(3) - (3)].st);
;}
    break;

  case 183:
#line 1833 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(1) - (1)].str));
  scc_statement_t *clsid, *bit;
  
  if(!sym)
    SCC_ABORT((yylsp[(1) - (1)]),"%s is not a declared class.\n",(yyvsp[(1) - (1)].str));
  
  if(sym->type != SCC_RES_CLASS)
    SCC_ABORT((yylsp[(1) - (1)]),"%s is not a class in the current context.\n",(yyvsp[(1) - (1)].str));
  
  // allocate rid
  if(!sym->rid) scc_ns_get_rid(sccp->ns,sym);
  
  // the arg is the class id + 0x80
  clsid = calloc(1,sizeof(scc_statement_t));
  clsid->type = SCC_ST_RES;
  clsid->val.r = sym;
  
  bit = calloc(1,sizeof(scc_statement_t));
  bit->type = SCC_ST_VAL;
  bit->val.i = 0x80;
  
  SCC_BOP((yyval.st),+,clsid,'+',bit);
;}
    break;

  case 184:
#line 1859 "/usr/tmp/scc_parse.y"
    {
  scc_symbol_t* sym = scc_ns_get_sym(sccp->ns,NULL,(yyvsp[(2) - (2)].str));
  
  if(!sym)
    SCC_ABORT((yylsp[(1) - (2)]),"%s is not a declared class.\n",(yyvsp[(2) - (2)].str));
  
  if(sym->type != SCC_RES_CLASS)
    SCC_ABORT((yylsp[(1) - (2)]),"%s is not a class in the current context.\n",(yyvsp[(2) - (2)].str));
  
  // allocate rid
  if(!sym->rid) scc_ns_get_rid(sccp->ns,sym);
  
  // the arg is simply the class id
  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_RES;
  (yyval.st)->val.r = sym;
;}
    break;

  case 185:
#line 1879 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_VAL;
  (yyval.st)->val.i = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 186:
#line 1886 "/usr/tmp/scc_parse.y"
    {
  (yyval.st) = calloc(1,sizeof(scc_statement_t));
  (yyval.st)->type = SCC_ST_STR;
  (yyval.st)->val.s = (yyvsp[(1) - (1)].strvar);
;}
    break;

  case 187:
#line 1893 "/usr/tmp/scc_parse.y"
    {
  (yyval.strvar) = (yyvsp[(1) - (1)].strvar);
;}
    break;

  case 188:
#line 1897 "/usr/tmp/scc_parse.y"
    {
  scc_str_t* s;
  for(s = (yyvsp[(1) - (2)].strvar) ; s->next ; s = s->next);
  s->next = (yyvsp[(2) - (2)].strvar);
  (yyval.strvar) = (yyvsp[(1) - (2)].strvar);
;}
    break;

  case 189:
#line 1906 "/usr/tmp/scc_parse.y"
    {
  (yyval.strvar) = calloc(1,sizeof(scc_str_t));
  (yyval.strvar)->type = SCC_STR_CHAR;
  (yyval.strvar)->str = (yyvsp[(1) - (1)].str);
;}
    break;

  case 190:
#line 1912 "/usr/tmp/scc_parse.y"
    {
  (yyval.strvar) = (yyvsp[(1) - (1)].strvar);
  // for color we have a raw value in str
  if((yyval.strvar)->type != SCC_STR_COLOR) {
    (yyval.strvar)->sym = scc_ns_get_sym(sccp->ns,NULL,(yyval.strvar)->str);
    if(!(yyval.strvar)->sym) // fix me we leak str      
      SCC_ABORT((yylsp[(1) - (1)]),"%s is not a declared variable.\n",(yyval.strvar)->str);

    free((yyval.strvar)->str);
    (yyval.strvar)->str = NULL;

    switch((yyval.strvar)->type) {
    case SCC_STR_VERB:
    case SCC_STR_NAME:
      if((yyval.strvar)->sym->type != SCC_RES_VAR &&
         (yyval.strvar)->sym->type != SCC_RES_LVAR)
        SCC_ABORT((yylsp[(1) - (1)]),"%s is not a variable",(yyval.strvar)->sym->sym);
      break;
    case SCC_STR_VOICE:
      if((yyval.strvar)->sym->type != SCC_RES_VOICE)
        SCC_ABORT((yylsp[(1) - (1)]),"%s is not a voice",(yyval.strvar)->sym->sym);
      break;
    case SCC_STR_FONT:
      if((yyval.strvar)->sym->type != SCC_RES_CHSET)
        SCC_ABORT((yylsp[(1) - (1)]),"%s is not a charset",(yyval.strvar)->sym->sym);
      break;
    }
    // allocate rid
    if(!(yyval.strvar)->sym->rid) scc_ns_get_rid(sccp->ns,(yyval.strvar)->sym);
  }
;}
    break;

  case 191:
#line 1946 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 192:
#line 1950 "/usr/tmp/scc_parse.y"
    {
  (yyval.integer) = -(yyvsp[(2) - (2)].integer);
;}
    break;


/* Line 1267 of yacc.c.  */
#line 3962 "scc_parse.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 1955 "/usr/tmp/scc_parse.y"


#undef yyparse
#undef yylex
#undef yyerror
#undef sccp


extern int scc_main_lexer(YYSTYPE *lvalp, YYLTYPE *llocp,scc_lex_t* lex);

typedef struct scc_source_st scc_source_t;
struct scc_source_st {
  scc_source_t* next;
  scc_ns_t* ns;
  scc_roobj_t* roobj_list;
  char* file;
  int num_deps;
  char** deps;
};


static void set_start_pos(YYLTYPE *llocp,int line,int column) {
  llocp->first_line = line+1;
  llocp->first_column = column;
}

static void set_end_pos(YYLTYPE *llocp,int line,int column) {
  llocp->last_line = line+1;
  llocp->last_column = column;
}

// WARNING: This function realloc the file to fit the new path in
static void scc_parser_find_res(scc_parser_t* sccp, char** file_ptr) {
  int i;
  char* file;
  
  if(!file_ptr || !file_ptr[0]) return;
  file = file_ptr[0];
  
  if(sccp->res_path) {
    int file_len = strlen(file);
    struct stat st;
    for(i = 0 ; sccp->res_path[i] ; i++) {
      int path_len = strlen(sccp->res_path[i]) + 1 + file_len + 1;
      char path[path_len];
      sprintf(path,"%s/%s",sccp->res_path[i],file);
      if(stat(path,&st) || !S_ISREG(st.st_mode)) continue;
      file_ptr[0] = realloc(file,path_len);
      strcpy(file_ptr[0],path);
      return;
    }
  }
}
    
      
void scc_parser_add_dep(scc_parser_t* sccp, char* dep) {
  int i;
  if(!sccp->num_deps)
    sccp->deps = malloc(sizeof(char*));
  else {
    for(i = 0 ; i < sccp->num_deps ; i++)
      if(!strcmp(sccp->deps[i],dep)) return;
    sccp->deps = realloc(sccp->deps,(sccp->num_deps+1)*sizeof(char*));
  }
  sccp->deps[sccp->num_deps] = strdup(dep);
  sccp->num_deps++;
}

scc_source_t* scc_parser_parse(scc_parser_t* sccp,char* file,char do_deps) {
  scc_source_t* src;

  if(do_deps) {
      sccp->lex->opened = (scc_lexer_opened_f)scc_parser_add_dep;
      sccp->lex->ignore_missing_include = 1;
  } else {
      sccp->lex->opened = NULL;
      sccp->lex->ignore_missing_include = 0;
  }

  if(!scc_lex_push_buffer(sccp->lex,file)) return NULL;

  sccp->ns = scc_ns_new(sccp->target);
  sccp->roobj_list = NULL;
  sccp->roobj = NULL;
  sccp->obj = NULL;
  sccp->local_vars = 0;
  sccp->local_scr = sccp->target->max_global_scr;
  sccp->cycl = 1;
  sccp->do_deps = do_deps;

  if(scc_parser_parse_internal(sccp)) return NULL;

  if(sccp->lex->error) {
    scc_log(LOG_ERR,"%s: %s\n",scc_lex_get_file(sccp->lex),sccp->lex->error);
    return NULL;
  }

  src = calloc(1,sizeof(scc_source_t));
  src->ns = sccp->ns;
  src->roobj_list = sccp->roobj_list;
  src->file = file;
  if(sccp->do_deps) {
    src->num_deps = sccp->num_deps;
    src->deps = sccp->deps;
    sccp->num_deps = 0;
    sccp->deps = NULL;
  }
  return src;
}

scc_parser_t* scc_parser_new(char** include, char** res_path,
                             int vm_version) {
  scc_target_t* target = scc_get_target(vm_version);
  scc_parser_t* p;

  if(!target) return NULL;

  p = calloc(1,sizeof(scc_parser_t));
  p->target = target;
  p->lex = scc_lex_new(scc_main_lexer,set_start_pos,set_end_pos,include);
  p->lex->userdata = p;
  p->res_path = res_path;
  return p;
}


int scc_parser_error(scc_parser_t* sccp,YYLTYPE *loc, const char *s)  /* Called by yyparse on error */
{
  scc_log(LOG_ERR,"%s: %s\n",scc_lex_get_file(sccp->lex),
          sccp->lex->error ? sccp->lex->error : s);
  return 0;
}

static char** scc_include = NULL;
static char** scc_res_path = NULL;
static int scc_do_deps = 0;
static int scc_vm_version = 6;

static scc_param_t scc_parse_params[] = {
  { "o", SCC_PARAM_STR, 0, 0, &scc_output },
  { "I", SCC_PARAM_STR_LIST, 0, 0, &scc_include },
  { "R", SCC_PARAM_STR_LIST, 0, 0, &scc_res_path },
  { "d", SCC_PARAM_FLAG, 0, 1, &scc_do_deps },
  { "v", SCC_PARAM_FLAG, LOG_MSG, LOG_V, &scc_log_level },
  { "vv", SCC_PARAM_FLAG, LOG_MSG, LOG_DBG, &scc_log_level },
  { "V", SCC_PARAM_INT, 6, 7, &scc_vm_version },
  { "help", SCC_PARAM_HELP, 0, 0, &scc_help },
  { NULL, 0, 0, 0, NULL }
};


int main (int argc, char** argv) {
  scc_cl_arg_t* files,*f;
  scc_parser_t* sccp;
  char* out;
  scc_source_t *src,*srcs = NULL;
  scc_roobj_t* scc_roobj;
  scc_fd_t* out_fd;
  int i;

  files = scc_param_parse_argv(scc_parse_params,argc-1,&argv[1]);

  if(!files) scc_print_help(&scc_help,1);

  sccp = scc_parser_new(scc_include,scc_res_path,scc_vm_version);

  for(f = files ; f ; f = f->next) {
    src = scc_parser_parse(sccp,f->val,scc_do_deps);
    if(!src) return 1;
    src->next = srcs;
    srcs = src;
  }

  out = scc_output ? scc_output : "output.roobj";
  out_fd = new_scc_fd(out,O_WRONLY|O_CREAT|O_TRUNC,0);
  if(!out_fd) {
    scc_log(LOG_ERR,"Failed to open output file %s.\n",out);
    return -1;
  }    

  if(scc_do_deps) {
    for(src = srcs ; src ; src = src->next) {
      char* pt = strrchr(src->file,'.');
      char* start = strrchr(src->file,'/');
      if(pt) pt[0] = '\0';
      if(start) start++;
      else start = src->file;
      scc_fd_printf(out_fd,"%s.roobj:",start);
      for(i = 0 ; i < src->num_deps ; i++)
        scc_fd_printf(out_fd," %s",src->deps[i]);
        scc_fd_printf(out_fd,"\n");
    }
    scc_fd_close(out_fd);
    return 0;
  }

  for(src = srcs ; src ; src = src->next) {
    for(scc_roobj = src->roobj_list ; scc_roobj ; 
        scc_roobj = scc_roobj->next) {
      if(!scc_roobj_write(scc_roobj,src->ns,out_fd)) {
        scc_log(LOG_ERR,"Failed to write ROOM????\n");
        return 1;
      }
    }
  }

  scc_fd_close(out_fd);

  return 0;
}

