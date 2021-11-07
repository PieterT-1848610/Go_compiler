#include "ASB/asb.hpp"

Block::Block(std::vector<Statment *> statments):statments{statments}{

};

Block::~Block(){
    for(int i=0; i<statments.size(); i++){
        delete statments[i];
    }
};

Root::Root(std::vector<TopDeclaration *> declartions): declarations{declarations}{

};

Root::~Root(){
    for(int i = 0; i<declarations.size(); i++){
        delete declarations[i];
    }
};

