#include "effect.hpp"

#include <iostream>

    Effect::Effect(int value = 0,
                std::string name = "",
                std::string description = ""):
                _value(value), _name(name), 
                _description(description){}

    int Effect::getValue(){
        return _value;
    }

    std::string Effect::getName(){
        return _name;
    }

    std::string Effect::getDescription(){
        return _description;
    }

    Effect* Effect::cloneEffect() {
         
        Effect* effect;
        effect = new Effect(this->getValue(),
                            this->getName(),
                            this->getDescription());

        return effect;
    }
    
    char Effect::getType(){
        return 'e';
    }