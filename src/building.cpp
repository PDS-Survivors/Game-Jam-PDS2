#include "building.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include "battle.hpp"

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

void Building::add_battle(){ 
    Pc* player;
    Npc* adversary[_totalBattles];
    for(int i=0;i<_totalBattles;i++){
         /* adversary[i] = NPC lido do arquivo*/
    }

    for(int i=_totalBattles;i>0;i--){
        _battles.push(Battle(player,adversary[i-1],i,_number));
    }
}
    
void Building::remove_battle(){
    _battles.pop();
}