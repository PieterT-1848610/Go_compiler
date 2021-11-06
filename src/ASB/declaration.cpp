#include "./includes/ASB/declaration.hpp"

FunctionDeclaration::FunctionDeclaration(std::string id, Type *signature, Block *functionBody):
                                        id{id}, signature {signature}, functionBody{functionBody}{

    }

FunctionDeclaration::~FunctionDeclaration(){
    delete signature;
    delete functionBody;
}

VariableDeclaration::VariableDeclaration(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions):
                                        ids {ids}, type{type}, expressions{expressions}{

    }

VariableDeclaration::~VariableDeclaration(){
    delete type;
    for(int i=0; i<expressions.size(); i++){    
        delete expressions[i];
    }
}
