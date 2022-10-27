#include "effect.hpp"

#include <iostream>

    Effect::Effect( int value,
                    int durability,
                    std::string name,
                    std::string description):
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

    
    
    