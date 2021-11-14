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

    linkedList<std::string> *idenList;

    linkedList<std::pair<std::string, ASB::Type *>> *fields;
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
%type <type> literalType;
%type <type> functionSignature;
%type <idenList> identifierList;


%type <fields> functionParameters;
%type <fields> functionResults;
%type <fields> functionParametersList;

%type <listTopDeclaration> listTopDeclaration;
%type <topDeclaration> functionDeclaration;

%type <listDeclaration> listDeclaration;
%type <declaration> variableDeclaration;





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


//No clue yet
literalType
    :IDENTIFIER                     {}
    ;


functionSignature
    :functionParameters functionResults 
                                    {
                                        $$=new ASB::functionType{$1->toVector(), $2->toVector()};
                                        delete $1;
                                        delete $2;
                                    }
    ;


functionResults
    :                               {$$= new linkedList<std::pair<std::string, ASB::Type *>>;}
    |functionParameters             {$$ = $1;}
    |type                           {
                                        auto type = $1;
                                        auto list = new linkedList<std::pair<std::string, ASB::Type *>>;
                                        list->add(0, std::make_pair("", type));
                                        $$ = list; 
                                    }
    ;


functionParameters
    :'(' ')'                            {$$ = new linkedList<std::pair<std::string, ASB::Type *>>; }
    |'(' functionParametersList ')'     {$$ = $2; }
    |'(' functionParametersList ',' ')' 
                                        {$$ = $2; }
    ;


functionParametersList
    :type                               {
                                            auto type = $1;
                                            auto list = new linkedList<std::pair<std::string, ASB::Type *>>;
                                            list->add(0, std::make_pair("", type));
                                            $$ = list;
                                        }

    |identifierList type                {
                                            auto ids = $1->toVector();
                                            auto type = $2;
                                            auto list = new linkedList<std::pair<std::string, ASB::Type *>>;
                                            for(int i=0; i<ids.size(); i++){
                                                list->add(i, std::make_pair(ids[i], type));
                                            }
                                            $$=list;
                                            delete $1;
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
                                            auto type = $2;
                                            auto list = $4;
                                            for(int i=0; i<ids.size(); i++){
                                                list->add(i, std::make_pair(ids[i], type));
                                            }
                                            $$ = list;
                                            delete $1;

                                        }
    ;

identifierList
    :IDENTIFIER                         {
                                            auto list = new linkedList<std::string>{};
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
    : '{' statment_list '}'         {$$ = new ASB::Block{$2->toVector()}; delete $2;}
    ;

%%

void yyerror(char const *message){
    printf("Error: %s\n", message);
}