#ifndef DEFENSE_H
#define DEFENSE_H

#include <iostream>

#include "attack.hpp"


    class Defense: public Attack{

            public:

            Defense(std::string file);

            ~Defense();
            virtual bool isDefense() override;

            virtual int Harvest(std::vector<Effect*>& effect) override;

    };
#endif