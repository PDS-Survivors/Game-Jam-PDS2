#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "attack.hpp"
#include "npc.hpp"

    namespace behavior{
        
        int rollDyce(int start, int lim);

        void berserkerbhv(Entity* enemy, Entity* player);

        void greedybhv(Entity* enemy, Entity* player);

        void speedybhv(Entity* enemy, Entity* player);

        void hybridbhv(Entity* enemy, Entity* player);

        void pacientbhv(Entity* enemy, Entity* player);

        void tankbhv(Entity* enemy, Entity* player);

        void doBehavior(Entity* enemy, Entity* player);
        
    }
#endif