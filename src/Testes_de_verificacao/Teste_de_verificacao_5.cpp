#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "battle.hpp"
#include "entities/pc.hpp"
#include "entities/npc.hpp" 
#include "namespaces/reader.hpp"

int main(){

    

    Pc* player = new Pc("lib/pcs/mago.txt"); 
    
    Battle bat(player, "lib/battles/fafich1.txt");

    bat.beginTxt();

    bat.fight();

    return 0;
}