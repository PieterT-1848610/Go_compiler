#include "ASB/expression.hpp"

ASB::IdentifierExpression::IdentifierExpression(std::string id): id{id}{

}

void ASB::IdentifierExpression::accept(Visitor *visitor) const{
    visitor->identifierExperssion(this->id);
}

ASB::BoolExpression::BoolExpression(bool value): value{value}{

}

ASB::IntegerExpression::IntegerExpression(int value): value{value}{

}

ASB::FloatExpression::FloatExpression(float value): value{value}{

}

ASB::CharExpression::CharExpression(char value): value{value}{
    
}