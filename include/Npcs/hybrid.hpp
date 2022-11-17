#ifndef HyBRID_H
#define HyBRID_H

#include "../npc.hpp"
#include <iostream>

class Hybrid: public Npc{

    public:

    Hybrid(std::string file);

    ~Hybrid();

    virtual void rebootTurner() override;

    virtual Attack* chooseAttack() override;
    
};
#endif