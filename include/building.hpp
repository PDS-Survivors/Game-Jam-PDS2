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
 * @details Classe responsavel pela classe "building" que se refere al predio da universidade em que o
 * player "pc" esta, responsavel tambem pela criação da pilha de batalhas e tambem pela inicialização
 * das batalhas 
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

    public:

        /**
        * @brief Constructor a new Building object
        * @details Construtor de um objeto building a partir de parametros
        * @param desc Complete descripition of the building
        * @param name Name of the building
        * @param number Number of the building
        * @param totalb Number of battles in the building
        */
        Building(std::string desc, std::string name, int number, int totalb);

        Building(std::string arqv);

        /**
         * @brief Destructor of a building object
         * @details Destroi o objeto building 
         * 
         */
        ~Building();

        /**
         * @brief Retorna a descrição de building 
         * @details Essa função retorna a descrição completa do objeto builidng, predio, em que
         *  o player esta.
        */
        std::string get_desc();

        /**
         * @brief Retorna o nome de building 
         * @details Essa função retorna o nome do objeto builidng, predio, em que o player esta.
        */
        std::string get_name();

        /**
         * @brief Retorna o numero de building 
         * @details Essa função retorna o numero referente ao objeto builidng, predio, em que
         *  o player esta.
        */
        int get_number();

        /**
         * @brief Return the nuber of the battle
         * @details
        */
        int get_numBattle();

        /**
         * @brief Set the nuber of the battle
         * @details
        */
        void set_numBattle(int num);

        /**
         * @brief Starts a battle
         * @details
        */
        void start_battle();

        /**
         * @brief 
         * @details
        */
        void doBattle();

        /**
         * @brief 
         * @details
        */
        bool isComplete();

        /**
         * @brief 
         * @details
        */
        void manageAttacks();
        
};

#endif