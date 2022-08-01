#ifndef INTERPRETOPRAND_OPERAND_HPP
#define INTERPRETOPRAND_OPERAND_HPP

class ValueDescriptor;

class Add {
    public:
        virtual ValueDescriptor* add(ValueDescriptor *other) = 0;
};

class Equal {
    public:
        virtual ValueDescriptor* equal(ValueDescriptor *ohter) = 0;
};

class Min {
    public:
        virtual ValueDescriptor* min(ValueDescriptor *other) = 0;
};

class LesserOrEqual{
    public:
            virtual ValueDescriptor* lesserOrEqual(ValueDescriptor *other) = 0;
};

class Not{
    public:
        virtual ValueDescriptor* notFunc() = 0;
};

#endif