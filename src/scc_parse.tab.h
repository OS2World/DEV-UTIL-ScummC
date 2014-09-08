/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1489 of yacc.c.  */
#line 177 "scc_parse.tab.h"
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


