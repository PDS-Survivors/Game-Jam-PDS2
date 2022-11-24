#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>
#include "entities/npc.hpp"
#include "entities/pc.hpp"

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

        Battle (Pc* player, Npc* adversary, int numBattle, int predio);

        ~Battle ();

        bool getResult ();

        static int getTotalLoses ();

        int getDamagePc ();

        int getDamageNpc ();
        
        std::string getName();

        void setResult (bool result);

        void setTotalLoses (int lose);
        
        void beginTxt();

        void imprimeVida ();

        bool defineResult ();

        void resultTxt ();

        void statistcs ();

        void fight (); 

        void figthPc ();

        void fightNpc ();
};

class ExcecaoEntradaInvalida : public std::exception {

     private:

         std::string _msgErro;
    
     public:

         ExcecaoEntradaInvalida ();

         const char* what () const noexcept override;
 };
 
#endif