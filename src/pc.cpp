#include "pc.hpp"

#include <iostream>
#include <list>

    Pc::Pc( std::string name,
            int life,
            int defense,
            std::list<Effect*>& effect,
            std::list<Attack*>& hit  ):
            Entity(name,life,defense,effect),
            _hit(hit){}

    Pc::~Pc(){

        std::list<Effect*>::iterator ite = _effect.begin();

        for(ite ;ite != _effect.end(); ite++){
            delete *ite;
            _effect.erase(ite);
        }

        std::list<Attack*>::iterator ita = _hit.begin();

        for(ita ;ita != _hit.end(); ita++){
            delete *ita;
            _hit.erase(ita);
        }

    }

    Attack* Pc::getHit(int id){

        std::list<Attack*>::iterator it = _hit.begin();

        for(int i=0;i<id;i++) it++;

        return *it;

    }