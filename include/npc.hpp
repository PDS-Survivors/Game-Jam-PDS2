#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>
#include <map>

#include "entity.hpp"
#include "attack.hpp"
#include "behavior.hpp"

class Npc: public Entity{

    protected:

        std::vector<Attack*> _hit;
        std::string _description;
        std::string _behavior;


    public:

        Npc( std::string name,
            int life,
            int defense,
            std::string description);

        Npc(std::string file);
        
        virtual ~Npc() override;

        void addAttack(Attack* attack);

        Attack* getHit(int id) override;

        virtual Attack* chooseAttack();
        
        std::string getDescription();

        int sizeofHit();

        std::string getBehavior();
    
        void doTurn(Entity* player);
        

        
};  
#endif