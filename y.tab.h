/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 15 "parser.y" /* yacc.c:1909  */

	#include "ast.h"

#line 48 "y.tab.h" /* yacc.c:1909  */

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
#line 11 "parser.y" /* yacc.c:1909  */

	AST_Node * node;

#line 128 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
