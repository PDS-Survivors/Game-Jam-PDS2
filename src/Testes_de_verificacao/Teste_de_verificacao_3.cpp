#include "battle.hpp"
#include "pc.hpp"
#include "npc.hpp"
#include "entity.hpp"
#include "attack.hpp"

#include <string>
#include <iostream>


int main () {
    Battle* battle;

    Attack* ataque1;
    Attack* ataque2;
    Attack* ataque3;
    Attack* ataque4;
    Attack* ataque5;
    Attack* ataque6;
    Attack* ataque7;
    Attack* ataque8;

    ataque1 = new Attack (30, 5, "bolinho de mercurio", "seu inimigo como esse bolinho");
    ataque2 = new Attack (25, 4, "ciclode de fofo", "bota fogo em tudo");
    ataque3 = new Attack (35, 3, "ataque do hamster", "roe a perna do seu inimigo");
    ataque4 = new Attack (10, 5, "estilingue", "atira uma manga verde");
    ataque5 = new Attack (35, 5, "chuva de canivetes", "clima estranho esse");
    ataque6 = new Attack (25, 4, "feitiço de tropeçar", "tropeça a cada 5 metros");
    ataque7 = new Attack (15, 3, "canhão de baratas", "nada legal");
    ataque8 = new Attack (15, 5, "nanorobôs ladrões de serotonina", "infelizes para sempre");

    Pc player ("Elfo", 80, 60);
    player.addHit(ataque1);
    player.addHit(ataque2);
    player.addHit(ataque3);
    player.addHit(ataque4);

    Npc* adversary;
    adversary = new Npc ("Fantasma do quinto periodo", 60, 90, "Descricao interessante :D");
    adversary->addAttack(ataque5);
    adversary->addAttack(ataque6);
    adversary->addAttack(ataque7);
    adversary->addAttack(ataque8);

    int numBattle = 1;
    int predio = 4;

    battle = new Battle (player, adversary, numBattle, predio);

    std::cout << battle->beginTxt();

    deNovo:
    std::cout << "Voce esta preparado para a batalha? (s/n)\n";
    switch (getchar()) {
        case 's' : std::cout << "Nao seria tao confiante se fosse voce.\n"; break;
        case 'n' : std::cout << "Preocupante.\n"; break;
        default : goto deNovo; break;
    }
    
    std::cout << battle->statistcs();

    battle->fight();

    std::cout << battle->resultTxt();

    std::cout << "Resultado: " << battle->getResult() << std::endl;
    std::cout << "Dano total em PC: " << battle->getDamagePc() << std::endl;
    std::cout << "Dano total em NPC: " << battle->getDamageNpc() << std::endl;
    std::cout << "Batalhas perdidas: " << battle->getTotalLoses() << std::endl;

    battle->~Battle();

    return 0;
}