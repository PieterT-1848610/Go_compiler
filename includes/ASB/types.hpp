#ifndef ASB_TYPES_HPP
#define ASB_TYPES_HPP

#include "asb.hpp"
#include <string>
namespace ASB
{
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

class FunctionType: public Type{
    public:
        FunctionType(
            std::vector<std::pair<std::string, Type *>>parameters,
            std::vector<std::pair<std::string, Type *>>results);

        virtual ~FunctionType() override = default;    
    private:
        std::vector<std::pair<std::string, Type *>> parameters;
        std::vector<std::pair<std::string, Type *>> results;
};

} // namespace ASB

#endif