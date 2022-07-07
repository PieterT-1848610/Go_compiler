#include "ASB/types.hpp"
#include <string>
#include <vector>
#include <functional>

void ASB::IntType::accept(Visitor *visitor) const{
    visitor->intType();
}

void ASB::BooleanType::accept(Visitor *visitor) const{
    visitor->boolType();
}


void ASB::FloatType::accept(Visitor *visitor) const{
    visitor->floatType();
}

void ASB::CharType::accept(Visitor *visitor) const{
    visitor->charType();
}

ASB::FunctionType::FunctionType(std::vector<std::pair<std::string, Type *>>parameters,
            std::vector<std::pair<std::string, Type *>>results): parameters{parameters}, results{results}{

};

ASB::FunctionType::~FunctionType(){
    for(int i=0; i<parameters.size(); i++){
        delete parameters[i].second;
    }

    for(int i=0; i<results.size(); i++){
        delete results[i].second;
    }
};

void ASB::FunctionType::accept(Visitor *visitor) const{
    std::vector<std::string> parametersName{};
    std::vector<std::function<void ()>> visitParametersType{};
    for(auto pairwise: this->parameters){
        parametersName.push_back(pairwise.first);
        visitParametersType.push_back([pairwise, visitor](){
            pairwise.second->accept(visitor);
        });
    }

    std::vector<std::string> resultsName{};
    std::vector<std::function<void ()>> visitResultsType{};
    for(auto pairwise: this->results){
        resultsName.push_back(pairwise.first);
        visitResultsType.push_back([pairwise, visitor](){
            pairwise.second->accept(visitor);
        });
    }

    visitor->functionType(parametersName, visitParametersType, resultsName, visitResultsType);
}

ASB::IdentifierType::IdentifierType(char *id): id{std::string{id}}{
    
};

void ASB::IdentifierType::accept(Visitor *visitor) const{
    visitor->identifierType(id);
}