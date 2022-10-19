#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>

    class Effect{

        protected:

            int _value;
            std::string _name;
            std::string _description;

        public:

            Effect( int value, std::string name, std::string  description);

            int getValue();
            
            std::string getName();

            std::string getDescription();
            
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.
            virtual Effect* cloneEffect();

            //polimorfismo principal da classe: retorna o tipo para a entidade 
            //reconhecer onde aplicar o efeito.
            virtual char getType();
            
    };
#endif