/**
 * @file building.hpp
 * @author Leonardo Antonio Gomes da Silva (Leoagdasilva@gmail.com)
 * @brief 
 * @details 
 * @version 1.0
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "battle.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <string>


/**
 * @brief Em qual predio da faculdade o PC esta
 * @details Classe responsavel pela classe "building" que se refere ao predio da universidade em que o
 * player "pc" esta, ela tambem é responsavel pela criação da pilha de batalhas do predio e tambem pela inicialização
 * dessas batalhas 
 * 
 */
class Building {

    private:

        std::stack<Battle*> _battles;
        std::string _desc;
        std::string _name;
        int _number;
        int _numBattle;
        int _totalBattles;
        bool _tryagain;
        Pc* _player;

    public:

        /**
        * @brief Constructor a new Building object
        * @details Construtor de um objeto building a partir de parametros
        * @param desc Desrição completa do objeto Building (predio da faculdade)
        * @param name Name of the building
        * @param number Number of the building
        * @param totalb Number of battles in the building
        */
        Building(std::string desc, std::string name, int number, int totalb);

        /**
        * @brief Constructor a new Building object
        * @details Construtor de um objeto Building a partir da leitura de um arquivo
        * @param player Ponteiro para um objeto Pc que contem as informações do jogador
        * @param arqv arquivo referente ao objeto predio em especifico
        */
        Building(Pc* player, std::string arqv);

        /**
         * @brief Destructor of a Building object
         * @details Destroi o objeto Building 
         * 
         */
        ~Building();

        /**
         * @brief Retorna a descrição de building 
         * @details Essa função retorna a descrição completa do objeto Building, predio, em que
         *  o player esta.
         * @return std::string
        */
        std::string get_desc();

        /**
         * @brief Retorna o nome de building 
         * @details Essa função retorna o nome do objeto Building, predio, em que o player esta.
         * @return std::string
        */
        std::string get_name();

        /**
         * @brief Retorna o numero de building 
         * @details Essa função retorna o numero referente ao objeto Building, predio, em que
         *  o player esta.
         * @return int
        */
        int get_number();

        /**
         * @brief Return the nuber of atual battle
         * @details Retorna o numero da batalha em que o player esta
         * @return int
        */
        int get_numBattle();

        /**
         * @brief Set the nuber of the battle
         * @details Set o numero da batalha em que o player esta
        */
        void set_numBattle(int num);

        /**
         * @brief Inicia a proxima batalha
         * @details Inicia a proxima batalha (essa função não esta sendo utilizada)
        */
        void start_battle();

        /**
         * @brief Inicia a proxima batalha
         * @details Incia a batalha que esta no topo da pilha de execução de batalhas em building
         * verifica se é a primeira tentativa do player em realiza-la e verifica os resultados de batalha
         * para dar continuidade à gameplay
        */
        void doBattle();

        /**
         * @brief Informa se todas as batalhas foram concluidas
         * @details Retorna um valor booleano "true" se todas as batalhas tiverem sido conluidas,
         * para isso verifica se a pilha de execuções de batalha do predio esta vazia
        */
        bool isComplete();

        /**
         * @brief ??
         * @details ??
        */
        void manageAttacks();
        
};

#endif