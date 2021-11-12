#ifndef ASB_BASE_HPP
#define ASB_BASE_HPP
//File voor de tree mee op te bouwen


#include <vector>
namespace ASB{
//Base Node class
class Node{
    public:
        virtual ~Node() = default;
    
    protected:
            Node() = default;
        
};


//Statment
class Statment: public Node{
    public:
        virtual ~Statment() = default;

    protected:
        Statment() = default;
};

class SimpleStatment:  public Statment{
    public:
        virtual ~SimpleStatment() = default;
    
    protected:
        SimpleStatment() = default;
};


//Expression
class Expression: public Node{
    public:
        virtual ~Expression() = default;

    protected:
        Expression() = default;
};


//Types
class Type: public Node{
    public:
        virtual ~Type() = default;
        
    protected:
        Type() = default;
};


//Declaration
class TopDeclaration: public Node{
    public:
        virtual ~TopDeclaration() = default;
    
    protected:
        TopDeclaration() = default;
    
};

class Declaration: public TopDeclaration{
    public:
        virtual ~Declaration() = default;
    
    protected:
        Declaration() = default;
    
};

//Base class voor Block bevat ook lijst van staments
class Block: public Node{
    public:
        Block(std::vector<Statment *> statments);
        virtual ~Block();

    protected:
        std::vector<Statment * > statments; 
        
};


//Root of program
class Root: public Node{
    public:
        Root(std::vector<TopDeclaration *> declarations);
        virtual ~Root();

    protected:
        std::vector<TopDeclaration *> declarations;

};
}

#endif