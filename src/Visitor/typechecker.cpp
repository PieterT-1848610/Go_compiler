    #include "Visitor/typechecker.hpp"
    #include <vector>
    #include <typeinfo>
    #include <iostream>

    TypeChecker::TypeChecker(): errors{}, typeStack{}, typeTable{}, expactedReturnType{}{

    }

    TypeChecker::~TypeChecker(){

    }

    void TypeChecker::root(const std::vector< std::function<void ()>> visitDeclarations){
        std::cout<<visitDeclarations.size()<<"\n";
        for(auto declartion: visitDeclarations){
            declartion();
            std::cout<<"reee\n";
        }
        //check and find main
        //

    }

    void TypeChecker::block(const std::vector< std::function<void ()>> visitStatments){
        std::cout<<"little check block \n";
        typeTable.newScope();
        for(auto stats: visitStatments){
            stats();
        }

        typeTable.removeScope();
    }
//not sure
    void TypeChecker::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {
        std::cout<<"little chekc function \n";

        visitSignature();
        auto functionsign = typeStack.pop();
        typeTable.set(id, functionsign);

    }

    void TypeChecker::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {
        std::cout<<"little chekc var \n";


    }


    //statments
    void TypeChecker::expressionStatment(const std::function< void ()> visitExperssion) {
        visitExperssion();
        typeStack.pop();
    }

    void TypeChecker::emptyStatment() {

    }

    void TypeChecker::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {

    }

    void TypeChecker::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {

    }

    void TypeChecker::declarationStament(const std::function< void ()>visitDeclaration) {
        visitDeclaration();


    }

    void TypeChecker::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {

    }

    void TypeChecker::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {
        for(auto expression: visitExpressions){
            expression();
        }

        auto returnType = typeStack.pop();
        if(returnType == expactedReturnType){
            errors.push("return Types don't match");
        }
    }


    //expresions
    void TypeChecker::identifierExperssion(const std::string id) {

    }

    void TypeChecker::boolExperssion(const bool value) {
        BoolTypeDesc * boolTypeDesc = {};
        typeStack.push(boolTypeDesc);
    }

    void TypeChecker::intergerExperssion(const int value) {
        IntTypeDesc *intTypeDesc = {};
        typeStack.push(intTypeDesc);
    }

    void TypeChecker::floatExperssion(const float value) {
        FloatTypeDesc *floatTypeDesc = {};
        typeStack.push(floatTypeDesc);
    }

    void TypeChecker::charExpression(const char value) {
        CharTypeDesc *charTypeDesc = {};
        typeStack.push(charTypeDesc);
    }


    // void Visiting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    void TypeChecker::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();

        if(typeid(leftSide)!=typeid(IntTypeDesc) && typeid(leftSide)!= typeid(FloatTypeDesc) && typeid(leftSide)!= typeid(BoolTypeDesc)){
            errors.push("wrong type, only int, float and bool allowed");
            std::cout<<"type not right, leftside (add)";
        }
        if(typeid(rightSide)!=typeid(IntTypeDesc) && typeid(rightSide)!= typeid(FloatTypeDesc) && typeid(rightSide)!= typeid(BoolTypeDesc)){
            errors.push("wrong type, only int, float and bool allowed");
            std::cout<<"type not right, rightside (add)";
        }

        if(leftSide->compare(rightSide)){
            errors.push("can't add the differnt types");
        }
        std::cout<<"hello binary add";
        typeStack.push(leftSide);
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
        IntTypeDesc* intTypedesc = {};
        typeStack.push(intTypedesc);
    }

    void TypeChecker::boolType() {
        BoolTypeDesc* boolTypedesc = {};
        typeStack.push(boolTypedesc);
    }

    void TypeChecker::floatType() {
        FloatTypeDesc* floatTypedesc = {};
        typeStack.push(floatTypedesc);
    }

    void TypeChecker::charType() {
        CharTypeDesc* charTypedesc = {};
        typeStack.push(charTypedesc);
    }

    void TypeChecker::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {
        std::cout<<"contorlin";
    }

    void TypeChecker::identifierType(const std::string id) {
        
    }
