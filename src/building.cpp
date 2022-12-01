#include "building.hpp"
#include "battle.hpp"
#include "entities/npc.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <ctime>

Building::Building(std::string desc, std::string name, int number, int totalb){
    _desc = desc;
    _name = name;
    _number = number;
    _totalBattles = totalb;
    _numBattle = 0;
    _tryagain = false;
}

Building::Building(Pc* player, std::string arqv){

    _player = player;

    std::vector<std::string> words;
    std::vector<std::string> files;
    std::vector<int> values;

    read::readfile (arqv, values, words, files);

    _number = values[0];
    _name = words[0];
    _desc = files[0];
    _totalBattles = values[1];

    for (int i = 1; i <= _totalBattles; i++){
        //Colocar as batalhas em ordem decrescente na pilha
        Battle* bat = new Battle (_player, files[i]);
        _battles.emplace(bat);
    }

    _tryagain = false;
}

Building::~Building(){
    

}

std::string Building::get_desc(){
    return _desc;
}

std::string Building::get_name(){
    return _name;
}

int Building::get_number(){
    return _number;
}

int Building::get_numBattle(){
    return _numBattle;
}

void Building::set_numBattle(int num){
    _numBattle = num;
}

void Building::start_battle(){
    _battles.top()->fight();
}
        

void Building::doBattle(){

    Battle* actualBattle = _battles.top();

    //se for a primeira tentativa
    if(!_tryagain){

        std::cout<<"\n== Batalha à frente:   ";
        std::cout<<_battles.top()->getName()<<std::endl;
        std::cout<<std::endl;

        read::wait(2);

        std::cout<<"      [Pressione Enter pra ir a luta] "<<std::endl;
        std::cout<<std::endl;
        
        getchar();
        getchar();
    
        _battles.top()->fight();
        _battles.top()->resultTxt();

        if(_battles.top()->getResult()){

            if (_player->getNumLifes() == 0) {return;}

            else {
                std::cout<<"Quer tentar de novo? (por sua conta em risco)"<<std::endl;
                std::cout<<std::endl;
                
                read::wait(1);

                std::cout<<"Vamo la fazer oq -> (s)"<<std::endl;
                std::cout<<"Vou dar uma respirada la fora volto ja -> (n)"<<std::endl;

                char choice = getchar();

                while(true){

                    switch(choice){

                        case 's':
                            doBattle();
                            return;
                            break;
                        
                        case 'n':
                            _tryagain = false;
                            return;
                            break;
                        
                        default: choice = getchar();
                        break;

                    }

                }
            }
        }
        
        // se o player ganhou
        else{

            _battles.top()->manageAttacks();

            _battles.pop();

            _tryagain = false;
            
            return;
        }
    }
    //se voce está tentando a mesma batalha de novo
    else{

        _battles.pop();
        _battles.emplace(actualBattle);

        std::cout<<" Batalha à frente:   ";
        std::cout<<_battles.top()->getName()<<std::endl;
        std::cout<<std::endl;
        
        std::cout<<"      [Pressione Enter pra revanche] "<<std::endl;
        std::cout<<std::endl;
        
        getchar();

        _battles.top()->fight();
        _battles.top()->resultTxt();
        
        //se o player perdeu
        if(_battles.top()->getResult()){

            if (_player->getNumLifes() == 0) {return;}

            else {
                std::cout<<"Quer tentar de novo? (por sua conta em risco)"<<std::endl;
                std::cout<<std::endl;
                
                read::wait(1);

                std::cout<<"Vamo la fazer oq -> (s)"<<std::endl;
                std::cout<<"Vou dar uma respirada la fora volto ja -> (n)"<<std::endl;

                char choice = getchar();

                while(true){

                    switch(choice){

                        case 's':
                            doBattle();
                            return;
                            break;
                        
                        case 'n':
                            _tryagain = false;
                            return;
                            break;
                        
                        default: choice = getchar();
                        break;

                    }
                }
            }
        }
        
        // se o player ganhou
        else{

            _battles.top()->manageAttacks();

            _battles.pop();

            _tryagain = false;
            
            return;
        }
    }
}

bool Building::isComplete(){
    return _battles.empty();
}