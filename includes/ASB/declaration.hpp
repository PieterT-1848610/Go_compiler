#ifndef ASB_DECLARTION_HPP
#define ASB_DECLARTION_HPP

#include "asb.hpp"
#include <string>

namespace ASB{

class FunctionDeclaration: public TopDeclaration{
    public:
        FunctionDeclaration(std::string id, Type *signature, Block *functionBody);
        virtual ~FunctionDeclaration() override;

        virtual void accept(Visitor *visitor)const override;
    private:
        std::string id;
        Type        *signature;
        Block       *functionBody;
};

class VariableDeclaration: public Declaration{
    public:
        VariableDeclaration(std::vector<std::string> ids, Type *type, std::vector<Expression *> expressions);
        virtual ~VariableDeclaration() override;

        virtual void accept(Visitor *visitor)const override;

    private:
        std::vector<std::string>    ids;
        Type                        *type;
        std::vector<Expression *>   expressions;
};

class PackageDeclaration: public Declaration{
    public:
        PackageDeclaration(std::string name);
        virtual ~PackageDeclaration() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::string name;

};


}

#endif
