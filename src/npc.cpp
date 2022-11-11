#include "npc.hpp"

#include <iostream>
#include <vector>

    Npc::Npc( std::string name,
              int life,
              int defense,
              std::string description):
              Entity(name,life,defense), _description(description){}

    Npc::~Npc(){

        std::list<Effect*>::iterator ite;

        for(ite  = _effect.begin();ite != _effect.end(); ite++){
            delete[] *ite;
            _effect.erase(ite);

            
        }

        for(Attack* a : _hit){
            delete[] a;
        }

    }

    void Npc::addAttack(Attack* attack){
        _hit.push_back(attack);
    }


    Attack* Npc::getHit(int id){
        return _hit[id];
    }

    Attack* Npc::chooseAttack(){
        return this->getHit(0);
    }