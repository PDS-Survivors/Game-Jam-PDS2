#include "entity.hpp"

#include <iostream>
#include <list>


    Entity::Entity( std::string name,
                    int life,
                    int defense,
                    std::list<Effect*>& effect):
                    _name(name),
                    _life(life),
                    _total_life(life),
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
    
    int Entity::rebootLife(){
        return _life = _total_life;
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

        //primeiro ele deleta o efeito e depois remove o efeito vazio da lista.
        delete[] effect;
        _effect.erase(it);

    }

    void Entity::applyEffect(char type, int& target){

        for(Effect* e : _effect){

            if(e->getType() == type){

                target += e->getValue();

                if(e->checkDurability())
                    delEffect(e);

            }
        }
    }

    int Entity::doHit(Entity& enemy, Attack* hit){

        int newLife = _life;

        int defense = _defense;
        
        int extradamage = 0;

        std::vector<Effect*> effect;

        //busca os efeitos de defesa para alterar defense.
        enemy.applyEffect('d', defense);

        //busca os efeitos de dano para incrementar o dano extra.
        this->applyEffect('h', extradamage);

        //aqui o ataque faz todo o cálculo da nova vida.
        newLife = hit->doAction(newLife, defense, extradamage, effect);

        //adicionando os efeitos vindos do ataque na lista de efeitos da entidade
        //e depois deletando esses esse vetor temporário.
        for(Effect* e : effect){
            _effect.push_back(e);
            delete[] e;
        }
        
        while(!effect.empty())
            effect.pop_back();

        //busca efeitos de vida para altera-la apenas após o golpe de fato acontecer.
        this->applyEffect('l', newLife);

        //altera finalmente a vida da entidade.
        return setLife(newLife);
    }



    