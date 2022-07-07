#ifndef ASB_TYPES_HPP
#define ASB_TYPES_HPP

#include "asb.hpp"
#include <string>

//accept in equals alle types 

//leaf voor visitor
// virtual void accept(Visitor *visitor) const  override;

namespace ASB
{
    class IntType : public Type
    {
    public:
        virtual ~IntType() override = default;
        virtual void accept(Visitor *visitor) const  override;

        IntType() = default;
    };

    class BooleanType : public Type
    {
    public:
        virtual ~BooleanType() override = default;
        BooleanType() = default;
        virtual void accept(Visitor *Visitor) const override;
    };

    class FloatType : public Type
    {
    public:
        virtual ~FloatType() override = default;
        FloatType() = default;
        virtual void accept(Visitor *Visitor) const override;

    };

    class CharType : public Type
    {
    public:
        virtual ~CharType() override = default;
        CharType() = default;
        virtual void accept(Visitor *Visitor) const override;

    };

    class FunctionType : public Type
    {
    public:
        FunctionType(
            std::vector<std::pair<std::string, Type *>> parameters,
            std::vector<std::pair<std::string, Type *>> results);

        virtual ~FunctionType() override;
        
        virtual void accept(Visitor *Visitor) const override;

    private:
        std::vector<std::pair<std::string, Type *>> parameters;
        std::vector<std::pair<std::string, Type *>> results;
    };

    class IdentifierType : public Type
    {
    public:
        IdentifierType(char *id);
        virtual ~IdentifierType() override = default;
        virtual void accept(Visitor *Visitor) const override;

    private:
        std::string id;
    };

} // namespace ASB

#endif