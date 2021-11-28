%locations
%defines "includes/Parser/parser.hpp"
//die gebruikt worden 
%code{
    #include <iostream>
    #include <string>
    #include <lexer/lexer.hpp>
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

    LinkedList<ASB::Statment *> *listStatment;
    LinkedList<ASB::SimpleStatment *> *listSimpleStatment;

    LinkedList<ASB::TopDeclaration *> *listTopDeclaration;
    LinkedList<ASB::Declaration *> *listDeclaration;
    
    LinkedList<ASB::Expression *> *listExpression;

    LinkedList<std::string> *idenList;

    LinkedList<std::pair<std::string, ASB::Type *>> *fields;
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
%type <listStatment> statmentList;
%type <statment> ifStatment;
%type <statment> returnStatment;
%type <statment> forStatment;


%type <simpleStatment> simpleStatment;
//%type <simpleStatment> expressionStatment;
//%type <simpleStatment> assignmentStatment;

%type <listExpression> expressionList;
%type <expression> expression;


%type <block> block;


%type <type> type;
%type <type> literalType;
%type <type> functionSignature;
%type <idenList> identifierList;


%type <fields> functionParameters;
%type <fields> functionResults;
%type <fields> functionParametersList;

%type <listTopDeclaration> listTopDeclaration;
%type <listTopDeclaration> topDeclaration;
%type <topDeclaration> functionDeclaration;

%type <listDeclaration> listDeclaration;
%type <listDeclaration> variableDeclaration;
%type <listDeclaration> varSpecList;
%type <declaration> varSpec;




//more noting
%%
start
    :listTopDeclaration     {tree = new ASB::Root{$1->toVector()}; }
    ;


//For type things
type
    :'('type ')'                    {$$ = $2;}
    |INT                            {$$ = new ASB::IntType{}; }
    |FLOAT32                        {$$ = new ASB::FloatType{}; }
    |BOOL                           {$$ = new ASB::BooleanType{}; }
    |CHAR                           {$$ = new ASB::CharType{}; }
    |literalType                    {$$ = $1;}
    |FUNC functionSignature         {$$ = $2;}
    ;


//voor identifier te maken
literalType
    :IDENTIFIER                     {$$ = new ASB::IdentifierType{$1}; delete $1;}
    ;

//voor functie type
functionSignature
    :functionParameters functionResults 
                                    {
                                        $$=new ASB::FunctionType{$1->toVector(), $2->toVector()};
                                        delete $1;
                                        delete $2;
                                    }
    ;


functionResults
    :                               {$$= new LinkedList<std::pair<std::string, ASB::Type *>>;}
    |functionParameters             {$$ = $1;}
    |type                           {
                                        auto type = $1;
                                        auto list = new LinkedList<std::pair<std::string, ASB::Type *>>;
                                        list->add(0, std::make_pair("", type));
                                        $$ = list; 
                                    }
    ;


functionParameters
    :'(' ')'                            {$$ = new LinkedList<std::pair<std::string, ASB::Type *>>; }
    |'(' functionParametersList ')'     {$$ = $2; }
    |'(' functionParametersList ',' ')' 
                                        {$$ = $2; }
    ;


functionParametersList
    :type                               {
                                            auto type = $1;
                                            auto list = new LinkedList<std::pair<std::string, ASB::Type *>>;
                                            list->add(0, std::make_pair("", type));
                                            $$ = list;
                                        }

    |identifierList type                {
                                            auto ids = $1->toVector();
                                            delete $1;
                                            auto type = $2;
                                            auto list = new LinkedList<std::pair<std::string, ASB::Type *>>;
                                            for(int i=0; i<ids.size(); i++){
                                                list->add(i, std::make_pair(ids[i], type));
                                            }
                                            $$=list;
                                            
                                        }

    |type ',' functionParametersList    {
                                            auto type = $1;
                                            auto list = $3;
                                            list->add(0, std::make_pair("", type));
                                            $$ = list;
                                        }
    
    |identifierList type ',' functionParametersList
                                        {
                                            auto ids = $1->toVector();
                                            delete $1;
                                            auto type = $2;
                                            auto list = $4;
                                            for(int i=0; i<ids.size(); i++){
                                                list->add(i, std::make_pair(ids[i], type));
                                            }
                                            $$ = list;
                                            

                                        }
    ;

identifierList
    :IDENTIFIER                         {
                                            auto list = new LinkedList<std::string>{};
                                            list->add(0, $1);
                                            $$ = list;
                                            delete $1;
                                        }
    |IDENTIFIER ',' identifierList      
                                        {
                                            auto list = $3;
                                            list->add(0, $1);
                                            $$ = list;
                                            delete $1;
                                        }
    ;




//For a block of code
block
    : '{' statmentList '}'         {$$ = new ASB::Block{$2->toVector()}; delete $2;}
    ;


//Not working right
//Declarations 
topDeclaration
    :listDeclaration                {   auto decla = $1->toVector();
                                        delete $1;
                                        auto list = new LinkedList<ASB::TopDeclaration *>;
                                        for(int i=0; i<decla.size(); i++){
                                            list->add(i, decla[i]);
                                        }
                                        $$ = list;
                                    }             
    
    |functionDeclaration            {
                                        auto function = $1;
                                        auto list = new LinkedList<ASB::TopDeclaration *>;
                                        list->add(0, function);
                                        $$ = list;
                                    }
    ;

//Voor functies
functionDeclaration
    :FUNC IDENTIFIER functionSignature block
                                    {
                                        $$ = new ASB::FunctionDeclaration{$2, $3, $4};
                                    }

listDeclaration
    :variableDeclaration            {$$ = $1;}
    ;

//voor var declaratie
variableDeclaration
    :VAR varSpec                    {
                                        auto varspec = $2;
                                        auto list = new LinkedList<ASB::Declaration *>;
                                        list->add(0, varspec);
                                        $$ = list;
                                    }

    |VAR '(' varSpecList ')'        {
                                        $$ = $3;
                                    }
    ;

varSpec
    :identifierList type                    {$$ = new ASB::VariableDeclaration{$1->toVector(), $2, {}};}
    |identifierList '=' expressionList      {$$ = new ASB::VariableDeclaration{$1->toVector(), nullptr, $3->toVector()};}
    |identifierList type '=' expressionList {$$ = new ASB::VariableDeclaration{$1->toVector(), $2, $4->toVector()};}
    ;

varSpecList
    :varSpec ';'                    {
                                        auto varspec = $1;
                                        auto list = new LinkedList<ASB::Declaration *>;
                                        list->add(0, varspec);
                                        $$ = list;
                                    }
    |varSpec ';' varSpecList        {
                                        auto varspec = $1;
                                        auto list = $3;
                                        list->add(0, varspec);
                                        $$ = list;
                                    }
    ;


listTopDeclaration
    :topDeclaration                         {
                                                $$ =$1;
                                            }
    |topDeclaration ';' listTopDeclaration  {
                                                auto topdeclartionlist = $1->toVector();
                                                delete $1;
                                                auto list = $3;
                                                for(int i=0; i < topdeclartionlist.size(); i++){
                                                    list->add(i, topdeclartionlist[i]);
                                                }
                                                $$ = list;                                            
                                            }
    ;

//Statments section
statments
    :simpleStatment                 {
                                        auto simplestatment = $1;
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, simplestatment);
                                        $$ = list;
                                    }
    |ifStatment                     {
                                        auto ifstatment = $1;
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, ifstatment);
                                        $$ = list;
                                    }
    |returnStatment                 {
                                        auto returnstat = $1;
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, returnstat);
                                        $$ = list;
                                    }
    |forStatment                    {
                                        auto forstat = $1;
                                        auto list = new LinkedList<ASB::Statment *>;
                                        list->add(0, forstat);
                                        $$ = list;
                                    }
    |listDeclaration                {
                                        auto listdeclaration = $1->toVector();
                                        delete $1;
                                        auto list = new LinkedList<ASB::Statment *>;
                                        for(int i = 0; i<listdeclaration.size(); i++){
                                            list->add(i, new ASB::DeclarationStatment{listdeclaration[i]});
                                        }                                           
                                        $$ = list;
                                    }   
    ;


//empty expression en assignment statments
simpleStatment
    :                               {$$ = new ASB::EmptyStatment{};}
    |expression                     {$$ = new ASB::ExpressionStatment{$1};}
    |expressionList '=' expressionList
                                    {
                                        auto leftside = $1->toVector();
                                        auto rightside = $3->toVector();
                                        $$ = new ASB::AssignmentStatment{leftside, rightside};
                                        delete $1;
                                        delete $3;
                                    }


ifStatment
    :IF expression block            {$$ = new ASB::IfStatment{$2, $3, new ASB::Block{ {} } }; }
    |IF expression block ELSE ifStatment  
                                    {$$ = new ASB::IfStatment{$2, $3, new ASB::Block{{$5}}}; }
    |IF expression block ELSE block {$$ = new ASB::IfStatment{$2, $3, $5}; }       
    ;


forStatment
    :FOR expression block           {$$ = new ASB::ForStatment{ new ASB::EmptyStatment{}, $2, new ASB::EmptyStatment{}, $3};}
    |FOR simpleStatment ';'  expression ';' simpleStatment block
                                    {$$ = new ASB::ForStatment{ $2, $4, $6, $7};}
    |FOR block                      {$$ = new ASB::ForStatment{ new ASB::EmptyStatment{}, new ASB::BoolExpression{true}, new ASB::EmptyStatment{}, $2};}
    ;

returnStatment
    :RETURN expressionList          {$$ = new ASB::ReturnStatment{$2->toVector()}; }
    ;

statmentList
    :                               {$$ = new LinkedList<ASB::Statment *>;}
    |statments ';' statmentList     {   auto stat = $1->toVector();
                                        delete $1;
                                        auto list = $3;
                                        for(int i=0; i < stat.size(); i++){
                                            list->add(i, stat[i]);
                                        }
                                        $$ = list;
                                    }
    ;

//expressions stuff
expression
    :INTEGER_LITERAL                {$$ = new ASB::IntegerExpression{$1};}
    |BOOLEAN_LITERAL                {$$ = new ASB::BoolExpression{$1};}
    |FLOAT_LITERAL                  {$$ = new ASB::FloatExpression{$1};}
    |CHAR_LITERAL                   {$$ = new ASB::CharExpression{$1};}
    |IDENTIFIER                     {$$ = new ASB::IdentifierExpression{$1};}
    ;

expressionList
    :expression                     {
                                        auto expr = $1;
                                        auto list = new LinkedList<ASB::Expression *>;
                                        list->add(0, expr);
                                        $$ = list;            
                                    }       
    |expression ';' expressionList  {
                                        auto expr = $1;
                                        auto list = $3;
                                        list->add(0, expr);
                                        $$ = list;
                                    }


%%

void yyerror(char const *message){
    printf("Error: %s\n", message);
}