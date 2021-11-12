%locations
%defines "includes/Parser/parser.hpp"
//die gebruikt worden 
%code{
    #include <iostream>
    #include <string>
    
    ASB::Root *tree;

    void yyerror(char const *message);

}
//alles wat in hearder file komt te staan
%code requires{
    #include <string>
    #include <vector>
    #include <ASB/asb.hpp>
    #include <ASB/declaration.hpp>
    #include <ASB/expression.hpp>
    #include <ASB/statment.hpp>
    #include <ASB/types.hpp>
    #include <other/linkedlist.hpp>


}

// declaratie van verschillende types
%union {
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

    linkedList<ASB::Statment> *listStatment;
    linkedList<ASB::SimpleStatment> *listSimpleStatment;

    linkedList<ASB::TopDeclaration> *listTopDeclaration;
    linkedList<ASB::Declaration> *listDeclaration;
    
    linkedList<ASB::Expression> *listExpression;



}


%token INT
%token FLOAT32
%token BOOL
%token CHAR
//%token STRING
%token RUNE
%token BYTE

%token SEMI
%token IF
%token ELSE
%token FOR
%token RETURN
%token VAR
%token FUNC

%token <identifierValue> IDENTIFIER
%token <integerValue> INTEGER_LITERAL
%token <floatValue> FLOAT_LITERAL
%token <booleanValue> BOOLEAN_LITERAL
%token <charValue> CHAR_LITERAL
//%token <stringValue> STRING_LITERAL
//type declaratie van niet-terminaal symbolen

//alle nodes die van statment komen
%type <listStatment> statments;
%type <listStatment> statment_list;
%type <statment> forStatment;
%type <statment> ifStatment;
%type <statment> returnStatment;
%type <statment> declarationStatment;

%type <simpleStatment> simpleStatment;
//%type <simpleStatment> expressionStatment;
//%type <simpleStatment> assignmentStatment;

%type <expression> identifierExpression;
%type <expression> boolExpression;
%type <expression> intergerExpression;
%type <expression> floatExpression;
%type <expression> charExpression;

%type <block> block;


%type <type> type;

%type <listTopDeclaration> listTopDeclaration;
%type <topDeclaration> functionDeclaration;

%type <listDeclaration> listDeclaration;
%type <declaration> variableDeclaration;





//more noting
%%
start
    :listTopDeclaration     {tree = new AST::Root{$1->toStdVector()}; }
    ;
//For type things
type
    :INT                    {$$ = new AST::IntType{}; }
    |FLOAT32                {$$ = new AST::FloatType{}; }
    |BOOL                   {$$ = new AST::BooleanType{}; }
    |CHAR                   {$$ = new AST::CharType{}; }
    ;

   
//For a block of code
block
    : '{' statment_list '}'     {$$ = new AST::Block{$2->toStdVector()}; delete $2;}
    ;

%%

void yyerror(char const *message){
    printf("Error: %s\n", message);
}