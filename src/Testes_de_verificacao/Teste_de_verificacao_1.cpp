
#include "pc.hpp"
#include "npc.hpp"
#include "effects/effect.hpp"
#include "effects/lifeeffect.hpp"
#include "effects/damageeffect.hpp"
#include "effects/defenseeffect.hpp"

#include <iostream>
#include <list>
#include <string>

void show(Entity* entity){

    std::cout<<entity->getName()<<std::endl;
    std::cout<<"vida: "<<entity->getLife();
    std::cout<<" defesa: "<<entity->getDefense()<<std::endl;

    std::cout<<"Efeitos: "<<std::endl;
    for(int i=0;i<entity->sizeofEffect();i++)
        std::cout<<entity->getEffect(i)->getName()<<std::endl;
    
}

void showAttack(Attack* ataque){
    std::cout<<ataque->getName()<<std::endl;
}


int main(){

    LifeEffect* efeito;

    efeito = new LifeEffect(-12, 1, "veneno", "veneno eh venenoso");


    Attack* ataque1;
    Attack* ataque2;
    Attack* ataque3;
    Attack* ataque4;

    
    ataque1 = new Attack(12, 2, "paulada na cabeça", "leva uma paulada na cabeça");
    ataque2 = new Attack(20, 4, "chute giratório", "leva um chute giratório");
    ataque3 = new Attack(30, 3, "cuspe no olho", "o cuspe ta muito molhado");
    ataque4 = new Attack(15, 1, "muqueca voadora", "insira aqui o texto");

    ataque1->addEffect(efeito);

    std::list<Attack*> ataquesPc;
    ataquesPc.push_back(ataque1);
    ataquesPc.push_back(ataque2);
   
    std::vector<Attack*> ataquesNpc;
    ataquesNpc.push_back(ataque3);
    ataquesNpc.push_back(ataque4);
    
    Pc* player;
    player = new Pc("mano", 100, 10);

    Npc* enemy;
    enemy = new Npc("sparring", 60, 5, "bobo");

    show(player);
    std::cout<<std::endl;

    player->addHit(ataque1);
    player->addHit(ataque2);
    player->addHit(ataque3);

    std::cout<<std::endl;


    show(enemy);
    std::cout<<std::endl;

    Attack* ataque = player->chooseAttack();

    std::cout<<"ataque escolhido"<<std::endl;
    showAttack(ataque);

    if(ataque == nullptr) std::cout<<"sem ataque dessa vez"<<std::endl;

    else{

        player->doHit(enemy, ataque);
        
    }

    show(enemy);
    

    return 0;
}

 // "./build/teste1.o"
