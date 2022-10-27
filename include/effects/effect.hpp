#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>

    class Effect{

        protected:

            //durability se refere a quantas vezes o efeito pode ser aplicado em
            //uma entidade.
            int _value;
            int _durability;
            std::string _name;
            std::string _description;

        public:

            Effect( int value, int durability, std::string name, std::string  description);

            //além de retornar o valor do efeito, reduz a durabilidade.
            int getValue();
            
            std::string getName();

            std::string getDescription();
            
            //Retorna pra entidade se a durabilidade do efeito acabou (se chegou a 0).
            //Para efeitos permanentes ou que duram de forma indeterminada, a durabilidade inicial 
            //é sempre negativa.
            bool checkDurability();
                
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.
            virtual Effect* cloneEffect() = 0;

            //polimorfismo principal da classe: retorna o tipo para a entidade 
            //reconhecer onde aplicar o efeito.
            virtual char getType() = 0;
            
    };
#endif