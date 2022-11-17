#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>

#include "entity.hpp"
#include "attack.hpp"

class Npc: public Entity{

    protected:

        std::vector<Attack*> _hit;
        std::string _description;
        int _turner = 0;

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

        virtual void rebootTurner() = 0;

        void increaseTurner();
};  
#endif