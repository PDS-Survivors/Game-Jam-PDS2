#include "npc.hpp"

#include <iostream>
#include <vector>

    Npc::Npc( std::string name,
              int life,
              int defense,
              std::string description):
              Entity(name,life,defense), _description(description){}

    Npc::Npc(std::string file){

        std::vector<std::string> words;
        std::vector<std::string> files;
        std::vector<int> values;

        read::readfile(file, values, words, files);

        _name = words[0];
        _description = words[1];
        _life = values[0];
        _defense = values[1];
        _stamina = values[2];

        for(std::string fl : files)
            _hit.push_back( new Attack(fl) );
        

    }
    Npc::~Npc(){

        std::list<Effect*>::iterator ite;

        for(ite  = _effect.begin();ite != _effect.end(); ite++){
            delete[] *ite;
            _effect.erase(ite);

            
        }

        for(Attack* a : _hit){
            delete[] a;
        }

    }

    void Npc::addAttack(Attack* attack){
        _hit.push_back(attack);
    }


    Attack* Npc::getHit(int id){
        return _hit[id];
    }

    Attack* Npc::chooseAttack(){
        return this->getHit(0);
    }

    std::string Npc::getDescription(){
        return _description;
    }