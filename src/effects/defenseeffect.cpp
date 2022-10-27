#include "effect.hpp"
#include "defenseeffect.hpp"
#include <iostream>

    DefenseEffect::DefenseEffect( int value,
                            int durability,
                            std::string name,
                            std::string description):
                            Effect(value, durability, name, description){}

    Effect* DefenseEffect::cloneEffect() {
         
        DefenseEffect* effect;
        effect = new DefenseEffect(  _value,
                                    _durability,
                                    _name,
                                    _description);

        return effect;
    }
    
    char DefenseEffect::getType(){
        return 'd';
    }