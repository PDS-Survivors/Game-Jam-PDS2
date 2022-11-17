#ifndef TANK_H
#define TANK_H

#include "../npc.hpp"
#include <iostream>

class Tank: public Npc{

    public:

    Tank(std::string file);

    ~Tank();

    virtual void rebootTurner() override;

    virtual Attack* chooseAttack() override;
    
};
#endif