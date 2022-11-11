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
    Pc player3;
    Npc* adversary3;
    int* numBattle3;
    int* totalLoses3;
    _battles.push(Battle(player3,adversary3,numBattle3,totalLoses3,_number));

    Pc player2;
    Npc* adversary2;
    int* numBattle2;
    int* totalLoses2;
    _battles.push(Battle(player2,adversary2,numBattle2,totalLoses2,_number));

    Pc player1;
    Npc* adversary1;
    int* numBattle1;
    int* totalLoses1;
    _battles.push(Battle(player1,adversary1,numBattle1,totalLoses1,_number));

}
    
void Building::remove_battle(){
    _battles.pop();
}