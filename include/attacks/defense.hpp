/**
 * @file defense.hpp
 * @author Enzo Bahia (ebahia@ufmg.br)
 * @brief Classe da Defesa (sub de Ataque que "ataca" o atacante)
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef DEFENSE_H
#define DEFENSE_H

#include <iostream>

#include "attack.hpp"

    /**
     * @brief classe de defesa (sub de ataque)
     * @details usa a mesma lógica de ataque porém quem a usa, aplica os efeitos em si mesmo 
     * 
     */
    class Defense: public Attack{

            public:

            /**
             * @brief Constrói uma defesa a partir do nome de um arquivo
             * 
             * @param file : nome do arquivo a ser lido
             */
            Defense(std::string file);
            
            /**
             * @brief Destrói uma defesa
             * 
             */
            ~Defense();

            /**
             * @brief verifica se é umaq defesa (nesse caso, sempre será true)
             * 
             * @return true: é uma defesa (nessa classe sempre retornará isso) 
             * @return false : não é uma defesa
             */
            virtual bool isDefense() override;
            
            /**
             * @brief função para revestir o atacante (como se ele atacasse si mesmo)
             * @details: ela implementada apenas para esta classe, pois o ataque normal nunca irá revestir
             * @param effect 
             */
            virtual void Harvest(std::vector<Effect*>& effect) override;

    };
#endif