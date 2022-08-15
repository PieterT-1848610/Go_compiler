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
        virtual bool manyVals();
    protected:
        ValueDescriptor() = default;
};

class BoolValue: public ValueDescriptor, public Equal, public Not, public AndOper, public OrOper, public NotEqual{
    public:
        BoolValue(bool value);
        ~BoolValue() = default;
        bool getValue();

        ValueDescriptor* equal(ValueDescriptor *other) override;
        ValueDescriptor* notFunc() override;

        ValueDescriptor* notEqual(ValueDescriptor *other) override;
        ValueDescriptor* andOpr(ValueDescriptor *other) override;
        ValueDescriptor* orOpr(ValueDescriptor *other) override;

    private:
        bool value;
};

//na kijken of long long moet zijn (64bit of 32 bit)
class IntValue: public ValueDescriptor, public Add, public Equal, public Min, public LesserOrEqual, public LesserThan, 
                public GreaterOrEqual, public GreaterThan, public Mul, public Div, public NotEqual, public IncreaseOne,
                public DecreaseOne, public Modulo, public PosValue, public NegValue{
    public:
        IntValue(long value);
        ~IntValue() = default;
        long getValue();

        ValueDescriptor* add(ValueDescriptor *other) override;
        ValueDescriptor* min(ValueDescriptor *other) override;
        ValueDescriptor* mul(ValueDescriptor *other) override;
        ValueDescriptor* div(ValueDescriptor *other) override;


        ValueDescriptor* equal(ValueDescriptor *other) override;
        ValueDescriptor* notEqual(ValueDescriptor *other) override;


        ValueDescriptor* lesserOrEqual(ValueDescriptor *other) override;
        ValueDescriptor* lesserThan(ValueDescriptor *other) override;

        ValueDescriptor* greaterOrEqual(ValueDescriptor *other) override;
        ValueDescriptor* greaterThan(ValueDescriptor *other) override;

        ValueDescriptor* increaseOne() override;
        ValueDescriptor* decreaseOne() override;

        ValueDescriptor* modulo(ValueDescriptor *other) override;
        ValueDescriptor* posValue() override;
        ValueDescriptor* negValue() override;


    private:
        long value;
};

class FloatValue: public ValueDescriptor, public Add, public Equal, public Min, public LesserOrEqual, public LesserThan, 
                    public GreaterOrEqual, public GreaterThan, public Mul, public Div, public NotEqual, public IncreaseOne,
                    public DecreaseOne, public PosValue, public NegValue{
    public:
        FloatValue(float value);
        ~FloatValue() = default;
        float getValue();

        ValueDescriptor* add(ValueDescriptor *other) override;
        ValueDescriptor* min(ValueDescriptor *other) override;
        ValueDescriptor* mul(ValueDescriptor *other) override;
        ValueDescriptor* div(ValueDescriptor *other) override;


        ValueDescriptor* equal(ValueDescriptor *other) override;
        ValueDescriptor* notEqual(ValueDescriptor *other) override;

        ValueDescriptor* lesserOrEqual(ValueDescriptor *other) override;
        ValueDescriptor* lesserThan(ValueDescriptor *other) override;

        ValueDescriptor* greaterOrEqual(ValueDescriptor *other) override;
        ValueDescriptor* greaterThan(ValueDescriptor *other) override;

        ValueDescriptor* increaseOne() override;
        ValueDescriptor* decreaseOne() override;

        ValueDescriptor* posValue() override;
        ValueDescriptor* negValue() override;

    private:
        float value; 
};

class CharValue: public ValueDescriptor, public Equal, public NotEqual{
    public:
        CharValue(char value);
        ~CharValue() = default;

        char getValue();
        ValueDescriptor* equal(ValueDescriptor *other) override;
        ValueDescriptor* notEqual(ValueDescriptor *other) override;

    private:
        char value;
};

//class FunctionValue
class FunctionValue: public ValueDescriptor{
    public:
        FunctionValue(std::function<void ()> func);
        ~FunctionValue() = default;

        void execute();
    private:
        std::function <void ()> func;     //wat de code uitvoert
};

class ReferenceValue: public ValueDescriptor, public Add, public Equal, public Min, public LesserOrEqual, 
                    public Not, public LesserThan, public GreaterOrEqual, public GreaterThan, public Mul,
                    public Div, public AndOper, public OrOper, public NotEqual,  public IncreaseOne,
                    public DecreaseOne, public Modulo, public PosValue, public NegValue{
    public:
        ReferenceValue(std::function<ValueDescriptor * ()> getter, std::function<void (ValueDescriptor *)> setter);
        ~ReferenceValue() = default;

        ValueDescriptor * getDescri() override;
        void setValue(ValueDescriptor* valueDescr);


        ValueDescriptor* add(ValueDescriptor *other) override;
        ValueDescriptor* min(ValueDescriptor *other) override;
        ValueDescriptor* mul(ValueDescriptor *other) override;
        ValueDescriptor* div(ValueDescriptor *other) override;



        ValueDescriptor* equal(ValueDescriptor* other) override;
        ValueDescriptor* notFunc() override;

        ValueDescriptor* notEqual(ValueDescriptor *other) override;
        ValueDescriptor* andOpr(ValueDescriptor *other) override;
        ValueDescriptor* orOpr(ValueDescriptor *other) override;


        ValueDescriptor* lesserOrEqual(ValueDescriptor *other) override;
        ValueDescriptor* lesserThan(ValueDescriptor *other) override;

        ValueDescriptor* greaterOrEqual(ValueDescriptor *other) override;
        ValueDescriptor* greaterThan(ValueDescriptor *other) override;


        ValueDescriptor* increaseOne() override;
        ValueDescriptor* decreaseOne() override;

        ValueDescriptor* modulo(ValueDescriptor *other) override;
        ValueDescriptor* posValue() override;
        ValueDescriptor* negValue() override;

    private:
        std::function<ValueDescriptor * ()> getter;
        std::function<void (ValueDescriptor *)> setter;
    
};

class ManyValues: public ValueDescriptor{
    public:
        ManyValues(std::vector<ValueDescriptor *> manyValues);
        ~ManyValues();

        std::vector<ValueDescriptor *> getValues();
        bool manyVals() override;

        
    private:
        std::vector<ValueDescriptor *> manyValues;
};

#endif
