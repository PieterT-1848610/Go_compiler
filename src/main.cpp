#include <iostream>
#include <cstdio>
#include "lexer/lexer.hpp"
#include "ASB/asb.hpp"
extern int yyparse();
extern ASB::Root *tree;
#include "Visitor/typechecker.hpp"
#include "Interpreting/interpreting.hpp"

int main(){
    
    yyin = fopen("/mnt/c/Users/thomi/Documents/Master/Compilers/giti/Go_compiler/test/test.go", "r");
    if(yyin == NULL){
        std::cout<<"error opening file";
        return -1;
    }
    //std::cout<<"fucking something";
    yyparse();
    //
    if(tree != nullptr){
        
    
        TypeChecker typecheck = TypeChecker(false);
       // try{
            tree->accept(&typecheck);
        //}catch(...){
        //    std::cout<<"crash?";
        //}
        if(!typecheck.emptyErrors()){
            std::cout<<"printing Errors: \n";
            for(auto error: typecheck.getErrors()){
                std::cout<<error<<"\n";
            }
        }else{
            std::cout<<"No Type errors\n";
            Interpreting interpret = Interpreting(true);

            std::cout<<"starting interpreting \n";
            tree->accept(&interpret);

        }
        //interpreteren 
        return EXIT_SUCCESS;
    }else{
        std::cout<<"Tree failed to build\n";
        return EXIT_FAILURE;
    }

}