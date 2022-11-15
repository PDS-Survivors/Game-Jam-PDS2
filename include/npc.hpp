#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>

#include "entity.hpp"
#include "attack.hpp"

class Npc: public Entity{

    private:

        std::vector<Attack*> _hit;
        std::string _description;

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

};  
#endif