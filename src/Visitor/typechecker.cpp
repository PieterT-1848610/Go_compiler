    #include "Visitor/typechecker.hpp"
    #include <vector>
    #include <typeinfo>
    #include <iostream>

    TypeChecker::TypeChecker(): errors{}, typeStack{}, typeTable{}, expactedReturnType{}{

    }

    TypeChecker::~TypeChecker(){

    }

    //fucked
    void TypeChecker::root(const std::vector< std::function<void ()>> visitDeclarations){
        std::cout<<"Root start: number of decla"<<visitDeclarations.size() <<"\n";
        for(auto declartion: visitDeclarations){
            declartion();
            std::cout<<"\n\n\n";
        }
        //check and find main
        //

    }

    void TypeChecker::block(const std::vector< std::function<void ()>> visitStatments){
        std::cout<<"check block \n";
        typeTable.newScope();
        for(auto stats: visitStatments){
            stats();
        }

        typeTable.removeScope();
    }
//not sure
    void TypeChecker::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {
        std::cout<<"check function \n";

        visitSignature();
        auto functionsign = typeStack.pop();
        typeTable.set(id, functionsign);
        expactedReturnType = functionsign;
        visitFunctionBody();

    }

    //TODO: deal if type is not given?
    void TypeChecker::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {
        std::cout<<"check var \n";

        if(ids.size() != visitExpressions.size()){
                errors.push("Var declaration: number of ids, not match number of expressions");
                return;
            }

        //type is not given with decalartion of var
        if(visitType == NULL){
            if(visitExpressions.size() <= 0){
                errors.push("Not allowed to create var this way");
                return;
            }
            for(int i = 0; i<ids.size(); i++){
                visitExpressions[i]();
                auto tempExpType = typeStack.pop();
                if(typeTable.contains(ids[i])){
                    errors.push("Id already in use");
                }
                typeTable.set(ids[i], tempExpType);
            }

        }else{
            //type is given with declaration of var
            visitType();
            auto typeVar = typeStack.pop();
            for(auto expr: visitExpressions){
                expr();
                auto tempExpType = typeStack.pop();
                if(!(typeVar->compare(*tempExpType))){
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

        auto tempType = typeTable.get(id);

        typeStack.push(tempType);

    }

    void TypeChecker::boolExperssion(const bool value) {
        std::cout<<"bool expr\n";

        typeStack.push(new BoolTypeDesc{});

    }

    void TypeChecker::intergerExperssion(const int value) {
        std::cout<<"int expr\n";

        typeStack.push(new IntTypeDesc{});
    }

    void TypeChecker::floatExperssion(const float value) {
        std::cout<<"float expr\n";

        typeStack.push(new FloatTypeDesc{});
    }

    void TypeChecker::charExpression(const char value) {
        std::cout<<"char expr\n";

        typeStack.push(new CharTypeDesc{});
    }


    // void Visiting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    void TypeChecker::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        std::cout<<"binary Add expre \n";
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{}) && !leftSide->compare(BoolTypeDesc{})){    
            errors.push("wrong type for leftSide, only int, float or bool allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{}) && ! rightSide->compare(BoolTypeDesc{})){
            errors.push("wrong type for rightSide, only int, float or bool allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
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

       typeStack.push(new IntTypeDesc{});
    }

    void TypeChecker::boolType() {
        std::cout<<"bool type check\n";

        typeStack.push(new BoolTypeDesc{});
    }

    void TypeChecker::floatType() {
        std::cout<<"float type check\n";

        typeStack.push(new FloatTypeDesc{});
    }

    void TypeChecker::charType() {
        std::cout<<"char type check\n";

        typeStack.push(new CharTypeDesc{});
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

bool TypeChecker::emptyErrors(){
    return errors.empty();
}