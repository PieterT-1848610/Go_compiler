#ifndef TYPEDESCRIPTOR_HPP
#define TYPEDESCRIPTOR_HPP

#include <string>

//mogelijk toevoeging float, char
enum class TypeCode{
    bool,
    int,
};


class TypeDescriptor{

    public:
        virtual ~TypeDescriptor() = default;
        virtual bool compare(const TypeDescriptor *other) const = 0;
        virtual std::string toString() const = 0;
        virtual TypeCode getCode() const = 0;
    protected:
        TypeDescriptor() = default; 

};

class BoolTypeDesc: public TypeDescriptor{
    public:
        bool compare (const TypeDescriptor *other) const override;  //if equal to other.getcode()
        std::string toString() const override;       //return bool as string
        TypeCode getCode() const override;          //return typeCode::bool

};

class IntTypeDesc: public TypeDescriptor{
    public:
        bool compare(const TypeDescriptor *other) const override;
        std::string toString() const override;
        TypeCode getCode() const override;

};
//functionType
//vector parameters pair
//vector returns    pair


//float and char


#endif