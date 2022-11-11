#include "building.hpp"
#include <iostream>
#include <vector>
#include <stack>

Building::Building(std::string desc, std::string name, int number){
    Building::_desc = desc;
    Building::_name = name;
    Building::_number = number;
    Building::_nBattle = 0;
}

std::string Building::get_desc(){
    return Building::_desc;

}

std::string Building::get_name(){
    return Building::_name;
}

int Building::get_number(){
    return Building::_number;
}

void Building::start_battle(){
    //_battles.top();

}

void Building::add_battle(){
    //_battles.push(Battle::Battle());
    //_battles.push(Battle::Battle());
    //_battles.push(Battle::Battle());
}
    
void Building::remove_battle(){
    //_battles.pop();
}