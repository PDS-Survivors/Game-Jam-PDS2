#include "effect.hpp"
#include "lifeeffect.hpp"
#include <iostream>
#include <vector>

    LifeEffect::LifeEffect( int value,
                            int durability,
                            std::string name,
                            std::string description):
                            Effect(value, durability, name, description){}

    LifeEffect::LifeEffect(std::string file): Effect(file){}

    LifeEffect::~LifeEffect(){}
    
    Effect* LifeEffect::cloneEffect() {
         
        LifeEffect* effect;
        effect = new LifeEffect(  _value,
                                    _durability,
                                    _name,
                                    _description);

        return effect;
    }
    
    char LifeEffect::getType(){
        return 'l';
    }