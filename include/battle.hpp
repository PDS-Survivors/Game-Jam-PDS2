#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>
#include "npc.hpp"
#include "pc.hpp"

class Battle {

    private:

        Pc _player;
        Npc* _adversary;
        bool _result;
        int _totalDamagePc;
        int _totalDamageNpc;
        int _numBattle;
        static int _totalLoses;
        int _predio;
        std::string _resultTxt;

    public:

        Battle(Pc* player, Npc* adversary, int numBattle, int predio);

        ~Battle ();

        bool getResult ();

        int getDamagePc ();

        int getDamageNpc ();

        static int getTotalLoses ();

        void setResult (bool result);

        void setDamagePc (int damage);
        
        void setDamageNpc (int damage);

        void setTotalLoses (int lose);
        
        std::string beginTxt();

        void imprimeVida ();

        bool defineResult ();

        std::string resultTxt ();

        std::string statistcs ();

        void fight (); 
};

#endif