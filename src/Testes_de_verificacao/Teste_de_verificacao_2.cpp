#include <iostream>
#include <vector>
#include <list>
#include <fstream>

#include "pc.hpp"
#include "npc.hpp" 
#include "effects/reader.hpp"

int main(){

    DamageEffect* efeito1;
    efeito1 = new DamageEffect("lib/filetest.txt");
    
    std::cout<<efeito1->getName()<<std::endl;
    std::cout<<efeito1->getDescription()<<std::endl;
    std::cout<<efeito1->getValue()<<std::endl;
    
    Attack* ataque1;
    ataque1 = new Attack("lib/hittest.txt");

    std::cout<<ataque1->getName()<<" ";
    std::cout<<ataque1->getDescription()<<" ";
    std::cout<<ataque1->getDamage()<<" ";
    std::cout<<std::endl;
    
    std::cout<<ataque1->getEffect(0)->getName()<<std::endl;
    std::cout<<ataque1->getEffect(0)->getValue()<<std::endl;
    
    return 0;
}