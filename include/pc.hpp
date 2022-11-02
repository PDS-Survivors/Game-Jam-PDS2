#ifndef PC_H
#define PC_H

#include <iostream>
#include <list>

#include "entity.hpp"
#include "attack.hpp"

class Pc: public Entity{

    private:

        std::list<Attack*> _hit;

    public:

        Pc( std::string name,
            int life,
            int defense );

        virtual ~Pc() override;

        Attack* getHit(int id) override;
        
        Attack* chooseAttack() override;
        
        void addHit(Attack* attack);

        void showHit();

};
#endif