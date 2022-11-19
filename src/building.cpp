#include "building.hpp"
#include "battle.hpp"
#include "entities/npc.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <string>

Building::Building(std::string desc, std::string name, int number, int totalb){
    _desc = desc;
    _name = name;
    _number = number;
    _totalBattles =totalb;
    _numBattle = 0;
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
    _battles.top().fight();
}

void Building::add_battles(){ 

    Pc* player;

    //vetor com as referencias para os adversarios
    Npc* adversary[_totalBattles];

    //vector com os arquivos referentes aos objetos NPC
    std::vector<std::string> files[_totalBattles];

    //vector com os objetos NPC referentes aos adversarios
    std::vector <Npc> adversaries;

    //cria as objetos refrentes aos Npc
    for(int i=0;i<_totalBattles;i++){
         adversaries[i] = Npc(files[i]);
    }
    
    //referencia os objetos
    for(int i=0;i<_totalBattles;i++){
         adversary[i] = &adversaries[i];
    }
    //adiciona as batlhas da ultima para a primeira
    for(int i=_totalBattles;i>0;i--){
        _battles.push(Battle(player,adversary[i-1],i,_number));
    }
}
    
void Building::remove_battle(){
    _battles.pop();
}