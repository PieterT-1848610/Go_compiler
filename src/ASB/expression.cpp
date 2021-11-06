#include "./includes/ASB/expression.hpp"

IdentifierExpression::IdentifierExpression(std::string id): id{id}{

}

BoolExpression::BoolExpression(bool value): value{value}{

}

IntegerExpression::IntegerExpression(int value): value{value}{

}

FloatExpression::FloatExpression(float value): value{value}{

}

CharExpression::CharExpression(char value): value{value}{
    
}