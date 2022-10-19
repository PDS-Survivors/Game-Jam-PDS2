#include "effect.hpp"
#include "lifeeffect.hpp"
#include <iostream>

    LifeEffect::LifeEffect(int value = 0,
                std::string name = "",
                std::string description = ""):
                Effect(value,name,description){}

    Effect* LifeEffect::cloneEffect() {
         
        LifeEffect* effect;
        effect = new LifeEffect(this->getValue(),
                            this->getName(),
                            this->getDescription());

        return effect;
    }
    
    char Effect::getType(){
        return 'l';
    }