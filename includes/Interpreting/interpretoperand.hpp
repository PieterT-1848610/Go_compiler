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

#endif