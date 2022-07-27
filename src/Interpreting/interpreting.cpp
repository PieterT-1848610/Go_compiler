#include "Interpreting/interpreting.hpp"

    Interpreting::Interpreting():valueStack{}, valueTable{}, paramValues{}, paramNames{}{
        
        //Not working 
        std::function<void ()>func{[this](){
            auto valueDesc = this->valueStack.pop();
            auto value = dynamic_cast<IntValue *>(valueDesc);
            std::cout<<value->getValue();
        }};
        
        valueTable.set("printInt", new FunctionValue(func) );    

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
    void Interpreting::block(const std::vector< std::function< void ()>> visitStatments) {
        //newscope table
        valueTable.newScope();
        for(auto param: paramValues){
            valueTable.set(param.first, param.second);
        }
        paramValues.clear();
        paramNames.clear();
        //set params, van vector param
        //clear vector param

        //removescope
        valueTable.removeScope();
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
                auto tempValue = this->valueStack.pop();
                this->paramValues.push_back(std::make_pair(this->paramNames[i],tempValue));
            }

            visitFunctionBody();
        }};
        FunctionValue *functionValue = new FunctionValue(func);
        valueTable.set(id, functionValue);
        
        //set to Table
    }

    void Interpreting::variableDeclaration(const std::vector<std::string> ids, const std::function< void ()> visitType, const std::vector < std::function< void ()>> visitExpressions) {
        //visitExpressions
        //pop valueStack
        std::vector<ValueDescriptor *> values;
        for(auto expr: visitExpressions){
            expr();
            values.push_back(valueStack.pop());
        }
        for(int i=0; i<ids.size(); i++){
            valueTable.set(ids[i], values[i]);
        }

        //set with valueTable id and value

    }


    //statments
    void Interpreting::expressionStatment(const std::function< void ()> visitExperssion) {}

    void Interpreting::emptyStatment() {}

    void Interpreting::assignmentStatment(const std::vector< std::function< void ()>> visitLeftSide, const std::vector<  std::function< void ()>> visitRightSide) {
        //visitleft

        //visitrightside
    }

    void Interpreting::forStatment(const std::function< void ()> visitInit,  const std::function< void ()> visitCondition, const std::function< void ()> visitPost, const std::function< void ()> visitBodyFor) {}

    void Interpreting::declarationStament(const std::function< void ()>visitDeclaration) {}

    void Interpreting::ifStatment(const std::function< void ()> visitCondition, const std::function< void ()> visitTrueCondition, const std::function< void ()> visitFalseCondition) {}

    void Interpreting::returnStatment(const std::vector<std::function< void ()>> visitExpressions) {
        //visitExpression();

    }


    //expresions
    void Interpreting::identifierExperssion(const std::string id) {
        auto idExpr = valueTable.get(id);
        valueStack.push(idExpr);

    }

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


    //TODO: reason print can't work
    void Interpreting::callExpression(const std::function<void ()> visitExpression, const std::vector<std::function<void ()>> visitArguments){
        //visitExpression()
        

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
    void Interpreting::functionType(const std::vector<std::string> parametersName,const std::vector<std::function < void ()>> visitParametersType, const std::vector<std::string> resultsName, const std::vector<std::function < void ()>> visitResultsType) {
        this->paramNames = parametersName;
    }

    void Interpreting::identifierType(const std::string id) {}

