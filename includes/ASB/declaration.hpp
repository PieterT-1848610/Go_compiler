#ifndef ASB_DECLARTION_HPP
#define ASB_DECLARTION_HPP

#include "asb.hpp"
#include <string>

namespace ASB{
    //leaf node van structuur implementatie van visitor

class FunctionDeclaration: public TopDeclaration{
    public:
        FunctionDeclaration(std::string id, Type *signature, Block *functionBody);
        virtual ~FunctionDeclaration() override;

    private:
        std::string id;
        Type        *signature;
        Block       *functionBody;
};

class VariableDeclaration: public Declaration{
    public:
        VariableDeclaration(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions);
        virtual ~VariableDeclaration() override;

    private:
        std::vector<std::string>    ids;
        Type                        *type;
        std::vector<Expression *>   expressions;
};
}

#endif