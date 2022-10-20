#include "effect.hpp"
#include "lifeeffect.hpp"
#include <iostream>

    LifeEffect::LifeEffect( int value = 0,
                            int durability = 1,
                            std::string name = "",
                            std::string description = ""):
                            Effect(value, durability, name, description){}

    Effect* LifeEffect::cloneEffect() {
         
        LifeEffect* effect;
        effect = new LifeEffect(  _value,
                                    _durability,
                                    _name,
                                    _description);

        return effect;
    }
    
    char Effect::getType(){
        return 'l';
    }