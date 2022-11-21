#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>
#include <map>

#include "entity.hpp"
#include "../attacks/attack.hpp"
#include "../namespaces/behavior.hpp"

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

        virtual int sizeofHit() override;

        virtual std::string getBehavior() override;

        virtual void showAction(Attack* hit) override;

        void doTurn(Entity* player);
        

        
};  
#endif