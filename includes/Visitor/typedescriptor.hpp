#ifndef TYPEDESCRIPTOR_HPP
#define TYPEDESCRIPTOR_HPP

#include <string>
#include <vector>
#include <utility>

//mogelijk toevoeging float, char
enum class TypeCode{
    booleanType,
    integerType,
    floatType,
    charType,
    functionType,
};


class TypeDescriptor{

    public:
        virtual ~TypeDescriptor() = default;
        virtual bool compare(const TypeDescriptor &other) const = 0;
        virtual std::string toString() const = 0;
        virtual TypeCode getCode() const = 0;
    protected:
        TypeDescriptor() = default; 

};

class BoolTypeDesc: public TypeDescriptor{
    public:
        bool compare (const TypeDescriptor &other) const override;  //if equal to other.getcode()
        std::string toString() const override;       //return bool as string
        TypeCode getCode() const override;          //return typeCode::bool

};

class IntTypeDesc: public TypeDescriptor{
    public:
        bool compare(const TypeDescriptor &other) const override;
        std::string toString() const override;
        TypeCode getCode() const override;

};

class FloatTypeDesc: public TypeDescriptor{
    public:
        bool compare(const TypeDescriptor &other) const override;
        std::string toString() const override;
        TypeCode getCode() const override;

};

class CharTypeDesc: public TypeDescriptor{
    public:
        bool compare(const TypeDescriptor &other) const override;
        std::string toString() const override;
        TypeCode getCode() const override;

};



//? constructor
class FunctionTypeDesc: public TypeDescriptor{
    public:
        FunctionTypeDesc(std::vector<std::pair<std::string, TypeDescriptor *>> parameters,
                std::vector<std::pair<std::string, TypeDescriptor *>> returns);
        ~FunctionTypeDesc() override;

        bool compare(const TypeDescriptor &other) const override;


        std::string toString() const override;
        TypeCode getCode() const override;

        std::vector<std::string> getParametersIds();
        std::vector<TypeDescriptor *> getParametersTypeDesc();

        std::vector<std::string> getReturnsIds();
        std::vector<TypeDescriptor *> getReturnsTypeDesc();

    private:
        std::vector<std::pair<std::string, TypeDescriptor *>> parameters;
        std::vector<std::pair<std::string, TypeDescriptor *>> returns;
};
//functionType
//vector parameters pair
//vector returns    pair


//float and char


#endif