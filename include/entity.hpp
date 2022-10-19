#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <iostream>
#include <list>
#include "attack.hpp"
#include "effect.hpp"

    class Entity{

        protected:

        std::string _name;
        int _life;
        int _defense;
        std::list<Effect*> _effect;

        public:

            Entity( std::string name,
                    int life,
                    int defense,
                    std::list<Effect*>& effect);
            
            ~Entity();
            
            int getLife();

            int setLife(int life);

            int getDefense();

            std::string getName();

            Effect* getEffect(int id);

            void addEffect(Effect* effect);
            
            void delEffect(Effect* effect);

            virtual Attack* getHit(int id);

            virtual int doHit(Entity& enemy, Attack* hit);


    };

#endif