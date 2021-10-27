%locations
%defines "includes/Parser/parser.hpp"
//die gebruikt worden 
%code{
    #include <iostream>

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
    str stringValue;

}


%token INT
%token FLOAT32
%token BOOL
%token CHAR
%token STRING
%token RUNE
%token BYTE


%token <identifierValue> IDENTIFIER
//type declaratie van niet-terminaal symbolen

//more noting
%%

start: ;

%%