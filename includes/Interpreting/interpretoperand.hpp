#ifndef INTERPRETOPRAND_OPERAND_HPP
#define INTERPRETOPRAND_OPERAND_HPP

class ValueDescriptor;

class Equal {
    public:
        virtual ValueDescriptor* equal(ValueDescriptor *ohter) = 0;
};

class NotEqual{
    public:
        virtual ValueDescriptor* notEqual(ValueDescriptor *other) = 0;
};

class AndOper{
    public:
        virtual ValueDescriptor* andOpr(ValueDescriptor *other) = 0;
};

class OrOper{
    public:
        virtual ValueDescriptor* orOpr(ValueDescriptor *other) = 0;
};

class Not{
    public:
        virtual ValueDescriptor* notFunc() = 0;
};

class Add {
    public:
        virtual ValueDescriptor* add(ValueDescriptor *other) = 0;
};

class Min {
    public:
        virtual ValueDescriptor* min(ValueDescriptor *other) = 0;
};

class Mul {
    public:
        virtual ValueDescriptor* mul(ValueDescriptor *other) = 0;
};

class Div {
    public:
        virtual ValueDescriptor* div(ValueDescriptor *other) = 0;
};

class LesserOrEqual{
    public:
        virtual ValueDescriptor* lesserOrEqual(ValueDescriptor *other) = 0;
};

class LesserThan{
    public:
        virtual ValueDescriptor* lesserThan(ValueDescriptor *other) = 0;
};

class GreaterOrEqual{
    public:
        virtual ValueDescriptor* greaterOrEqual(ValueDescriptor *other) = 0;
};

class GreaterThan{
    public:
        virtual ValueDescriptor* greaterThan(ValueDescriptor *other) = 0;
};

#endif