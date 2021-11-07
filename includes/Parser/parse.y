%locations
%defines "includes/Parser/parser.hpp"
//die gebruikt worden 
%code{
    #include <iostream>
    #include <string>

}
//alles wat in hearder file komt te staan
%code requires{
    #include <string>
    #include <vector>

}

// declaratie van verschillende types
%union {
    int integerValue;
    float floatValue;
    bool booleanValue;
    char charValue;
    char *identifierValue;
    
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


%token <identifierValue> IDENTIFIER
%token <integerValue> INTEGER_LITERAL
%token <floatValue> FLOAT_LITERAL
%token <booleanValue> BOOLEAN_LITERAL
%token <charValue> CHAR_LITERAL
//%token <stringValue> STRING_LITERAL
//type declaratie van niet-terminaal symbolen

//more noting
%%

start: ;

%%