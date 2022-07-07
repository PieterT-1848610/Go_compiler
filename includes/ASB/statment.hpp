#ifndef ASB_STATMENT_HPP
#define ASB_STATMENT_HPP

#include "asb.hpp"
namespace ASB{

//leaf voor visitor patroon         virtual void accept(Visitor *visitor) const  override;

class ExpressionStatment: public SimpleStatment{
    public:
        ExpressionStatment(Expression *expression);
        virtual  ~ExpressionStatment() override;
        virtual void accept(Visitor *visitor) const  override;
    private:
        Expression *expression;
};


class EmptyStatment: public SimpleStatment{
    public:
        EmptyStatment() = default;
        virtual ~EmptyStatment() override = default;
        virtual void accept(Visitor *visitor) const override;
};

class AssignmentStatment: public SimpleStatment{
    public:
        AssignmentStatment(std::vector<Expression *> leftSide, std::vector<Expression *> rightSide);
        virtual ~AssignmentStatment() override;

        virtual void accept(Visitor *visitor) const override;

    private: 
        std::vector<Expression *> leftSide;
        std::vector<Expression *> rightSide;
};


class ForStatment: public Statment{
    public:
        ForStatment(SimpleStatment *init, Expression *condition, SimpleStatment *post, Block *bodyFor);
        virtual ~ForStatment() override;

        virtual void accept(Visitor *visitor) const override;
    private:
        SimpleStatment      *initStatment;
        Expression          *condition;
        SimpleStatment      *postStatment;
        Block               *bodyFor;


};


class DeclarationStatment: public Statment{
    public:
        DeclarationStatment(Declaration *declaration);
        virtual ~DeclarationStatment() override;

        virtual void accept(Visitor *visitor) const override;
    private:
        Declaration *declaration;
};


class IfStatment: public Statment{
    public:
        IfStatment(Expression *condition, Block *TrueCondition, Block *FalseCondition);
        virtual ~IfStatment() override;

        virtual void accept(Visitor *visitor) const override;
    private:
        Expression  *condition;
        Block       *trueCondition;
        Block       *falseCondition;
};


class ReturnStatment: public Statment{
    public:
        ReturnStatment(std::vector<Expression *> expressions);
        virtual ~ReturnStatment() override;

        virtual void accept(Visitor *visitor) const override;

    private:
        std::vector<Expression *> expressions;
};



}
#endif