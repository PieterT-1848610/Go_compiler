#include "ASB/statment.hpp"

ASB::ExpressionStatment::ExpressionStatment(Expression *expression): expression{expression}{

}

ASB::ExpressionStatment::~ExpressionStatment(){
    delete expression;
}

ASB::AssignmentStatment::AssignmentStatment(std::vector<Expression *> leftSide, std::vector<Expression *> rightSide):
                                            leftSide {leftSide}, rightSide{rightSide}{

    }

ASB::AssignmentStatment::~AssignmentStatment(){
    for(int i=0; i< leftSide.size(); i++){
        delete leftSide[i];
    }
    for (int i= 0 ; i< rightSide.size(); i++){
        delete rightSide[i];
    }
}

ASB::ForStatment::ForStatment(SimpleStatment *init, Expression *condition, SimpleStatment *post, Block *bodyFor):
                        initStatment{init}, condition{condition}, postStatment{post}, bodyFor{bodyFor}{

    }

ASB::ForStatment::~ForStatment(){
    delete initStatment;
    delete condition;
    delete postStatment;
    delete bodyFor;
}

ASB::DeclarationStatment::DeclarationStatment(Declaration *declaration): declaration{declaration}{

}

ASB::DeclarationStatment::~DeclarationStatment(){
    delete declaration;
}

ASB::IfStatment::IfStatment(Expression *condition, Block *TrueCondition, Block *FalseCondition):
                    condition{condition}, TrueCondition{TrueCondition}, FalseCondition{FalseCondition}{

    }

ASB::IfStatment::~IfStatment(){
    delete condition;
    delete TrueCondition;
    delete FalseCondition;
}


ASB::ReturnStatment::ReturnStatment(std::vector<Expression *> expressions): expressions{expressions}{

}

ASB::ReturnStatment::~ReturnStatment(){
    for(int i=0; i<expressions.size(); i++){
        delete expressions[i];
    }
}