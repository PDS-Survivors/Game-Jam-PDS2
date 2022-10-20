#include "pc.hpp"

#include <iostream>
#include <list>

    Pc::Pc( std::string name,
            int life,
            int defense,
            std::list<Effect*>& effect,
            std::list<Attack*>& hit  ):
            Entity(name,life,defense,effect),
            _hit(hit){}

    Pc::~Pc(){

        std::list<Effect*>::iterator ite = _effect.begin();

        for(ite ;ite != _effect.end(); ite++){
            delete *ite;
            _effect.erase(ite);
        }

        std::list<Attack*>::iterator ita = _hit.begin();

        for(ita ;ita != _hit.end(); ita++){
            delete *ita;
            _hit.erase(ita);
        }

    }

    Attack* Pc::getHit(int id){

        std::list<Attack*>::iterator it = _hit.begin();

        for(int i=0;i<id;i++) it++;

        return *it;

    }

    int Pc::doHit(Entity& enemy, Attack* hit){

        int newLife = _life;

        int defense = _defense;
        
        int extradamage = 0;


        std::vector<Effect*> effect;

        //busca os efeitos de defesa para alterar defense
        enemy.applyEffect('d', defense);

        //busca os efeitos de dano para incrementar o dano extra.
        this->applyEffect('h', extradamage);

        //aqui o ataque faz todo o cálculo da nova vida.
        newLife = hit->doAction(newLife, defense, extradamage, effect);

        //adicionando os efeitos vindos do ataque na lista de efeitos da entidade
        //e depois deletando esses esse vetor temporário.
        for(Effect* e : effect){
            _effect.push_back(e);
            delete[] e;
        }
        
        while(!effect.empty())
            effect.pop_back();

        //busca efeitos de vida para altera-la apenas após o golpe de fato acontecer.
        this->applyEffect('l', newLife);

        //altera finalmente a vida da entidade.
        return setLife(newLife);
    }