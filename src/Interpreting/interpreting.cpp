#include "Interpreting/interpreting.hpp"

    Interpreting::Interpreting():valueStack{}, valueTable{}, functionSignature{}{

    }

    Interpreting::~Interpreting(){

    }

    void Interpreting::root(const std::vector< std::function< void ()>> visitDeclarations) {
        //visit all functions and make the signatures
        for(auto declaration: visitDeclarations){
            declaration();
        }

        //find main function
        auto mainFunc = dynamic_cast<FunctionValue *> (valueTable.get("main")->getDescri());
        if(mainFunc == nullptr){
            throw("casting problem interpriting");
        }

        //mainFunc->execute();

    }

    //Block
    void Interpreting::block(const std::vector< std::function< void ()>> visitStatments) {}

    //Declaration
    void Interpreting::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {
        
        visitSignature();
    }

    void Interpreting::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {}


    //statments
    void Interpreting::expressionStatment(const std::function< void ()> visitExperssion) {}

    void Interpreting::emptyStatment() {}

    void Interpreting::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {}

    void Interpreting::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {}

    void Interpreting::declarationStament(const std::function< void ()>visitDeclaration) {}

    void Interpreting::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {}

    void Interpreting::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {}


    //expresions
    void Interpreting::identifierExperssion(const std::string id) {}

    void Interpreting::boolExperssion(const bool value) {
        valueStack.push(new BoolValue(value));
    }

    void Interpreting::intergerExperssion(const int value) {
        valueStack.push(new IntValue(value));
    }

    void Interpreting::floatExperssion(const float value) {
        valueStack.push(new FloatValue(value));
    }

    void Interpreting::charExpression(const char value) {
        valueStack.push(new CharValue(value));
    }


    // void Interpreting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    void Interpreting::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryMinExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryMulExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryDivExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryNEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryANDExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryORExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryGTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryGEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryLTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    void Interpreting::binaryLEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {}

    //Unary Operations
    void Interpreting::unaryNotExpression(const std::function< void ()> visitExpression) {}


    //types
    //no need ?
    void Interpreting::intType() {}

    void Interpreting::boolType() {}

    void Interpreting::floatType() {}

    void Interpreting::charType() {}

    //no clue yet
    void Interpreting::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {}

    void Interpreting::identifierType(const std::string id) {}

