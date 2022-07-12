#include "ASB/asb.hpp"
#include <functional>


ASB::Block::Block(std::vector<Statment *> statments):statments{statments}{

};

ASB::Block::~Block(){
    for(int i=0; i<statments.size(); i++){
        delete statments[i];
    }
};

void ASB::Block::accept(Visitor *visitor) const{
    std::vector<std::function<void ()>> visitStatments{};
    for(auto stat: this->statments){
        visitStatments.push_back([stat, visitor](){
            stat->accept(visitor);
        });
    }
    visitor->block(visitStatments);
}

ASB::Root::Root(std::vector<TopDeclaration *> declarations): declarations{declarations}{

};

void ASB::Root::accept(Visitor *visitor) const{
    std::vector<std::function<void ()>> visitDeclarations{};
    for(auto declaration: this->declarations){
        visitDeclarations.push_back([declaration, visitor](){
            declaration->accept(visitor);
        });
    }

    visitor->root(visitDeclarations);
}


ASB::Root::~Root(){
    for(int i = 0; i<declarations.size(); i++){
        delete declarations[i];
    }
};

