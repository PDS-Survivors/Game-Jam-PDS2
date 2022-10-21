#include "npc.hpp"

#include <iostream>
#include <vector>

    Npc::Npc( std::string name,
              int life,
              int defense,
              std::list<Effect*>& effect,
              std::vector<Attack*>& hit ):
              Entity(name,life,defense,effect),
              _hit(hit){}

    Attack* Npc::getHit(int id){
        return _hit[id];
    }

