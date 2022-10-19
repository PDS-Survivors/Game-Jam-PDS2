#include "effect.hpp"
#include "defenseeffect.hpp"
#include <iostream>

    DefenseEffect::DefenseEffect(int value = 0,
                std::string name = "",
                std::string description = ""):
                Effect(value,name,description){}

    Effect* DefenseEffect::cloneEffect() {
         
        DefenseEffect* effect;
        effect = new DefenseEffect(this->getValue(),
                            this->getName(),
                            this->getDescription());

        return effect;
    }
    
    char Effect::getType(){
        return 'd';
    }