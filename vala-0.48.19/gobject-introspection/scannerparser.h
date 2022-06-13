/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SCANNERPARSER_H_INCLUDED
# define YY_YY_SCANNERPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* "identifier"  */
    TYPEDEF_NAME = 259,            /* "typedef-name"  */
    INTEGER = 260,                 /* INTEGER  */
    FLOATING = 261,                /* FLOATING  */
    CHARACTER = 262,               /* CHARACTER  */
    STRING = 263,                  /* STRING  */
    ELLIPSIS = 264,                /* ELLIPSIS  */
    ADDEQ = 265,                   /* ADDEQ  */
    SUBEQ = 266,                   /* SUBEQ  */
    MULEQ = 267,                   /* MULEQ  */
    DIVEQ = 268,                   /* DIVEQ  */
    MODEQ = 269,                   /* MODEQ  */
    XOREQ = 270,                   /* XOREQ  */
    ANDEQ = 271,                   /* ANDEQ  */
    OREQ = 272,                    /* OREQ  */
    SL = 273,                      /* SL  */
    SR = 274,                      /* SR  */
    SLEQ = 275,                    /* SLEQ  */
    SREQ = 276,                    /* SREQ  */
    EQ = 277,                      /* EQ  */
    NOTEQ = 278,                   /* NOTEQ  */
    LTEQ = 279,                    /* LTEQ  */
    GTEQ = 280,                    /* GTEQ  */
    ANDAND = 281,                  /* ANDAND  */
    OROR = 282,                    /* OROR  */
    PLUSPLUS = 283,                /* PLUSPLUS  */
    MINUSMINUS = 284,              /* MINUSMINUS  */
    ARROW = 285,                   /* ARROW  */
    AUTO = 286,                    /* AUTO  */
    BOOL = 287,                    /* BOOL  */
    BREAK = 288,                   /* BREAK  */
    CASE = 289,                    /* CASE  */
    CHAR = 290,                    /* CHAR  */
    CONST = 291,                   /* CONST  */
    CONTINUE = 292,                /* CONTINUE  */
    DEFAULT = 293,                 /* DEFAULT  */
    DO = 294,                      /* DO  */
    DOUBLE = 295,                  /* DOUBLE  */
    ELSE = 296,                    /* ELSE  */
    ENUM = 297,                    /* ENUM  */
    EXTERN = 298,                  /* EXTERN  */
    FLOAT = 299,                   /* FLOAT  */
    FOR = 300,                     /* FOR  */
    GOTO = 301,                    /* GOTO  */
    IF = 302,                      /* IF  */
    INLINE = 303,                  /* INLINE  */
    INT = 304,                     /* INT  */
    LONG = 305,                    /* LONG  */
    REGISTER = 306,                /* REGISTER  */
    RESTRICT = 307,                /* RESTRICT  */
    RETURN = 308,                  /* RETURN  */
    SHORT = 309,                   /* SHORT  */
    SIGNED = 310,                  /* SIGNED  */
    SIZEOF = 311,                  /* SIZEOF  */
    STATIC = 312,                  /* STATIC  */
    STRUCT = 313,                  /* STRUCT  */
    SWITCH = 314,                  /* SWITCH  */
    TYPEDEF = 315,                 /* TYPEDEF  */
    UNION = 316,                   /* UNION  */
    UNSIGNED = 317,                /* UNSIGNED  */
    VOID = 318,                    /* VOID  */
    VOLATILE = 319,                /* VOLATILE  */
    WHILE = 320,                   /* WHILE  */
    FUNCTION_MACRO = 321,          /* FUNCTION_MACRO  */
    OBJECT_MACRO = 322             /* OBJECT_MACRO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define TYPEDEF_NAME 259
#define INTEGER 260
#define FLOATING 261
#define CHARACTER 262
#define STRING 263
#define ELLIPSIS 264
#define ADDEQ 265
#define SUBEQ 266
#define MULEQ 267
#define DIVEQ 268
#define MODEQ 269
#define XOREQ 270
#define ANDEQ 271
#define OREQ 272
#define SL 273
#define SR 274
#define SLEQ 275
#define SREQ 276
#define EQ 277
#define NOTEQ 278
#define LTEQ 279
#define GTEQ 280
#define ANDAND 281
#define OROR 282
#define PLUSPLUS 283
#define MINUSMINUS 284
#define ARROW 285
#define AUTO 286
#define BOOL 287
#define BREAK 288
#define CASE 289
#define CHAR 290
#define CONST 291
#define CONTINUE 292
#define DEFAULT 293
#define DO 294
#define DOUBLE 295
#define ELSE 296
#define ENUM 297
#define EXTERN 298
#define FLOAT 299
#define FOR 300
#define GOTO 301
#define IF 302
#define INLINE 303
#define INT 304
#define LONG 305
#define REGISTER 306
#define RESTRICT 307
#define RETURN 308
#define SHORT 309
#define SIGNED 310
#define SIZEOF 311
#define STATIC 312
#define STRUCT 313
#define SWITCH 314
#define TYPEDEF 315
#define UNION 316
#define UNSIGNED 317
#define VOID 318
#define VOLATILE 319
#define WHILE 320
#define FUNCTION_MACRO 321
#define OBJECT_MACRO 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 190 "scannerparser.y"

  char *str;
  GList *list;
  CSymbol *symbol;
  CType *ctype;
  StorageClassSpecifier storage_class_specifier;
  TypeQualifier type_qualifier;
  FunctionSpecifier function_specifier;
  UnaryOperator unary_operator;

#line 212 "scannerparser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (GIGenerator* igenerator);

#endif /* !YY_YY_SCANNERPARSER_H_INCLUDED  */
