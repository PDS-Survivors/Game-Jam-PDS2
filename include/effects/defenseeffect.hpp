#ifndef DEFFECT_H
#define DEFFECT_H

#include <iostream>
#include "effect.hpp"

    class DefenseEffect: public Effect{

        public:

            DefenseEffect( int value, std::string name, std::string  description);
            
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.
            Effect* cloneEffect() override;

            //polimorfismo principal da classe: retorna o tipo para a entidade 
            //reconhecer onde aplicar o efeito.
            char getType() override;
            
    };
#endif