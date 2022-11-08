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
        std::string _resultTxt;

    public:

        Battle(Pc* player, Npc* adversary);

        ~Battle ();

        bool getResult ();

        int getDamagePc ();

        int getDamageNpc ();

        void setDamagePc (int damage);
        
        void setDamageNpc (int damage);
        
        std::string statistcs ();

        void fight ();
        
        Attack* readCommand();

        std::string readNpc();

        std::string readResultTxt ();
};

#endif