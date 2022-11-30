#include "match.hpp"
#include "building.hpp"
#include "battle.hpp"
#include "entities/pc.hpp"
#include "entities/npc.hpp" 
#include "namespaces/reader.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <fstream>

int main () {
    //Tela de introdução do jogo na intervace
    
    //Quanto o botão de começar é pressionado o objeto match é instânciado
    Match match();

    std::cout << match.introducao();

    std::cout << "VOCÊ ACEITARÁ ESSA PROPOSTA?"

    bool op;
    std::cin >> op;

    std::cout << match.introducao2(op);

    //Tela de escolha do personagem pela interface
    
    int pc;
    std::cin >> pc;

    match.setPlayer(pc);

    std::cout << "Agora que já possuimos suas informações, está na hora de começar a trabahar!\n\n";

    while (!match.end()){

        match.playBuilding();
        match.chooseEvent();

    }

    match.printEpilogue(match.getNumLifes());

    return 0;
}
