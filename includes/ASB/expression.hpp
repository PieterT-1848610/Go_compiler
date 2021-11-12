#ifndef ASB_EXPRESSION_HPP
#define ASB_EXPRESSION_HPP

#include "asb.hpp"
#include <string>

namespace ASB{

class IdentifierExpression: public Expression{
    public:
        IdentifierExpression(std::string id);
        virtual ~IdentifierExpression() override = default;

    private:
        std::string id;
};

class BoolExpression: public Expression{
    public:
        BoolExpression(bool value);
        virtual ~BoolExpression() override = default;

    private:
        bool value;
};

class IntegerExpression: public Expression{
    public:
        IntegerExpression(int value);
        virtual ~IntegerExpression() override = default;


    private:
        int value;
};

class FloatExpression: public Expression{
    public:
        FloatExpression(float value);
        virtual ~FloatExpression() override = default;

    private:
        float value;
};

class CharExpression: public Expression{
    public:
        CharExpression(char value);
        virtual ~CharExpression() override = default;

    private:
        char value;
};
}
#endif