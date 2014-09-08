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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 187 "/usr/tmp/cost_parse.y"
{
  int integer;    // INTEGER, number
  char* str;      // STRING, ID
  int intpair[2];
  uint8_t* intlist;
}
/* Line 1489 of yacc.c.  */
#line 100 "cost_parse.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;