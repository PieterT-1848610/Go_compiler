#include "asb.hpp"

class IntType: public Type{
    public:
        virtual ~IntType() override = default;
        IntType() = default;

};

class BooleanType: public Type{
    public:
        virtual ~BooleanType() override = default;
        BooleanType() = default;
};


class FloatType: public Type{
    public:
        virtual ~FloatType() override = default;
        FloatType() = default;
};

class CharType: public Type{
    public:
        virtual ~CharType() override = default;
        CharType() = default;
};