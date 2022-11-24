/**
 * @file effect.hpp
 * @author Enzo Bahia (ebahia@ufmg.br)
 * @brief Classe de efeitos que alteram atributos das entidades
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>
#include "../namespaces/reader.hpp"
    /**
     * @brief efeitos que alteram atributos de entidades.
     * 
     */
    class Effect{

        protected:

            //durability se refere a quantas vezes o efeito pode ser aplicado em
            //uma entidade.
            int _value;
            int _durability;
            std::string _name;
            std::string _description;

        public:
            /**
             * @brief Constrói um effect manualmente.
             * 
             * @param value 
             * @param durability 
             * @param name 
             * @param description 
             */
            Effect( int value, int durability, std::string name, std::string  description);
            /**
             * @brief Constrói um effect a partir do nome de um arquivo.
             * 
             * @param file 
             */
            Effect(std::string file);

            /**
             * @brief destrói um effect.
             * 
             * 
             */
            ~Effect();

            /**
             * @brief além de retornar o valor do efeito, reduz a durabilidade.
             * 
             * @return retorna o valor do efeito
             */
            int getValue();

            /**
             * @brief Acessa o nome do efeito
             * 
             * @return retorna o nome do efeito 
             */
            std::string getName();

            /**
             * @brief Acessa a descrição do efeito
             * 
             * @return Acessa a descrição do efeito 
             */
            std::string getDescription();
            
            /**
             * @brief Retorna pra entidade se a durabilidade do efeito acabou (se chegou a 0)
             * @details Para efeitos permanentes ou que duram de forma indeterminada, a durabilidade inicial é sempre negativa
             * @return true : o efeito já foi totalmente utiizado
             * @return false : o efeito ainda não foi totalmente utilizado, ou nunca será esgotado
             */
            bool checkDurability();
                
            // clona o efeito para a entidade colocar esse clone
            // em sua lista de efeitos.

            /**
             * @brief clona o efeito para a entidade gerenciar esta cópia
             * 
             * @return Effect* : o ponteiro do efeito criado
             */
            virtual Effect* cloneEffect() = 0;

            //polimorfismo principal da classe: retorna o tipo para a entidade 
            //reconhecer onde aplicar o efeito.

            /**
             * @brief polimorfismo principal da classe: retorna o tipo para a entidade
             * 
             * @return char : o tipo de efeito que é
             */
            virtual char getType() = 0;
            
    };
#endif