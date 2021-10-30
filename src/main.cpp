#include <iostream>
#include <cstdio>
#include "Lexer/lex.yy.c"
#include "includes/Parser/parser.hpp"
extern int yyparse();

int main(){
    yyin = fopen("test/test.go", "r");
    if(yyin){
        std::cout<<"error opening file";
        return -1;
    }

    yyparse();

    return 1;
}