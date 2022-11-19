#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <vector>
#include "../effects/effect.hpp"
#include "../effects/lifeeffect.hpp"
#include "../effects/damageeffect.hpp"
#include "../effects/defenseeffect.hpp"

    class Attack{

        protected:

            int _damage;
            int _stamina;
            std::string _name;
            std::string _description;
            std::vector<Effect*> _effects;
            //_effects é um vetor porque o ataque não adiciona nem deleta
            // efeitos, apenas acessa eles.

        public:

            Attack( int damage,
                    int stamina,
                    std::string name,
                    std::string description,
                    std::vector<Effect*>& effects 
                  );

            Attack( int damage,
                    int stamina,
                    std::string name,
                    std::string description
                  );  

            Attack( std::string file);
              
            ~Attack();

            std::string getDescription();

            std::string getName();

            int getStamina();

            int getDamage();
            
            //retorna o tamanho do vetor para loops. 
            int sizeofEffects();

            //seleciona qual efeito do ataque será utilizado.
            Effect* getEffect(int id = 0);
            
            //realiza todo o calculo de danos.
            int doAction(int life, int defense, int extradamage, std::vector<Effect*>& effect);


            void operator += (Effect* const effect);

            void addEffect(Effect* effect);

            virtual bool isDefense();

            virtual int Harvest(std::vector<Effect*>& effect);

    };
#endif