#include "effect.hpp"
#include "damageeffect.hpp"
#include <iostream>

    DamageEffect::DamageEffect( int value,
                            int durability,
                            std::string name,
                            std::string description):
                            Effect(value, durability, name, description){}

    Effect* DamageEffect::cloneEffect() {
         
        DamageEffect* effect;
        effect = new DamageEffect(  _value,
                                    _durability,
                                    _name,
                                    _description);

        return effect;
    }
    
    char DamageEffect::getType(){
        return 'h';
    }