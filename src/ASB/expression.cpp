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