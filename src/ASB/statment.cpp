#include "ASB/statment.hpp"
#include <vector>
#include <functional>

ASB::ExpressionStatment::ExpressionStatment(Expression *expression): expression{expression}{

};


ASB::ExpressionStatment::~ExpressionStatment(){
    delete expression;
};

void ASB::ExpressionStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitExpression{ [visitor, this](){
        this->expression->accept(visitor);
    }};

    visitor->expressionStatment(visitExpression);
};

void ASB::EmptyStatment::accept(Visitor *visitor) const{
    visitor->emptyStatment();
}



ASB::AssignmentStatment::AssignmentStatment(std::vector<Expression *> leftSide, std::vector<Expression *> rightSide):
                                            leftSide {leftSide}, rightSide{rightSide}{

    };

void ASB::AssignmentStatment::accept(Visitor *visitor) const{
    std::vector<std::function<void ()>> visitLeftSide{};
    for(auto left: this->leftSide){
        visitLeftSide.push_back([left, visitor](){
            left->accept(visitor);
        });
    }

    std::vector<std::function<void ()>> visitRightSide{};
    for(auto right: this->rightSide){
        visitRightSide.push_back([right, visitor](){
            right->accept(visitor);
        });
    }

    visitor->assignmentStatment(visitLeftSide, visitRightSide);
};

ASB::AssignmentStatment::~AssignmentStatment(){
    for(int i=0; i< leftSide.size(); i++){
        delete leftSide[i];
    }
    for (int i= 0 ; i< rightSide.size(); i++){
        delete rightSide[i];
    }
};

ASB::IncrStatment::IncrStatment(Expression * expression):expression{expression}{

}

ASB::IncrStatment::~IncrStatment(){
    delete expression;
}

void ASB::IncrStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitExpression{[this, visitor](){
        this->expression->accept(visitor);
    }};

    visitor->incrStatment(visitExpression);
}


ASB::DecrStatment::DecrStatment(Expression * expression):expression{expression}{

}

ASB::DecrStatment::~DecrStatment(){
    delete expression;
}

void ASB::DecrStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitExpression{[this, visitor](){
        this->expression->accept(visitor);
    }};

    visitor->decrStatment(visitExpression);
}


ASB::DecrAssignStatment::DecrAssignStatment(Expression* leftExpression, Expression* rightExpression): 
    leftExpression{leftExpression}, rightExpression{rightExpression}{

}

ASB::DecrAssignStatment::~DecrAssignStatment(){
    delete rightExpression;
    delete leftExpression;
}

void ASB::DecrAssignStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftExpr{[this, visitor](){
        this->leftExpression->accept(visitor);
    }};

    std::function<void ()> visitRightExpr{[this, visitor](){
        this->rightExpression->accept(visitor);
    }};
    
    visitor->decrAssignStatment(visitLeftExpr, visitRightExpr);

}

ASB::IncrAssignStatment::IncrAssignStatment(Expression* leftExpression, Expression* rightExpression): 
    leftExpression{leftExpression}, rightExpression{rightExpression}{

}

ASB::IncrAssignStatment::~IncrAssignStatment(){
    delete rightExpression;
    delete leftExpression;
}

void ASB::IncrAssignStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftExpr{[this, visitor](){
        this->leftExpression->accept(visitor);
    }};

    std::function<void ()> visitRightExpr{[this, visitor](){
        this->rightExpression->accept(visitor);
    }};
    
    visitor->incrAssignStatment(visitLeftExpr, visitRightExpr);

}

ASB::MultpAssignStatment::MultpAssignStatment(Expression* leftExpression, Expression* rightExpression): 
    leftExpression{leftExpression}, rightExpression{rightExpression}{

}

ASB::MultpAssignStatment::~MultpAssignStatment(){
    delete rightExpression;
    delete leftExpression;
}

void ASB::MultpAssignStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftExpr{[this, visitor](){
        this->leftExpression->accept(visitor);
    }};

    std::function<void ()> visitRightExpr{[this, visitor](){
        this->rightExpression->accept(visitor);
    }};
    
    visitor->mulAssignStatment(visitLeftExpr, visitRightExpr);

}

ASB::DivAssignStatment::DivAssignStatment(Expression* leftExpression, Expression* rightExpression): 
    leftExpression{leftExpression}, rightExpression{rightExpression}{

}

ASB::DivAssignStatment::~DivAssignStatment(){
    delete rightExpression;
    delete leftExpression;
}

void ASB::DivAssignStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftExpr{[this, visitor](){
        this->leftExpression->accept(visitor);
    }};

    std::function<void ()> visitRightExpr{[this, visitor](){
        this->rightExpression->accept(visitor);
    }};
    
    visitor->divAssignStatment(visitLeftExpr, visitRightExpr);

}

ASB::ForStatment::ForStatment(SimpleStatment *init, Expression *condition, SimpleStatment *post, Block *bodyFor):
                        initStatment{init}, condition{condition}, postStatment{post}, bodyFor{bodyFor}{

    };

void ASB::ForStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitInit{[this, visitor](){
        this->initStatment->accept(visitor);
    }};
    std::function<void ()> visitCondition{[this, visitor](){
        this->condition->accept(visitor);
    }};
    std::function<void ()> visitPostStatment{[this, visitor](){
        this->postStatment->accept(visitor);
    }};
    std::function<void ()> visitBodyFor{[this, visitor](){
        this->bodyFor->accept(visitor);
    }};

    visitor->forStatment(visitInit, visitCondition, visitPostStatment, visitBodyFor);
};

ASB::ForStatment::~ForStatment(){
    delete initStatment;
    delete condition;
    delete postStatment;
    delete bodyFor;
};

ASB::DeclarationStatment::DeclarationStatment(Declaration *declaration): declaration{declaration}{

};

ASB::DeclarationStatment::~DeclarationStatment(){
    delete declaration;
};

void ASB::DeclarationStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitDeclaration{[this, visitor](){
        this->declaration->accept(visitor);
    }};
    visitor->declarationStament(visitDeclaration);
};

ASB::IfStatment::IfStatment(Expression *condition, Block *trueCondition, Block *falseCondition):
                    condition{condition}, trueCondition{trueCondition}, falseCondition{falseCondition}{

    };

ASB::IfStatment::~IfStatment(){
    delete condition;
    delete trueCondition;
    delete falseCondition;
};

void ASB::IfStatment::accept(Visitor *visitor) const{
    std::function<void ()> visitCondition{[this, visitor](){
        this->condition->accept(visitor);
    }};
    std::function<void ()> visitTrueCondition{[this, visitor](){
        this->trueCondition->accept(visitor);
    }};
    std::function<void ()> visitFalseCondition{[this, visitor](){
        this->falseCondition->accept(visitor);
    }};

    visitor->ifStatment(visitCondition, visitTrueCondition, visitFalseCondition);
};


ASB::ReturnStatment::ReturnStatment(std::vector<Expression *> expressions): expressions{expressions}{

};

ASB::ReturnStatment::~ReturnStatment(){
    for(int i=0; i<expressions.size(); i++){
        delete expressions[i];
    }
};

void ASB::ReturnStatment::accept(Visitor *visitor) const{
    std::vector<std::function<void ()>> visitExpressions{};
    for(auto expr: this->expressions){
        visitExpressions.push_back([expr, visitor](){
            expr->accept(visitor);
        });
    }

    visitor->returnStatment(visitExpressions);
};

