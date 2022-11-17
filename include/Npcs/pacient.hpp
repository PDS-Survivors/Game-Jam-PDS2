#ifndef PACIENT_H
#define PACIENT_H

#include "../npc.hpp"
#include <iostream>

class Pacient: public Npc{

    public:

    Pacient(std::string file);

    ~Pacient();

    virtual void rebootTurner() override;

    virtual Attack* chooseAttack() override;
    
};
#endif