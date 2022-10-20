#ifndef DEFENSE_H
#define DEFENSE_H

#include "attack.hpp"
#include <iostream>
#include <vector>

    class Defense: public Attack{

        public:

            Defense( int damage,
                    std::string name,
                    std::string description,
                    std::vector<Effect*>& effects 
                  );

            ~Defense();

            int doAction(int life, int defense, std::vector<Effect*>& effect) override;

    };

#endif