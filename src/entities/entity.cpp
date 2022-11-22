#include "entity.hpp"

#include <iostream>
#include <list>

   

    Entity::Entity( std::string name,
                    int life,
                    int defense):
                    _name(name),
                    _life(life),
                    _total_life(life),
                    _defense(defense){}

    Entity::Entity(){}
    
    Entity::~Entity(){}

    int Entity::getLife(){
        return _life;
    }
    
    int Entity::rebootLife(){
        return _life = _total_life;
    }

    int Entity::rebootStamina(int value){
        return _stamina += value;
    }

    void Entity::setStamina(int stamina){
        _stamina += stamina;
    }

    int Entity::getStamina(){
        return _stamina;
    }

    //função pra mudar a vida de uma entidade.
    //a função de ataque já faz os cálculos para determinar o quanto de dano o personagem sofreu
    //este set serve apenas para a entity receber a vida alterada.
    int Entity::setLife(int life){

        if(life < 0) life = 0;

        return _life = life;
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

    int Entity::sizeofEffect(){
        return _effect.size();
    }

    void Entity::addEffect(Effect* effect){

        _effect.push_back(effect);

    }

    void Entity::delEffect(Effect* effect){

        std::list<Effect*>::iterator it;

        for(it= _effect.begin(); it!=_effect.end() ; it++)
            if(*it == effect) break;


        //primeiro ele deleta o efeito e depois remove o efeito vazio da lista.
        _effect.erase(it);
        
    }

    void Entity::applyEffect(char type, int& target){

        if(this->sizeofEffect() == 0) return;

        bool ok = true;
        while(ok){
            
            if(_effect.empty()) break;
            for(Effect* e : _effect){
                ok = false;
                if(e->getType() == type){
                    
                    target += e->getValue();

                    if(e->checkDurability()){
                        delEffect(e);
                        ok = true;
                        break;
                    }
                }
            }

        }  
    }

    int Entity::doHit(Entity* enemy, Attack* hit){

        if(hit->getStamina() > this->getStamina())
            return -1;


        read::wait(1);
        showAction(hit);
        
        if(hit->isDefense()){

            std::vector<Effect*> effect;

            hit->Harvest(effect);


        //adicionando os efeitos vindos da defesa na lista de efeitos da entidade atacante
        //e depois deletando esse vetor temporário.
        for(Effect* e : effect)
            this->addEffect(e);

        while(!effect.empty())
            effect.pop_back();

        return 0;
        }
        
        int newLife = enemy->getLife();

        int defense = enemy->getDefense();
        
        int extradamage = 0;
        
        
        //busca os efeitos de defesa para alterar defense do atacado.
        enemy->applyEffect('d', defense);
        
        //busca os efeitos de dano para incrementar o dano extra do atacante.
        this->applyEffect('h', extradamage);
        
        //criando um vetor de effect para passar os efeitos do ataque para o atacado.
        std::vector<Effect*> effect;

        
        //aqui o ataque faz todo o cálculo da nova vida.
        newLife = hit->doAction(newLife, defense, extradamage, effect);
        //gasta a stamina da entidade
        this->setStamina(-1 * hit->getStamina());
        
        

        //adicionando os efeitos vindos do ataque na lista de efeitos da entidade
        //e depois deletando esses esse vetor temporário.
        for(Effect* e : effect){
            
            enemy->addEffect(e);
        }
        

        while(!effect.empty())
            effect.pop_back();
        

        //busca efeitos de vida para altera a do atacado apenas após o golpe de fato acontecer.
        enemy->applyEffect('l', newLife);

        //altera finalmente a vida da entidade atacada.
        return enemy->setLife(newLife);
    }

    int Entity::sizeofHit(){
        return 0;
    }

    std::string Entity::getBehavior(){
        return "";
    }

    void Entity::showAction(Attack* hit){}


    