/**
 * @file damageeffect.hpp
 * @author Enzo Bahia (ebahia@ufmg.br)
 * @brief classe do efeito de defesa (sub da classe efeito)
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DAMFECT_H
#define DAMFECT_H

#include <iostream>
#include "effect.hpp"

    /**
     * @brief classe do efeito de dano
     * 
     */
    class DamageEffect: public Effect{

        public:
            
            /**
             * @brief Constrói um damageeffect manualmente
             * 
             * @param value 
             * @param durability 
             * @param name 
             * @param description 
             */
            DamageEffect( int value,
                            int durability,
                            std::string name,
                            std::string description);
            
            /**
             * @brief Constrói um damageeffect com o nome de um arquivo
             * 
             * @param file : nome do arquivo 
             */
            DamageEffect(std::string file);
            
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.

            /**
             * @brief clona o efeito de dano para a entidade gerenciar esta cópia
             * 
             * @return Effect* : o ponteiro do efeito de dano criado
             */
            Effect* cloneEffect() override;

            /**
             * @brief polimorfismo principal da classe: retorna o tipo de efeito 
             * 
             * @return char : o tipo de efeito que é (nesse caso 'h')
             */
            char getType() override;
            
    };
#endif