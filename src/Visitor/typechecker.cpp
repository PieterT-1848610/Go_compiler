    #include "Visitor/typechecker.hpp"
    #include <vector>

    TypeChecker::TypeChecker(){

    }

    TypeChecker::~TypeChecker(){

    }

    void TypeChecker::root(const std::vector< std::function<void ()>> visitDeclarations){

    }

    void TypeChecker::block(const std::vector< std::function<void ()>> visitStatments){

    }

    void TypeChecker::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {

    }

    void TypeChecker::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {

    }


    //statments
    void TypeChecker::expressionStatment(const std::function< void ()> visitExperssion) {

    }

    void TypeChecker::emptyStatment() {

    }

    void TypeChecker::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {

    }

    void TypeChecker::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {

    }

    void TypeChecker::declarationStament(const std::function< void ()>visitDeclaration) {

    }

    void TypeChecker::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {

    }

    void TypeChecker::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {

    }


    //expresions
    void TypeChecker::identifierExperssion(const std::string id) {

    }

    void TypeChecker::boolExperssion(const bool value) {

    }

    void TypeChecker::intergerExperssion(const int value) {

    }

    void TypeChecker::floatExperssion(const float value) {

    }

    void TypeChecker::charExpression(const char value) {

    }


    // void Visiting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    void TypeChecker::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryMinExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryMulExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryDivExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryNEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryANDExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryORExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryGTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryGEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryLTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryLEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    //Unary Operations
    void TypeChecker::unaryNotExpression(const std::function< void ()> visitExpression) {

    }


    //types
    void TypeChecker::intType() {

    }

    void TypeChecker::boolType() {

    }

    void TypeChecker::floatType() {

    }

    void TypeChecker::charType() {

    }

    void TypeChecker::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {

    }

    void TypeChecker::identifierType(const std::string id) {
        
    }
