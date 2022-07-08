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
        
        virtual void accept(Visitor *visitor) const  override;

        //getType -> IdType
    private:
        std::string id;
};

class BoolExpression: public Expression{
    public:
        BoolExpression(bool value);
        virtual ~BoolExpression() override = default;
        //getType -> return Boolean;

        virtual void accept(Visitor *visitor) const override;
    private:
        bool value;
};

class IntegerExpression: public Expression{
    public:
        IntegerExpression(int value);
        virtual ~IntegerExpression() override = default;

        virtual void accept(Visitor *visitor) const override;
    private:
        int value;
};

class FloatExpression: public Expression{
    public:
        FloatExpression(float value);
        virtual ~FloatExpression() override = default;
        virtual void accept(Visitor *visitor) const override;

    private:
        float value;
};
//always true
class CharExpression: public Expression{
    public:
        CharExpression(char value);
        virtual ~CharExpression() override = default;
        virtual void accept(Visitor *visitor) const override;

    private:
        char value;
};



//need to be specilias  up in add, sub, 
//so not a leaf, protected constructor
class BinaryOperation: public Expression{
    //type checken of beide compatible zijn
    public:
        virtual ~BinaryOperation() = default;
        virtual void accept(Visitor *visitor) const override = 0;
    
    protected:
        BinaryOperation() = default;

};

class BinaryAddOperation: public BinaryOperation{
    public:
        BinaryAddOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryAddOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};

class BinaryMinOperation: public BinaryOperation{
    public:
        BinaryMinOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryMinOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


}
#endif