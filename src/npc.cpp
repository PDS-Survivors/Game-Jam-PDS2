#include "npc.hpp"

#include <iostream>
#include <vector>

    Npc::Npc( std::string name,
              int life,
              int defense,
              std::list<Effect*>& effect,
              std::vector<Attack*>& hit ):
              Entity(name,life,defense,effect),
              _hit(hit){}

    Attack* Npc::getHit(int id){
        return _hit[id];
    }

    //obs: a função a priori está exatamente igual a pc,
    //a gente pode ler a ação do jogador durante a batalha.
    int Npc::doHit(Entity& enemy, Attack* hit){

        int life = enemy.getLife();

        int damage = hit->getDamage();

        int defense = enemy.getDefense();

        int newLife = life + defense - damage;

        //Esse loop procura nos efeitos do ataque algum LifeEffect para alterar o valor 
        //da vida do enemy.
        for(int i=0;i<hit->sizeofEffects() ;i++)
            if(hit->getEffect(i)->getType() == 'l')
                newLife -= hit->getEffect(i)->getValue();
        
        return enemy.setLife(newLife);
    }