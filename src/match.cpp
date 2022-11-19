#include "match.hpp"
#include <iostream>


Match::Match(){
    _player = new Pc();
}

void Match::playBuilding(Building* building){}

int Match::chooseEffect(){}

void Match::eventHappen(int numEvent){}

//errado, essa função tem que receber alguma coisa, estava em duvida do que seria especificamente por isso não pus
void Match::setEpilogue(){}
        
void Match::printEpilogue(){
    std::cout << _epilogue << std::endl;
}