#include "ASB/declaration.hpp"

ASB::FunctionDeclaration::FunctionDeclaration(std::string id, Type *signature, Block *functionBody):
                                        id{id}, signature {signature}, functionBody{functionBody}{

    }

ASB::FunctionDeclaration::~FunctionDeclaration(){
    delete signature;
    delete functionBody;
}

ASB::VariableDeclaration::VariableDeclaration(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions):
                                        ids {ids}, type{type}, expressions{expressions}{
                                            


    }

ASB::VariableDeclaration::~VariableDeclaration(){
    delete type;
    for(int i=0; i<expressions.size(); i++){    
        delete expressions[i];
    }
}
