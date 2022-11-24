/**
 * @file battle.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>
#include "entities/npc.hpp"
#include "entities/pc.hpp"

/**
 * @brief 
 * 
 */
class Battle {

    private:

        Pc _player;
        Npc* _adversary;
        bool _result;
        int _totalDamagePc;
        int _totalDamageNpc;
        int _numBattle;
        int _predio;
        int _round;
        int _size;
        std::string _name;
        std::string _beginTxt;
        std::string _resultTxt;
        static int _totalLoses;

    public:
    
        Battle (Pc* player, std::string file);

        /**
         * @brief Construct a new Battle object
         * 
         * @param player 
         * @param adversary 
         * @param numBattle 
         * @param predio 
         */
        Battle (Pc* player, Npc* adversary, int numBattle, int predio);

        /**
         * @brief Destroy the Battle object
         * 
         */
        ~Battle ();

        /**
         * @brief Get the Result object
         * 
         * @return true 
         * @return false 
         */
        bool getResult ();

        /**
         * @brief Get the Total Loses object
         * 
         * @return int 
         */
        static int getTotalLoses ();

        /**
         * @brief Get the Damage Pc object
         * 
         * @return int 
         */
        int getDamagePc ();

        /**
         * @brief Get the Damage Npc object
         * 
         * @return int 
         */
        int getDamageNpc ();
        
        std::string getName();

        /**
         * @brief Set the Result object
         * 
         * @param result 
         */
        void setResult (bool result);

        /**
         * @brief Set the Total Loses object
         * 
         * @param lose 
         */
        void setTotalLoses (int lose);
        
        /**
         * @brief 
         * 
         */
        void beginTxt();

        /**
         * @brief 
         * 
         */
        void imprimeVida ();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool defineResult ();

        /**
         * @brief 
         * 
         */
        void resultTxt ();

        /**
         * @brief 
         * 
         */
        void statistcs ();

        /**
         * @brief 
         * 
         */
        void fight (); 

        /**
         * @brief 
         * 
         */
        void figthPc ();

        /**
         * @brief 
         * 
         */
        void fightNpc ();

        void manageAttacks();
};

/**
 * @brief 
 * 
 */
class ExcecaoEntradaInvalida : public std::exception {

     private:

        std::string _msgErro;
    
     public:

        /**
         * @brief Construct a new Excecao Entrada Invalida object
         * 
         */
        ExcecaoEntradaInvalida ();

        /**
         * @brief 
         * 
         * @return const char* 
         */
        const char* what () const noexcept override;
 };

/**
 * @brief 
 * 
 */
class ExcecaoEntradaInvalida2 : public std::exception {

    private:

        std::string _msgErro;

    public:

        /**
         * @brief Construct a new Excecao Entrada Invalida 2 object
         * 
         */
        ExcecaoEntradaInvalida2 () ;

        /**
         * @brief 
         * 
         * @return const char* 
         */
        const char* what () const noexcept override;
};

#endif