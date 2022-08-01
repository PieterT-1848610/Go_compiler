#ifndef VALUEDESCRIPTOR_VALUE_HPP
#define VALUEDESCRIPTOR_VALUE_HPP

#include "Interpreting/interpretoperand.hpp"

#include <string>
#include <vector>
#include <utility>
#include <functional>

class ValueDescriptor{

    public:
        virtual ~ValueDescriptor()= default;
        virtual ValueDescriptor * getDescri();

    protected:
        ValueDescriptor() = default;
};

class BoolValue: public ValueDescriptor, public Equal{
    public:
        BoolValue(bool value);
        ~BoolValue() = default;
        bool getValue();

        ValueDescriptor* equal(ValueDescriptor *other) override;

    private:
        bool value;
};

//na kijken of long long moet zijn (64bit of 32 bit)
class IntValue: public ValueDescriptor, public Add, public Equal, public Min, public LesserOrEqual{
    public:
        IntValue(long value);
        ~IntValue() = default;
        long getValue();

        ValueDescriptor* add(ValueDescriptor *other) override;
        ValueDescriptor* equal(ValueDescriptor *other) override;
        ValueDescriptor* min(ValueDescriptor *other) override;
        ValueDescriptor* lesserOrEqual(ValueDescriptor *other) override;

    private:
        long value;
};

class FloatValue: public ValueDescriptor, public Add, public Equal, public Min, public LesserOrEqual{
    public:
        FloatValue(float value);
        ~FloatValue() = default;
        float getValue();

        ValueDescriptor* add(ValueDescriptor *other) override;
        ValueDescriptor* equal(ValueDescriptor *other) override;
        ValueDescriptor* min(ValueDescriptor *other) override;
        ValueDescriptor* lesserOrEqual(ValueDescriptor *other) override;



    private:
        float value; 
};

class CharValue: public ValueDescriptor, public Equal{
    public:
        CharValue(char value);
        ~CharValue() = default;

        char getValue();
        ValueDescriptor* equal(ValueDescriptor *other) override;

    private:
        char value;
};

//class FunctionValue
//TODO: needs work, parameters, body, rest
class FunctionValue: public ValueDescriptor{
    public:
        FunctionValue(std::function<void ()> func);
        ~FunctionValue() = default;

        void execute();
    private:
        std::function <void ()> func;     //wat de code uitvoert
};

class ReferenceValue: public ValueDescriptor, public Add, public Equal, public Min, public LesserOrEqual{
    public:
        ReferenceValue(std::function<ValueDescriptor * ()> getter, std::function<void (ValueDescriptor *)> setter);
        ~ReferenceValue() = default;

        ValueDescriptor * getDescri() override;
        void setValue(ValueDescriptor* valueDescr);


        ValueDescriptor* add(ValueDescriptor *other) override;
        ValueDescriptor* equal(ValueDescriptor* other) override;
        ValueDescriptor* min(ValueDescriptor *other) override;
        ValueDescriptor* lesserOrEqual(ValueDescriptor *other) override;


    private:
        std::function<ValueDescriptor * ()> getter;
        std::function<void (ValueDescriptor *)> setter;
    
};

#endif