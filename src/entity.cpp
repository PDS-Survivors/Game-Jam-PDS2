#include "entity.hpp"

#include <iostream>
#include <list>


    Entity::Entity( std::string name,
                    int life,
                    int defense,
                    std::list<Effect*>& effect):
                    _name(name),
                    _life(life),
                    _defense(defense),
                    _effect(effect){}

    Entity::~Entity(){

        std::list<Effect*>::iterator ite = _effect.begin();

        for(ite ;ite != _effect.end(); ite++){
            delete *ite;
            _effect.erase(ite);
        }

    }
    int Entity::getLife(){
        return _life;
    }

    //função pra mudar a vida de uma entidade.
    //a função de ataque já faz os cálculos para determinar o quanto de dano o personagem sofreu
    //este set serve apenas para a entity receber a vida alterada.
    int Entity::setLife(int life){
        
        _life = life;
    }

    int Entity::getDefense(){
        return _defense;
    }

    std::string Entity::getName(){
        return _name;
    }

    Effect* Entity::getEffect(int id){

        std::list<Effect*>::iterator it = _effect.begin();

        for(int i=0;i<id;i++) it++;

        return *it;
    }

    void Entity::addEffect(Effect* effect){

        _effect.push_back(effect);

    }

    void Entity::delEffect(Effect* effect){

        std::list<Effect*>::iterator it = _effect.begin();

        for(it; it!=_effect.end() ; it++)
            if(*it == effect) break;

        delete effect;
        _effect.erase(it);

    }



    