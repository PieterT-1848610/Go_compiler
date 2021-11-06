#include "./includes/ASB/stament.hpp"

ExpressionStatment::ExpressionStatment(Expression *expression): expression{expression}{

}

ExpressionStatment::~ExpressionStatment(){
    delete expression;
}

AssignmentStatment::AssignmentStatment(std::vector<Expression *> leftSide, std::vector<Expression *> rightSide):
                                            leftSide {leftSide}, rightSide{rightSide}{

    }

AssignmentStatment::~AssignmentStatment(){
    for(int i=0; i< leftSide.size(); i++){
        delete leftSide[i];
    }
    for (int i= 0 ; i< rightSide.size(); i++){
        delete rightSide[i];
    }
}

ForStatment::ForStatment(SimpleStatment *init, Expression *condition, SimpleStatment *post, Block *bodyFor):
                        initStatment{init}, condition{condition}, postStatment{post}, bodyFor{bodyFor}{

    }

ForStatment::~ForStatment(){
    delete initStatment;
    delete condition;
    delete postStatment;
    delete bodyFor;
}

DeclarationStatment::DeclarationStatment(Declaration *declaration): declaration{declaration}{

}

DeclarationStatment::~DeclarationStatment(){
    delete declaration;
}

IfStatment::IfStatment(Expression *condition, Block *TrueCondition, Block *FalseCondition):
                    condition{condition}, TrueCondition{TrueCondition}, FalseCondition{FalseCondition}{

    }

IfStatment::~IfStatment(){
    delete condition;
    delete TrueCondition;
    delete FalseCondition;
}


ReturnStatment::ReturnStatment(std::vector<Expression *> expressions): expressions{expressions}{

}

ReturnStatment::~ReturnStatment(){
    for(int i=0; i<expressions.size(); i++){
        delete expressions[i];
    }
}