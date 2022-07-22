#ifndef ASB_BASE_HPP
#define ASB_BASE_HPP
//File voor de tree mee op te bouwen
#include "Visitor/Visitor.hpp"


#include <vector>
#include <string>
#include <iostream>


namespace ASB{
//Base Node class
class Node{
    public:
        virtual ~Node() = default;
        //past niks aan in boom en bij alle subnodes
        virtual void accept(Visitor *visitor) const = 0;
        void print(){};
    protected:
            Node() = default;
        
};


//Statment
class Statment: public Node{
    public:
        virtual ~Statment() = default;
        virtual void accept(Visitor *visitor) const  override = 0;

    protected:
        Statment() = default;
};

class SimpleStatment:  public Statment{
    public:
        virtual ~SimpleStatment() = default;
        virtual void accept(Visitor *visitor) const  override = 0;

    protected:
        SimpleStatment() = default;
};


//Expression
class Expression: public Node{
    public:
        virtual ~Expression() = default;
        virtual void accept(Visitor *visitor) const  override = 0;

    protected:
        Expression() = default;
};


//Types
//Function equals. compares to type
class Type: public Node{
    public:
        virtual ~Type() = default;
        virtual void accept(Visitor *visitor) const  override = 0;
       
    protected:
        Type() = default;
};


//Declaration
class TopDeclaration: public Node{
    public:
        virtual ~TopDeclaration() = default;
        virtual void accept(Visitor *visitor) const  override = 0;

    protected:
        TopDeclaration() = default;
    
};

class Declaration: public TopDeclaration{
    public:
        virtual ~Declaration() = default;
        virtual void accept(Visitor *visitor) const  override = 0;

    protected:
        Declaration() = default;
    
};

//Base class voor Block bevat ook lijst van staments
class Block: public Node{
    public:
        Block(std::vector<Statment *> statments);
        virtual ~Block();
        virtual void accept(Visitor *visitor) const  override;

    protected:
        std::vector<Statment * > statments; 
        
};

//template <typename T>

//Root of program
//is program so need visitor implementead
class Root: public Node{
    public:
        Root(std::vector<TopDeclaration *> declarations);
        virtual ~Root();
        void print() {
            for(auto a: declarations){
                std::cout<<a<<"testing";
            }
        }
        virtual void accept(Visitor *visitor) const  override;

    protected:
        std::vector<TopDeclaration *> declarations;

};
}

#endif