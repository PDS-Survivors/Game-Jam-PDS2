#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>

#include "entity.hpp"
#include "attack.hpp"

class Npc: public Entity{

    private:

        std::vector<Attack*> _hit;

    public:

        Npc( std::string name,
            int life,
            int defense,
            std::list<Effect*>& effect,
            std::vector<Attack*>& hit  );

        Attack* getHit(int id) override;

        int doHit(Entity& enemy, Attack* hit) override;


};
#endif