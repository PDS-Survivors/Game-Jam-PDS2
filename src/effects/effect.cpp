#include "effect.hpp"

#include <iostream>

    Effect::Effect( int value = 0,
                    int durability = 1,
                    std::string name = "",
                    std::string description = ""):
                    _value(value), _durability(durability),
                    _name(name), _description(description){}

    int Effect::getValue(){
        _durability--;
        return _value;
    }

    std::string Effect::getName(){
        return _name;
    }

    std::string Effect::getDescription(){
        return _description;
    }

    bool Effect::checkDurability(){
        return (_durability == 0);
    }

    Effect* Effect::cloneEffect() {
         
        Effect* effect;
        effect = new Effect(_value,
                            _durability,
                            _name,
                            _description);

        return effect;
    }
    
    char Effect::getType(){
        return 'e';
    }