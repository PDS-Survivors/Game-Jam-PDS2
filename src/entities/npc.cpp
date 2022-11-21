#include "npc.hpp"

#include "../namespaces/behavior.hpp"
#include <iostream>
#include <string>
#include <vector>

    Npc::Npc( std::string name,
              int life,
              int defense,
              std::string description,
              std::string behavior1):
              Entity(name,life,defense), _description(description), _behavior(behavior1)
              {_stamina = 5;}

    Npc::Npc(std::string file){
        
        //cria vetores para guardar o conteúdo do arquivo
        std::vector<std::string> words;
        std::vector<std::string> files;
        std::vector<int> values;

        //essa função transfere o conteúdo do arquivo para os vetores de cima.
        read::readfile(file, values, words, files);

        //as posições no arquivo importam já que, por exemplo, a primeira string lida será o nome.
        _name = words[0];
        _description = words[1];
        _behavior = words[2];
        _life = values[0];
        _defense = values[1];
        _stamina = 5;

        //percorre a lista de arquivos e cria eles (no caso de Npc, os arquivos serão todos ataques
        // que por sua vez criarão efeitos).
        for(std::string fl : files) {
            _hit.push_back( new Attack(fl) );
        }

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

    int Npc::sizeofHit(){
        return _hit.size();
    }

    std::string Npc::getBehavior(){
        return _behavior;
    }
    
    void Npc::doTurn(Entity* player){
        behavior::doBehavior(this, player);
    }

    void Npc::showAction(Attack* hit){
        std::cout<<this->getName()<<" usou "<<hit->getName();
        std::cout<<"!"<<std::endl;

        read::wait(1);
    }