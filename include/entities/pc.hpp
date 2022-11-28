/**
 * @file pc.hpp
 * @author Enzo Bahia (ebahia@ufmg.br)
 * @brief classe que implementa a lógica do player
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PC_H
#define PC_H

#include <iostream>
#include <list>

#include "entity.hpp"
#include "../attacks/attack.hpp"
/**
 * @brief classe que implementa a lógica do player.
 * 
 */
class Pc: public Entity{

    private:

        std::list<Attack*> _hit;

    public:

        /**
         * @brief Construtor básico de pc.
         * 
         */
        Pc ();
        
        /**
         * @brief Constrói um pc manualmente.
         * 
         * @param name 
         * @param life 
         * @param defense 
         */
        Pc( std::string name,
            int life,
            int defense );
        
        /**
         * @brief Destrói um pc.
         * 
         */
        ~Pc();

        /**
         * @brief retorna o ponteiro de um ataque da lista de ataques a partir da sua posição.
         * @details pc tem uma lista de ataques porque os ataques sempre vão estar sendo adicionados e deletados.
         * @param id : posição do ataque na lista de ataques de pc.
         * @return Attack* : ponteiro do ataque selecionado.
         */
        Attack* getHit(int id) override;
        
        /**
        * @brief escolhe qual ataque será usado e se o ataque é válido para o atual nível de estamina.
        * @details é uma função mais complexa que o getHit justamente por ter o controle de estamina.
        * @return Attack* : ponteiro do ataque escolhido
        */
        Attack* chooseAttack();

        /**
         * @brief retorna o tamanho da lista de ataques.
         * 
         * @return int : tamanho da lista de ataques.
         */
        virtual int sizeofHit() override;
        
        /**
         * @brief adiciona novos ataques a lista de ataques.
         * 
         * @param attack : ponteiro do ataque a ser adicionado.
         */
        void addHit(Attack* attack);

        /**
         * @brief deleta o ataque da posição id na lista de ataques.
         * 
         * @param id : posição na lista de ataques.
         */
        void delHit(int id);

        /**
         * @brief mostra a lista de ataques que podem ser usados no momento e as staminas respectivas.
         * @details só serão mostrados os ataques cuja stamina é inferior ou igual à atual stamina do jogador.
         */
        void showHit();

        /**
         * @brief mostra qual ataque foi utilizado no pelo jogador.
         * 
         * @param hit : o ataque que foi usado pelo jogador. 
         */
        virtual void showAction(Attack* hit) override;
};
#endif