/**
 * @file entity.hpp
 * @author Enzo Bahia(ebahia@ufmg.br)
 * @brief Classe que implementa o funcionamento de entidades
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <iostream>
#include <list>
#include "../attacks/attack.hpp"
#include "../attacks/defense.hpp"
#include "../effects/effect.hpp"

    /**
     * @brief classe que implementa o funcionamento de entidades.
     * @details é a superclasse que contém comportamentos básicos dos personagens jogáveis (Pc) e não jogáveis (Npc)
     */
    class Entity{

        protected:

        std::string _name;
        int _life;
        int _total_life;
        int _defense;
        int _stamina;
        std::list<Effect*> _effect;

        public:
            
            /**
             * @brief Constrói uma entidade manualmente.
             * 
             * @param name : nome da entidade
             * @param life : vida da entidade
             * @param defense : defesa da entidade
             */
            Entity( std::string name,
                    int life,
                    int defense);
            
            /**
             * @brief Construtor base da classe entidade.
             * 
             */
            Entity();
            
            /**
             * @brief Destrutor da classe entidade
             * 
             */
            virtual ~Entity();
            
            /**
             * @brief retorna a vida atual da entidade.
             * 
             * @return int : vida atual da entidade
             */
            int getLife();

            /**
             * @brief função para resetar a vida da entidade a quatidade máxima.
             * @details retorna um valor inteiro para dar um feedback da vida atual da entidade
             * @return int : vida atual da entidade (em seu valor máximo) 
             */
            int rebootLife();

            /**
             * @brief reseta ou gasta a estamina da entidade após um turno.
             * @details a stamina pode ser resetada para um valor diferente de 5 para algumas exceções de npcs, ou até mesmo pcs. 
             * @param value : o valor a ser adicionado na stamina da entidade
             * @return int : a stamina atual da entidade.
             */
            int rebootStamina(int value = 5);
            
            /**
             * @brief retorna a stamina atual da entidade.
             * @details essa função é importante para o controle dos ataques das entidades.
             * @return int : a stamina atual da entidade.
             */
            int getStamina();

            /**
             * @brief Muda a vida da entidade.
             * @details ao receber um número negativo como parâmetro, a vida da entidade passa a ser 0.
             * @param life : vida nova da entidade.
             * @return int : vida atual da entidade.
             */
            int setLife(int life);
            
            /**
             * @brief Retorna a defesa da entidade.
             * @details a defesa da entidade não vai ser alterada desde sua criação.
             * @return int : defesa da entidade.
             */
            int getDefense();

            /**
             * @brief Retorna o nome da entidade.
             * 
             * @return std::string : nome da entidade.
             */
            std::string getName();

            /**
             * @brief dado a posição do efeito, retorna seu ponteiro.
             * 
             * @param id : posição do ponteiro na lista de ponteiros da entidade.
             * @return Effect* : ponteiro apontando para o efeito desejado.
             */
            Effect* getEffect(int id);

            /**
             * @brief retorna o tamanho da lista de efeitos da entidade.
             * @details seu uso é para acessar os efeitos de uma entidade fora dela.
             * @return int : tamanho da lista de efeitos da entidade.
             */
            int sizeofEffect();

            /**
             * @brief adiciona um efeito a lista de efeitos da entidade.
             * 
             * @param effect : efeito a ser adicionado.
             */
            void addEffect(Effect* effect);
            
            /**
             * @brief retira um efeito da lista de efeitos da entidade.
             * 
             * @param effect : efeito a ser removido da enitdade.
             */
            void delEffect(Effect* effect);

            /**
             * @brief aplica todos os efeitos de determinado tipo de efeito na entidade.
             * @details é chamado no momento do ataque para aplicar os efeitos e alterar as condições da batalha.
             * @param type : tipo dos efeitos que serão aplicados. 
             * @param target : qual parâmetro da entidade será a afetado pelos efeitos.
             */
            void applyEffect(char type, int& target);
            
            /**
             * @brief Ataca outra entidade ou aumenta sua defesa.
             * @details dependendo do tipo de ataque recebido (attack ou defense), vai afetar a outra entidade recebida ou a si mesmo.
             * @param enemy : entidade alvo do ataque.
             * @param hit : ataque selecionado
             * @return int : vida atual da entidade que sofreu o ataque.
             */
            int doHit(Entity* enemy, Attack* hit);

            /**
             * @brief retorna o ponteiro de um ataque a partir de seu id.
             * @details não será implementado na classe entity pois pc terá uma lista de ataques enquanto npc terá um vector de ataques.
             * @param id : posição na lista ou no vector da entidade.
             * @return Attack* : ponteiro do ataque desejado. 
             */
            virtual Attack* getHit(int id) = 0;

            /**
             * @brief retorna o tamanho da lista ou vector de ataques.
             * 
             * @return int : tamanho da lista ou vector de ataques.
             */
            virtual int sizeofHit();
            
            /**
             * @brief retorna o comportamento da entidade (será utilizado apenas para o npc).
             * 
             * @return std::string : comportamento da entidade.
             */
            virtual std::string getBehavior();

            /**
             * @brief imprime qual ataque foi utilizado durante o turno.
             * 
             * @param hit : ataque que foi utilizado.
             */
            virtual void showAction(Attack* hit);
    };

#endif