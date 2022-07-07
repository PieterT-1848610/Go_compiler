#ifndef ASB_EXPRESSION_HPP
#define ASB_EXPRESSION_HPP

#include "asb.hpp"
#include <string>

namespace ASB{
//leaf dus impl van visitor


//aan de hand van type calssen. Get type
// Type check (equeals). Compaer if given type is equal
//Trival basic types.(Boolean, Int, Float) True
class IdentifierExpression: public Expression{
    public:
        IdentifierExpression(std::string id);
        virtual ~IdentifierExpression() override = default;

        //getType -> IdType
    private:
        std::string id;
};

class BoolExpression: public Expression{
    public:
        BoolExpression(bool value);
        virtual ~BoolExpression() override = default;
        //getType -> return Boolean;
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
//always true
class CharExpression: public Expression{
    public:
        CharExpression(char value);
        virtual ~CharExpression() override = default;

    private:
        char value;
};

//need to be specilias  up in add, sub, 
//so not a leaf, protected constructor
class BinaryOperation: public Expression{
    //type checken of beide compatible zijn
};


}
#endif