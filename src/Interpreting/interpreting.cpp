#include "Interpreting/interpreting.hpp"

    Interpreting::Interpreting(bool debug):valueStack{}, valueTable{}, paramValues{}, paramNames{}, debug{debug}, returnValue{false}{
        
        //Not working 
        std::function<void ()>funcInt{[this](){
            auto valueDesc = this->valueStack.pop();
            auto value = dynamic_cast<IntValue *>(valueDesc->getDescri());
            if(this->debug){
                std::cout<<"\n\n\n"<<value->getValue()<<"\n\n\n";
            }else{
                std::cout<<value->getValue()<<"\n";
            }

        }};
        valueTable.set("printInt", new FunctionValue(funcInt) );

        std::function<void ()>funcFloat{[this](){
            auto valueDesc = this->valueStack.pop();
            auto value = dynamic_cast<FloatValue *>(valueDesc->getDescri());
            if(this->debug){
                std::cout<<"\n\n\n"<<value->getValue()<<"\n\n\n";
            }else{
                std::cout<<value->getValue()<<"\n";
            }
        }};  
        valueTable.set("printFloat", new FunctionValue(funcFloat));

        std::function<void ()>funcBool{[this](){
            auto valueDesc = this->valueStack.pop();
            auto value = dynamic_cast<BoolValue *>(valueDesc->getDescri());
            std::string boolString {};
            if(value->getValue()){
                boolString.assign("true");
            }else{
                boolString.assign("false");
            }

            if(this->debug){
                std::cout<<"\n\n\n"<<boolString<<"\n\n\n";
            }else{
                std::cout<<boolString<<"\n";
            }
            
        }};  
        valueTable.set("printBool", new FunctionValue(funcBool));

    }

    Interpreting::~Interpreting(){

    }

    void Interpreting::root(const std::vector< std::function< void ()>> visitDeclarations) {
        //visit all functions and make the signatures
        for(auto declaration: visitDeclarations){
            declaration();
        }

        //find main function
        auto mainFunc = dynamic_cast<FunctionValue *> (valueTable.get("main"));
        if(mainFunc == nullptr){
            throw("casting problem interpriting");
        }

        mainFunc->execute();

    }

    //Block
    //TODO: fix socope problem
    void Interpreting::block(const std::vector< std::function< void ()>> visitStatments) {
        if(debug){
            std::cout<<"Enter Block\n";
        }
        
        //newscope table
        valueTable.newScope();
        for(auto param: paramValues){
            valueTable.set(param.first, param.second);
        }
        paramValues.clear();
        paramNames.clear();
        //set params, van vector param
        //clear vector param
        for(auto stat: visitStatments){
            stat();
            if(returnValue){
                break;
            }
        }

        
        //removescope
        valueTable.removeScope();
        if(debug){
            std::cout<<"Exit of block \n";
        }

    }

    //Declaration
    void Interpreting::functionDeclaration(const std::string id, const std::function< void ()> visitSignature, const std::function< void ()> visitFunctionBody) {
        
        //visitSignature();

        //make functionValue
        //in site std::function(
            //eerst: visitSignature()   weet voor params name
            //paramNames voor de ids    
            //last name comes first for value
            //set op vector paramvalues with names en paramvalues
            //body()
            //
        //)
        std::function<void ()>func{[this, visitSignature, visitFunctionBody](){
            visitSignature();
            
            for(int i = this->paramNames.size() -1; i>=0 ; i--){
                auto tempValue = this->valueStack.pop()->getDescri();
                this->paramValues.push_back(std::make_pair(this->paramNames[i],tempValue));
            }

            visitFunctionBody();
        }};
        FunctionValue *functionValue = new FunctionValue(func);
        valueTable.set(id, functionValue->getDescri());
        
        //set to Table
    }

    void Interpreting::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {
        //visitExpressions
        //pop valueStack
        if(debug){
            std::cout<<"var interpreting \n";
        }

        std::vector<ValueDescriptor *> values;
        for(auto expr: visitExpressions){
            expr();
            auto temp = valueStack.pop()->getDescri();
            if(temp->manyVals()){
                std::vector<ValueDescriptor *> manyVals = dynamic_cast<ManyValues *>(temp)->getValues();
                for(auto val: manyVals){
                    values.push_back(val->getDescri());
                }
            }else{
                values.push_back(temp);
            }
            //values.push_back(valueStack.pop()->getDescri());
        }
        for(int i=0; i<ids.size(); i++){
            valueTable.set(ids[i], values[i]->getDescri());
        }

        //set with valueTable id and value

    }


    void Interpreting::packageDeclaration(const std::string packageName){
        
    }

    //statments
    void Interpreting::expressionStatment(const std::function< void ()> visitExperssion) {
        if(debug){
            std::cout<<"expr stat \n";
        }

        visitExperssion();
    }

    void Interpreting::emptyStatment() {
        if(debug){
            std::cout<<"expr empty stat \n";
        }
    }

    //x, y = y,x not working
    void Interpreting::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {
        if(debug){
            std::cout<<"assing stat \n";
        }
        //visitleft
        std::vector<ValueDescriptor *> leftValues {};
        for(auto leftSide: visitLeftSide){
            leftSide();
            leftValues.push_back(valueStack.pop());
        }

        //visitrightside
        std::vector<ValueDescriptor *> rightValues {};
        //std::vector<ValueDescriptor> tempValues {};
        for(auto rightSide: visitRightSide){
            rightSide();
            auto temp = valueStack.pop()->getDescri();
            if(temp->manyVals()){
                std::vector<ValueDescriptor *> manyVals = dynamic_cast<ManyValues *>(temp)->getValues();
                for(auto val: manyVals){
                    rightValues.push_back(val->getDescri());
                }
            }else{
                rightValues.push_back(temp);
            }

            //rightValues.push_back(valueStack.pop()->getDescri());
            //tempValues.push_back(* valueStack.pop());
        }

        for(int i=0; i<visitLeftSide.size(); i++){
           dynamic_cast<ReferenceValue *>(leftValues[i])->setValue(rightValues[i]->getDescri());
           //dynamic_cast<ReferenceValue *>(leftValues[i])->setValue(tempValues[i].getDescri());
        }


    }
    

    //hmmmm, not working skip it maybe. cast to ref
    void Interpreting::incrStatment(const std::function <void ()> visitExpression){
        if(debug){
            std::cout<<"incr stat \n";
        }
        visitExpression();
        auto expr = valueStack.pop();
        auto inc_expr = dynamic_cast<IncreaseOne *>(expr);
        auto newVal = inc_expr->increaseOne();
        
        dynamic_cast<ReferenceValue *>(expr)->setValue(newVal->getDescri());
    }


    void Interpreting::decrStatment(const std::function <void ()> visitExpression){
        if(debug){
            std::cout<<"decr stat \n";
        }
        visitExpression();
        auto expr = valueStack.pop();
        auto inc_expr = dynamic_cast<DecreaseOne *>(expr);
        auto newVal = inc_expr->decreaseOne();
        
        dynamic_cast<ReferenceValue *>(expr)->setValue(newVal->getDescri());
    }


    void Interpreting::decrAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"decr assing stat\n";
        }
        visitLeftExpression();
        auto leftValue = valueStack.pop();
        visitRightExpression();
        auto rightValue = valueStack.pop()->getDescri();

        auto leftSideEq = dynamic_cast<Min *>(leftValue->getDescri());
        auto result = leftSideEq->min(rightValue)->getDescri();
        dynamic_cast<ReferenceValue *>(leftValue)->setValue(result);

    }

    void Interpreting::incrAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"incr assing stat\n";
        }
        visitLeftExpression();
        auto leftValue = valueStack.pop();
        visitRightExpression();
        auto rightValue = valueStack.pop()->getDescri();

        auto leftSideEq = dynamic_cast<Add *>(leftValue->getDescri());
        auto result = leftSideEq->add(rightValue)->getDescri();
        dynamic_cast<ReferenceValue *>(leftValue)->setValue(result);

    }

    void Interpreting::mulAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"mull assing stat\n";
        }
        visitLeftExpression();
        auto leftValue = valueStack.pop();
        visitRightExpression();
        auto rightValue = valueStack.pop()->getDescri();

        auto leftSideEq = dynamic_cast<Mul *>(leftValue->getDescri());
        auto result = leftSideEq->mul(rightValue)->getDescri();
        dynamic_cast<ReferenceValue *>(leftValue)->setValue(result);

    }


    void Interpreting::divAssignStatment(const std::function<void ()> visitLeftExpression, const std::function<void ()> visitRightExpression){
        if(debug){
            std::cout<<"div assing stat\n";
        }
        visitLeftExpression();
        auto leftValue = valueStack.pop();
        visitRightExpression();
        auto rightValue = valueStack.pop()->getDescri();

        auto leftSideEq = dynamic_cast<Div *>(leftValue->getDescri());
        auto result = leftSideEq->div(rightValue)->getDescri();
        dynamic_cast<ReferenceValue *>(leftValue)->setValue(result);

    }

    void Interpreting::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {
        visitInit();

        visitCondition();
        bool cond = dynamic_cast<BoolValue *>(valueStack.pop()->getDescri())->getValue();

        while (cond){
            visitBodyFor();

            if(returnValue){
                break;
            }

            visitPost();

            visitCondition();
            cond = dynamic_cast<BoolValue *>(valueStack.pop()->getDescri())->getValue();
        }

    }

    void Interpreting::declarationStament(const std::function< void ()>visitDeclaration) {
        if(debug){
            std::cout<<"decl stat \n";
        }

        visitDeclaration();
    }

    void Interpreting::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {
        if(debug){
            std::cout<<"if stat \n";
        }
        visitCondition();
        auto cond = dynamic_cast<BoolValue *>(valueStack.pop()->getDescri());

        if(cond->getValue()){
            visitTrueCondition();
        }else{
            visitFalseCondition();
        }

    }

    void Interpreting::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {
        if(debug){
            std::cout<<"return stat \n";
        }

        std::vector<ValueDescriptor *> tempValues = {};
        
        if(visitExpressions.size() == 1){
            visitExpressions[0]();
            auto temp = valueStack.pop();
            valueStack.push(temp->getDescri());
        }else{
            for(auto expr: visitExpressions){
            expr();
            auto temp = valueStack.pop();
            //valueStack.push(temp->getDescri());
            tempValues.push_back(temp->getDescri());
            }
            valueStack.push(new ManyValues(tempValues));
        }
        returnValue = true;
    }


    //expresions
    void Interpreting::identifierExperssion(const std::string id) {
        if(debug){
            std::cout<<"id expr \n";
        }
        
        std::function<void (ValueDescriptor*)> setFunc = [this, id](ValueDescriptor* newVal){
            auto _id = id;
            //this->valueTable.setOther(_id, newVal);
            this->valueTable.replace(_id, newVal);
        };

        std::function<ValueDescriptor* ()> getFunc = [this, id]()->ValueDescriptor *{
            auto _id = id;
            return this->valueTable.get(_id);
            //return temp->getDescri();
            //return temp;
        };
        
        valueStack.push(new ReferenceValue(getFunc, setFunc));
        //valueStack.push(idExpr);

    }

    void Interpreting::boolExperssion(const bool value) {
        if(debug){
            std::cout<<"bool expr \n";
        }

        valueStack.push(new BoolValue(value));
    }

    void Interpreting::intergerExperssion(const int value) {
        if(debug){
            std::cout<<"int expr \n";
        }

        valueStack.push(new IntValue(value));
    }

    void Interpreting::floatExperssion(const float value) {
        if(debug){
            std::cout<<"float expr \n";
        }

        valueStack.push(new FloatValue(value));
    }

    void Interpreting::charExpression(const char value) {
        if(debug){
            std::cout<<"char expr \n";
        }

        valueStack.push(new CharValue(value));
    }


    //TODO: reason print can't work
    void Interpreting::callExpression(const std::function<void ()> visitExpression, const std::vector<std::function<void ()>> visitArguments){
        if(debug){
            std::cout<<"call expr \n";
        }
        visitExpression();
        auto func = valueStack.pop()->getDescri();


        for(auto arg: visitArguments){
            arg();
        }
        returnValue =false;
        auto funcExc = dynamic_cast<FunctionValue *>(func->getDescri());
        funcExc->execute();
        returnValue = false;
        
    }

    // void Interpreting::identifierExperssion(const std::string id);
    //Binary for alle operatie +, -, /, * const std::function< void ()> visitleft en const std::function< void ()>rightside (function)
    void Interpreting::binaryAddExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"Add expr \n";
        }
        visitLeftSide();
        auto leftSide = dynamic_cast<Add *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());


        //auto result = leftSide->add(rightSide);
        valueStack.push(leftSide->add(rightSide)->getDescri());

    }

    void Interpreting::binaryMinExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"Min expr \n";
        }
        visitLeftSide();
        auto leftSide = dynamic_cast<Min *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());


        //auto result = leftSide->add(rightSide);
        valueStack.push(leftSide->min(rightSide)->getDescri());
    }

    void Interpreting::binaryMulExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"Mul expr \n";
        }
        visitLeftSide();
        auto leftSide = dynamic_cast<Mul *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());


        //auto result = leftSide->add(rightSide);
        valueStack.push(leftSide->mul(rightSide)->getDescri());
    }

    void Interpreting::binaryDivExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        if(debug){
            std::cout<<"Div expr \n";
        }
        visitLeftSide();
        auto leftSide = dynamic_cast<Div *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());


        //auto result = leftSide->add(rightSide);
        valueStack.push(leftSide->div(rightSide)->getDescri());
    }

    void Interpreting::binaryEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<Equal *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());

        valueStack.push(leftSide->equal(rightSide)->getDescri());

    }

    void Interpreting::binaryNEQExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<NotEqual *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());

        valueStack.push(leftSide->notEqual(rightSide)->getDescri());
    }

    void Interpreting::binaryANDExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<AndOper *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());

        valueStack.push(leftSide->andOpr(rightSide)->getDescri());

    }

    void Interpreting::binaryORExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<OrOper *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = (valueStack.pop()->getDescri());

        valueStack.push(leftSide->orOpr(rightSide)->getDescri());

    }

    // >
    void Interpreting::binaryGTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<GreaterThan *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = valueStack.pop()->getDescri();

        valueStack.push(leftSide->greaterThan(rightSide)->getDescri());
    }

    //>=
    void Interpreting::binaryGEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<GreaterOrEqual *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = valueStack.pop()->getDescri();

        valueStack.push(leftSide->greaterOrEqual(rightSide)->getDescri());
    }

    // <
    void Interpreting::binaryLTExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<LesserThan *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = valueStack.pop()->getDescri();

        valueStack.push(leftSide->lesserThan(rightSide)->getDescri());
    }

    //<=
    void Interpreting::binaryLEExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<LesserOrEqual *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = valueStack.pop()->getDescri();

        valueStack.push(leftSide->lesserOrEqual(rightSide)); 
    }

    void Interpreting::binaryModExpression(const std::function< void ()> visitLeftSide, const std::function< void ()> visitRightSide) {
        visitLeftSide();
        auto leftSide = dynamic_cast<Modulo *>(valueStack.pop()->getDescri());

        visitRightSide();
        auto rightSide = valueStack.pop()->getDescri();

        valueStack.push(leftSide->modulo(rightSide)->getDescri());
    }
    //Unary Operations
    void Interpreting::unaryNotExpression(const std::function< void ()> visitExpression) {
        visitExpression();
        auto expr = dynamic_cast<Not *>(valueStack.pop()->getDescri());

        valueStack.push(expr->notFunc()->getDescri());
    }


    void Interpreting::unaryNegExpression(const std::function< void ()> visitExpression) {
        visitExpression();
        auto expr = dynamic_cast<NegValue *>(valueStack.pop()->getDescri());

        valueStack.push(expr->negValue()->getDescri());
    }

    void Interpreting::unaryPosExpression(const std::function< void ()> visitExpression) {
        visitExpression();
        auto expr = dynamic_cast<PosValue *>(valueStack.pop()->getDescri());

        valueStack.push(expr->posValue()->getDescri());
    }

    //types
    //no need ?
    void Interpreting::intType() {}

    void Interpreting::boolType() {}

    void Interpreting::floatType() {}

    void Interpreting::charType() {}

    //no clue yet
    void Interpreting::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {
        this->paramNames = parametersName;
    }

    void Interpreting::identifierType(const std::string id) {}

