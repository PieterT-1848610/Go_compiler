#ifndef ASB_BASE_HPP
#define ASB_BASE_HPP
//File voor de tree mee op te bouwen


#include <vector>
#include <string>

template <typename T>
//good way like the interpret thing in exp 1
class TypeEntryTable{
    public:
        TypeEntryTable(std::string, T value): name(std::move(name)), type(value){}

        std::string getName(){
             return name;
         }
        
        void setType(T newType){
            type = newType;
        }

        T getType() const{
            return type;
        }

    private:
        std::string name;
        T type;

};
template <typename T>

class TypeTable{
    public:
        T get(const std::string &identifier){
            for(auto item:list){
                if(item.getName() == identifier){
                    return item.getvalue();
                }
            }
            return nullptr;
        }

        

        void update(const std::string& identifier, T type){
            for(auto item: list){
                if(item.getName() == identifier){
                    item.setType(type);
                    return;
                }
            }

            TypeEntryTable<T> entry = *new TypeEntryTable<T>(identifier, type);
            list.insert(list.begin(), entry);
        }


    private:
        std::vector<TypeEntryTable<T>> list;

};

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

//template <typename T>

//Root of program
class Root: public Node{
    public:
        Root(std::vector<TopDeclaration *> declarations);
        virtual ~Root();

       // void typechecking(TypeTable<T> *table);

    protected:
        std::vector<TopDeclaration *> declarations;

};
}

#endif