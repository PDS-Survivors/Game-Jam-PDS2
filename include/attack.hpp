#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <vector>
#include "effect.hpp"
#include "lifeeffect.hpp"
#include "damageeffect.hpp"
#include "defenseeffect.hpp"

    class Attack{

        protected:

            int _damage;
            std::string _name;
            std::string _description;
            std::vector<Effect*> _effects;
            //_effects é um vetor porque o ataque não adiciona nem deleta
            // efeitos, apenas acessa eles.

        public:

            Attack( int damage,
                    std::string name,
                    std::string description,
                    std::vector<Effect*>& effects 
                  );
                  
            ~Attack();

            std::string getDescription();

            std::string getName();

            int getDamage();
            
            //retorna o tamanho do vetor para loops. 
            int sizeofEffects();

            //seleciona qual efeito do ataque será utilizado.
            Effect* getEffect(int id = 0);
            
            //realiza todo o calculo de danos.
            virtual int doAction(int life, int defense, int extradamage, std::vector<Effect*>& effect);

    };
#endif