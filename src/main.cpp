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

int main ()
{
  //Tela de introdução do jogo na interface
  std::cout << "========================================================================================";
  std::cout << "\n\n                            ESCAPE FROM UFMG\n\n";
  std::cout << "========================================================================================\n\n";
    
  reader::wait(6);

  //Quanto o botão de começar é pressionado o objeto match é instânciado
  Match* match = new Match;

  match->chooseMatch();

  std::cout << match->introducao();

  reader::wait (10);

  std::cout << "== VOCÊ ACEITARÁ ESSA PROPOSTA?(s/n)\n";

  char op;
  std::cin >> op;

  std::cout << match->introducao2(op);

  reader::wait(10);

  //Tela de escolha do personagem pela interface

  std::cout << "== Quem é você nessa jornada?\n\n";
  std::cout << "(0) Mago : Não é mágica, é matemática!\n";
  std::cout << "(1) Mestre de armas : Levantar a voz não vence uma língua afiada\n";
  std::cout << "(2) Druida : Altos contatos com a natureza\n\n";

  int pc;
  std::cin >> pc;

  match->setPlayer(pc);

  reader::wait(3);

  std::cout << "\n== Agora que já possuimos suas informações, está na hora de começar a trabahar!\n\n";

  std::cout << "========================================================================================\n\n";
  std::cout <<"Entrando na UFMG . . .";

  reader::wait(4);

  match->setBuildingStack();

  while (!match->end())
  {
    match->playBuilding();
    if (match->getPlayerLifes() <= 0) { break;}
    match->chooseEvent();
  }

  std::cout << "========================================================================================\n\n";

  match->printEpilogue();

  return 0;
} 
