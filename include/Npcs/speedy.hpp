#ifndef SPEEDY_H
#define SPEEDY_H

#include "../npc.hpp"
#include <iostream>

class Speedy: public Npc{

    public:

    Speedy(std::string file);

    ~Speedy();

    virtual void rebootTurner() override;

    virtual Attack* chooseAttack() override;
    
};
#endif