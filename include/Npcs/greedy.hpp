#ifndef GREEDY_H
#define GREEDY_H

#include "../npc.hpp"
#include <iostream>

class Greedy: public Npc{

    public:

    Greedy(std::string file);

    ~Greedy();

    virtual void rebootTurner() override;

    virtual Attack* chooseAttack() override;
    
};
#endif