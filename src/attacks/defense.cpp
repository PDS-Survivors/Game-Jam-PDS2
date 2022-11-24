#include "defense.hpp"

#include <iostream>
#include <vector>

    Defense::Defense(std::string file): Attack(file){}

    Defense::~Defense(){ 
           // deleta os ponteiros na heap primeiro.
        for(Effect* e : _effects)
            delete[] e;

        // como o vector está com ponteiros nulos, esvazia o vetor _effects.
        while(!_effects.empty())
            _effects.pop_back();

    }
    
    bool Defense::isDefense(){
        return true;
    }

    void Defense::Harvest(std::vector<Effect*>& effect){

        if(this->sizeofEffects() != 0){

            //clona todos os efeitos do ataque e os coloca em um vetor.
            for(int i=0; i<this->sizeofEffects() ;i++)
                effect.push_back(_effects[i]->cloneEffect());
                
        }
    }