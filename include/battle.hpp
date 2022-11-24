/**
 * @file battle.hpp
 * @author Talita Félix Lúcio(talitafelixlucio2004@gmail.com)
 * @brief Essa biblioteca possui três classes, sendo battle a principal e responsável por fazer
 * a batalha entre o player e um adversário atacontecer e as outras para tratamento de exceção.
 * @details 
 * @version 1.0
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
 * @details
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

        /**
         * @brief Constrói um novo objeto Battle
         * @details 
         * 
         * @param player objeto Pc que contem as informações do jogador
         * @param file arquivo na forma de string que possui informações sobre o adversário, nome
         * da batalha, texto de introdução da batalha (história do adversário) e um texto de 
         * vitória caso o jogador derrote o seu adversário.
         */
        Battle (Pc* player, std::string file);

        /**
         * @brief Constrói um novo objeto Battle
         * @details
         * 
         * @param player 
         * @param adversary 
         * @param numBattle 
         * @param predio 
         */
        Battle (Pc* player, Npc* adversary, int numBattle, int predio, std::string name);

        /**
         * @brief Destroy the Battle object
         * @details
         * 
         */
        ~Battle ();

        /**
         * @brief Get the Result object
         * @details
         * 
         * @return true 
         * @return false 
         */
        bool getResult ();

        /**
         * @brief Get the Total Loses object
         * @details
         * 
         * @return int 
         */
        static int getTotalLoses ();

        /**
         * @brief Get the Damage Pc object
         * @details
         * 
         * @return int 
         */
        int getDamagePc ();

        /**
         * @brief Get the Damage Npc object
         * @details description
         * 
         * @return int 
         */
        int getDamageNpc ();
        
        std::string getName();

        /**
         * @brief Set the Result object
         * @details description
         * 
         * @param result 
         */
        void setResult (bool result);

        /**
         * @brief Set the Total Loses object
         * @details description
         * 
         * @param lose 
         */
        void setTotalLoses (int lose);
        
        /**
         * @brief 
         * @details description
         * 
         */
        void beginTxt();

        /**
         * @brief 
         * @details description
         * 
         */
        void imprimeVida ();

        /**
         * @brief 
         * @details
         * 
         * @return true 
         * @return false 
         */
        bool defineResult ();

        /**
         * @brief 
         * @details description
         * 
         */
        void resultTxt ();

        /**
         * @brief 
         * @details
         * 
         */
        void statistcs ();

        /**
         * @brief 
         * @details
         * 
         */
        void fight (); 

        /**
         * @brief 
         * @details
         * 
         */
        void figthPc ();

        /**
         * @brief 
         * @details
         * 
         */
        void fightNpc ();

        /**
         * @brief 
         * 
         */
        void manageAttacks();
};

/**
 * @brief 
 * @details
 * 
 */
class ExcecaoEntradaInvalida : public std::exception {

     private:

        std::string _msgErro;
    
     public:

        /**
         * @brief Construct a new Excecao Entrada Invalida object
         * @details
         * 
         */
        ExcecaoEntradaInvalida ();

        /**
         * @brief 
         * @details
         * 
         * @return const char* 
         */
        const char* what () const noexcept override;
 };

/**
 * @brief 
 * @details
 * 
 */
class ExcecaoEntradaInvalida2 : public std::exception {

    private:

        std::string _msgErro;

    public:

        /**
         * @brief Construct a new Excecao Entrada Invalida 2 object
         * @details
         * 
         */
        ExcecaoEntradaInvalida2 () ;

        /**
         * @brief
         * @details 
         * 
         * @return const char* 
         */
        const char* what () const noexcept override;
};

/**
 * @brief 
 * 
 */
class ExcecaoEntradaInvalida3 : public std::exception {

    private:

        std::string _msgErro;
    
    public:

        /**
         * @brief Construct a new Excecao Entrada Invalida 3 object
         * 
         */
        ExcecaoEntradaInvalida3 ();

        /**
         * @brief 
         * 
         * @return const char* 
         */
        const char* what () const noexcept override;
};

#endif