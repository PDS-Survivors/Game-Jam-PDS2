#ifndef MATCH_HPP
#define MATCH_HPP



#include "building.hpp"
#include "effects/effect.hpp"
#include "entities/pc.hpp"
#include <string>
#include <vector>
#include <stack>

class Match {
    private:
        Pc* _player;
        std::stack<Building*> _buildings;
        std::vector<Effect*> _permanentEffects;
        int _numLifes = 3;
        std::string _epilogue;

    public:
        //construtor
        Match();

        void playBuilding(Building*);

        int chooseEffect();

        void eventHappen(int);

        //errado, essa função tem que receber alguma coisa, estava em duvida do que seria especificamente por isso não pus
        void setEpilogue();
        
        void printEpilogue();

        int getNumLifes();

        void died();


};

#endif