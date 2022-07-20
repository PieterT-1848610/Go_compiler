#include "Visitor/typedescriptor.hpp"


bool BoolTypeDesc::compare(const TypeDescriptor *other) const{
    TypeCode otherType = other->getCode();

    return (TypeCode::booleanType == otherType);
}

std::string BoolTypeDesc::toString() const{
    return "Bool Type";
}

TypeCode BoolTypeDesc::getCode() const{
    return TypeCode::booleanType;
}


bool IntTypeDesc::compare(const TypeDescriptor *other) const{
    TypeCode otherType = other->getCode();

    return (TypeCode::integerType == otherType);
}

std::string IntTypeDesc::toString() const{
    return "Integer Type";
}

TypeCode IntTypeDesc::getCode() const{
    return TypeCode::integerType;
}

bool FloatTypeDesc::compare(const TypeDescriptor *other) const{
    TypeCode otherType = other->getCode();

    return (TypeCode::floatType == otherType);
}

std::string FloatTypeDesc::toString() const{
    return "Float Type";
}

TypeCode FloatTypeDesc::getCode() const{
    return TypeCode::floatType;
}

bool CharTypeDesc::compare(const TypeDescriptor *other) const{
    TypeCode otherType = other->getCode();

    return (TypeCode::charType == otherType);
}

std::string CharTypeDesc::toString() const{
    return "Char Type";
}

TypeCode CharTypeDesc::getCode() const{
    return TypeCode::charType;
}


//Still needs work
FunctionTypeDesc::FunctionTypeDesc(std::vector<std::pair<std::string, TypeDescriptor *>> parameters,
                std::vector<std::pair<std::string, TypeDescriptor *>> returns): parameters{parameters}, returns{returns} {

}
//not sure yet
FunctionTypeDesc::~FunctionTypeDesc(){

}

bool FunctionTypeDesc::compare(const TypeDescriptor *other) const{
    TypeCode otherType = other->getCode();

    return (TypeCode::booleanType == otherType);
}

std::string FunctionTypeDesc::toString() const{
    return "Function Type";
}

TypeCode FunctionTypeDesc::getCode() const{
    return TypeCode::functionType;
}

std::vector<std::string> FunctionTypeDesc::getParametersIds(){
    std::vector<std::string> parameterids = {};

    for(auto pairwise: parameters){
        parameterids.push_back(pairwise.first);
    }

    return parameterids;
}


std::vector<TypeDescriptor *> FunctionTypeDesc::getParametersTypeDesc(){
    std::vector<TypeDescriptor *> parametersType = {};

    for(auto pairwise: parameters){
        parametersType.push_back(pairwise.second);
    }

    return parametersType;
}

std::vector<std::string> FunctionTypeDesc::getReturnsIds(){
    std::vector<std::string> returnids = {};

    for(auto pairwise: returns){
        returnids.push_back(pairwise.first);
    }

    return returnids;
}


std::vector<TypeDescriptor *> FunctionTypeDesc::getReturnsTypeDesc(){
    std::vector<TypeDescriptor *> returnTypes = {};

    for(auto pairwise: returns){
        returnTypes.push_back(pairwise.second);
    }

    return returnTypes;
}