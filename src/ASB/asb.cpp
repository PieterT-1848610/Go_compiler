#include "ASB/asb.hpp"

ASB::Block::Block(std::vector<Statment *> statments):statments{statments}{

};

ASB::Block::~Block(){
    for(int i=0; i<statments.size(); i++){
        delete statments[i];
    }
};

ASB::Root::Root(std::vector<TopDeclaration *> declartions): declarations{declarations}{

};

ASB::Root::~Root(){
    for(int i = 0; i<declarations.size(); i++){
        delete declarations[i];
    }
};

