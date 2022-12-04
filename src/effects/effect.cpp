#include "../effects/effect.hpp"
#include "../namespaces/reader.hpp"
#include <iostream>
#include <vector>

    Effect::Effect( int value,
                    int durability,
                    std::string name,
                    std::string description):
                    _value(value), _durability(durability),
                    _name(name), _description(description){}

    Effect::Effect( std::string file){

        std::vector<int> values;
        std::vector<std::string> words;
        std::vector<std::string> files;
        

        reader::readfile(file, values, words, files);

        _value = values[0];
        _durability = values[1];
        _name = words[0];
        _description = words[1];

    }
    Effect::~Effect(){}
    
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

    
    
    