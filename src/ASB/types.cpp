#include "ASB/types.hpp"


ASB::FunctionType::FunctionType(std::vector<std::pair<std::string, Type *>>parameters,
            std::vector<std::pair<std::string, Type *>>results): parameters{parameters}, results{results}{

            }

ASB::FunctionType::~FunctionType(){
    for(int i=0; i<parameters.size(); i++){
        delete parameters[i].second;
    }

    for(int i=0; i<results.size(); i++){
        delete results[i].second;
    }
};