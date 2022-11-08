#ifndef HEFFECT_H
#define HEFFECT_H

#include <iostream>
#include "effect.hpp"

    class DamageEffect: public Effect{

        public:

            DamageEffect( int value,
                            int durability,
                            std::string name,
                            std::string description);
            
            DamageEffect(std::string file);

            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.
            Effect* cloneEffect() override;

            //polimorfismo principal da classe: retorna o tipo para a entidade 
            //reconhecer onde aplicar o efeito.
            virtual char getType() override;
        
    };
#endif
