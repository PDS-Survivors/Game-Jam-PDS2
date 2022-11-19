#include <iostream>
#include <vector>
#include <list>
#include <fstream>

#include "entities/pc.hpp"
#include "entities/npc.hpp" 
#include "namespaces/reader.hpp"

int main(){

    Npc* enemy1 = new Npc("lib/npcs/mortovivo.txt");

    Npc* enemy2 = new Npc("lib/npcs/mortovivo.txt");
    
    std::cout<<enemy2->getLife()<<std::endl;
    
    for(int i=0; i<20;i++){
    enemy1->doTurn(enemy2);

    std::cout<<enemy2->getLife()<<std::endl;

    enemy1->rebootStamina();
    }

    return 0;
}