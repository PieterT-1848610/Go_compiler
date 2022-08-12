#include "Interpreting/valuedescriptor.hpp"

ValueDescriptor* ValueDescriptor::getDescri(){
     return this;
}

bool ValueDescriptor::manyVals(){
    return false;
}

BoolValue::BoolValue(bool value): value{value}{

}

bool BoolValue::getValue(){
    return value;
}

ValueDescriptor* BoolValue::equal(ValueDescriptor *other){
    BoolValue* otherValue = dynamic_cast<BoolValue *>(other->getDescri());
    return new BoolValue(value == otherValue->getValue());
}

ValueDescriptor* BoolValue::notFunc(){
    return new BoolValue(!this->value);
}

ValueDescriptor* BoolValue::notEqual(ValueDescriptor *other){
    BoolValue* otherValue = dynamic_cast<BoolValue *>(other->getDescri());
    return new BoolValue(value != otherValue->getValue());
}

ValueDescriptor* BoolValue::andOpr(ValueDescriptor *other){
    BoolValue* otherValue = dynamic_cast<BoolValue *>(other->getDescri());
    return new BoolValue(value && otherValue->getValue());
}

ValueDescriptor* BoolValue::orOpr(ValueDescriptor *other){
    BoolValue* otherValue = dynamic_cast<BoolValue *>(other->getDescri());
    return new BoolValue(value || otherValue->getValue());
}



IntValue::IntValue(long value): value{value}{

}

long IntValue::getValue(){
    return value;
}


ValueDescriptor* IntValue::add(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new IntValue(value + otherValue->getValue());
}

ValueDescriptor* IntValue::min(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new IntValue(value - otherValue->getValue());
}

ValueDescriptor* IntValue::mul(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new IntValue(value * otherValue->getValue());
}

ValueDescriptor* IntValue::div(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new IntValue(value / otherValue->getValue());
}


ValueDescriptor* IntValue::equal(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new BoolValue(value == otherValue->getValue());
}

ValueDescriptor* IntValue::notEqual(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new BoolValue(value != otherValue->getValue());
}


ValueDescriptor* IntValue::lesserOrEqual(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new BoolValue(value <= otherValue->getValue());
}

ValueDescriptor* IntValue::lesserThan(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new BoolValue(value < otherValue->getValue());
}

ValueDescriptor* IntValue::greaterOrEqual(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new BoolValue(value >= otherValue->getValue());
}

ValueDescriptor* IntValue::greaterThan(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new BoolValue(value > otherValue->getValue());
}


ValueDescriptor* IntValue::increaseOne(){
    return new IntValue(value + 1);
}

ValueDescriptor* IntValue::decreaseOne(){
    return new IntValue(value - 1);
}

ValueDescriptor* IntValue::modulo(ValueDescriptor *other){
    IntValue* otherValue = dynamic_cast<IntValue *>(other->getDescri());
    return new IntValue(value % otherValue->getValue());
}

ValueDescriptor* IntValue::posValue(){
    return new IntValue(this->value);
}

ValueDescriptor* IntValue::negValue(){
    return new IntValue(-this->value);
}

FloatValue::FloatValue(float value): value{value}{

}

float FloatValue::getValue(){
    return value;
}

ValueDescriptor* FloatValue::add(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new FloatValue(value + otherValue->getValue());
}

ValueDescriptor* FloatValue::min(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new FloatValue(value - otherValue->getValue());
}

ValueDescriptor* FloatValue::mul(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new FloatValue(value * otherValue->getValue());
}

ValueDescriptor* FloatValue::div(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new FloatValue(value / otherValue->getValue());
}


ValueDescriptor* FloatValue::equal(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new BoolValue(value == otherValue->getValue());
}

ValueDescriptor* FloatValue::notEqual(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new BoolValue(value != otherValue->getValue());
}

ValueDescriptor* FloatValue::lesserOrEqual(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new BoolValue(value <= otherValue->getValue());
}

ValueDescriptor* FloatValue::lesserThan(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new BoolValue(value < otherValue->getValue());
}

ValueDescriptor* FloatValue::greaterOrEqual(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new BoolValue(value >= otherValue->getValue());
}

ValueDescriptor* FloatValue::greaterThan(ValueDescriptor *other){
    FloatValue* otherValue = dynamic_cast<FloatValue *>(other->getDescri());
    return new BoolValue(value > otherValue->getValue());
}

ValueDescriptor* FloatValue::increaseOne(){
    return new FloatValue(value + 1);
}

ValueDescriptor* FloatValue::decreaseOne(){
    return new FloatValue(value - 1);
}




ValueDescriptor* FloatValue::posValue(){
    return new FloatValue(this->value);
}

ValueDescriptor* FloatValue::negValue(){
    return new FloatValue(-this->value);
}

CharValue::CharValue(char value): value{value}{

}

char CharValue::getValue(){
    return value;
}

ValueDescriptor* CharValue::equal(ValueDescriptor *other){
    CharValue* otherValue = dynamic_cast<CharValue *>(other->getDescri());
    return new BoolValue(value == otherValue->getValue());
}

ValueDescriptor* CharValue::notEqual(ValueDescriptor *other){
    CharValue* otherValue = dynamic_cast<CharValue *>(other->getDescri());
    return new BoolValue(value != otherValue->getValue());
}


FunctionValue::FunctionValue(std::function<void ()> func): func{func}{

}

void FunctionValue::execute(){
    func();

}

ReferenceValue::ReferenceValue(std::function<ValueDescriptor * ()> getter, 
                                std::function<void (ValueDescriptor *)> setter): 
                                getter{getter}, setter{setter}{

}

ValueDescriptor* ReferenceValue::getDescri(){
    return getter();
}

void ReferenceValue::setValue(ValueDescriptor* valueDescr){
    setter(valueDescr->getDescri());
}


ValueDescriptor* ReferenceValue::add(ValueDescriptor *other){
    auto value = dynamic_cast<Add *>(this->getDescri());
    return value->add(other->getDescri());
}

ValueDescriptor* ReferenceValue::min(ValueDescriptor *other){
    auto value = dynamic_cast<Min *>(this->getDescri());
    return value->min(other->getDescri());
}

ValueDescriptor* ReferenceValue::mul(ValueDescriptor *other){
    auto value = dynamic_cast<Mul *>(this->getDescri());
    return value->mul(other->getDescri());
}

ValueDescriptor* ReferenceValue::div(ValueDescriptor *other){
    auto value = dynamic_cast<Div *>(this->getDescri());
    return value->div(other->getDescri());
}


ValueDescriptor* ReferenceValue::equal(ValueDescriptor *other){
    auto value = dynamic_cast<Equal *>(this->getDescri());
    return value->equal(other->getDescri());
}


ValueDescriptor* ReferenceValue::notEqual(ValueDescriptor *other){
    auto value = dynamic_cast<NotEqual *>(this->getDescri());
    return value->notEqual(other->getDescri());
}

ValueDescriptor* ReferenceValue::andOpr(ValueDescriptor *other){
    auto value = dynamic_cast<AndOper *>(this->getDescri());
    return value->andOpr(other->getDescri());
}

ValueDescriptor* ReferenceValue::orOpr(ValueDescriptor *other){
    auto value = dynamic_cast<OrOper *>(this->getDescri());
    return value->orOpr(other->getDescri());
}


ValueDescriptor* ReferenceValue::notFunc(){
    auto value = dynamic_cast<Not *>(this->getDescri());
    return value->notFunc();
}


ValueDescriptor* ReferenceValue::lesserOrEqual(ValueDescriptor *other){
    auto value = dynamic_cast<LesserOrEqual *>(this->getDescri());
    return value->lesserOrEqual(other->getDescri());
}

ValueDescriptor* ReferenceValue::lesserThan(ValueDescriptor *other){
    auto value = dynamic_cast<LesserThan *>(this->getDescri());
    return value->lesserThan(other->getDescri());
}

ValueDescriptor* ReferenceValue::greaterOrEqual(ValueDescriptor *other){
    auto value = dynamic_cast<GreaterOrEqual *>(this->getDescri());
    return value->greaterOrEqual(other->getDescri());
}

ValueDescriptor* ReferenceValue::greaterThan(ValueDescriptor *other){
    auto value = dynamic_cast<GreaterThan *>(this->getDescri());
    return value->greaterThan(other->getDescri());
}

ValueDescriptor* ReferenceValue::increaseOne(){
    auto value = dynamic_cast<IncreaseOne *>(this->getDescri());
    return value->increaseOne();
}

ValueDescriptor* ReferenceValue::decreaseOne(){
    auto value = dynamic_cast<DecreaseOne *>(this->getDescri());
    return value->decreaseOne();
}

ValueDescriptor* ReferenceValue::modulo(ValueDescriptor *other){
    auto value = dynamic_cast<Modulo *>(this->getDescri());
    return value->modulo(other->getDescri());
}

ValueDescriptor* ReferenceValue::posValue(){
    auto value = dynamic_cast<PosValue *>(this->getDescri());
    return value->posValue();
}


ValueDescriptor* ReferenceValue::negValue(){
    auto value = dynamic_cast<NegValue *>(this->getDescri());
    return value->negValue();
}

ManyValues::ManyValues(std::vector<ValueDescriptor *> manyValues): manyValues{manyValues}{

}

ManyValues::~ManyValues(){
    for(auto vals: manyValues){
        delete vals;
    }
}

std::vector<ValueDescriptor *> ManyValues::getValues(){
    return manyValues;
}

bool ManyValues::manyVals(){
    return true;
}
