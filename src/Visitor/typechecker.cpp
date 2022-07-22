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
        expactedReturnType = functionsign;
        visitFunctionBody();

    }

    void TypeChecker::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {
        std::cout<<"little chekc var \n";
        visitType();
        auto typeVar = typeStack.pop();
        for(auto expr: visitExpressions){
            expr();
            auto tempExpType = typeStack.pop();
            if(typeVar->compare(*tempExpType)){
                errors.push("Expression type not same as giving type for Var");
            }
        }
        for(auto id: ids){
            if(typeTable.contains(id)){
                errors.push("Id already in use");
            }
            typeTable.set(id, typeVar);

        }

    }


    //statments
    void TypeChecker::expressionStatment(const std::function< void ()> visitExperssion) {
        std::cout<<"check expre stat\n";
        visitExperssion();
        typeStack.pop();
    }

    void TypeChecker::emptyStatment() {
        std::cout<<"empyt stat\n";
    }

    //further
    void TypeChecker::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {
        std::cout<<"assignstat stat\n";

        for(auto leftSide: visitLeftSide){
            leftSide();
        }

        for(auto rightSide: visitRightSide){
            rightSide();
        }


    }

    void TypeChecker::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {
        std::cout<<"for stat\n";



    }

    void TypeChecker::declarationStament(const std::function< void ()>visitDeclaration) {
        std::cout<<"decl  stat\n";
        
        visitDeclaration();
        //typeStack.pop();


    }

    void TypeChecker::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {
        std::cout<<"if stat\n";

    }

    void TypeChecker::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {
        std::cout<<"return stat\n";
        
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
        std::cout<<"id expr\n";

    }

    void TypeChecker::boolExperssion(const bool value) {
        std::cout<<"bool expr\n";

        BoolTypeDesc* boolTypeDesc = {};
        typeStack.push(boolTypeDesc);
        int a = 3;
        a = 5;
    }

    void TypeChecker::intergerExperssion(const int value) {
        std::cout<<"int expr\n";

        IntTypeDesc *intTypeDesc = {};
        typeStack.push(intTypeDesc);
    }

    void TypeChecker::floatExperssion(const float value) {
        std::cout<<"float expr\n";

        FloatTypeDesc *floatTypeDesc = {};
        typeStack.push(floatTypeDesc);
    }

    void TypeChecker::charExpression(const char value) {
        std::cout<<"char expr\n";

        CharTypeDesc *charTypeDesc = {};
        typeStack.push(charTypeDesc);
    }


    // void Visiting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    void TypeChecker::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        std::cout<<"binary Add expre \n";
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

        if(leftSide->compare(*rightSide)){
            errors.push("can't add the differnt types");
        }
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
        std::cout<<"int type check\n";

        IntTypeDesc* intTypedesc = {};
        typeStack.push(intTypedesc);
    }

    void TypeChecker::boolType() {
        std::cout<<"bool type check\n";

        BoolTypeDesc* boolTypedesc = {};
        typeStack.push(boolTypedesc);
    }

    void TypeChecker::floatType() {
        std::cout<<"float type check\n";

        FloatTypeDesc* floatTypedesc = {};
        typeStack.push(floatTypedesc);
    }

    void TypeChecker::charType() {
        std::cout<<"char type check\n";

        CharTypeDesc* charTypedesc = {};
        typeStack.push(charTypedesc);
    }

    void TypeChecker::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {
        std::cout<<"function type \n";
        std::vector<std::pair<std::string, TypeDescriptor *>> parameter = {};

        for(int i = 0; i < visitParametersType.size(); i++){
            visitParametersType[i]();
            auto tempType = typeStack.pop();
            parameter.push_back(std::make_pair(parametersName[i], tempType));
        }

        std::vector<std::pair<std::string, TypeDescriptor *>> returns = {};

        for(int i = 0; i < visitResultsType.size(); i++){
            visitResultsType[i]();
            auto tempType = typeStack.pop();
            returns.push_back(std::make_pair(resultsName[i], tempType));
        }

        FunctionTypeDesc funcTypeDesc = FunctionTypeDesc(parameter, returns);
        typeStack.push(&funcTypeDesc);

    }

    void TypeChecker::identifierType(const std::string id) {
        std::cout<<"identiefier type check";
        
    }


std::vector<std::string> TypeChecker::getErrors(){
    std::vector<std::string> errorlist = {};

    while(!errors.empty()){
        errorlist.push_back(errors.pop());
    }

    return errorlist;
    
}