#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <iostream>
#include <list>
#include "attack.hpp"
#include "effects/effect.hpp"

    class Entity{

        protected:

        std::string _name;
        int _life;
        int _total_life;
        int _defense;
        int _stamina;
        std::list<Effect*> _effect;

        public:

            Entity( std::string name,
                    int life,
                    int defense);
            
             virtual ~Entity() = 0;
            
            int getLife();

            //função pra resetar a vida da entidade a quatidade máxima.
            int rebootLife();

            //reseta a estamina após o turno.
            int rebootStamina(int value = 5);

            int getStamina();

            int setLife(int life);

            int getDefense();

            std::string getName();

            Effect* getEffect(int id);

            int sizeofEffect();
            
            void addEffect(Effect* effect);
            
            void delEffect(Effect* effect);

            //aplica todos os efeitos de determinado tipo de efeito.
            void applyEffect(char type, int& target);

            //função utilizada internamente para defesa. retorna o valor
            //que a entidade vai usar para defender, que não necessariamente é o valor da defesa;
            int doHarvest();
            
            //executa um ataque através da função de ataque do hit.
            int doHit(Entity* enemy, Attack* hit);

            virtual Attack* getHit(int id) = 0;

            //escolhe qual ataque será usado, se o ataque é válido para o atual nível de estamina.
            //é uma função mais complexa que o getHit justamente por ter o controle de estamina.
            virtual Attack* chooseAttack() = 0;
            
    };

#endif