#include "effect.hpp"
#include "defenseeffect.hpp"
#include <iostream>

    DefenseEffect::DefenseEffect( int value = 0,
                            int durability = 1,
                            std::string name = "",
                            std::string description = ""):
                            Effect(value, durability, name, description){}

    Effect* DefenseEffect::cloneEffect() {
         
        DefenseEffect* effect;
        effect = new DefenseEffect(  _value,
                                    _durability,
                                    _name,
                                    _description);

        return effect;
    }
    
    char Effect::getType(){
        return 'd';
    }