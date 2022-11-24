/**
 * @file lifeeffect.hpp
 * @author Enzo Bahia (ebahia@ufmg.br)
 * @brief classe do efeito de defesa (sub da classe efeito)
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LIFEECT_H
#define LIFEECT_H

#include <iostream>
#include "effect.hpp"

    /**
     * @brief classe do efeito de vida
     * 
     */
    class LifeEffect: public Effect{

        public:
            
            /**
             * @brief Constrói umlifeeffect manualmente
             * 
             * @param value 
             * @param durability 
             * @param name 
             * @param description 
             */
            LifeEffect( int value,
                            int durability,
                            std::string name,
                            std::string description);
            
            /**
             * @brief Constrói um lifeeffect com o nome de um arquivo
             * 
             * @param file : nome do arquivo 
             */
            LifeEffect(std::string file);

            /**
             * @brief Destrutor padrão de um objeto LifeEffect
             * 
             */
            ~LifeEffect();
            
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.

            /**
             * @brief clona o efeito de vida para a entidade gerenciar esta cópia
             * 
             * @return Effect* : o ponteiro do efeito de vida criado
             */
            Effect* cloneEffect() override;

            /**
             * @brief polimorfismo principal da classe: retorna o tipo de efeito 
             * 
             * @return char : o tipo de efeito que é (nesse caso 'l')
             */
            char getType() override;
            
    };
#endif