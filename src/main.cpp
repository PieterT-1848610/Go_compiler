#include <iostream>
#include <cstdio>
#include "lexer/lexer.hpp"
#include "ASB/asb.hpp"
extern int yyparse();
extern ASB::Node *tree;


int main(){
    
    yyin = fopen("/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/test/test.go", "r");
    if(yyin == NULL){
        std::cout<<"error opening file";
        return -1;
    }
    //std::cout<<"fucking something";
    yyparse();
    
    if(tree != nullptr){
        std::cout<<"fucking Succes\n";
        return EXIT_SUCCESS;
    }else{
        std::cout<<"fucking Failure\n";
        return EXIT_FAILURE;
    }

}