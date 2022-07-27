#include "Interpreting/valuedescriptor.hpp"

ValueDescriptor* ValueDescriptor::getDescri(){
    return this;
}

BoolValue::BoolValue(bool value): value{value}{

}

bool BoolValue::getValue(){
    return value;
}

IntValue::IntValue(long value): value{value}{

}

long IntValue::getValue(){
    return value;
}

FloatValue::FloatValue(float value): value{value}{

}

float FloatValue::getValue(){
    return value;
}

CharValue::CharValue(char value): value{value}{

}

char CharValue::getValue(){
    return value;
}


FunctionValue::FunctionValue(){

}

// ValueDescriptor * FunctionValue::execute(std::vector<ValueDescriptor *> paramValues){


// }