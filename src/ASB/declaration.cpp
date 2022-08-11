#include "ASB/declaration.hpp"

ASB::FunctionDeclaration::FunctionDeclaration(std::string id, Type *signature, Block *functionBody):
                                        id{id}, signature {signature}, functionBody{functionBody}{

    }

ASB::FunctionDeclaration::~FunctionDeclaration(){
    delete signature;
    delete functionBody;
}

void ASB::FunctionDeclaration::accept(Visitor *visitor) const{
    std::function<void ()>visitSignature{ [visitor, this](){
        this->signature->accept(visitor);
    }};
    std::function<void ()>visitFunctionBody{ [visitor, this](){
        this->functionBody->accept(visitor);
    }};

    visitor->functionDeclaration(id, visitSignature, visitFunctionBody);
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

void ASB::VariableDeclaration::accept(Visitor *visitor) const{
    std::vector<std::function<void ()>>visitExpressions{};
    for(auto expre: this->expressions){
        visitExpressions.push_back([expre, visitor](){
            expre->accept(visitor);
        });
    }

    std::function<void ()>visitType{[visitor, this](){
        this->type->accept(visitor);
    }};

    if(this->type == NULL){
        visitType = NULL;
    }

    visitor->variableDeclaration(this->ids, visitType, visitExpressions);
}

ASB::PackageDeclaration::PackageDeclaration(std::string name):name{name}{

}
ASB::PackageDeclaration::~PackageDeclaration(){

}

void ASB::PackageDeclaration::accept(Visitor *visitor) const{

    visitor->packageDeclaration(this->name);
}