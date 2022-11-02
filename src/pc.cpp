#include "pc.hpp"

#include <iostream>
#include <list>

    Pc::Pc( std::string name,
            int life,
            int defense ):
            Entity(name,life,defense){ _stamina = 5; }

    Pc::~Pc(){

        std::list<Effect*>::iterator ite;

        for(ite  = _effect.begin();ite != _effect.end(); ite++){
            delete[] *ite;
            _effect.erase(ite);
        }

        std::list<Attack*>::iterator ita;

        for(ita  = _hit.begin();ita != _hit.end(); ita++){
            delete[] *ita;
            _hit.erase(ita);
        }

    }

    Attack* Pc::getHit(int id){

        std::list<Attack*>::iterator it = _hit.begin();

        for(int i=0;i<id;i++) it++;

        return *it;

    }

    Attack* Pc::chooseAttack(){

        int choice;
        Attack* attack;

        while(std::cin>>choice){
            
            if(choice == int(_hit.size())){
                attack = nullptr;
                break;
            }

            if(choice >= 0 and choice < int(_hit.size())){
                attack = this->getHit(choice);
                
                if(this->getStamina() >= attack->getStamina()) break;

                else std::cout<<"você não tem energia suficiente. tente novamente!"<<std::endl;
            }

            else std::cout<<"ataque inválido. tente novamente!"<<std::endl;
        }

        return attack;
    }

    void Pc::addHit(Attack* attack){
        _hit.push_back(attack);
        
    }

    void Pc::showHit(){
        
        for(Attack* hit: _hit)
            std::cout<<hit->getName()<<std::endl;
        
    }
    
    