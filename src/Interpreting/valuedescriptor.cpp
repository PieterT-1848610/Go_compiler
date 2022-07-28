#include "Interpreting/valuedescriptor.hpp"

// ValueDescriptor* ValueDescriptor::getDescri(){
//     return this;
// }

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


ValueDescriptor* IntValue::add(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other);
    return new IntValue(value + otherValue->getValue());
}

FloatValue::FloatValue(float value): value{value}{

}

float FloatValue::getValue(){
    return value;
}

ValueDescriptor* FloatValue::add(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other);
    return new FloatValue(value + otherValue->getValue());
}

CharValue::CharValue(char value): value{value}{

}

char CharValue::getValue(){
    return value;
}


FunctionValue::FunctionValue(std::function<void ()> func): func{func}{

}

void FunctionValue::execute(){
    func();

}