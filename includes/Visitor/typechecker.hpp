#ifndef VISITING_VISITING_HPP
#define VISITING_VISITING_HPP

#include <vector>
#include <string>
#include <functional>
#include "other/stack.hpp"
#include "Visitor/typedescriptor.hpp"
#include "Visitor.hpp"
#include "other/symboltable.hpp"


class TypeChecker: public Visitor{
    public:
        TypeChecker(bool debug = false);
        ~TypeChecker();
    
        void root(const std::vector< std::function<void ()>> visitDeclarations) override;

        //Block
        void block(const std::vector< std::function<void ()>> visitStatments) override;

        //Declaration
        void functionDeclaration(const std::string id, const std::function<void ()> visitSignature, const std::function<void ()> visitFunctionBody) override;   //add to funcTable
        //visitSign, gaat para en return visit komen op stack
        //assign functypdesc to id and push to functionTable
        //set ExpactedReturnType
        //visitFunctionBody




        void variableDeclaration(const std::vector<std::string> ids, const std::function<void ()> visitType, const std::vector < std::function<void ()>> visitExpressions) override; 
        //vistType and pop
        //visit all Expr
        //compare with type
        //check if id already exists
        //add to varTable (ids, and type) 

        void packageDeclaration(const std::string packageName) override;


        //statments
        void expressionStatment(const std::function<void ()> visitExperssion) override; //hint pop last type

        void emptyStatment() override;  

        void assignmentStatment(const std::vector< std::function<void ()>> visitLeftSide, const std::vector<  std::function<void ()>> visitRightSide) override;     //for visit left, and visit right

        void incrStatment(const std::function<void ()> visitExpression) override;

        void decrStatment(const std::function<void ()> visitExpression) override;

        void forStatment(const std::function<void ()> visitInit,  const std::function<void ()> visitCondition, const std::function<void ()> visitPost, const std::function<void ()> visitBodyFor) override;

        void declarationStament(const std::function<void ()>visitDeclaration) override;

        void ifStatment(const std::function<void ()> visitCondition, const std::function<void ()> visitTrueCondition, const std::function<void ()> visitFalseCondition) override;

        void returnStatment(const std::vector<std::function<void ()>> visitExpressions) override;   //pop type and compare to expactedreturntype



        void decrAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression) override;

        void incrAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression) override;

        void mulAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression) override;

        void divAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression) override;


        //expresions
        void identifierExperssion(const std::string id) override; //varsymbooltable 

        void boolExperssion(const bool value) override;

        void intergerExperssion(const int value) override;
 
        void floatExperssion(const float value) override;

        void charExpression(const char value) override;

        void callExpression(const std::function<void ()> visitExpression, const std::vector<std::function<void ()>> visitArguments) override;
        

        void binaryAddExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;     //visitleftside() (for visiting side)
                                                                                                                                        //pop 
                                                                                                                                        //visitright
                                                                                                                                        //pop
                                                                                                                                        //check if types are allowed
                                                                                                                                        //left and right
                                                                                                                                        //compare the types
                                                                                                                                        //push type of leftside on stack
                                                                                                                                        

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

        void binaryModExpression(const std::function<void ()> visitLeftSide, const std::function<void ()> visitRightSide) override;


        //Unary Operations
        void unaryNotExpression(const std::function<void ()> visitExpression) override;

        void unaryPosExpression(const std::function<void ()> visitExpression) override;

        void unaryNegExpression(const std::function<void ()> visitExpression) override;


        //types
        void intType() override;    //wordt op de typeStack gegooit

        void boolType() override;

        void floatType() override;

        void charType() override;

        void functionType(const std::vector<std::string> parametersName,const std::vector<std::function <void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function <void ()>> visitResultsType) override;
            //visit and make functiondesc

        void identifierType(const std::string id) override;

        std::vector<std::string> getErrors();

        bool emptyErrors();

        bool checkDuplicateStrings(std::vector<std::string> listString);

    private:
        Stack<std::string> errors;

        Stack<TypeDescriptor*> typeStack;

        //symboltable func and symboltable var;
        SymbolTable<TypeDescriptor*> typeTable;
        
        //gets functionDescriptor to compare the return types
        FunctionTypeDesc * currentFunctionType;

        //eerste enkle sign, daarna function bezit body en de rest
        std::vector<std::pair<std::string, std::function <void ()> >> functionSignatures;

        std::vector<std::pair<std::string, TypeDescriptor*>> paramTypes;
        std::vector<std::pair<std::string, TypeDescriptor*>> returnTypes;

        bool debug;

        Stack<bool> referncableStack;

        bool packageMain;

};

#endif
