    #include "Visitor/visiting.hpp"
    #include <vector>

    Visiting::Visiting(){

    }

    Visiting::~Visiting(){

    }

    void Visiting::root(const std::vector< std::function<void ()>> visitDeclarations){

    }

    void Visiting::block(const std::vector< std::function<void ()>> visitStatments){

    }

    void Visiting::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {

    }

    void Visiting::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {

    }


    //statments
    void Visiting::expressionStatment(const std::function< void ()> visitExperssion) {

    }

    void Visiting::emptyStatment() {

    }

    void Visiting::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {

    }

    void Visiting::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {

    }

    void Visiting::declarationStament(const std::function< void ()>visitDeclaration) {

    }

    void Visiting::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {

    }

    void Visiting::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {

    }


    //expresions
    void Visiting::identifierExperssion(const std::string id) {

    }

    void Visiting::boolExperssion(const bool value) {

    }

    void Visiting::intergerExperssion(const int value) {

    }

    void Visiting::floatExperssion(const float value) {

    }

    void Visiting::charExpression(const char value) {

    }


    // void Visiting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    void Visiting::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryMinExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryMulExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryDivExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryNEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryANDExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryORExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryGTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryGEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryLTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void Visiting::binaryLEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    //Unary Operations
    void Visiting::unaryNotExpression(const std::function< void ()> visitExpression) {

    }


    //types
    void Visiting::intType() {

    }

    void Visiting::boolType() {

    }

    void Visiting::floatType() {

    }

    void Visiting::charType() {

    }

    void Visiting::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {

    }

    void Visiting::identifierType(const std::string id) {
        
    }
