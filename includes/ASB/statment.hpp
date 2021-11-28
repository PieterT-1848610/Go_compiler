#ifndef ASB_STATMENT_HPP
#define ASB_STATMENT_HPP

#include "asb.hpp"
namespace ASB{

class ExpressionStatment: public SimpleStatment{
    public:
        ExpressionStatment(Expression *expression);
        virtual  ~ExpressionStatment() override;

    private:
        Expression *expression;
};


class EmptyStatment: public SimpleStatment{
    public:
        EmptyStatment() = default;
        virtual ~EmptyStatment() override = default;

};

class AssignmentStatment: public SimpleStatment{
    public:
        AssignmentStatment(std::vector<Expression *> leftSide, std::vector<Expression *> rightSide);
        virtual ~AssignmentStatment() override;

    private: 
        std::vector<Expression *> leftSide;
        std::vector<Expression *> rightSide;
};


class ForStatment: public Statment{
    public:
        ForStatment(SimpleStatment *init, Expression *condition, SimpleStatment *post, Block *bodyFor);
        virtual ~ForStatment() override;

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

    private:
        Declaration *declaration;
};


class IfStatment: public Statment{
    public:
        IfStatment(Expression *condition, Block *TrueCondition, Block *FalseCondition);
        virtual ~IfStatment() override;

    private:
        Expression  *condition;
        Block       *TrueCondition;
        Block       *FalseCondition;
};


class ReturnStatment: public Statment{
    public:
        ReturnStatment(std::vector<Expression *> expressions);
        virtual ~ReturnStatment() override;

    private:
        std::vector<Expression *> expressions;
};



}
#endif