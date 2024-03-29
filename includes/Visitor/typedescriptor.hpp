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
    manyType,
};

//reference value firstr all op true


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
        BoolTypeDesc() = default;
        bool compare (const TypeDescriptor &other) const override;  
        std::string toString() const override;       
        TypeCode getCode() const override;          

};

class IntTypeDesc: public TypeDescriptor{
    public:
        IntTypeDesc() = default;
        bool compare(const TypeDescriptor &other) const override;
        std::string toString() const override;
        TypeCode getCode() const override;

};

class FloatTypeDesc: public TypeDescriptor{
    public:
        FloatTypeDesc() = default;
        bool compare(const TypeDescriptor &other) const override;
        std::string toString() const override;
        TypeCode getCode() const override;

};

class CharTypeDesc: public TypeDescriptor{
    public:
        CharTypeDesc() = default;
        bool compare(const TypeDescriptor &other) const override;
        std::string toString() const override;
        TypeCode getCode() const override;

};

//Try to solve multi return
class ManyTypeDesc: public TypeDescriptor{
    public:
        ManyTypeDesc(std::vector<TypeDescriptor *> allTypes);
        ~ManyTypeDesc() override;
        bool compare(const TypeDescriptor &other) const override;

        std::string toString() const override;
        TypeCode getCode() const override; 
        std::vector<TypeDescriptor *> getTypes() const;
    private:
        std::vector<TypeDescriptor *> allTypes;
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

        bool compareType(const TypeDescriptor &other) const;

        std::vector<std::string> getParametersIds();
        std::vector<TypeDescriptor *> getParametersTypeDesc();

        std::vector<std::string> getReturnsIds();
        std::vector<TypeDescriptor *> getReturnsTypeDesc();

        std::vector<std::pair<std::string, TypeDescriptor *>> getParams();
        std::vector<std::pair<std::string, TypeDescriptor *>> getReturns();

    private:
        std::vector<std::pair<std::string, TypeDescriptor *>> parameters;
        std::vector<std::pair<std::string, TypeDescriptor *>> returns;
};
//functionType
//vector parameters pair
//vector returns    pair


//float and char


#endif
