#ifndef VISITOR_VISITOR_HPP
#define VISITOR_VISITOR_HPP

#include <vector>
#include <functional>
#include <string>

class Visitor{
    public:
        //alle visiting functies
        //Root
        virtual void root(const std::vector< std::function<void ()>> visitDeclarations)=0;

        //Block
        virtual void block(const std::vector< std::function<void ()>> visitStatments)=0;

        //Declaration
        virtual void functionDeclaration(const std::string id, const std::function<void ()> visitSignature, const std::function<void ()> visitFunctionBody)=0;

        virtual void variableDeclaration(const std::vector<std::string> ids, const std::function<void ()> visitType, const std::vector < std::function<void ()>> visitExpressions)=0;


        //statments
        virtual void expressionStatment(const std::function<void ()> visitExperssion)=0;

        virtual void emptyStatment()=0;

        virtual void assignmentStatment(const std::vector< std::function<void ()>> visitLeftSide, const std::vector<  std::function<void ()>> visitRightSide)=0;

        virtual void forStatment(const std::function<void ()> visitInit,  const std::function<void ()> visitCondition, const std::function<void ()> visitPost, const std::function<void ()> visitBodyFor)=0;

        virtual void declarationStament(const std::function<void ()>visitDeclaration)=0;

        virtual void ifStatment(const std::function<void ()> visitCondition, const std::function<void ()> visitTrueCondition, const std::function<void ()> visitFalseCondition)=0;

        virtual void returnStatment(const std::vector<std::function<void ()>> visitExpressions)=0;


        //expresions
        virtual void identifierExperssion(const std::string id)=0;

        virtual void boolExperssion(const bool value)=0;

        virtual void intergerExperssion(const int value)=0;

        virtual void floatExperssion(const float value)=0;

        virtual void charExpression(const char value)=0;
        

        //virtual void identifierExperssion(const std::string id)=0;
        //Binary for alle operatie +, -, /, * const std::function<void ()> visitleft en const std::function<void ()>rightside (function)
        virtual void binaryAddExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryMinExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryMulExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryDivExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryEQExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryNEQExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryANDExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryORExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryGTExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryGEExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryLTExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        virtual void binaryLEExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) =0;

        //Unary Operations
        virtual void unaryNotExpression(const std::function<void ()> visitExpression) = 0;


        //types
        virtual void intType()=0;

        virtual void boolType()=0;

        virtual void floatType()=0;

        virtual void charType()=0;

        virtual void functionType(const std::vector<std::string> parametersName,const std::vector<std::function <void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function <void ()>> visitResultsType)=0;

        virtual void identifierType(const std::string id)=0;

        


    protected:
        Visitor() = default;
        virtual ~Visitor() = default;
};

#endif