#include "building.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include "battle.hpp"

Building::Building(std::string desc, std::string name, int number){
    _desc = desc;
    _name = name;
    _number = number;
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
    Pc player;
    Npc* adversary3;
    _battles.push(Battle(player,adversary3,3,_number));

    Npc* adversary2;
    _battles.push(Battle(player,adversary2,2,_number));

    Npc* adversary1;
    _battles.push(Battle(player,adversary1,1,_number));
}
    
void Building::remove_battle(){
    _battles.pop();
}