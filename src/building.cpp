#include "../include/building.hpp"
#include "../include/battle.hpp"
#include "../include/entities/npc.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <ctime>

//construtor baseado em parametros
Building::Building(std::string desc, std::string name, int number, int totalb){
    _desc = desc;
    _name = name;
    _number = number;
    _totalBattles = totalb;
    _numBattle = 0;
    _tryagain = false;
}

//construtor baseado na leitura de um arquivo
Building::Building(Pc* player, std::string arqv){

    _player = player;

    std::vector<std::string> words;
    std::vector<std::string> files;
    std::vector<int> values;

    reader::readfile (arqv, values, words, files);

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

std::stack<Battle*>* Building::getBattleStack(){
    return &_battles;
}

void Building::set_numBattle(int num){
    _numBattle = num;
}

void Building::start_battle(){
    _battles.top()->fight();
}
        

void Building::doBattle(){

    bool theEnd = false;

    //se for a primeira tentativa
    if(!theEnd){

        std::cout<<"\n== Batalha à frente: ";
        std::cout<<_battles.top()->getName()<<std::endl;
        std::cout<<std::endl;

        reader::wait(2);
        
        //Se for a sua primeira que a batalha ocorre
        if (!_tryagain) { std::cout<<"      [Pressione Enter pra ir a luta] "<<std::endl;}
        //Se não for a primeira vez
        else { std::cout<<"      [Pressione Enter pra revanche] "<<std::endl; }

        std::cout<<std::endl;
        
        getchar(); 
        
        char c = getchar();

        while(c != char(10)) {
            std::cin>>c;
            c = getchar();
        }
    
        _battles.top()->fight();

        if(_battles.top()->getResult()){

            if (_player->getNumLifes() == 0) { theEnd = true;}

            else {
                std::cout<<"Quer tentar de novo? (por sua conta em risco)"<<std::endl;
                std::cout<<std::endl;
                
                reader::wait(1);

                std::cout<<"Vamo la fazer oq -> (s)"<<std::endl;
                std::cout<<"Vou dar uma respirada la fora volto ja -> (n)"<<std::endl;

                char choice = getchar();

                while(true){

                    switch(choice){

                        case 's':
                            _tryagain = true;
                            doBattle();
                            return;
                            break;
                        
                        case 'n':
                            _tryagain = false;
                            return;
                            break;
                        
                        default: choice = getchar();
                        //implementar tratamento de exceção
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

            theEnd = true;
        }
    }
}

bool Building::isComplete(){
    return _battles.empty();
}