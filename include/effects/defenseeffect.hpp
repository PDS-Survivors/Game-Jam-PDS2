/**
 * @file defenseeffect.hpp
 * @author Enzo Bahia (ebahia@ufmg.br)
 * @brief classe do efeito de defesa (sub da classe efeito)
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DEFFECT_H
#define DEFFECT_H

#include <iostream>
#include "effect.hpp"

    /**
     * @brief classe do efeito de defesa
     * 
     */
    class DefenseEffect: public Effect{

        public:
            
            /**
             * @brief Constrói um defenseeffect manualmente
             * 
             * @param value 
             * @param durability 
             * @param name 
             * @param description 
             */
            DefenseEffect( int value,
                            int durability,
                            std::string name,
                            std::string description);
            
            /**
             * @brief Constrói um defenseeffect com o nome de um arquivo
             * 
             * @param file : nome do arquivo 
             */
            DefenseEffect(std::string file);
            
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.

            /**
             * @brief clona o efeito de defesa para a entidade gerenciar esta cópia
             * 
             * @return Effect* : o ponteiro do efeito de defesa criado
             */
            Effect* cloneEffect() override;

            /**
             * @brief polimorfismo principal da classe: retorna o tipo de efeito 
             * 
             * @return char : o tipo de efeito que é (nesse caso 'd')
             */
            char getType() override;
            
    };
#endif