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
#line 57 "cd2Inter.y" /* yacc.c:1909  */

	int value;
	char *text;
	char *str;
	

#line 145 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
