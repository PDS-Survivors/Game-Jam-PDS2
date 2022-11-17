#ifndef BERSERKER_H
#define BERSERKER_H

#include "../npc.hpp"
#include <iostream>

class Berserker: public Npc{

    public:

    Berserker(std::string file);

    ~Berserker();

    virtual void rebootTurner() override;

    virtual Attack* chooseAttack() override;
    
};
#endif