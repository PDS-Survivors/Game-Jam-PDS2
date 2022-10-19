#include "effect.hpp"
#include "damageeffect.hpp"
#include <iostream>

    DamageEffect::DamageEffect(int value = 0,
                std::string name = "",
                std::string description = ""):
                Effect(value,name,description){}

    Effect* DamageEffect::cloneEffect() {
         
        DamageEffect* effect;
        effect = new DamageEffect(this->getValue(),
                            this->getName(),
                            this->getDescription());

        return effect;
    }
    
    char Effect::getType(){
        return 'h';
    }