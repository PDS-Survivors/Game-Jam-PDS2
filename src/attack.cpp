#include "attack.hpp"

#include <iostream>
#include <vector> 

    Attack::Attack( int damage,
                    int stamina,
                    std::string name,
                    std::string description,
                    std::vector<Effect*>& effects
                  ):
                  _damage(damage),
                  _stamina(stamina),
                  _name(name),
                  _description(description),
                  _effects(effects)
                  {}

    Attack::Attack( int damage,
                    int stamina,
                    std::string name,
                    std::string description 
                  ):
                  _damage(damage),
                  _stamina(stamina),
                  _name(name),
                  _description(description){}

    Attack::~Attack(){
        
        // deleta os ponteiros na heap primeiro.
        for(Effect* e : _effects)
            delete[] e;

        // como o vector está com ponteiros nulos, esvazia o vetor _effects.
        while(!_effects.empty())
            _effects.pop_back();

    }

    std::string Attack::getDescription(){
        return _description;
    }

    std::string Attack::getName(){
        return _name;
    }

    int Attack::getDamage(){
        return _damage;
    }

    int Attack::getStamina(){
        return _stamina;
    }

    int Attack::sizeofEffects(){
        return _effects.size();
    }
    Effect* Attack::getEffect(int id){

        return _effects[id];

    }

    int Attack::doAction(int life, int defense, int extradamage, std::vector<Effect*>& effect){
        
        
        if(this->sizeofEffects() != 0){

            //clona todos os efeitos do ataque e os coloca em um vetor.
            for(int i=0; i<this->sizeofEffects() ;i++)
                effect.push_back(_effects[i]->cloneEffect());
                
        }

        int damage = _damage + extradamage - defense;

        if(damage < 0) damage = 0;

        return (life -= damage);
    }

    void Attack::operator+= (Effect* const effect){
        _effects.push_back(effect);
    }

    void Attack::addEffect(Effect* effect){
        _effects.push_back(effect);
    }