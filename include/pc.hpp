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
            int defense,
            std::list<Effect*>& effect,
            std::list<Attack*>& hit  );

        ~Pc();

        Attack* getHit(int id) override;

        int doHit(Entity& enemy, Attack* hit) override;


};
#endif