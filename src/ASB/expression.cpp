#include "ASB/expression.hpp"

#include <vector>
#include <functional>
#include <string>

ASB::IdentifierExpression::IdentifierExpression(std::string id): id{id}{

}

void ASB::IdentifierExpression::accept(Visitor *visitor) const{
    visitor->identifierExperssion(this->id);
}

ASB::BoolExpression::BoolExpression(bool value): value{value}{

}

void ASB::BoolExpression::accept(Visitor *visitor) const{
    visitor->boolExperssion(this->value);
}

ASB::IntegerExpression::IntegerExpression(int value): value{value}{

}

void ASB::IntegerExpression::accept(Visitor *visitor) const{
    visitor->intergerExperssion(this->value);
}

ASB::FloatExpression::FloatExpression(float value): value{value}{
}

void ASB::FloatExpression::accept(Visitor *visitor) const{
    visitor->floatExperssion(this->value);
}

ASB::CharExpression::CharExpression(char value): value{value}{
    
}

void ASB::CharExpression::accept(Visitor *visitor) const{
    visitor->charExpression(this->value);
}

ASB::BinaryAddOperation::BinaryAddOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryAddOperation::~BinaryAddOperation(){
    delete leftSide;
    delete rightSide;
}

void ASB::BinaryAddOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryAddExpression(visitLeftSide, visitRightSide);
};


ASB::BinaryMinOperation::BinaryMinOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryMinOperation::~BinaryMinOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryMinOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryMinExpression(visitLeftSide, visitRightSide);
};



ASB::BinaryMulOperation::BinaryMulOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryMulOperation::~BinaryMulOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryMulOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryMulExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryDivOperation::BinaryDivOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryDivOperation::~BinaryDivOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryDivOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryDivExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryEQOperation::BinaryEQOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryEQOperation::~BinaryEQOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryEQOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryEQExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryNEQOperation::BinaryNEQOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryNEQOperation::~BinaryNEQOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryNEQOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryNEQExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryANDOperation::BinaryANDOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryANDOperation::~BinaryANDOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryANDOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryANDExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryOROperation::BinaryOROperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryOROperation::~BinaryOROperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryOROperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryORExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryGTOperation::BinaryGTOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryGTOperation::~BinaryGTOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryGTOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryGTExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryGEOperation::BinaryGEOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryGEOperation::~BinaryGEOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryGEOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryGEExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryLTOperation::BinaryLTOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryLTOperation::~BinaryLTOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryLTOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryLTExpression(visitLeftSide, visitRightSide);
};

ASB::BinaryLEOperation::BinaryLEOperation(Expression *leftSide, Expression *rightSide): leftSide{leftSide}, rightSide{rightSide}{

};

ASB::BinaryLEOperation::~BinaryLEOperation(){
    delete leftSide;
    delete rightSide;
};

void ASB::BinaryLEOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitLeftSide{[visitor, this](){
        this->leftSide->accept(visitor);
    }};

    std::function<void ()> visitRightSide{[visitor, this](){
        this->rightSide->accept(visitor);
    }};

    visitor->binaryLEExpression(visitLeftSide, visitRightSide);
};

ASB::UnaryNotOperation::UnaryNotOperation(Expression *expression): expression{expression}{

};

ASB::UnaryNotOperation::~UnaryNotOperation(){
    delete expression;
}

void ASB::UnaryNotOperation::accept(Visitor *visitor) const{
    std::function<void ()> visitExpression{[visitor, this](){
        this->expression->accept(visitor);
    }};

    visitor->unaryNotExpression(visitExpression);
}