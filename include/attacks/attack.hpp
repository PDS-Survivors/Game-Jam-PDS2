/**
 * @file attack.hpp
 * @author Enzo Bahia (ebahia@ufmg.br)
 * @brief Classe ataque reponsavel por calcular o dano que uma entidade causa na outra, e aplicá-lo
 * @details Ataque também aplica efeitos em entidades quando executados
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <vector>
#include "../effects/effect.hpp"
#include "../effects/lifeeffect.hpp"
#include "../effects/damageeffect.hpp"
#include "../effects/defenseeffect.hpp"
    /**
     * @brief Aplicação da classe ataque
     * 
     */

    class Attack{

        protected:

            int _damage;
            int _stamina;
            std::string _name;
            std::string _description;
            std::vector<Effect*> _effects;
            //_effects é um vetor porque o ataque não adiciona nem deleta
            // efeitos, apenas acessa eles.

        public:
            /**
             * @brief Constrói um ataque manualmente
             * 
             * @param damage : dano padrão do ataque
             * @param stamina : o quanto de stamina que a entidade vai gastar para usar o ataque
             * @param name : nome do ataque
             * @param description : descrição do ataque
             * @param effects : efeitos contidos no ataque
             */
            Attack( int damage,
                    int stamina,
                    std::string name,
                    std::string description,
                    std::vector<Effect*>& effects 
                  );

            Attack( int damage,
                    int stamina,
                    std::string name,
                    std::string description
                  );  

            /**
             * @brief Constrói um ataque a partir do nome de um arquivo
             * 
             * @param file : nome do arquivo para construir o ataque
             */
            Attack( std::string file);

            /**
             * @brief Destrói um ataque
             * 
             */
            ~Attack();

            /**
             * @brief retorna a descrição de um ataque
             * 
             * @return std::string : descrição do ataque
             */
            std::string getDescription();

            /**
             * @brief retorna o nome de um ataque
             * 
             * @return std::string : nome do ataque
             */
            std::string getName();

            /**
             * @brief retorna a stamina para usar o ataque
             * 
             * @return int : stamina do ataque
             */
            int getStamina();

            /**
             * @brief retorna o dano padrão do ataque
             * 
             * @return int : dano do ataque
             */
            int getDamage();
            
            /**
             * @brief retorna o tamanho do vetor de efeitos, para construir funções futuras
             * 
             * @return int : tamanho do vetor de efeitos 
             */
            int sizeofEffects();

            /**
             * @brief retorna um efeito contido no ataque a partir do índice dele no vetor
             * 
             * @param id : índice do efeito contido
             * @return Effect* : efeito com o índice inserido
             */
            Effect* getEffect(int id = 0);
            
            /**
             * @brief faz todos ss cálculos necessários para a realização do ataque propriamente dito
             * 
             * @param life : vida do defensor 
             * @param defense : defesa do defensor
             * @param extradamage : dano extra adicionado pelo atacante
             * @param effect : vetor de efeitos passado como referência para copiar os efeitos do ataque
             * @return int : valor da vida do defensor após o ataque
             */
            int doAction(int life, int defense, int extradamage, std::vector<Effect*>& effect);

            void operator += (Effect* const effect);

            /**
             * @brief adiciona um efeito ao vetor de efeitos do ataque
             * 
             * @param effect : efeito a ser adicionado
             */
            void addEffect(Effect* effect);

            /**
             * @brief verifica se o ataque é uma defesa ou não
             * 
             * @return true : é uma defesa (a classe ataque em si retorna false)
             * @return false não é uma defesa (attack retorna false)
             */
            virtual bool isDefense();

            /**
             * @brief função para revestir o atacante (como se ele atacasse si mesmo)
             * @details não será implementada nessa classe pois o ataque não reveste, e sim a defesa
             * @param effect : um vetor de efeitos passado por referência para copiar os efeitos do ataque/defesa
             */
            virtual void Harvest(std::vector<Effect*>& effect);

    };
#endif