/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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



#line 124 "src/Parser/parser.cpp"

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

#line 191 "src/Parser/parser.cpp"

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


/* Unqualified %code blocks.  */
#line 4 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"

    #include <iostream>
    #include <string>
    #include <lexer/lexer.hpp>
    ASB::Root *tree;

    void yyerror(char *message);


#line 232 "src/Parser/parser.cpp"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    29,     2,     2,
      30,    31,    27,    24,    32,    25,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   141,   141,   147,   148,   149,   150,   151,   152,   153,
     159,   164,   174,   175,   176,   186,   187,   188,   194,   201,
     213,   220,   240,   247,   256,   266,   272,   277,   284,   290,
     291,   292,   296,   302,   312,   315,   328,   334,   340,   346,
     352,   366,   367,   368,   379,   380,   382,   387,   388,   390,
     394,   398,   399,   411,   412,   413,   414,   415,   419,   425,
     435,   441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT32", "BOOL", "CHAR", "RUNE",
  "IF", "ELSE", "FOR", "RETURN", "VAR", "FUNC", "AND", "OR", "NOT", "EQ",
  "NEQ", "IDENTIFIER", "INTEGER_LITERAL", "FLOAT_LITERAL",
  "BOOLEAN_LITERAL", "CHAR_LITERAL", "'+'", "'-'", "'^'", "'*'", "'/'",
  "'%'", "'('", "')'", "','", "'{'", "'}'", "'='", "';'", "$accept",
  "start", "type", "literalType", "functionSignature", "functionResults",
  "functionParameters", "functionParametersList", "block",
  "topDeclaration", "functionDeclaration", "listDeclaration",
  "variableDeclaration", "varSpec", "varSpecList", "listTopDeclarations",
  "statments", "simpleStatment", "ifStatment", "forStatment",
  "returnStatment", "statmentList", "expression", "expressionList",
  "identifierList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    94,    42,    47,    37,
      40,    41,    44,   123,   125,    61,    59
};
# endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,    -8,    -6,    32,     8,   -63,   -63,   -63,   -63,    17,
      41,   -63,    48,    34,   -63,    13,    41,    26,    35,   -63,
     -63,   -63,   -63,    34,   -63,    71,    36,    30,   -63,    66,
      40,    89,   -63,   -63,    41,   -63,   -63,    37,   -63,   -63,
     -63,   -63,   -63,    49,   -63,    36,    -1,   -63,    50,     4,
      71,   105,   -63,    66,   -63,   -63,   -63,   -63,   -63,    36,
     -63,   101,   -63,    55,    56,    36,   113,    36,   -63,    44,
     -63,   -63,   -63,   -63,    53,   -18,    54,    16,   -63,   -63,
     -63,   101,    40,   -63,    62,   -25,   -63,   105,   -63,    36,
     -63,    82,    36,   -63,   -63,   -63,    -5,    63,   -63,   -63,
      36,    40,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    34,    24,    23,    26,     2,    60,
       0,    27,     0,     0,     1,     0,     0,     0,     0,     4,
       5,     6,     7,     0,    10,     0,     0,    29,     9,     0,
       0,    12,    35,    61,    32,    28,     8,     0,    57,    54,
      55,    53,    56,    58,    31,     0,    60,    15,    18,     0,
       0,    41,    25,     0,    14,    11,    13,    33,     3,     0,
      30,     0,    16,     0,    19,     0,    41,     0,    40,     0,
      36,    37,    39,    38,     0,    42,     0,     0,    59,    20,
      17,     0,     0,    49,     0,    42,    50,    41,    22,     0,
      21,    44,     0,    47,    52,    43,     0,     0,    46,    45,
      41,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,    -7,   -63,    77,   -63,    72,   -52,   -62,   -63,
     -63,   -49,   -63,   108,    76,    96,   -63,   -60,    22,   -63,
     -63,    25,   -50,   -26,    11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    48,    28,    30,    55,    31,    49,    52,     4,
       5,     6,     7,    17,    18,     8,    69,    70,    71,    72,
      73,    74,    43,    76,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    75,    68,    65,    83,    27,    84,    59,    51,    79,
     -58,     9,    12,    13,    59,    82,    85,   -58,    37,    60,
      91,    12,    10,    93,    54,     1,     2,    33,    51,    90,
     -10,    16,    14,    78,    98,    62,    63,    75,    68,   102,
     101,    86,    97,    64,    15,    12,    77,    58,    61,    16,
      75,    19,    20,    21,    22,    38,    39,    40,    41,    42,
       9,    23,    34,    95,    29,    45,    35,    24,    58,    19,
      20,    21,    22,    51,    19,    20,    21,    22,    25,    23,
      87,    59,    61,    26,    23,    46,    80,    88,    81,    89,
      24,    96,    19,    20,    21,    22,    25,    47,    92,   100,
      36,    25,    23,    56,    19,    20,    21,    22,    24,    11,
      57,    32,    94,    65,    23,    66,    67,     1,    99,    53,
      46,     0,     0,     0,    38,    39,    40,    41,    42,     0,
       0,    25,    38,    39,    40,    41,    42,     0,     0,   -51,
       0,     0,     0,     0,     0,     0,    51
};

static const yytype_int8 yycheck[] =
{
      26,    51,    51,     8,    66,    12,    66,    32,    33,    61,
      35,    19,     1,    19,    32,    65,    66,    35,    25,    45,
      82,    10,    30,    85,    31,    12,    13,    16,    33,    81,
      31,    32,     0,    59,    96,    31,    32,    87,    87,   101,
     100,    67,    92,    50,    36,    34,    53,    31,    32,    32,
     100,     3,     4,     5,     6,    19,    20,    21,    22,    23,
      19,    13,    36,    89,    30,    35,    31,    19,    31,     3,
       4,     5,     6,    33,     3,     4,     5,     6,    30,    13,
      36,    32,    32,    35,    13,    19,    31,    34,    32,    35,
      19,     9,     3,     4,     5,     6,    30,    31,    36,    36,
      23,    30,    13,    31,     3,     4,     5,     6,    19,     1,
      34,    15,    87,     8,    13,    10,    11,    12,    96,    30,
      19,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      -1,    30,    19,    20,    21,    22,    23,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    38,    46,    47,    48,    49,    52,    19,
      30,    50,    61,    19,     0,    36,    32,    50,    51,     3,
       4,     5,     6,    13,    19,    30,    35,    39,    40,    30,
      41,    43,    52,    61,    36,    31,    41,    39,    19,    20,
      21,    22,    23,    59,    60,    35,    19,    31,    39,    44,
      61,    33,    45,    30,    39,    42,    43,    51,    31,    32,
      60,    32,    31,    32,    39,     8,    10,    11,    48,    53,
      54,    55,    56,    57,    58,    59,    60,    39,    60,    44,
      31,    32,    59,    45,    54,    59,    60,    36,    34,    35,
      44,    45,    36,    45,    58,    60,     9,    59,    45,    55,
      36,    54,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    39,    39,    39,
      40,    41,    42,    42,    42,    43,    43,    43,    44,    44,
      44,    44,    45,    46,    46,    47,    48,    49,    49,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    58,    58,    59,    59,    59,    59,    59,    60,    60,
      61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     1,     2,     1,
       1,     2,     0,     1,     1,     2,     3,     4,     1,     2,
       3,     4,     3,     1,     1,     4,     1,     2,     4,     2,
       4,     3,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     0,     1,     3,     3,     5,     5,     3,     7,     2,
       2,     0,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 141 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                             {tree = new ASB::Root{(yyvsp[0].listTopDeclaration)->toVector()}; }
#line 1572 "src/Parser/parser.cpp"
    break;

  case 3:
#line 147 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = (yyvsp[-1].type);}
#line 1578 "src/Parser/parser.cpp"
    break;

  case 4:
#line 148 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = new ASB::IntType{}; }
#line 1584 "src/Parser/parser.cpp"
    break;

  case 5:
#line 149 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = new ASB::FloatType{}; }
#line 1590 "src/Parser/parser.cpp"
    break;

  case 6:
#line 150 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = new ASB::BooleanType{}; }
#line 1596 "src/Parser/parser.cpp"
    break;

  case 7:
#line 151 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = new ASB::CharType{}; }
#line 1602 "src/Parser/parser.cpp"
    break;

  case 8:
#line 152 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = (yyvsp[0].type);}
#line 1608 "src/Parser/parser.cpp"
    break;

  case 9:
#line 153 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = (yyvsp[0].type);}
#line 1614 "src/Parser/parser.cpp"
    break;

  case 10:
#line 159 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.type) = new ASB::IdentifierType{(yyvsp[0].identifierValue)}; delete (yyvsp[0].identifierValue);}
#line 1620 "src/Parser/parser.cpp"
    break;

  case 11:
#line 165 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        (yyval.type)=new ASB::FunctionType{(yyvsp[-1].fields)->toVector(), (yyvsp[0].fields)->toVector()};
                                        delete (yyvsp[-1].fields);
                                        delete (yyvsp[0].fields);
                                    }
#line 1630 "src/Parser/parser.cpp"
    break;

  case 12:
#line 174 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.fields)= new LinkedList<std::pair<std::string, ASB::Type *>>;}
#line 1636 "src/Parser/parser.cpp"
    break;

  case 13:
#line 175 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.fields) = (yyvsp[0].fields);}
#line 1642 "src/Parser/parser.cpp"
    break;

  case 14:
#line 176 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto type = (yyvsp[0].type);
                                        auto list = new LinkedList<std::pair<std::string, ASB::Type *>>;
                                        list->add(0, std::make_pair("", type));
                                        (yyval.fields) = list; 
                                    }
#line 1653 "src/Parser/parser.cpp"
    break;

  case 15:
#line 186 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {(yyval.fields) = new LinkedList<std::pair<std::string, ASB::Type *>>; }
#line 1659 "src/Parser/parser.cpp"
    break;

  case 16:
#line 187 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {(yyval.fields) = (yyvsp[-1].fields); }
#line 1665 "src/Parser/parser.cpp"
    break;

  case 17:
#line 189 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {(yyval.fields) = (yyvsp[-2].fields); }
#line 1671 "src/Parser/parser.cpp"
    break;

  case 18:
#line 194 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {
                                            auto type = (yyvsp[0].type);
                                            auto list = new LinkedList<std::pair<std::string, ASB::Type *>>;
                                            list->add(0, std::make_pair("", type));
                                            (yyval.fields) = list;
                                        }
#line 1682 "src/Parser/parser.cpp"
    break;

  case 19:
#line 201 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {
                                            auto ids = (yyvsp[-1].idenList)->toVector();
                                            delete (yyvsp[-1].idenList);
                                            auto type = (yyvsp[0].type);
                                            auto list = new LinkedList<std::pair<std::string, ASB::Type *>>;
                                            for(int i=0; i<ids.size(); i++){
                                                list->add(i, std::make_pair(ids[i], type));
                                            }
                                            (yyval.fields)=list;
                                            
                                        }
#line 1698 "src/Parser/parser.cpp"
    break;

  case 20:
#line 213 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {
                                            auto type = (yyvsp[-2].type);
                                            auto list = (yyvsp[0].fields);
                                            list->add(0, std::make_pair("", type));
                                            (yyval.fields) = list;
                                        }
#line 1709 "src/Parser/parser.cpp"
    break;

  case 21:
#line 221 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {
                                            auto ids = (yyvsp[-3].idenList)->toVector();
                                            delete (yyvsp[-3].idenList);
                                            auto type = (yyvsp[-2].type);
                                            auto list = (yyvsp[0].fields);
                                            for(int i=0; i<ids.size(); i++){
                                                list->add(i, std::make_pair(ids[i], type));
                                            }
                                            (yyval.fields) = list;
                                            

                                        }
#line 1726 "src/Parser/parser.cpp"
    break;

  case 22:
#line 240 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                   {(yyval.block) = new ASB::Block{(yyvsp[-1].listStatment)->toVector()}; delete (yyvsp[-1].listStatment);}
#line 1732 "src/Parser/parser.cpp"
    break;

  case 23:
#line 247 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {   auto decla = (yyvsp[0].listDeclaration)->toVector();
                                        delete (yyvsp[0].listDeclaration);
                                        auto list = new LinkedList<ASB::TopDeclaration *>;
                                        for(int i=0; i<decla.size(); i++){
                                            list->add(i, decla[i]);
                                        }
                                        (yyval.listTopDeclaration) = list;
                                    }
#line 1745 "src/Parser/parser.cpp"
    break;

  case 24:
#line 256 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto function = (yyvsp[0].topDeclaration);
                                        auto list = new LinkedList<ASB::TopDeclaration *>;
                                        list->add(0, function);
                                        (yyval.listTopDeclaration) = list;
                                    }
#line 1756 "src/Parser/parser.cpp"
    break;

  case 25:
#line 267 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        (yyval.topDeclaration) = new ASB::FunctionDeclaration{(yyvsp[-2].identifierValue), (yyvsp[-1].type), (yyvsp[0].block)};
                                    }
#line 1764 "src/Parser/parser.cpp"
    break;

  case 26:
#line 272 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.listDeclaration) = (yyvsp[0].listDeclaration);}
#line 1770 "src/Parser/parser.cpp"
    break;

  case 27:
#line 277 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto varspec = (yyvsp[0].declaration);
                                        auto list = new LinkedList<ASB::Declaration *>;
                                        list->add(0, varspec);
                                        (yyval.listDeclaration) = list;
                                    }
#line 1781 "src/Parser/parser.cpp"
    break;

  case 28:
#line 284 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        (yyval.listDeclaration) = (yyvsp[-1].listDeclaration);
                                    }
#line 1789 "src/Parser/parser.cpp"
    break;

  case 29:
#line 290 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                            {(yyval.declaration) = new ASB::VariableDeclaration{(yyvsp[-1].idenList)->toVector(), (yyvsp[0].type), {}};}
#line 1795 "src/Parser/parser.cpp"
    break;

  case 30:
#line 291 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                            {(yyval.declaration) = new ASB::VariableDeclaration{(yyvsp[-3].idenList)->toVector(), (yyvsp[-2].type), (yyvsp[0].listExpression)->toVector()};}
#line 1801 "src/Parser/parser.cpp"
    break;

  case 31:
#line 292 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                            {(yyval.declaration) = new ASB::VariableDeclaration{(yyvsp[-2].idenList)->toVector(), nullptr, (yyvsp[0].listExpression)->toVector()};}
#line 1807 "src/Parser/parser.cpp"
    break;

  case 32:
#line 296 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto varspec = (yyvsp[-1].declaration);
                                        auto list = new LinkedList<ASB::Declaration *>;
                                        list->add(0, varspec);
                                        (yyval.listDeclaration) = list;
                                    }
#line 1818 "src/Parser/parser.cpp"
    break;

  case 33:
#line 302 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto varspec = (yyvsp[-2].declaration);
                                        auto list = (yyvsp[0].listDeclaration);
                                        list->add(0, varspec);
                                        (yyval.listDeclaration) = list;
                                    }
#line 1829 "src/Parser/parser.cpp"
    break;

  case 34:
#line 312 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                            {
                                                (yyval.listTopDeclaration) =(yyvsp[0].listTopDeclaration);
                                            }
#line 1837 "src/Parser/parser.cpp"
    break;

  case 35:
#line 315 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                             {
                                                auto topdeclartionlist = (yyvsp[-2].listTopDeclaration)->toVector();
                                                delete (yyvsp[-2].listTopDeclaration);
                                                auto list = (yyvsp[0].listTopDeclaration);
                                                for(int i=0; i < topdeclartionlist.size(); i++){
                                                    list->add(i, topdeclartionlist[i]);
                                                }
                                                (yyval.listTopDeclaration) = list;                                            
                                            }
#line 1851 "src/Parser/parser.cpp"
    break;

  case 36:
#line 328 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto simplestatment = (yyvsp[0].simpleStatment);
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, simplestatment);
                                        (yyval.listStatment) = list;
                                    }
#line 1862 "src/Parser/parser.cpp"
    break;

  case 37:
#line 334 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto ifstatment = (yyvsp[0].statment);
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, ifstatment);
                                        (yyval.listStatment) = list;
                                    }
#line 1873 "src/Parser/parser.cpp"
    break;

  case 38:
#line 340 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto returnstat = (yyvsp[0].statment);
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, returnstat);
                                        (yyval.listStatment) = list;
                                    }
#line 1884 "src/Parser/parser.cpp"
    break;

  case 39:
#line 346 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto forstat = (yyvsp[0].statment);
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, forstat);
                                        (yyval.listStatment) = list;
                                    }
#line 1895 "src/Parser/parser.cpp"
    break;

  case 40:
#line 352 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto listdeclaration = (yyvsp[0].listDeclaration)->toVector();
                                        delete (yyvsp[0].listDeclaration);
                                        auto list = new LinkedList<ASB::Statment *>;
                                        for(int i = 0; i<listdeclaration.size(); i++){
                                            list->add(i, new ASB::DeclarationStatment{listdeclaration[i]});
                                        }                                           
                                        (yyval.listStatment) = list;
                                    }
#line 1909 "src/Parser/parser.cpp"
    break;

  case 41:
#line 366 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.simpleStatment) = new ASB::EmptyStatment{};}
#line 1915 "src/Parser/parser.cpp"
    break;

  case 42:
#line 367 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.simpleStatment) = new ASB::ExpressionStatment{(yyvsp[0].expression)};}
#line 1921 "src/Parser/parser.cpp"
    break;

  case 43:
#line 369 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto leftside = (yyvsp[-2].listExpression)->toVector();
                                        auto rightside = (yyvsp[0].listExpression)->toVector();
                                        (yyval.simpleStatment) = new ASB::AssignmentStatment{leftside, rightside};
                                        delete (yyvsp[-2].listExpression);
                                        delete (yyvsp[0].listExpression);
                                    }
#line 1933 "src/Parser/parser.cpp"
    break;

  case 44:
#line 379 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.statment) = new ASB::IfStatment{(yyvsp[-1].expression), (yyvsp[0].block), new ASB::Block{ {} } }; }
#line 1939 "src/Parser/parser.cpp"
    break;

  case 45:
#line 381 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.statment) = new ASB::IfStatment{(yyvsp[-3].expression), (yyvsp[-2].block), new ASB::Block{{(yyvsp[0].statment)}}}; }
#line 1945 "src/Parser/parser.cpp"
    break;

  case 46:
#line 382 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.statment) = new ASB::IfStatment{(yyvsp[-3].expression), (yyvsp[-2].block), (yyvsp[0].block)}; }
#line 1951 "src/Parser/parser.cpp"
    break;

  case 47:
#line 387 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.statment) = new ASB::ForStatment{ new ASB::EmptyStatment{}, (yyvsp[-1].expression), new ASB::EmptyStatment{}, (yyvsp[0].block)};}
#line 1957 "src/Parser/parser.cpp"
    break;

  case 48:
#line 389 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.statment) = new ASB::ForStatment{ (yyvsp[-5].simpleStatment), (yyvsp[-3].expression), (yyvsp[-1].simpleStatment), (yyvsp[0].block)};}
#line 1963 "src/Parser/parser.cpp"
    break;

  case 49:
#line 390 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.statment) = new ASB::ForStatment{ new ASB::EmptyStatment{}, new ASB::BoolExpression{true}, new ASB::EmptyStatment{}, (yyvsp[0].block)};}
#line 1969 "src/Parser/parser.cpp"
    break;

  case 50:
#line 394 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.statment) = new ASB::ReturnStatment{(yyvsp[0].listExpression)->toVector()}; }
#line 1975 "src/Parser/parser.cpp"
    break;

  case 51:
#line 398 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.listStatment) = new LinkedList<ASB::Statment *>;}
#line 1981 "src/Parser/parser.cpp"
    break;

  case 52:
#line 399 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {   auto stat = (yyvsp[-2].listStatment)->toVector();
                                        delete (yyvsp[-2].listStatment);
                                        auto list = (yyvsp[0].listStatment);
                                        for(int i=0; i < stat.size(); i++){
                                            list->add(i, stat[i]);
                                        }
                                        (yyval.listStatment) = list;
                                    }
#line 1994 "src/Parser/parser.cpp"
    break;

  case 53:
#line 411 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.expression) = new ASB::BoolExpression{(yyvsp[0].booleanValue)};}
#line 2000 "src/Parser/parser.cpp"
    break;

  case 54:
#line 412 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.expression) = new ASB::IntegerExpression{(yyvsp[0].integerValue)};}
#line 2006 "src/Parser/parser.cpp"
    break;

  case 55:
#line 413 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.expression) = new ASB::FloatExpression{(yyvsp[0].floatValue)};}
#line 2012 "src/Parser/parser.cpp"
    break;

  case 56:
#line 414 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.expression) = new ASB::CharExpression{(yyvsp[0].charValue)};}
#line 2018 "src/Parser/parser.cpp"
    break;

  case 57:
#line 415 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {(yyval.expression) = new ASB::IdentifierExpression{(yyvsp[0].identifierValue)};}
#line 2024 "src/Parser/parser.cpp"
    break;

  case 58:
#line 419 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto expr = (yyvsp[0].expression);
                                        auto list = new LinkedList<ASB::Expression *>{};
                                        list->add(0, expr);
                                        (yyval.listExpression) = list;            
                                    }
#line 2035 "src/Parser/parser.cpp"
    break;

  case 59:
#line 425 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                    {
                                        auto expr = (yyvsp[-2].expression);
                                        auto list = (yyvsp[0].listExpression);
                                        list->add(0, expr);
                                        (yyval.listExpression) = list;
                                    }
#line 2046 "src/Parser/parser.cpp"
    break;

  case 60:
#line 435 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {
                                            auto list = new LinkedList<std::string>{};
                                            list->add(0, (yyvsp[0].identifierValue));
                                            (yyval.idenList) = list;
                                            delete (yyvsp[0].identifierValue);
                                        }
#line 2057 "src/Parser/parser.cpp"
    break;

  case 61:
#line 442 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"
                                        {
                                            auto list = (yyvsp[0].idenList);
                                            list->add(0, (yyvsp[-2].identifierValue));
                                            (yyval.idenList) = list;
                                            delete (yyvsp[-2].identifierValue);
                                        }
#line 2068 "src/Parser/parser.cpp"
    break;


#line 2072 "src/Parser/parser.cpp"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 452 "/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/includes/Parser/parse.y"


//debug but learn and adapt
void yyerror(char *message)
{
    std::cerr << message << " on line " << yylloc.first_line << ", column " << yylloc.first_column+1 << std::endl;
    if (*yytext == '\n') {
        std::cerr  << "unexpected newline (implicit semicolon)." << std::endl;
    } else {
        std::cerr  << "unexpected \'" << yytext << "\'." << std::endl;
    }
}
