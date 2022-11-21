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
    Attack* ataque5;
    Attack* ataque6;

    ataque1 = new Attack (65, 3, "ataque do hamster", "roe a perna do seu inimigo");
    ataque2 = new Attack (10, 2, "estilingue", "atira uma manga verde");
    ataque3 = new Attack (90, 4, "feitiço de tropeçar", "tropeça a cada 5 metros");
    ataque4 = new Attack (85, 5, "nanorobôs ladrões de serotonina", "infelizes para sempre");
    ataque5 = new Attack (70, 3, "feitiço", "enfeitiça");
    ataque6 = new Attack (72, 2, "algo", "faz alguma coisa");

    ataque1->addEffect(lifeEffect);
    ataque2->addEffect(damageEffect);

    Pc* player;
    player = new Pc ("Elfo saltitante", 80, 30);
    player->addHit(ataque1);
    player->addHit(ataque2);

    Npc* adversary;
    adversary = new Npc ("Fantasma do quinto periodo", 60, 50, "Descricao interessante :D", "b");
    adversary->addAttack(ataque3);
    adversary->addAttack(ataque4);
    adversary->addAttack(ataque5);
    adversary->addAttack(ataque6);

    int numBattle = 1;
    int predio = 4;

    battle = new Battle (player, adversary, numBattle, predio);

    battle->beginTxt();

    bool i = true;
    while (i == true){
        char get_char;
        std::cout << "Voce esta preparado para a batalha? (s/n)\n";
        std::cin >> get_char;
        switch (get_char) {
            case 's' : {std::cout << "Nao seria tao confiante se fosse voce.\n\n";
                        i = false; read::wait(2);}
                        break;
            case 'n' : {std::cout << "Preocupante.\n\n"; 
                        i = false; read::wait(2);}
                        break;
            default : i = true; break;
        }
    }
    
    battle->statistcs();

    battle->fight();

    battle->resultTxt();

    std::cout << "Resultado: ";
    if (!battle->getResult()) {std::cout << "vitótia!\n";}
    else {std::cout << "derrota T_T\n";}
    read::wait(1);
    std::cout << "Dano total em PC: " << battle->getDamagePc() << std::endl;
    read::wait(1);
    std::cout << "Dano total em NPC: " << battle->getDamageNpc() << std::endl;
    read::wait(1);
    std::cout << "Batalhas perdidas: " << battle->getTotalLoses() << std::endl << std::endl;
    read::wait(3);

    //Obs:Segmentation fault no destrutor de battle

    return 0;
}