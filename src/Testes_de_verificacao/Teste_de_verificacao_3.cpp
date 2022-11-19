#include "battle.hpp"
#include "entities/pc.hpp"
#include "entities/npc.hpp"
#include "entities/entity.hpp"
#include "attacks/attack.hpp"

#include <string>
#include <iostream>


int main () {

    LifeEffect* lifeEffect;
    DamageEffect* damageEffect;

    lifeEffect = new LifeEffect (-10, 4, "fogo", "muito quente");
    damageEffect = new DamageEffect (-15, 5, "espíritos", "extremamente bondosos");

    Battle* battle;

    Attack* ataque1;
    Attack* ataque2;
    Attack* ataque3;
    Attack* ataque4;

    ataque1 = new Attack (35, 3, "ataque do hamster", "roe a perna do seu inimigo");
    ataque2 = new Attack (10, 5, "estilingue", "atira uma manga verde");
    ataque3 = new Attack (50, 4, "feitiço de tropeçar", "tropeça a cada 5 metros");
    ataque4 = new Attack (15, 5, "nanorobôs ladrões de serotonina", "infelizes para sempre");

    ataque1->addEffect(lifeEffect);
    ataque2->addEffect(damageEffect);

    Pc* player;
    player = new Pc ("Elfo", 80, 30);
    player->addHit(ataque1);
    player->addHit(ataque2);

    Npc* adversary;
    adversary = new Npc ("Fantasma do quinto periodo", 60, 50, "Descricao interessante :D");
    adversary->addAttack(ataque3);
    adversary->addAttack(ataque4);

    int numBattle = 1;
    int predio = 4;

    battle = new Battle (player, adversary, numBattle, predio);

    std::cout << battle->beginTxt();

    bool i = true;
    while (i == true){
        char get_char;
        std::cout << "Voce esta preparado para a batalha? (s/n)\n";
        std::cin >> get_char;
        switch (get_char) {
            case 's' : {std::cout << "Nao seria tao confiante se fosse voce.\n\n";
                        i = false;}
                        break;
            case 'n' : {std::cout << "Preocupante.\n\n"; 
                        i = false;}
                        break;
            default : i = true; break;
        }
    }
    
    std::cout << battle->statistcs();

    battle->fight();

    std::cout << battle->resultTxt() << std::endl;

    std::cout << "Resultado: " << battle->getResult() << std::endl;
    std::cout << "Dano total em PC: " << battle->getDamagePc() << std::endl;
    std::cout << "Dano total em NPC: " << battle->getDamageNpc() << std::endl;
    std::cout << "Batalhas perdidas: " << battle->getTotalLoses() << std::endl;

    //Obs:Segmentation fault no destrutor de battle

    return 0;
}