#include "asb.hpp"
#include <string>

namespace ASB{
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