#ifndef LEFFECT_H
#define LEFFECT_H

#include <iostream>
#include "effect.hpp"

    class LifeEffect: public Effect{

        public:

            LifeEffect( int value,
                        int durability,
                        std::string name,
                        std::string description);
            
            LifeEffect(std::string file);
            
            ~LifeEffect();
            
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.
            Effect* cloneEffect() override;

            //polimorfismo principal da classe: retorna o tipo para a entidade 
            //reconhecer onde aplicar o efeito.
            virtual char getType() override;
            
    };
#endif