    #include "Visitor/typechecker.hpp"
    #include <vector>
    #include <typeinfo>
    #include <iostream>
    #include <map>


    //add option for other print statments
    TypeChecker::TypeChecker(bool debug): errors{}, typeStack{}, typeTable{}, 
    currentFunctionType{}, functionSignatures{}, paramTypes{}, 
    returnTypes{}, debug{debug}, referncableStack{}{

        typeTable.set("printInt", new FunctionTypeDesc{{ std::make_pair("value", new IntTypeDesc{})} , {}});
        typeTable.set("printFloat", new FunctionTypeDesc{{ std::make_pair("value", new FloatTypeDesc{})} , {}});
        typeTable.set("printBool", new FunctionTypeDesc{{ std::make_pair("value", new BoolTypeDesc{})} , {}});

    }

    TypeChecker::~TypeChecker(){

    }

    //fucked
    void TypeChecker::root(const std::vector< std::function<void ()>> visitDeclarations){
        if(debug){
            std::cout<<"Root start: number of decla"<<visitDeclarations.size() <<"\n";
        }
        for(auto declartion: visitDeclarations){
            declartion();
        }
        if(!typeTable.contains("main")){
            errors.push("No main function found");
        }
        auto mainFunc = dynamic_cast<FunctionTypeDesc *>(typeTable.get("main"));
        if(mainFunc == nullptr){
            throw("casting problem typechecking");
        }

        if(mainFunc->getParametersIds().size() != 0 || mainFunc->getReturnsIds().size() != 0){
            errors.push("no input or output allow for main function");
        }


        for(int i = 0; i < functionSignatures.size(); i++){
            functionSignatures[i].second();
        }
        //daarna alle vector functie aan van de functies
        //check and find main
        //

    }

    void TypeChecker::block(const std::vector< std::function<void ()>> visitStatments){
        if(debug){
            std::cout<<"check block \n";
        }
        typeTable.newScope();
        //maybe set the function params?
        //unpacken van currentFunctionType en set typeTable setten? voor params en voor Return als id hebben
        //mag enkel als functie is
        //set params vector
        if(!paramTypes.empty()){
            for(auto param: paramTypes){
                typeTable.set(param.first, param.second);
            }
        }
        if(!returnTypes.empty()){
            for(auto returning: returnTypes){
                typeTable.set(returning.first, returning.second);
            }
        }

        paramTypes.clear();
        returnTypes.clear();
    
        
        for(auto stats: visitStatments){
            stats();
        }
        
        typeTable.removeScope();
    }
//not sure
    void TypeChecker::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {
        if(debug){
            std::cout<<"check function \n";
        }


        visitSignature();
        auto functionsign = typeStack.pop();
        typeTable.set(id, functionsign);
        //functionsing unpacken en die op typeTable setten
        //std::function
        //dat deel uistellen en in vector steken voor later op te roepen.
        //[functionSign]
        std::function<void ()>visitRest{[functionsign, visitFunctionBody, this](){
            currentFunctionType = dynamic_cast<FunctionTypeDesc *>(functionsign);
            if(currentFunctionType == nullptr){
                throw("fucked up hard, casting error");
            }
            paramTypes = this->currentFunctionType->getParams();
            returnTypes = this->currentFunctionType->getReturns();

            visitFunctionBody();
            
        }};

        functionSignatures.push_back(std::make_pair(id, visitRest));
        
    }

    //TODO: deal if type is not given?
    void TypeChecker::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {
        if(debug){
           std::cout<<"check var \n";
        }

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
            std::vector<TypeDescriptor *> tempTypes = {};
            for(int i = 0; i<ids.size(); i++){
                visitExpressions[i]();
                tempTypes.push_back(typeStack.pop());

                referncableStack.pop();

                // if(typeTable.contains(ids[i])){
                //     errors.push("Id already in use");
                // }
                // typeTable.set(ids[i], tempExpType);
            }
            for(int i = 0; i<ids.size(); i++){
                if(typeTable.contains(ids[i])){
                    errors.push("Id already in use");
                }
                typeTable.set(ids[i], tempTypes[i]);
            }

        }else{
            //type is given with declaration of var
            visitType();
            auto typeVar = typeStack.pop();
            for(auto expr: visitExpressions){
                expr();
                auto tempExpType = typeStack.pop();

                referncableStack.pop();

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
        if(debug){
            std::cout<<"check expre stat\n";
        }
        
        
        visitExperssion();
        //typeStack.pop();
    }

    void TypeChecker::emptyStatment() {
        if(debug){
            std::cout<<"empyt stat\n";
        }
    }

    //further
    void TypeChecker::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {
        if(debug){
            std::cout<<"assignstat stat\n";
        }
        if(visitLeftSide.size() != visitRightSide.size()){
            errors.push("Assignment but left and right side don't have same number of values");
            return;
        }

        std::vector<TypeDescriptor *> leftTypes {};
        std::vector<bool> leftReference {};
        //needs to be refernceable
        for(auto leftSide: visitLeftSide){
            leftSide();
            leftTypes.push_back(typeStack.pop());

            leftReference.push_back(referncableStack.pop());
        }

        std::vector<TypeDescriptor *> rightTypes {};
        for(auto rightSide: visitRightSide){
            rightSide();
            rightTypes.push_back(typeStack.pop());

            referncableStack.pop();
        }

        for(int i = 0; i < leftTypes.size(); i++){
            auto leftType = leftTypes[i];
            auto rightType = rightTypes[i];

            if(!leftReference[i]){
                errors.push("Left side of assignment need to be assignable");
            }

            if(!leftType->compare(*rightType)){
                errors.push("Right Side has not excpacted type for the assigment of left");
            }
        }


    }

    void TypeChecker::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {
        if(debug){
            std::cout<<"for stat\n";
        }
        visitInit();

        visitCondition();
        auto cond = dynamic_cast<BoolTypeDesc *>(typeStack.pop());
        referncableStack.pop();

        if(!cond->compare(BoolTypeDesc{})){
            errors.push("for stat, condition needs to be a bool type");
        }

        visitPost();

        visitBodyFor();


    }

    void TypeChecker::declarationStament(const std::function< void ()>visitDeclaration) {
        if(debug){
            std::cout<<"decl  stat\n";
        
        }
        visitDeclaration();
        //typeStack.pop();


    }

    //maybe do things with visitTrue and visitFalse
    void TypeChecker::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {
        if(debug){
            std::cout<<"if stat\n";
        }

        visitCondition();
        auto condType = typeStack.pop();

        if(!condType->compare(BoolTypeDesc{})){
            errors.push("Condition for if-stat must be Bool, but it ain't");
        }

        visitTrueCondition();

        visitFalseCondition();

    }


    //TODO: not working like wtf, ExpactedReturnType keeps empty
    void TypeChecker::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {
        if(debug){
            std::cout<<"return stat\n";
        }
            
        if(visitExpressions.size() != currentFunctionType->getReturnsTypeDesc().size()){
            errors.push("Return expression must match number of expected returns");
        }

        auto expactedTypes = currentFunctionType->getReturnsTypeDesc();

        for(int i = 0; i<visitExpressions.size(); i++){
            visitExpressions[i]();
            auto returnType = typeStack.pop();

            referncableStack.pop();

            if(!expactedTypes[i]->compare(* returnType)){
                errors.push("Return expr don't match expected type");
            }
        }

    }


    //expresions
    //true add
    void TypeChecker::identifierExperssion(const std::string id) {
        if(debug){
            std::cout<<"id expr\n";
        }

        auto tempType = typeTable.get(id);
        typeStack.push(tempType);

        referncableStack.push(true);
    }

    //false add
    void TypeChecker::boolExperssion(const bool value) {
        if(debug){
            std::cout<<"bool expr\n";
        }

        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);
    }

    void TypeChecker::intergerExperssion(const int value) {
        if(debug){
            std::cout<<"int expr\n";
        }

        typeStack.push(new IntTypeDesc{});

        referncableStack.push(false);
    }

    void TypeChecker::floatExperssion(const float value) {
        if(debug){
            std::cout<<"float expr\n";
        }

        typeStack.push(new FloatTypeDesc{});

        referncableStack.push(false);
    }

    void TypeChecker::charExpression(const char value) {
        if(debug){
            std::cout<<"char expr\n";
        }

        typeStack.push(new CharTypeDesc{});

        referncableStack.push(false);
    }

    //pop all arguments
    //push false equal amount of returns
    void TypeChecker::callExpression(const std::function<void ()> visitExpression, const std::vector<std::function<void ()>> visitArguments){
        if(debug){
            std::cout<<"Call expr \n";
        }

        visitExpression();
        auto exprType = typeStack.pop();
        //maybe do something with?
        std::vector<TypeDescriptor *> argTypes{};
        for(auto arg: visitArguments){
            arg();
            argTypes.push_back(typeStack.pop());

            //pop for refern
            referncableStack.pop();
        }

        FunctionTypeDesc *tempFunc {};

        if(!tempFunc->compareType(*exprType)){
            errors.push("Call needs to be to a function");
        }

        auto funcType = dynamic_cast<FunctionTypeDesc *>(exprType);

        auto paramType = funcType->getParametersTypeDesc();

        if(paramType.size() != argTypes.size()){
            errors.push("No same amount of params as arguments for function");
        }

        for(int i = 0; i<paramType.size(); i++){
            if(!paramType[i]->compare(*argTypes[i])){
                errors.push("Argument Type did not match expacted paramtype for function");
            }
        }

        auto returnType = funcType->getReturnsTypeDesc();
        for(auto ret: returnType){
            typeStack.push(ret);

            referncableStack.push(false);
        }
    }


    // void Visiting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    //pop 2 and add 1 
    void TypeChecker::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary Add expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();

        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

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
        
        referncableStack.push(false);
    }


    void TypeChecker::binaryMinExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary Add expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();

        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

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
        
        referncableStack.push(false);
    }

    void TypeChecker::binaryMulExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryDivExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {

    }

    void TypeChecker::binaryEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary EQ expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();
        
        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{}) && !leftSide->compare(BoolTypeDesc{}) && !leftSide->compare(CharTypeDesc{})){    
            errors.push("wrong type for leftSide, only int, float or bool allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{}) && ! rightSide->compare(BoolTypeDesc{}) && !leftSide->compare(CharTypeDesc{})){
            errors.push("wrong type for rightSide, only int, float or bool allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);
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

    //<=
    void TypeChecker::binaryLEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"lesser or equal expr \n";
        }

        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();
        
        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{}) ){    
            errors.push("wrong type for leftSide, only int, float");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{}) ){
            errors.push("wrong type for rightSide, only int, float ");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't compare the different types");
        }
        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);
    }

    //Unary Operations
    void TypeChecker::unaryNotExpression(const std::function< void ()> visitExpression) {
        if(debug){
            std::cout<<"unary not \n";
        }
        visitExpression();
        TypeDescriptor * expr=typeStack.pop();
        referncableStack.pop();

        if(!expr->compare(BoolTypeDesc{})){
            errors.push("Wrong type not expr, needs to be bool");
        }

        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);

    }


    //types
    void TypeChecker::intType() {
        if(debug){
            std::cout<<"int type check\n";
        }

        typeStack.push(new IntTypeDesc{});
    }

    void TypeChecker::boolType() {
        if(debug){
            std::cout<<"bool type check\n";
        }

        typeStack.push(new BoolTypeDesc{});
    }

    void TypeChecker::floatType() {
        if(debug){
            std::cout<<"float type check\n";
        }


        typeStack.push(new FloatTypeDesc{});
    }

    void TypeChecker::charType() {
        if(debug){
            std::cout<<"char type check\n";
        }

        typeStack.push(new CharTypeDesc{});
    }

    void TypeChecker::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {
        if(debug){
            std::cout<<"function type \n";
        }

        if(checkDuplicateStrings(parametersName)){
            errors.push("Cant use same name for different params");
        }
        if(checkDuplicateStrings(resultsName)){
            errors.push("Cant use same name for different returns");
        }

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

        FunctionTypeDesc *funcTypeDesc = new FunctionTypeDesc(parameter, returns);
        typeStack.push(funcTypeDesc);

    }

    void TypeChecker::identifierType(const std::string id) {
        if(debug){
            std::cout<<"identiefier type check";
        }
        
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

bool TypeChecker::checkDuplicateStrings(std::vector<std::string> listString){
    std::map<std::string, int> countMap = {};

    for(auto elem: listString){
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if(result.second ==false){
            result.first->second++;
        }
    }
    for(auto elem: countMap){
        if(elem.second >1){
            return true;
        }
    }
    return false;
}