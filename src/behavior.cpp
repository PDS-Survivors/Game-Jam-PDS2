#include "behavior.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace behavior;

    int rollDice(int start, int lim){

        srand((unsigned) time(NULL));
        
        return rand() % lim + start;
    }

    void berserkerbhv(Npc* enemy, Entity* player){

        int turn = rollDice(1, 3);

        switch(turn){

            case 1:

                enemy->doHit(player, enemy->getHit(rollDice(0,2)));
                enemy->doHit(player, enemy->getHit(rollDice(0,2)));

                break;

            case 2:

                enemy->doHit(player, enemy->getHit(2));

                break;

            case 3:

                enemy->doHit(player, enemy->getHit(3));

                break;
            
            default: break;
        }

        turn++;

        if(turn > 3) turn = 1;

    }

    void speedybhv(Npc* enemy, Entity* player){
        
        int turn = rollDice(1, 2);

        switch(turn){

            case 1:

                enemy->doHit(player, enemy->getHit(rollDice(0, 3)));
                enemy->doHit(player, enemy->getHit(rollDice(0, 3)));
                enemy->doHit(player, enemy->getHit(rollDice(0, 3)));

                break;

            case 2:

                enemy->doHit(player, enemy->getHit(3));

                break;

            default: break;

        }


    }

    void tankbhv(Npc* enemy, Entity* player){

        int turn = rollDice(1, 5);

        switch(turn){

            case 1:

                enemy->doHit(player, enemy->getHit(rollDice(0, 2)));
                enemy->doHit(player, enemy->getHit(rollDice(0, 2)));

                break;
            
            case 2:

                enemy->doHit(player, enemy->getHit(rollDice(0, 2)));
                enemy->doHit(player, enemy->getHit(rollDice(0, 2)));

                break;

            case 3:

                enemy->doHit(player, enemy->getHit(rollDice(2, 2)));

                break;
            
            case 4:

                enemy->doHit(player, enemy->getHit(rollDice(0, 2)));
                enemy->doHit(player, enemy->getHit(rollDice(0, 2)));

                break;
            
            case 5:

                enemy->doHit(player, enemy->getHit(rollDice(2, 2)));
                
                break;
            
            default: break;
        }
    
    }

    void hybridbhv(Npc* enemy, Entity* player){
        
        int turn = rollDice(1, 2);

        switch(turn){

            case 1:

                enemy->doHit(player, enemy->getHit(0));
                
                break;

            case 2:

                for(int i=1; i < enemy->sizeofHit();i++)
                    enemy->doHit(player, enemy->getHit(i));
                
                break;

            default: break;
        }


    }

    void pacientbhv(Npc* enemy, Entity* player){

        int turn = rollDice(1, 5);

        if(turn = 3)
            enemy->doHit(player, enemy->getHit(rollDice(0,2)));

    }

    void doBehavior(Npc* enemy, Entity* player){
        
        switch((enemy->getBehavior())[0]){
            
            case 'b':
                berserkerbhv(enemy, player);

                break;

            case 's':
                speedybhv(enemy, player);

                break;

            case 'p':
                pacientbhv(enemy, player);

                break;

            case 't':
                tankbhv(enemy, player);

                break;

            case 'h':
                hybridbhv(enemy, player);

                break;
            
        }

    }