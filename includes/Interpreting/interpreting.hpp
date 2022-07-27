#ifndef INTERPRETING_INTERPRETING_HPP
#define INTERPRETING_INTERPRETING_HPP


#include <vector>
#include <string>
#include <functional>
#include "other/stack.hpp"
#include "valuedescriptor.hpp"
#include "Visitor/Visitor.hpp"
#include "other/symboltable.hpp"

class Interpreting: public Visitor{
    public:
        Interpreting();
        ~Interpreting();
    
        void root(const std::vector< std::function<void ()>> visitDeclarations) override;

        //Block
        void block(const std::vector< std::function<void ()>> visitStatments) override;

        //Declaration
        void functionDeclaration(const std::string id, const std::function<void ()> visitSignature, const std::function<void ()> visitFunctionBody) override;   //add to funcTable
        

        void variableDeclaration(const std::vector<std::string> ids, const std::function<void ()> visitType, const std::vector < std::function<void ()>> visitExpressions) override; 

        //statments
        void expressionStatment(const std::function<void ()> visitExperssion) override; 

        void emptyStatment() override;  

        void assignmentStatment(const std::vector< std::function<void ()>> visitLeftSide, const std::vector<  std::function<void ()>> visitRightSide) override;     //for visit left, and visit right

        void forStatment(const std::function<void ()> visitInit,  const std::function<void ()> visitCondition, const std::function<void ()> visitPost, const std::function<void ()> visitBodyFor) override;

        void declarationStament(const std::function<void ()>visitDeclaration) override;

        void ifStatment(const std::function<void ()> visitCondition, const std::function<void ()> visitTrueCondition, const std::function<void ()> visitFalseCondition) override;

        void returnStatment(const std::vector<std::function<void ()>> visitExpressions) override;   


        //expresions
        void identifierExperssion(const std::string id) override; //varsymbooltable 

        void boolExperssion(const bool value) override;

        void intergerExperssion(const int value) override;
 
        void floatExperssion(const float value) override;

        void charExpression(const char value) override;

        void callExpression(const std::function<void ()> visitExpression, const std::vector<std::function<void ()>> visitArguments) override;

        

        //Binary for alle operatie +, -, /, * const std::function<void ()> visitleft en const std::function<void ()>rightside (function)
        void binaryAddExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;     
                                                                                                                                        

        void binaryMinExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryMulExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryDivExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryEQExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryNEQExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryANDExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryORExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryGTExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryGEExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryLTExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        void binaryLEExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;

        //Unary Operations
        void unaryNotExpression(const std::function<void ()> visitExpression) override;


        //types
        void intType() override;    

        void boolType() override;

        void floatType() override;

        void charType() override;

        void functionType(const std::vector<std::string> parametersName,const std::vector<std::function <void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function <void ()>> visitResultsType) override;


        void identifierType(const std::string id) override;

    private:

        Stack<ValueDescriptor *> valueStack;

        
        SymbolTable<ValueDescriptor *> valueTable;

        std::vector<std::pair<std::string, ValueDescriptor *>> paramValues;
        

        std::vector<std::string> paramNames;
        //mapping van function op naam
        //std::vector<std::pair<std::string, std::function <void ()> >> functionSignature;

};

#endif