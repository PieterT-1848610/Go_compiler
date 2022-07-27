#ifndef VALUEDESCRIPTOR_VALUE_HPP
#define VALUEDESCRIPTOR_VALUE_HPP

#include <string>
#include <vector>
#include <utility>
#include <functional>

class ValueDescriptor{

    public:
        virtual ~ValueDescriptor()= default;
        //virtual ValueDescriptor * getDescri();

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

//na kijken of long long moet zijn (64bit of 32 bit)
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
        FunctionValue(std::function<void ()> func);
        ~FunctionValue() = default;

        void execute();
    private:
        std::function <void ()> func;     //wat de code uitvoert
        

};

#endif