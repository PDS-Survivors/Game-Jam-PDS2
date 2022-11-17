#include "include/Npcs/Berserker.hpp"
#include <iostream>

    Berserker::Berserker(std::string file): Npc(file){ _turner = 1;}

    Berserker::~Berserker(){}

    void Berserker::rebootTurner(){

        if(_turner > 3) _turner = 1;
    }

    Attack* Berserker::chooseAttack(){

        switch(_turner){

            case 1:
                return this->getHit(0);

            break;

            case 2:
                return this->getHit(2);
                
            break;

            case 3:
                return this->getHit(3);
            
            break;

        }
    }