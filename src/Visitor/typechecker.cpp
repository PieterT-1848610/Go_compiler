    #include "Visitor/typechecker.hpp"
    #include <vector>
    #include <typeinfo>
    #include <iostream>
    #include <map>


    //add option for other print statments
    TypeChecker::TypeChecker(bool debug): errors{}, typeStack{}, typeTable{}, 
    currentFunctionType{}, functionSignatures{}, paramTypes{}, 
    returnTypes{}, debug{debug}, referncableStack{}, packageMain{false}{

        typeTable.set("printInt", new FunctionTypeDesc{{ std::make_pair("value", new IntTypeDesc{})} , {}});
        typeTable.set("printFloat", new FunctionTypeDesc{{ std::make_pair("value", new FloatTypeDesc{})} , {}});
        typeTable.set("printBool", new FunctionTypeDesc{{ std::make_pair("value", new BoolTypeDesc{})} , {}});

    }

    TypeChecker::~TypeChecker(){

    }

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
        if(!packageMain){
            errors.push("No main package found");
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


    void TypeChecker::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {
        if(debug){
            std::cout<<"check function \n";
        }


        visitSignature();
        auto functionsign = typeStack.pop();
        typeTable.set(id, functionsign);
        
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


    void TypeChecker::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {
        if(debug){
           std::cout<<"check var \n";
        }

        //type is not given with decalartion of var
        if(visitType == NULL){
            if(visitExpressions.size() <= 0){
                errors.push("Not allowed to create var this way");
                return;
            }
            std::vector<TypeDescriptor *> tempTypes = {};
            for(int i = 0; i<visitExpressions.size(); i++){
                visitExpressions[i]();
                auto tempExpType = typeStack.pop();

                // referncableStack.pop();
                if(tempExpType->compare(ManyTypeDesc({}))){
                    std::vector<TypeDescriptor *> manyTypes = dynamic_cast<ManyTypeDesc *>(tempExpType)->getTypes();
                    for(auto types: manyTypes){
                        tempTypes.push_back(types);
                        referncableStack.pop();
                    }
                }else{
                    tempTypes.push_back(tempExpType);
                    referncableStack.pop();
                }
            }
            if(ids.size() != tempTypes.size()){
                errors.push("Not same amount of var and expression values");
                return;
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

                if(tempExpType->compare(ManyTypeDesc({}))){
                    std::vector<TypeDescriptor *> manyTypes = dynamic_cast<ManyTypeDesc *>(tempExpType)->getTypes();
                    for(auto types: manyTypes){
                        if(!(typeVar->compare(*types))){
                            errors.push("Expression type not same as giving type for var");
                        }
                        referncableStack.pop();
                    }
                }else{
                    if(!(typeVar->compare(*tempExpType))){
                        errors.push("Expression type not same as giving type for Var");
                    }
                    referncableStack.pop();
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



    void TypeChecker::packageDeclaration(const std::string packageName){
        if(debug){
            std::cout<<"check package\n";
        }
        if(packageMain){
            errors.push("Only support main package");
        }
        if(packageName != "main"){
            errors.push("wrong package name");
        }else{
            packageMain = true;
        }
    }

    //statments
    void TypeChecker::expressionStatment(const std::function< void ()> visitExperssion) {
        if(debug){
            std::cout<<"check expre stat\n";
        }
        
        visitExperssion();
    }

    void TypeChecker::emptyStatment() {
        if(debug){
            std::cout<<"empyt stat\n";
        }
    }

    void TypeChecker::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {
        if(debug){
            std::cout<<"assignstat stat\n";
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
            auto tempType = typeStack.pop();

            if(tempType->compare(ManyTypeDesc({}))){
                std::vector<TypeDescriptor *> manyTypes = dynamic_cast<ManyTypeDesc *>(tempType)->getTypes();
                for(auto types: manyTypes){
                    rightTypes.push_back(types);
                    referncableStack.pop();
                }

            }else{
                rightTypes.push_back(tempType);
                referncableStack.pop();
            }
        }
        if(leftTypes.size() != rightTypes.size()){
            errors.push("Assignment but left and right side don't have same number of values");
            return;
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

    void TypeChecker::incrStatment(const std::function<void ()> visitExpression){
        if(debug){
            std::cout<<"incr stat \n";
        }

        visitExpression();
        auto temp = typeStack.pop();
        auto referncheck = referncableStack.pop();
        if(!referncheck){
            errors.push("Incr statment, value still needs to be referenceable");
        }

        if(!temp->compare(IntTypeDesc{}) && !temp->compare(FloatTypeDesc{})){    
            errors.push("wrong type for increseas, only int or float allowed");
        }
        referncableStack.push(false);

    }

    void TypeChecker::decrStatment(const std::function<void ()> visitExpression){
        if(debug){
            std::cout<<"decr stat \n";
        }

        visitExpression();
        auto temp = typeStack.pop();
        auto referncheck = referncableStack.pop();
        if(!referncheck){
            errors.push("Decr statment, value still needs to be referenceable");
        }

        if(!temp->compare(IntTypeDesc{}) && !temp->compare(FloatTypeDesc{})){    
            errors.push("wrong type for decrease, only int or float allowed");
        }
        referncableStack.push(false);

    }

    void TypeChecker::decrAssignStatment(const std::function<void ()>visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"decr assign stat\n";
        }
        //leftSide
        visitLeftExpression();
        auto leftType = typeStack.pop();
        auto referncheck = referncableStack.pop();
        if(!referncheck){
            errors.push("Decr Assign stat, value needs to be referenceable");
        }

        if(!leftType->compare(IntTypeDesc{}) && !leftType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        //rightSide 
        visitRightExpression();
        auto rightType = typeStack.pop();
        referncableStack.pop();
        
        if(!rightType->compare(IntTypeDesc{}) && !rightType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        if(!leftType->compare(* rightType)){
            errors.push("Left side of assing is differnt from right");
        }

        referncableStack.push(false);
    }

void TypeChecker::incrAssignStatment(const std::function<void ()>visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"incr assign stat\n";
        }
        //leftSide
        visitLeftExpression();
        auto leftType = typeStack.pop();
        auto referncheck = referncableStack.pop();
        if(!referncheck){
            errors.push("Decr Assign stat, value needs to be referenceable");
        }

        if(!leftType->compare(IntTypeDesc{}) && !leftType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        //rightSide 
        visitRightExpression();
        auto rightType = typeStack.pop();
        referncableStack.pop();
        
        if(!rightType->compare(IntTypeDesc{}) && !rightType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        if(!leftType->compare(* rightType)){
            errors.push("Left side of assing is differnt from right");
        }

        referncableStack.push(false);
    }

    void TypeChecker::mulAssignStatment(const std::function<void ()>visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"mul assign stat\n";
        }
        //leftSide
        visitLeftExpression();
        auto leftType = typeStack.pop();
        auto referncheck = referncableStack.pop();
        if(!referncheck){
            errors.push("Decr Assign stat, value needs to be referenceable");
        }

        if(!leftType->compare(IntTypeDesc{}) && !leftType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        //rightSide 
        visitRightExpression();
        auto rightType = typeStack.pop();
        referncableStack.pop();
        
        if(!rightType->compare(IntTypeDesc{}) && !rightType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        if(!leftType->compare(* rightType)){
            errors.push("Left side of assing is differnt from right");
        }

        referncableStack.push(false);
    }

    void TypeChecker::divAssignStatment(const std::function<void ()>visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"div assign stat\n";
        }
        //leftSide
        visitLeftExpression();
        auto leftType = typeStack.pop();
        auto referncheck = referncableStack.pop();
        if(!referncheck){
            errors.push("Decr Assign stat, value needs to be referenceable");
        }

        if(!leftType->compare(IntTypeDesc{}) && !leftType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        //rightSide 
        visitRightExpression();
        auto rightType = typeStack.pop();
        referncableStack.pop();
        
        if(!rightType->compare(IntTypeDesc{}) && !rightType->compare(FloatTypeDesc{})){
            errors.push("Wrong type for decr assign stat, only int or float allowed");
        }

        if(!leftType->compare(* rightType)){
            errors.push("Left side of assing is differnt from right");
        }

        referncableStack.push(false);
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

    }


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
                    std::cout<<"return type"<<returnType->toString()<<"\n";
                    errors.push("Return expr don't match expected type");
                }
            //}
        }
        
    }


    //expresions
    void TypeChecker::identifierExperssion(const std::string id) {
        if(debug){
            std::cout<<"id expr\n";
        }

        auto tempType = typeTable.get(id);
        typeStack.push(tempType);
        referncableStack.push(true);
    }

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
            errors.push("Function needs different amount of parameters, than is given");
            return;
        }
    

        for(int i = 0; i<paramType.size(); i++){
            if(!paramType[i]->compare(*argTypes[i])){
                errors.push("Argument Type did not match expacted paramtype for function");
            }
        }

        auto returnType = funcType->getReturnsTypeDesc();
        if(returnType.size()==1){
            referncableStack.push(false);
            typeStack.push(returnType[0]);
        }else if(returnType.size() > 1){
            auto manyReturnType = new ManyTypeDesc(returnType);
            for(auto ret: returnType){

                referncableStack.push(false);
            }
            typeStack.push(manyReturnType);
        }
        
    }


    //pop 2 and add 1 ref
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

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{})){    
            errors.push("wrong type for leftSide, only int or float allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{})){
            errors.push("wrong type for rightSide, only int or float allowed");
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
            std::cout<<"binary Min expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();

        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{}) && !leftSide->compare(BoolTypeDesc{})){    
            errors.push("wrong type for leftSide, only int or float allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{}) && ! rightSide->compare(BoolTypeDesc{})){
            errors.push("wrong type for rightSide, only int or float allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(leftSide);
        
        referncableStack.push(false);
    }

    void TypeChecker::binaryMulExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary Mul expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();

        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{}) && !leftSide->compare(BoolTypeDesc{})){    
            errors.push("wrong type for leftSide, only int or float allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{}) && ! rightSide->compare(BoolTypeDesc{})){
            errors.push("wrong type for rightSide, only int or float allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(leftSide);
        
        referncableStack.push(false);
    }

    void TypeChecker::binaryDivExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary Div expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();

        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{})){    
            errors.push("wrong type for leftSide, only int or float allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{})){
            errors.push("wrong type for rightSide, only int or float allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(leftSide);
        
        referncableStack.push(false);
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
            errors.push("wrong type for leftSide, only int, float, bool or char allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{}) && ! rightSide->compare(BoolTypeDesc{}) && !leftSide->compare(CharTypeDesc{})){
            errors.push("wrong type for rightSide, only int, float, bool or char allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);
    }


    void TypeChecker::binaryNEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary NEQ expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();
        
        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) && !leftSide->compare(FloatTypeDesc{}) && !leftSide->compare(BoolTypeDesc{}) && !leftSide->compare(CharTypeDesc{})){    
            errors.push("wrong type for leftSide, only int, float, bool or char allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) && !rightSide->compare(FloatTypeDesc{}) && ! rightSide->compare(BoolTypeDesc{}) && !leftSide->compare(CharTypeDesc{})){
            errors.push("wrong type for rightSide, only int, float, bool or char allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);
    }

    void TypeChecker::binaryANDExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary AND expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();
        
        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(BoolTypeDesc{})){    
            errors.push("wrong type for leftSide, only bool allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(BoolTypeDesc{})){
            errors.push("wrong type for rightSide bool allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);
    }

    void TypeChecker::binaryORExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"binary OR expre \n";
        }
                       
        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();
        
        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(BoolTypeDesc{})){    
            errors.push("wrong type for leftSide, only bool allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(BoolTypeDesc{})){
            errors.push("wrong type for rightSide bool allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't add the different types");
        }
        typeStack.push(new BoolTypeDesc{});

        referncableStack.push(false);
    }

    // >
    void TypeChecker::binaryGTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"Greater than expr \n";
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


    // >=
    void TypeChecker::binaryGEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"greater equal expr \n";
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

    // <
    void TypeChecker::binaryLTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"lesser than expr \n";
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

    void TypeChecker::binaryModExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"Mod expr \n";
        }

        visitLeftSide();
        TypeDescriptor * leftSide = typeStack.pop();
        referncableStack.pop();

        visitRightSide();
        TypeDescriptor * rightSide = typeStack.pop();
        referncableStack.pop();

        if(!leftSide->compare(IntTypeDesc{}) ){    
            errors.push("wrong type for leftSide, only int allowed");
            //std::cout<<"type not allowed, leftside (add) "<<leftSide->toString()<<"\n";
        }

        if(!rightSide->compare(IntTypeDesc{}) ){
            errors.push("wrong type for rightSide, only int  allowed");
           // std::cout<<"type not allowed, rightside (add) "<<rightSide->toString()<<"\n";
        }

        if(!leftSide->compare(*rightSide)){
            errors.push("can't modulo the different types");
        }
        typeStack.push(leftSide);
        
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

    void TypeChecker::unaryPosExpression(const std::function< void ()> visitExpression) {
        if(debug){
            std::cout<<"unary Pos \n";
        }
        visitExpression();
        TypeDescriptor * expr=typeStack.pop();
        referncableStack.pop();

        if(!expr->compare(IntTypeDesc{}) && !expr->compare(FloatTypeDesc{}) ){
            errors.push("Wrong type not expr, needs to be int or float for pos expression");
        }

        typeStack.push(expr);

        referncableStack.push(false);

    }

    void TypeChecker::unaryNegExpression(const std::function< void ()> visitExpression) {
        if(debug){
            std::cout<<"unary Neg \n";
        }
        visitExpression();
        TypeDescriptor * expr=typeStack.pop();
        referncableStack.pop();

        if(!expr->compare(IntTypeDesc{}) && !expr->compare(FloatTypeDesc{})){
            errors.push("Wrong type not expr, needs to be int or float for neg expression");
        }

        typeStack.push(expr);

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
        // if(checkDuplicateStrings(resultsName)){
        //     errors.push("Cant use same name for different returns");
        // }

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
