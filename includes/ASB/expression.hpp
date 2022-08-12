#ifndef ASB_EXPRESSION_HPP
#define ASB_EXPRESSION_HPP

#include "asb.hpp"
#include <string>
#include <vector>

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


class CallExpression: public Expression{
    public:
        CallExpression(Expression * expression, std::vector<Expression *> arguments);
        virtual ~CallExpression() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        std::vector<Expression *> arguments;
        Expression* expression;
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


class BinaryMulOperation: public BinaryOperation{
    public:
        BinaryMulOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryMulOperation() override;
        virtual void accept(Visitor *visitor) const override;
    
    private:
        Expression *leftSide;
        Expression *rightSide;

};


class BinaryDivOperation: public BinaryOperation{
    public:
        BinaryDivOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryDivOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


class BinaryEQOperation: public BinaryOperation{
    public:
        BinaryEQOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryEQOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


class BinaryNEQOperation: public BinaryOperation{
    public:
        BinaryNEQOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryNEQOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


class BinaryANDOperation: public BinaryOperation{
    public:
        BinaryANDOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryANDOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


class BinaryOROperation: public BinaryOperation{
    public:
        BinaryOROperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryOROperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


//greater than >
class BinaryGTOperation: public BinaryOperation{
    public:
        BinaryGTOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryGTOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


//greater than or equal >=
class BinaryGEOperation: public BinaryOperation{
    public:
        BinaryGEOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryGEOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


//lesear than <
class BinaryLTOperation: public BinaryOperation{
    public:
        BinaryLTOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryLTOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


//leser than or equal <=
class BinaryLEOperation: public BinaryOperation{
    public:
        BinaryLEOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryLEOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};

class BinaryModOperation: public BinaryOperation{
    public:
        BinaryModOperation(Expression *leftSide, Expression *rightSide);
        virtual ~BinaryModOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *leftSide;
        Expression *rightSide;
};


//unary for not?
//inc, dec?
//plusassign, ...?

class UnaryOperation: public Expression{
    public:
        virtual ~UnaryOperation() = default;
        virtual void accept(Visitor *visitor) const override = 0;

    protected:
        UnaryOperation()= default;
};

class UnaryNotOperation: public UnaryOperation{
    public:
        UnaryNotOperation(Expression *expression);
        virtual ~UnaryNotOperation() override;
        virtual void accept(Visitor *visitor) const override;

    private:
        Expression *expression;
};

class UnaryPosOperation: public UnaryOperation{
    public:
        UnaryPosOperation(Expression *expression);
        virtual ~UnaryPosOperation() override;
        virtual void accept(Visitor *visitor) const override;
    
    private:
        Expression *expression;
};

class UnaryNegOperation: public UnaryOperation{
    public:
        UnaryNegOperation(Expression *expression);
        virtual ~UnaryNegOperation() override;
        virtual void accept(Visitor *visitor) const override;
    
    private:
        Expression *expression;
};


}
#endif
