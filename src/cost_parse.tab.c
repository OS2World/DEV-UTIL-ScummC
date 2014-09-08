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
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PALETTE = 258,
     FLAGS = 259,
     LOOP = 260,
     FLIP = 261,
     PICTURE = 262,
     LIMB = 263,
     ANIM = 264,
     INTEGER = 265,
     STRING = 266,
     SYM = 267,
     PATH = 268,
     GLOB = 269,
     POSITION = 270,
     MOVE = 271,
     START = 272,
     STOP = 273,
     HIDE = 274,
     SKIP = 275,
     SOUND = 276,
     ERROR = 277
   };
#endif
/* Tokens.  */
#define PALETTE 258
#define FLAGS 259
#define LOOP 260
#define FLIP 261
#define PICTURE 262
#define LIMB 263
#define ANIM 264
#define INTEGER 265
#define STRING 266
#define SYM 267
#define PATH 268
#define GLOB 269
#define POSITION 270
#define MOVE 271
#define START 272
#define STOP 273
#define HIDE 274
#define SKIP 275
#define SOUND 276
#define ERROR 277




/* Copy the first part of user declarations.  */
#line 26 "/usr/tmp/cost_parse.y"


#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#ifndef IS_MINGW
#include <glob.h>
#endif


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "scc_fd.h"
#include "scc_util.h"
#include "scc_param.h"
#include "scc_img.h"
#include "cost_parse.tab.h"
#include "scc_lex.h"

#include "cost_help.h"

#define YYERROR_VERBOSE 1

  int yylex(void);
  int yyerror (const char *s);

#define COST_ABORT(at,msg...)  { \
  printf("Line %d, column %d: ",at.first_line,at.first_column); \
  printf(msg); \
  YYABORT; \
}

  typedef struct cost_pic cost_pic_t;
  struct cost_pic {
    cost_pic_t* next;
    // name from the sym
    char* name;
    // number of references from limbs
    unsigned ref;
    // offset where it will be written
    unsigned offset;
    // global index for akos
    unsigned idx;
    // path/glob
    char* path;
    int is_glob;
    // params, they will be copied for globs
    int16_t rel_x,rel_y;
    int16_t move_x,move_y;

    uint16_t width,height;
    uint8_t* data;
    uint32_t data_size;
  };

  static cost_pic_t* cur_pic = NULL;
  static cost_pic_t* pic_list = NULL;

#define COST_MAX_LIMBS 16
#define LIMB_MAX_PICTURES 0x70
#define COST_MAX_DIR 4

  typedef struct cost_limb {
    char* name;
    unsigned num_pic;
    cost_pic_t* pic[LIMB_MAX_PICTURES];
  } cost_limb_t;
  

  static cost_limb_t limbs[COST_MAX_LIMBS];
  static cost_limb_t* cur_limb = NULL;

#define COST_MAX_ANIMS 0x3F
#define COST_MAX_LIMB_CMDS 0x7F

  typedef struct cost_limb_anim {
    unsigned len;
    unsigned flags;
    uint8_t cmd[COST_MAX_LIMB_CMDS];
  } cost_limb_anim_t;

  typedef struct cost_anim_dir {
    unsigned limb_mask;
    cost_limb_anim_t limb[COST_MAX_LIMBS];
  } cost_anim_dir_t;

  typedef struct cost_anim {
    char* name;
    cost_anim_dir_t dir[COST_MAX_DIR];
  } cost_anim_t;
  
  static cost_anim_t anims[COST_MAX_ANIMS];
  static cost_anim_t* cur_anim = NULL;
  static cost_anim_dir_t* cur_dir = NULL;

#define COST_MAX_PALETTE_SIZE 32
  static unsigned pal_size = 0;
  static uint8_t pal[COST_MAX_PALETTE_SIZE];

  // Default to no flip
  static unsigned cost_flags = 0x80;

  static char* img_path = NULL;
  static char* cost_output = NULL;
  static scc_fd_t* out_fd = NULL;

  // Output a AKOS instead of COST
  static int akos = 0;

  // Ouput a header
  static char* header_name = NULL;
  static char* symbol_prefix = NULL;

  static int cost_pic_load(cost_pic_t* pic,char* file);

  static cost_pic_t* find_pic(char* name) {
    cost_pic_t* p;
    for(p = pic_list ; p ; p = p->next)
      if(!strcmp(name,p->name)) break;
    return p;
  }

  struct dir_map {
    char* name;
    unsigned id;
  } dir_map[] = {
    { "W",   0 },
    { "E",   1 },
    { "S",   2 },
    { "N",   3 },
    { NULL,  0 }
  };

  struct anim_map {
    char* name;
    unsigned id;
  } anim_map[] = {
    { "init",       1 },
    { "walk",       2 },
    { "stand",      3 },
    { "talkStart",  4 },
    { "talkStop",   5 },
    { NULL, 0 }
  };
  
#define ANIM_USER_START 6

#define COST_CMD_SOUND 0x70
#define COST_CMD_STOP  0x79
#define COST_CMD_START 0x7A
#define COST_CMD_HIDE  0x7B
#define COST_CMD_SKIP  0x7C
  


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
#line 187 "/usr/tmp/cost_parse.y"
{
  int integer;    // INTEGER, number
  char* str;      // STRING, ID
  int intpair[2];
  uint8_t* intlist;
}
/* Line 187 of yacc.c.  */
#line 307 "cost_parse.tab.c"
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
#line 332 "cost_parse.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,     2,     2,     2,
      28,    29,     2,    34,    27,    31,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    24,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     6,    10,    12,    15,    19,    21,
      23,    25,    27,    29,    31,    33,    39,    42,    44,    48,
      52,    56,    60,    64,    70,    74,    76,    80,    86,    90,
      93,    97,   103,   105,   107,   111,   117,   122,   124,   128,
     130,   132,   134,   136,   138,   143,   149,   151,   155,   157,
     163,   164,   169,   170,   172,   174,   178,   180,   183,   185,
     187,   193,   195,   198,   201,   202
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    -1,    38,    -1,    58,    61,    39,    -1,
      23,    -1,    40,    23,    -1,    39,    40,    23,    -1,    41,
      -1,    42,    -1,    46,    -1,    49,    -1,    43,    -1,    47,
      -1,    50,    -1,    43,    24,    25,    44,    26,    -1,     7,
      12,    -1,    45,    -1,    44,    27,    45,    -1,    13,    24,
      11,    -1,    14,    24,    11,    -1,    15,    24,    66,    -1,
      16,    24,    66,    -1,    47,    24,    25,    48,    26,    -1,
       8,    12,    68,    -1,    12,    -1,    48,    27,    12,    -1,
      50,    24,    25,    51,    26,    -1,     9,    12,    68,    -1,
      52,    23,    -1,    51,    52,    23,    -1,    53,    24,    25,
      54,    26,    -1,    12,    -1,    55,    -1,    54,    27,    55,
      -1,    12,    28,    56,    29,    62,    -1,    12,    28,    29,
      62,    -1,    57,    -1,    56,    27,    57,    -1,    60,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    28,
      10,    29,    -1,     3,    28,    59,    29,    23,    -1,    60,
      -1,    59,    27,    60,    -1,    10,    -1,    30,    10,    31,
      10,    32,    -1,    -1,     4,    24,    63,    23,    -1,    -1,
      63,    -1,    64,    -1,    63,    27,    64,    -1,    65,    -1,
      33,    65,    -1,     6,    -1,     5,    -1,    25,    67,    27,
      67,    26,    -1,    10,    -1,    31,    10,    -1,    34,    10,
      -1,    -1,    35,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   216,   216,   217,   222,   225,   226,   227,   230,   231,
     232,   233,   236,   240,   244,   250,   320,   337,   338,   341,
     351,   365,   370,   378,   381,   419,   430,   448,   454,   500,
     501,   504,   507,   520,   521,   524,   548,   566,   567,   578,
     579,   585,   591,   597,   603,   614,   625,   626,   637,   646,
     667,   668,   676,   680,   683,   684,   691,   696,   703,   708,
     715,   722,   723,   727,   734,   737
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PALETTE", "FLAGS", "LOOP", "FLIP",
  "PICTURE", "LIMB", "ANIM", "INTEGER", "STRING", "SYM", "PATH", "GLOB",
  "POSITION", "MOVE", "START", "STOP", "HIDE", "SKIP", "SOUND", "ERROR",
  "';'", "'='", "'{'", "'}'", "','", "'('", "')'", "'['", "'-'", "']'",
  "'!'", "'+'", "'@'", "$accept", "srcfile", "costume", "statementlist",
  "statement", "dec", "picture", "picturedec", "picparamlist", "picparam",
  "limb", "limbdec", "piclist", "anim", "animdec", "animdirlist",
  "animdir", "animdirname", "limbanimlist", "limbanim", "cmdlist",
  "cmdlistitem", "palette", "intlist", "intlistitem", "costflags",
  "limbanimflags", "flaglist", "flag", "flagvalue", "numberpair", "number",
  "location", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    59,    61,   123,   125,    44,    40,    41,
      91,    45,    93,    33,    43,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    39,    39,    39,    40,    40,
      40,    40,    41,    41,    41,    42,    43,    44,    44,    45,
      45,    45,    45,    46,    47,    48,    48,    49,    50,    51,
      51,    52,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    67,    67,    67,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     3,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     5,     2,     1,     3,     3,
       3,     3,     3,     5,     3,     1,     3,     5,     3,     2,
       3,     5,     1,     1,     3,     5,     4,     1,     3,     1,
       1,     1,     1,     1,     4,     5,     1,     3,     1,     5,
       0,     4,     0,     1,     1,     3,     1,     2,     1,     1,
       5,     1,     2,     2,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     3,    50,     0,     1,     0,     0,    48,
       0,     0,    46,     0,     0,     0,     0,     5,     4,     0,
       8,     9,    12,    10,    13,    11,    14,     0,     0,     0,
      59,    58,     0,     0,    54,    56,    16,    64,    64,     0,
       6,     0,     0,     0,     0,    47,    45,    57,    51,     0,
       0,    24,    28,     7,     0,     0,     0,     0,    55,    65,
       0,     0,     0,     0,     0,    17,    25,     0,    32,     0,
       0,     0,    49,     0,     0,     0,     0,    15,     0,    23,
       0,    27,     0,    29,     0,    19,    20,     0,    21,    22,
      18,    26,    30,     0,    61,     0,     0,     0,     0,     0,
      33,    62,    63,     0,     0,    31,     0,     0,    40,    41,
      42,    43,     0,    52,     0,    37,    39,    34,    60,     0,
      36,    53,     0,    52,     0,    38,    35,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    18,    19,    20,    21,    22,    64,    65,
      23,    24,    67,    25,    26,    69,    70,    71,    99,   100,
     114,   115,     4,    11,   116,     8,   120,   121,    34,    35,
      88,    97,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -23
static const yytype_int8 yypact[] =
{
      12,   -19,    47,   -23,    21,     6,   -23,    32,    30,   -23,
      48,    16,   -23,    -5,    45,    49,    50,   -23,    33,    36,
     -23,   -23,    39,   -23,    40,   -23,    41,    29,     6,    43,
     -23,   -23,    44,   -20,   -23,   -23,   -23,    34,    34,    51,
     -23,    42,    46,    52,    58,   -23,   -23,   -23,   -23,    -5,
      60,   -23,   -23,   -23,    -2,    61,    63,    53,   -23,   -23,
      54,    55,    56,    57,   -21,   -23,   -23,    25,   -23,    -4,
      59,    62,   -23,    65,    72,    64,    64,   -23,    -2,   -23,
      75,   -23,    67,   -23,    66,   -23,   -23,    -8,   -23,   -23,
     -23,   -23,   -23,    76,   -23,    74,    82,    68,    69,    28,
     -23,   -23,   -23,    -8,     0,   -23,    76,    70,   -23,   -23,
     -23,   -23,    71,    -5,    19,   -23,   -23,   -23,   -23,    83,
     -23,    73,    14,    -5,    77,   -23,   -23,   -23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,   -23,   -23,    80,   -23,   -23,   -23,   -23,    -6,
     -23,   -23,   -23,   -23,   -23,   -23,    35,   -23,   -23,   -12,
     -23,   -17,   -23,   -23,    -1,   -23,   -22,    89,    78,    79,
      27,     4,    81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    31,    94,    48,    12,    77,    78,    49,    68,     5,
       9,    60,    61,    62,    63,     1,     9,   108,   109,   110,
     111,   112,    81,    95,     9,     7,    96,    45,    32,   113,
      10,   108,   109,   110,   111,   112,    10,    14,    15,    16,
      14,    15,    16,    28,    10,    29,   122,     6,   123,    30,
      31,    79,    80,    17,   105,   106,    13,    36,    27,    40,
      44,    37,    38,    41,    42,    43,    46,    54,    57,    50,
      59,    55,    90,    66,    53,    68,    85,    56,    73,    74,
      75,    76,    83,    86,   101,    72,    84,    91,    98,    87,
      92,    93,   102,   124,   117,   103,   118,   104,    39,   119,
      49,   126,    33,    89,    82,   125,   127,   107,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,    58
};

static const yytype_int8 yycheck[] =
{
       5,     6,    10,    23,     5,    26,    27,    27,    12,    28,
      10,    13,    14,    15,    16,     3,    10,    17,    18,    19,
      20,    21,    26,    31,    10,     4,    34,    28,    33,    29,
      30,    17,    18,    19,    20,    21,    30,     7,     8,     9,
       7,     8,     9,    27,    30,    29,    27,     0,    29,     5,
       6,    26,    27,    23,    26,    27,    24,    12,    10,    23,
      31,    12,    12,    24,    24,    24,    23,    25,    10,    35,
      10,    25,    78,    12,    23,    12,    11,    25,    24,    24,
      24,    24,    23,    11,    10,    32,    24,    12,    12,    25,
      23,    25,    10,    10,   106,    27,    26,    28,    18,    28,
      27,   123,    13,    76,    69,   122,    29,   103,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    37,    38,    58,    28,     0,     4,    61,    10,
      30,    59,    60,    24,     7,     8,     9,    23,    39,    40,
      41,    42,    43,    46,    47,    49,    50,    10,    27,    29,
       5,     6,    33,    63,    64,    65,    12,    12,    12,    40,
      23,    24,    24,    24,    31,    60,    23,    65,    23,    27,
      35,    68,    68,    23,    25,    25,    25,    10,    64,    10,
      13,    14,    15,    16,    44,    45,    12,    48,    12,    51,
      52,    53,    32,    24,    24,    24,    24,    26,    27,    26,
      27,    26,    52,    23,    24,    11,    11,    25,    66,    66,
      45,    12,    23,    25,    10,    31,    34,    67,    12,    54,
      55,    10,    10,    27,    28,    26,    27,    67,    17,    18,
      19,    20,    21,    29,    56,    57,    60,    55,    26,    28,
      62,    63,    27,    29,    10,    57,    62,    29
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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
        case 12:
#line 237 "/usr/tmp/cost_parse.y"
    {
  cur_pic = NULL;
;}
    break;

  case 13:
#line 241 "/usr/tmp/cost_parse.y"
    {
  cur_limb = NULL;
;}
    break;

  case 14:
#line 245 "/usr/tmp/cost_parse.y"
    {
  cur_anim = NULL;
;}
    break;

  case 15:
#line 251 "/usr/tmp/cost_parse.y"
    {
  // check that the pic have an image
  if(!cur_pic->path)
    COST_ABORT((yylsp[(1) - (5)]),"Picture %s has no path defined.\n",
               cur_pic->name);
  
  if(cur_pic->is_glob) {
    glob_t gl;
    int n,nlen = strlen(cur_pic->name);
    char name[nlen+16];
    cost_pic_t* p;
    
    // expand the glob
    if(glob(cur_pic->path,0,NULL,&gl))
      COST_ABORT((yylsp[(1) - (5)]),"Glob pattern error: %s\n",cur_pic->path);
    if(!gl.gl_pathc)
      COST_ABORT((yylsp[(1) - (5)]),"Glob pattern didn't match anything: %s\n",cur_pic->path);
    
    // detach the current pic from the list
    if(pic_list == cur_pic)
      pic_list = cur_pic->next;
    else {
      for(p = pic_list ; p && p->next != cur_pic ; p = p->next);
      if(!p) COST_ABORT((yylsp[(1) - (5)]),"Internal error: failed to find current pic in pic list.\n");
      p->next = cur_pic->next;
    }
    cur_pic->next = NULL;
    
    // create the new pictures
    for(n = 0 ; n < gl.gl_pathc ; n++) {
      sprintf(name,"%s%02d",cur_pic->name,n);
      p = find_pic(name);
      if(p) {
        if(p->path)
          COST_ABORT((yylsp[(1) - (5)]),"Glob expansion failed: %s is already defined\n",name);
      } else {
        p = calloc(1,sizeof(cost_pic_t));
        p->name = strdup(name);
      }
      // load it up
      p->path = strdup(gl.gl_pathv[n]);
      if(!cost_pic_load(p,p->path))
        COST_ABORT((yylsp[(1) - (5)]),"Failed to load %s.\n",p->path);
      // copy the position, etc
      p->rel_x = cur_pic->rel_x;
      p->rel_y = cur_pic->rel_y;
      p->move_x = cur_pic->move_x;
      p->move_y = cur_pic->move_y;
      
      // append it to the list
      p->next = pic_list;
      pic_list = p;
    }
    
    // free the cur_pic
    free(cur_pic->name);
    free(cur_pic->path);
    free(cur_pic);
    globfree(&gl);
  } else {  
    // load it up
    if(!cost_pic_load(cur_pic,cur_pic->path))
      COST_ABORT((yylsp[(1) - (5)]),"Failed to load %s.\n",cur_pic->path);
  }

  cur_pic = NULL;
;}
    break;

  case 16:
#line 321 "/usr/tmp/cost_parse.y"
    {
  cost_pic_t* p = find_pic((yyvsp[(2) - (2)].str));

  // alloc the pic
  if(!p) {
    p = calloc(1,sizeof(cost_pic_t));
    p->name = (yyvsp[(2) - (2)].str);
    p->next = pic_list;
    pic_list = p;
  } else
    free((yyvsp[(2) - (2)].str));
  // set it as the current pic
  cur_pic = p;
;}
    break;

  case 19:
#line 342 "/usr/tmp/cost_parse.y"
    {
  if(cur_pic->path)
    COST_ABORT((yylsp[(1) - (3)]),"This picture already has a path defined.\n");

  if(img_path)
    asprintf(&cur_pic->path,"%s/%s",img_path,(yyvsp[(3) - (3)].str));
  else
    cur_pic->path = (yyvsp[(3) - (3)].str);
;}
    break;

  case 20:
#line 352 "/usr/tmp/cost_parse.y"
    {
  if(cur_pic->path)
    COST_ABORT((yylsp[(1) - (3)]),"This picture already has a path defined.\n");

  if(cur_pic->ref)
    COST_ABORT((yylsp[(1) - (3)]),"This picture has already been referenced, we can't expand it to a glob anymore.\n");

  if(img_path)
    asprintf(&cur_pic->path,"%s/%s",img_path,(yyvsp[(3) - (3)].str));
  else
    cur_pic->path = (yyvsp[(3) - (3)].str);
  cur_pic->is_glob = 1;
;}
    break;

  case 21:
#line 366 "/usr/tmp/cost_parse.y"
    {
  cur_pic->rel_x = (yyvsp[(3) - (3)].intpair)[0];
  cur_pic->rel_y = (yyvsp[(3) - (3)].intpair)[1];
;}
    break;

  case 22:
#line 371 "/usr/tmp/cost_parse.y"
    {
  cur_pic->move_x = (yyvsp[(3) - (3)].intpair)[0];
  cur_pic->move_y = (yyvsp[(3) - (3)].intpair)[1];
;}
    break;

  case 24:
#line 382 "/usr/tmp/cost_parse.y"
    {
  int n;

  if((yyvsp[(3) - (3)].integer) >= 0) {
    // valid index ??
    if((yyvsp[(3) - (3)].integer) >= COST_MAX_LIMBS)
      COST_ABORT((yylsp[(3) - (3)]),"Limb index %d is invalid. Costumes can only have up to %d limbs.\n",
                 (yyvsp[(3) - (3)].integer),COST_MAX_LIMBS);
    n = (yyvsp[(3) - (3)].integer);
    // name mismatch ???
    if(limbs[n].name && strcmp(limbs[n].name,(yyvsp[(2) - (3)].str)))
       COST_ABORT((yylsp[(3) - (3)]),"Limb %d is already defined with the name %s.\n",
                  n,limbs[n].name);
  } else {
    // look if there a limb with that name
    for(n = 0 ; n < COST_MAX_LIMBS ; n++) {
      if(!limbs[n].name) continue;
      if(!strcmp(limbs[n].name,(yyvsp[(2) - (3)].str))) break;
    }
    // no limb with that name then look for a free index
    if(n == COST_MAX_LIMBS) {
      for(n = 0 ; n < COST_MAX_LIMBS ; n++)
        if(!limbs[n].name) break;
      if(n == COST_MAX_LIMBS)
        COST_ABORT((yylsp[(1) - (3)]),"Too many limbs defined. Costumes can only have up to %d limbs.\n",
                   COST_MAX_LIMBS);
    }
  }

  // alloc it
  if(!limbs[n].name)
    limbs[n].name = strdup((yyvsp[(2) - (3)].str));

  cur_limb = &limbs[n];
;}
    break;

  case 25:
#line 420 "/usr/tmp/cost_parse.y"
    {
  cost_pic_t* p = find_pic((yyvsp[(1) - (1)].str));

  if(!p)
    COST_ABORT((yylsp[(1) - (1)]),"There is no picture named %s.\n",(yyvsp[(1) - (1)].str));
    
  cur_limb->pic[0] = p;
  cur_limb->num_pic = 1;
  p->ref++;
;}
    break;

  case 26:
#line 431 "/usr/tmp/cost_parse.y"
    {
  cost_pic_t* p = find_pic((yyvsp[(3) - (3)].str));

  if(!p)
    COST_ABORT((yylsp[(3) - (3)]),"There is no picture named %s.\n",(yyvsp[(3) - (3)].str));

  if(cur_limb->num_pic >= LIMB_MAX_PICTURES)
    COST_ABORT((yylsp[(3) - (3)]),"Too many pictures in limb. A limb can only have up to %d pictures.\n",
               LIMB_MAX_PICTURES);

  cur_limb->pic[cur_limb->num_pic] = p;
  cur_limb->num_pic++;
  p->ref++;
;}
    break;

  case 27:
#line 449 "/usr/tmp/cost_parse.y"
    {
  cur_anim = NULL;
;}
    break;

  case 28:
#line 455 "/usr/tmp/cost_parse.y"
    {
  int n;

  if((yyvsp[(3) - (3)].integer) >= 0) {
    // valid index ??
    if((yyvsp[(3) - (3)].integer) >= COST_MAX_ANIMS)
      COST_ABORT((yylsp[(3) - (3)]),"Anim index %d is invalid. Costumes can only have up to %d anims.\n",
                 (yyvsp[(3) - (3)].integer),COST_MAX_ANIMS);
    n = (yyvsp[(3) - (3)].integer);
    // name mismatch ???
    if(anims[n].name && strcmp(anims[n].name,(yyvsp[(2) - (3)].str)))
       COST_ABORT((yylsp[(3) - (3)]),"Anim %d is already defined with the name %s.\n",
                  n,anims[n].name);
  } else {
    // look if there a anim with that name
    for(n = 0 ; n < COST_MAX_ANIMS ; n++) {
      if(!anims[n].name) continue;
      if(!strcmp(anims[n].name,(yyvsp[(2) - (3)].str))) break;
    }
    // no anim with that name then look for a free index
    if(n == COST_MAX_ANIMS) {
      // look if it's a predefined name
      for(n = 0 ; anim_map[n].name ; n++)
        if(!strcmp(anim_map[n].name,(yyvsp[(2) - (3)].str))) break;

      if(anim_map[n].name) n = anim_map[n].id;
      else {
        for(n = ANIM_USER_START ; n < COST_MAX_ANIMS ; n++)
          if(!anims[n].name) break;
        if(n == COST_MAX_ANIMS)
          COST_ABORT((yylsp[(1) - (3)]),"Too many anims defined. Costumes can only have up to %d anims.\n",
                     COST_MAX_ANIMS);
      }
    }
  }

  // alloc it
  if(!anims[n].name)
    anims[n].name = strdup((yyvsp[(2) - (3)].str));

  cur_anim = &anims[n];

;}
    break;

  case 32:
#line 508 "/usr/tmp/cost_parse.y"
    {
  int n;
  for(n = 0 ; dir_map[n].name ; n++)
    if(!strcmp(dir_map[n].name,(yyvsp[(1) - (1)].str))) break;

  if(!dir_map[n].name)
    COST_ABORT((yylsp[(1) - (1)]),"Bad direction name.\n");

  cur_dir = cur_anim->dir+dir_map[n].id;
;}
    break;

  case 35:
#line 525 "/usr/tmp/cost_parse.y"
    {
  int n;
  // find the limb
  for(n = 0 ; n < COST_MAX_LIMBS ; n++)
    if(limbs[n].name && !strcmp(limbs[n].name,(yyvsp[(1) - (5)].str))) break;
  if(n == COST_MAX_LIMBS)
    COST_ABORT((yylsp[(1) - (5)]),"There is no limb named %s.\n",(yyvsp[(1) - (5)].str));

  if((yyvsp[(3) - (5)].intlist)[0] > COST_MAX_LIMB_CMDS)
    COST_ABORT((yylsp[(3) - (5)]),"Too many commands. A limb anim can have only %d commands.\n",
               COST_MAX_LIMB_CMDS);

  if(cur_dir->limb_mask & (1 << n))
    COST_ABORT((yylsp[(1) - (5)]),"Anim for limb %s is already defined.\n",
               limbs[n].name);

  cur_dir->limb_mask |= (1 << n);
  cur_dir->limb[n].len = (yyvsp[(3) - (5)].intlist)[0];
  cur_dir->limb[n].flags |=  (yyvsp[(5) - (5)].intpair)[0];
  cur_dir->limb[n].flags &= ~(yyvsp[(5) - (5)].intpair)[1];
  memcpy(cur_dir->limb[n].cmd,(yyvsp[(3) - (5)].intlist)+1,(yyvsp[(3) - (5)].intlist)[0]);
  free((yyvsp[(3) - (5)].intlist));
;}
    break;

  case 36:
#line 549 "/usr/tmp/cost_parse.y"
    {
  int n;
  // find the limb
  for(n = 0 ; n < COST_MAX_LIMBS ; n++)
    if(limbs[n].name && !strcmp(limbs[n].name,(yyvsp[(1) - (4)].str))) break;
  if(n == COST_MAX_LIMBS)
    COST_ABORT((yylsp[(1) - (4)]),"There is no limb named %s.\n",(yyvsp[(1) - (4)].str));

  if(cur_dir->limb_mask & (1 << n))
    COST_ABORT((yylsp[(1) - (4)]),"Anim for limb %s is already defined.\n",
               limbs[n].name);
  cur_dir->limb_mask |= (1 << n);
  cur_dir->limb[n].flags |=  (yyvsp[(4) - (4)].intpair)[0];
  cur_dir->limb[n].flags &= ~(yyvsp[(4) - (4)].intpair)[1];
;}
    break;

  case 38:
#line 568 "/usr/tmp/cost_parse.y"
    {
  int l = (yyvsp[(1) - (3)].intlist)[0] + (yyvsp[(3) - (3)].intlist)[0];

  (yyval.intlist) = realloc((yyvsp[(1) - (3)].intlist),l+1);
  memcpy((yyval.intlist)+(yyval.intlist)[0]+1,(yyvsp[(3) - (3)].intlist)+1,(yyvsp[(3) - (3)].intlist)[0]);
  (yyval.intlist)[0] = l;
  free((yyvsp[(3) - (3)].intlist));
;}
    break;

  case 40:
#line 580 "/usr/tmp/cost_parse.y"
    {
  (yyval.intlist) = malloc(2);
  (yyval.intlist)[0] = 1;
  (yyval.intlist)[1] = COST_CMD_START;
;}
    break;

  case 41:
#line 586 "/usr/tmp/cost_parse.y"
    {
  (yyval.intlist) = malloc(2);
  (yyval.intlist)[0] = 1;
  (yyval.intlist)[1] = COST_CMD_STOP;
;}
    break;

  case 42:
#line 592 "/usr/tmp/cost_parse.y"
    {
  (yyval.intlist) = malloc(2);
  (yyval.intlist)[0] = 1;
  (yyval.intlist)[1] = COST_CMD_HIDE;
;}
    break;

  case 43:
#line 598 "/usr/tmp/cost_parse.y"
    {
  (yyval.intlist) = malloc(2);
  (yyval.intlist)[0] = 1;
  (yyval.intlist)[1] = COST_CMD_SKIP;
;}
    break;

  case 44:
#line 604 "/usr/tmp/cost_parse.y"
    {
  if((yyvsp[(3) - (4)].integer) < 1 || (yyvsp[(3) - (4)].integer) > 8)
    COST_ABORT((yylsp[(3) - (4)]),"Invalid costume sound index: %d.\n",(yyvsp[(3) - (4)].integer));
  
  (yyval.intlist) = malloc(2);
  (yyval.intlist)[0] = 1;
  (yyval.intlist)[1] = COST_CMD_SOUND + (yyvsp[(3) - (4)].integer);
;}
    break;

  case 45:
#line 615 "/usr/tmp/cost_parse.y"
    {
  if((yyvsp[(3) - (5)].intlist)[0] != 16 &&
     (yyvsp[(3) - (5)].intlist)[0] != 32)
    COST_ABORT((yylsp[(1) - (5)]),"Invalid palette size. Must be 16 or 32.\n");
  pal_size = (yyvsp[(3) - (5)].intlist)[0];
  memcpy(pal,(yyvsp[(3) - (5)].intlist)+1,pal_size);
  free((yyvsp[(3) - (5)].intlist));
;}
    break;

  case 47:
#line 627 "/usr/tmp/cost_parse.y"
    {
  int l = (yyvsp[(1) - (3)].intlist)[0] + (yyvsp[(3) - (3)].intlist)[0];

  (yyval.intlist) = realloc((yyvsp[(1) - (3)].intlist),l+1);
  memcpy((yyval.intlist)+(yyval.intlist)[0]+1,(yyvsp[(3) - (3)].intlist)+1,(yyvsp[(3) - (3)].intlist)[0]);
  (yyval.intlist)[0] = l;
  free((yyvsp[(3) - (3)].intlist));
;}
    break;

  case 48:
#line 638 "/usr/tmp/cost_parse.y"
    {
  if((yyvsp[(1) - (1)].integer) < 0 || (yyvsp[(1) - (1)].integer) > 255)
    COST_ABORT((yylsp[(1) - (1)]),"List items can't be greater than 255.\n");

  (yyval.intlist) = malloc(2);
  (yyval.intlist)[0] = 1;
  (yyval.intlist)[1] = (yyvsp[(1) - (1)].integer);
;}
    break;

  case 49:
#line 647 "/usr/tmp/cost_parse.y"
    {
  int i,s,l = (yyvsp[(4) - (5)].integer)-(yyvsp[(2) - (5)].integer)+1;

  if((yyvsp[(2) - (5)].integer) < 0 || (yyvsp[(2) - (5)].integer) > 255)
    COST_ABORT((yylsp[(2) - (5)]),"List items can't be greater than 255.\n");
  if((yyvsp[(4) - (5)].integer) < 0 || (yyvsp[(4) - (5)].integer) > 255)
    COST_ABORT((yylsp[(4) - (5)]),"List items can't be greater than 255.\n");

  if((yyvsp[(4) - (5)].integer) >= (yyvsp[(2) - (5)].integer))
    l = (yyvsp[(4) - (5)].integer)-(yyvsp[(2) - (5)].integer)+1, s = 1;
  else
    l = (yyvsp[(2) - (5)].integer)-(yyvsp[(4) - (5)].integer)+1, s = -1;
    
  (yyval.intlist) = malloc(l+1);
  (yyval.intlist)[0] = l;
  for(i = 0 ; i < l ; i++)
    (yyval.intlist)[i+1] = (yyvsp[(2) - (5)].integer)+s*i;
;}
    break;

  case 51:
#line 669 "/usr/tmp/cost_parse.y"
    {
  cost_flags |=  (yyvsp[(3) - (4)].intpair)[0];
  cost_flags &= ~(yyvsp[(3) - (4)].intpair)[1];
;}
    break;

  case 52:
#line 676 "/usr/tmp/cost_parse.y"
    {
  (yyval.intpair)[0] = 0;
  (yyval.intpair)[1] = 0;
;}
    break;

  case 55:
#line 685 "/usr/tmp/cost_parse.y"
    {
  (yyval.intpair)[0] |= (yyvsp[(3) - (3)].intpair)[0];
  (yyval.intpair)[1] |= (yyvsp[(3) - (3)].intpair)[1];
;}
    break;

  case 56:
#line 692 "/usr/tmp/cost_parse.y"
    {
  (yyval.intpair)[0] = (yyvsp[(1) - (1)].intpair)[0];
  (yyval.intpair)[1] = (yyvsp[(1) - (1)].intpair)[1];
;}
    break;

  case 57:
#line 697 "/usr/tmp/cost_parse.y"
    {
  (yyval.intpair)[0] = (yyvsp[(2) - (2)].intpair)[1];
  (yyval.intpair)[1] = (yyvsp[(2) - (2)].intpair)[0];
;}
    break;

  case 58:
#line 704 "/usr/tmp/cost_parse.y"
    {
  (yyval.intpair)[0] = 0;
  (yyval.intpair)[1] = 0x80;
;}
    break;

  case 59:
#line 709 "/usr/tmp/cost_parse.y"
    {
  (yyval.intpair)[0] = 0;
  (yyval.intpair)[1] = 0x80;
;}
    break;

  case 60:
#line 716 "/usr/tmp/cost_parse.y"
    {
  (yyval.intpair)[0] = (yyvsp[(2) - (5)].integer);
  (yyval.intpair)[1] = (yyvsp[(4) - (5)].integer);
;}
    break;

  case 62:
#line 724 "/usr/tmp/cost_parse.y"
    {
  (yyval.integer) = - (yyvsp[(2) - (2)].integer);
;}
    break;

  case 63:
#line 728 "/usr/tmp/cost_parse.y"
    {
  (yyval.integer) = (yyvsp[(2) - (2)].integer);
;}
    break;

  case 64:
#line 734 "/usr/tmp/cost_parse.y"
    {
  (yyval.integer) = -1;
;}
    break;

  case 65:
#line 738 "/usr/tmp/cost_parse.y"
    {
  (yyval.integer) = (yyvsp[(2) - (2)].integer);
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2210 "cost_parse.tab.c"
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


#line 743 "/usr/tmp/cost_parse.y"


// load an image and encode it with the strange vertical RLE
static int cost_pic_load(cost_pic_t* pic,char* file) {  
  scc_img_t* img = scc_img_open(file);
  int color,rep,shr,max_rep,x,y;
  uint8_t* dst;

  if(!img) return 0;

  if(img->ncol != pal_size)
    printf("Warning, image %s doesn't have the same number of colors as the palette: %d != %d.\n",file,img->ncol,pal_size);

  pic->width = img->w;
  pic->height = img->h;

  // encode the pic
  // alloc enouth mem for the worst case
  dst = pic->data = malloc(img->w*img->h);

  // set the params
  switch(pal_size) {
  case 16:
    shr = 4;
    max_rep = 0x0F;
    break;
  case 32:
    shr = 3;
    max_rep = 0x07;
    break;
  }

  // take the initial color
  color = img->data[0];
  if(color >= pal_size) color = pal_size-1;
  rep = 0;
  for(x = 0 ; x < img->w ; x++)
    for(y = 0 ; y < img->h ; y++) {
      if(rep < 255 && // can repeat ??
         img->data[y*img->w+x] == color) {
        rep++;
        continue;
      }
      // write the repetition
      if(rep > max_rep) {
        pic->data[pic->data_size] = (color << shr);
        pic->data_size++;
        pic->data[pic->data_size] = rep;
        pic->data_size++;
      } else {
        pic->data[pic->data_size] = (color << shr) | rep;
        pic->data_size++;
      }

      color = img->data[y*img->w+x];
      if(color >= pal_size) color = pal_size-1;
      rep = 1;
    }
  // write the last repetition
  if(rep > 0) {
    if(rep > max_rep) {
      pic->data[pic->data_size] = (color << shr);
      pic->data_size++;
      pic->data[pic->data_size] = rep;
      pic->data_size++;
    } else {
      pic->data[pic->data_size] = (color << shr) | rep;
      pic->data_size++;
    }
  }

  if(pic->data_size < img->w*img->h)
    pic->data = realloc(pic->data,pic->data_size);

  scc_img_free(img);
  return 1;
}

// compute the whole size of the costume
static int cost_get_size(int *na,unsigned* coff,unsigned* aoff,unsigned* loff) {
  cost_pic_t* p;
  int i,j,num_anim,clen = 0;
  int size = 4 + // size
    2 + // header
    1 + // num anim
    1 + // format
    pal_size + // palette
    2 + // cmds offset
    2*16; // limbs offset
    
  // get the highest anim id
  for(i = COST_MAX_ANIMS-1 ; i >= 0 ; i--)
    if(anims[i].name) break;
  num_anim = i+1;

  size += 2*COST_MAX_DIR*num_anim; // anim offsets

  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++) {
    cost_anim_dir_t* anim = &anims[i/COST_MAX_DIR].dir[i%COST_MAX_DIR];
    if(aoff) {
      if(anim->limb_mask)
        aoff[i] = size-clen;
      else
        aoff[i] = 0;
    }
    size += 2; // limb mask
    if(!anim->limb_mask) continue;
    for(j = COST_MAX_LIMBS-1 ; j >= 0 ; j--) {
      if(!(anim->limb_mask & (1 << j))) continue;
      if(anim->limb[j].len) {
        size += 2 + 1 + anim->limb[j].len; // limb start/len + cmds
        clen += anim->limb[j].len;
      } else
        size += 2;
    }
  }
  if(coff) coff[0] = size-clen;

  // limbs table
  for(i = COST_MAX_LIMBS-1 ; i >= 0 ; i--) {
    if(loff) {
      if(limbs[i].num_pic > 0)
        loff[i] = size;
      else
        loff[i] = 0;
    }
    size += 2*limbs[i].num_pic;
  }
    
  // pictures
  //  for(p = pic_list ; p ; p = p->next)
  for(i = COST_MAX_LIMBS-1 ; i >= 0 ; i--) // pictures
    for(j = 0 ; j < limbs[i].num_pic ; j++) {
      if(!(p = limbs[i].pic[j])) continue;
      if(p->ref && !p->offset) {
        p->offset = size;
        size += p->data_size + 6*2;
      }
    }

  na[0] = num_anim;
  return size;
}

static int cost_write(scc_fd_t* fd) {
  int size,num_anim,i,j,pad = 0;
  cost_pic_t* p;
  uint8_t fmt = 0x58 | cost_flags;
  unsigned coff,cpos = 0;
  unsigned aoff[COST_MAX_ANIMS*COST_MAX_DIR];
  unsigned loff[COST_MAX_LIMBS];

  if(pal_size == 32) fmt |= 1;

  size = cost_get_size(&num_anim,&coff,aoff,loff);

  // round up to next 2 multiple
  if(size & 1) {
    size++;
    pad = 1;
  }

  scc_fd_w32(fd,MKID('C','O','S','T'));
  scc_fd_w32be(fd,size+8);


  scc_fd_w32le(fd,size);  // size

  scc_fd_w8(fd,'C'); // header
  scc_fd_w8(fd,'O');

  scc_fd_w8(fd,num_anim*COST_MAX_DIR-1); // last anim

  scc_fd_w8(fd,fmt); // format

  scc_fd_write(fd,pal,pal_size); // palette

  scc_fd_w16le(fd,coff); // cmd offset

  for(i = COST_MAX_LIMBS-1 ; i >= 0 ; i--) // limbs offset
    scc_fd_w16le(fd,loff[i]);

  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++) // anim offsets
    scc_fd_w16le(fd,aoff[i]);

  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++) { // anims
    cost_anim_dir_t* anim = &anims[i/COST_MAX_DIR].dir[i%COST_MAX_DIR];
    scc_fd_w16le(fd,anim->limb_mask); // limb mask
    if(!anim->limb_mask) continue;
    for(j = COST_MAX_LIMBS-1 ; j >= 0 ; j--) {
      if(!(anim->limb_mask & (1 << j))) continue;
      if(anim->limb[j].len) {
        scc_fd_w16le(fd,cpos);  // cmd start
        cpos += anim->limb[j].len;
        // last cmd offset
        scc_fd_w8(fd,((anim->limb[j].len-1)&0x7F) |
                    (anim->limb[j].flags&0x80));
      } else
        scc_fd_w16le(fd,0xFFFF); // stoped limb
    }
  }

  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++) { // anim cmds
    cost_anim_dir_t* anim = &anims[i/COST_MAX_DIR].dir[i%COST_MAX_DIR];
    for(j = COST_MAX_LIMBS-1 ; j >= 0 ; j--) {
      if(!anim->limb[j].len ) continue;
      scc_fd_write(fd,anim->limb[j].cmd,anim->limb[j].len);
    }
  }

  for(i = COST_MAX_LIMBS-1 ; i >= 0 ; i--)  // limbs
    for(j = 0 ; j < limbs[i].num_pic ; j++) {
      if(limbs[i].pic[j]) scc_fd_w16le(fd,limbs[i].pic[j]->offset);
      else scc_fd_w16le(fd,0);
    }

  // i would prefer to just go along the list,
  // but that should give results closer to the original.
  for(i = COST_MAX_LIMBS-1 ; i >= 0 ; i--) // pictures
    for(j = 0 ; j < limbs[i].num_pic ; j++) {
      if(!(p = limbs[i].pic[j])) continue;
      if(!p->ref) continue;
      if(!p->width || !p->height) printf("Bad pic?\n");
      //printf("Write pic: %dx%d\n",p->width,p->height);
      scc_fd_w16le(fd,p->width);
      scc_fd_w16le(fd,p->height);
      scc_fd_w16le(fd,p->rel_x);
      scc_fd_w16le(fd,p->rel_y);
      scc_fd_w16le(fd,p->move_x);
      scc_fd_w16le(fd,p->move_y);
      scc_fd_write(fd,p->data,p->data_size);
      p->ref = 0;
    }

  if(pad) scc_fd_w8(fd,0);

  return 1;
}


static int akos_write(scc_fd_t* fd) {
  int akhd_size = 8 + 2 + 1 + 1 + 2 + 2 + 2;
  int akpl_size = 8 + pal_size;
  int aksq_size = 8;
  int akch_size = 8;
  int akof_size = 8;
  int akci_size = 8;
  int akcd_size = 8;
  int akos_size;
  int i,j,d;
  int cpos = 0;
  int aoff[COST_MAX_DIR*COST_MAX_ANIMS];
  cost_pic_t* pic;
  int num_anim = 0, num_pic = 0;
  int data_off = 0, header_off = 0;


  // get the highest anim id
  for(i = COST_MAX_ANIMS-1 ; i >= 0 ; i--)
    if(anims[i].name) break;
  num_anim = i+1;

  // Compute the number of picture and setup the ids
  for(pic = pic_list ; pic ; pic = pic->next) {
    if(!pic->ref) continue;
    pic->idx = num_pic;
    num_pic++;
  }

  // Compute the size needed for all commands
  for(i = 0 ; i < num_anim ; i++)
    for(d = 0 ; d < COST_MAX_DIR ; d++)
      for(j = COST_MAX_LIMBS-1 ; j >= 0 ; j--)
        aksq_size += anims[i].dir[d].limb[j].len;

  // Compute the size needed for the anim definitions
  akch_size += 2*COST_MAX_DIR*num_anim;
  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++) {
    cost_anim_dir_t* anim = &anims[i/COST_MAX_DIR].dir[i%COST_MAX_DIR];
    if(!anim->limb_mask) {
      aoff[i] = 0;
      continue;
    }
    aoff[i] = akch_size-8;
    akch_size += 2;
    for(j = COST_MAX_LIMBS-1 ; j >= 0 ; j--) {
      if(!(anim->limb_mask & (1 << j))) continue;
      akch_size += 1 + 2 + 2;
    }
  }

  akof_size += (4 + 2)*num_pic;

  akci_size += (2+2 + 2+2 + 2+2)*num_pic;

  // Compute the size needed for the picture data
  for(pic = pic_list ; pic ; pic = pic->next) {
    if(!pic->ref) continue;
    akcd_size += pic->data_size;
  }

  akos_size = 8 + akhd_size + akpl_size + aksq_size +
    akch_size + akof_size + akci_size + akcd_size;

  scc_fd_w32(fd,MKID('A','K','O','S'));
  scc_fd_w32be(fd,akos_size);

  // Write the header
  scc_fd_w32(fd,MKID('A','K','H','D'));
  scc_fd_w32be(fd,akhd_size);
  // Version ?
  scc_fd_w16le(fd,0x0001);
  // Flags
  scc_fd_w8(fd,cost_flags>>7);
  // Unknown
  scc_fd_w8(fd,0x80);
  // Num anim
  scc_fd_w16le(fd,num_anim*COST_MAX_DIR);
  // Num frame
  scc_fd_w16le(fd,num_pic);
  // Codec
  scc_fd_w16le(fd,1);

  // Write the palette
  scc_fd_w32(fd,MKID('A','K','P','L'));
  scc_fd_w32be(fd,akpl_size);
  scc_fd_write(fd,pal,pal_size);

  // Write the commands, a bit tricky because
  // need to relocate the picture id from limb picture
  // to global picture.
  scc_fd_w32(fd,MKID('A','K','S','Q'));
  scc_fd_w32be(fd,aksq_size);
  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++) {
    cost_anim_dir_t* anim = &anims[i/COST_MAX_DIR].dir[i%COST_MAX_DIR];
    for(j = COST_MAX_LIMBS-1 ; j >= 0 ; j--) {
      int c;
      for(c = 0 ; c < anim->limb[j].len ; c++) {
        int cmd = anim->limb[j].cmd[c];
        // Ignore high id atm, that include commands
        if(cmd >= 0x80) {
          scc_fd_w8(fd,cmd), c++;
          scc_fd_w8(fd,anim->limb[j].cmd[c]);
          continue;
        }
        if(cmd >= limbs[j].num_pic ||
           !limbs[j].pic[cmd]) {
          printf("Warning: Bad picture index in anim %s, "
                 "limb %s at %d: %d\n",
                 anims[i/COST_MAX_DIR].name,limbs[j].name,c,cmd);
          scc_fd_w8(fd,0);
        } else
          scc_fd_w8(fd,limbs[j].pic[cmd]->idx);
      }
    }
  }

  // Write the anims
  scc_fd_w32(fd,MKID('A','K','C','H'));
  scc_fd_w32be(fd,akch_size);
  // offsets
  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++)
    scc_fd_w16le(fd,aoff[i]);
  // definitions
  for(i = 0 ; i < num_anim*COST_MAX_DIR ; i++) {
    cost_anim_dir_t* anim = &anims[i/COST_MAX_DIR].dir[i%COST_MAX_DIR];
    if(!anim->limb_mask) continue;
    // limb mask
    scc_fd_w16le(fd,anim->limb_mask);
    for(j = COST_MAX_LIMBS-1 ; j >= 0 ; j--) {
      if(!(anim->limb_mask & (1 << j))) continue;
      // mode
      scc_fd_w8(fd,(anim->limb[j].flags&0x80) ? 0x03 : 0x02);
      // cmd start
      scc_fd_w16le(fd,cpos);
      cpos += anim->limb[j].len;
      // len
      scc_fd_w16le(fd,anim->limb[j].len-1);
    }
  }

  // Write the offset table
  scc_fd_w32(fd,MKID('A','K','O','F'));
  scc_fd_w32be(fd,akof_size);
  for(pic = pic_list ; pic ; pic = pic->next) {
    if(!pic->ref) continue;
    // Data offset
    scc_fd_w32le(fd,data_off);
    data_off += pic->data_size;
    // Header offset
    scc_fd_w16le(fd,header_off);
    header_off += 2+2 + 2+2 + 2+2;
  }

  // Write the pic headers
  scc_fd_w32(fd,MKID('A','K','C','I'));
  scc_fd_w32be(fd,akci_size);
  for(pic = pic_list ; pic ; pic = pic->next) {
    if(!pic->ref) continue;
    // width / height
    scc_fd_w16le(fd,pic->width);
    scc_fd_w16le(fd,pic->height);
    scc_fd_w16le(fd,pic->rel_x);
    scc_fd_w16le(fd,pic->rel_y);
    scc_fd_w16le(fd,pic->move_x);
    scc_fd_w16le(fd,pic->move_y);
  }

  // Write the pic data
  scc_fd_w32(fd,MKID('A','K','C','D'));
  scc_fd_w32be(fd,akcd_size);
  for(pic = pic_list ; pic ; pic = pic->next) {
    if(!pic->ref) continue;
    scc_fd_write(fd,pic->data,pic->data_size);
  }

  return 1;
}

static int header_write(scc_fd_t* fd,char *prefix) {
  int i;
  scc_fd_printf(fd,"/* This file was generated do not edit */\n\n");
  for(i = 0 ; i < COST_MAX_ANIMS ; i++) {
    if(!anims[i].name) continue;
    scc_fd_printf(fd,"#define %s%s %d\n",prefix,anims[i].name,i);
  }
  return 1;
}

static scc_lex_t* cost_lex;
extern int cost_main_lexer(YYSTYPE *lvalp, YYLTYPE *llocp,scc_lex_t* lex);

static void set_start_pos(YYLTYPE *llocp,int line,int column) {
  llocp->first_line = line+1;
  llocp->first_column = column;
}

static void set_end_pos(YYLTYPE *llocp,int line,int column) {
  llocp->last_line = line+1;
  llocp->last_column = column;
}

int yylex(void) {
  return scc_lex_lex(&yylval,&yylloc,cost_lex);
}

int yyerror (const char *s)  /* Called by yyparse on error */
{
  scc_log(LOG_ERR,"%s: %s\n",scc_lex_get_file(cost_lex),
          cost_lex->error ? cost_lex->error : s);
  return 0;
}

static scc_param_t scc_parse_params[] = {
  { "o", SCC_PARAM_STR, 0, 0, &cost_output },
  { "I", SCC_PARAM_STR, 0, 0, &img_path },
  { "akos", SCC_PARAM_FLAG, 0, 1, &akos },
  { "prefix", SCC_PARAM_STR, 0, 0, &symbol_prefix },
  { "header", SCC_PARAM_STR, 0, 0, &header_name },
  { "help", SCC_PARAM_HELP, 0, 0, &cost_help },
  { NULL, 0, 0, 0, NULL }
};

int main (int argc, char** argv) {
  scc_cl_arg_t* files;
  char* out;

  files = scc_param_parse_argv(scc_parse_params,argc-1,&argv[1]);

  if(!files) scc_print_help(&cost_help,1);

  out = cost_output ? cost_output : "output.cost";
  out_fd = new_scc_fd(out,O_WRONLY|O_CREAT|O_TRUNC,0);
  if(!out_fd) {
    printf("Failed to open output file %s.\n",out);
    return -1;
  }

  cost_lex = scc_lex_new(cost_main_lexer,set_start_pos,set_end_pos,NULL);
  if(!scc_lex_push_buffer(cost_lex,files->val)) return -1;

  if(yyparse()) return -1;

  if(akos)
    akos_write(out_fd);
  else
    cost_write(out_fd);

  scc_fd_close(out_fd);

  if(header_name) {
    out_fd = new_scc_fd(header_name,O_WRONLY|O_CREAT|O_TRUNC,0);
    if(!out_fd) {
      printf("Failed to open output file %s.\n",out);
      return -1;
    }
    header_write(out_fd,symbol_prefix);
    scc_fd_close(out_fd);
  }

  return 0;
}

