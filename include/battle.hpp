#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>
#include <list>
#include <npc.hpp>
#include <pc.hpp>

class Battle {

    private:

        Pc _player;
        Npc* _adversary;
        bool _result;
        int _totalDamagePc;
        int _totalDamageNpc;
        int* _numBattle;
        int* _totalLoses;
        int _predio;
        std::string _resultTxt;

    public:

        Battle(Pc player, Npc* adversary, int* numBattle, int* totalLoses, int predio);

        ~Battle ();

        bool getResult ();

        int getDamagePc ();

        int getDamageNpc ();

        void setDamagePc (int damage);
        
        void setDamageNpc (int damage);
        
        std::string statistcs ();

        void fight ();

        std::string readNpc();

        std::string readResultTxt ();
};

#endif