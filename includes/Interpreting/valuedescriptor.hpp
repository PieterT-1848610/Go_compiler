#ifndef VALUEDESCRIPTOR_VALUE_HPP
#define VALUEDESCRIPTOR_VALUE_HPP

#include <string>
#include <vector>
#include <utility>

class ValueDescriptor{

    public:
        virtual ~ValueDescriptor()= default;
        virtual ValueDescriptor * getDescri();

    protected:
        ValueDescriptor() = default;
};

class BoolValue: public ValueDescriptor{
    public:
        BoolValue(bool value);
        ~BoolValue() = default;
        bool getValue();

    private:
        bool value;
};


class IntValue: public ValueDescriptor{
    public:
        IntValue(long value);
        ~IntValue() = default;
        long getValue();

    private:
        long value;
};

class FloatValue: public ValueDescriptor{
    public:
        FloatValue(float value);
        ~FloatValue() = default;
        float getValue();

    private:
        float value; 
};

class CharValue: public ValueDescriptor{
    public:
        CharValue(char value);
        ~CharValue() = default;

        char getValue();
    private:
        char value;
};

//class FunctionValue
//TODO: needs work, parameters, body, rest
class FunctionValue: public ValueDescriptor{
    public:
        FunctionValue();
        ~FunctionValue() = default;

        //ValueDescriptor* execute(std::vector<ValueDescriptor *> paramValues);
    private:

        

};

#endif