/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_INCLUDES_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_INCLUDES_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 14 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"

    #include <string>
    #include <vector>
    #include <ASB/asb.hpp>
    #include <ASB/declaration.hpp>
    #include <ASB/expression.hpp>
    #include <ASB/statment.hpp>
    #include <ASB/types.hpp>
    #include <other/linkedlist.hpp>



#line 61 "includes/Parser/parser.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT32 = 259,
    BOOL = 260,
    CHAR = 261,
    RUNE = 262,
    IF = 263,
    ELSE = 264,
    FOR = 265,
    RETURN = 266,
    VAR = 267,
    FUNC = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    EQ = 272,
    NEQ = 273,
    IDENTIFIER = 274,
    INTEGER_LITERAL = 275,
    FLOAT_LITERAL = 276,
    BOOLEAN_LITERAL = 277,
    CHAR_LITERAL = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"

    int integerValue;
    float floatValue;
    bool booleanValue;
    char charValue;
    char *identifierValue;
    
    ASB::Block *block;
    
    ASB::Type  *type;

    ASB::Statment *statment;
    ASB::SimpleStatment *simpleStatment;

    ASB::TopDeclaration *topDeclaration;
    ASB::Declaration    *declaration;

    ASB::Expression     *expression;

    LinkedList<ASB::Statment *> *listStatment;
    LinkedList<ASB::SimpleStatment *> *listSimpleStatment;

    LinkedList<ASB::TopDeclaration *> *listTopDeclaration;
    LinkedList<ASB::Declaration *> *listDeclaration;
    
    LinkedList<ASB::Expression *> *listExpression;

    LinkedList<std::string> *idenList;

    LinkedList<std::pair<std::string, ASB::Type *>> *fields;

#line 128 "includes/Parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_INCLUDES_PARSER_PARSER_HPP_INCLUDED  */
