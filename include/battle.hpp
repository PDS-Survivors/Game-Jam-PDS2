#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>
#include <list>
#include <npc.hpp>
#include <pc.hpp>

class Battle {
    private:
        Npc* _adversary;
        bool _result;
        int _totalDamagePc;
        int _totalDamageNpc;

    public:
        /**
         * @brief Construct a new Battle object
         * 
         * @param adversary 
         * @param lifePc 
         * @param lifeNpc 
         * @param isOver 
         * @param result 
         * @param totalDamagePc 
         * @param totalDamageNpc 
         * @param active 
         */
        Battle (Npc* adversary, int lifePc, int lifeNpc, bool isOver, bool result,
                                int totalDamagePc, int totalDamageNpc, std::list<Entity> active);

        /**
         * @brief Destroy the Battle object
         * 
         */
        ~Battle ();

        /**
         * @brief Get the Result object
         * 
         * @return true if the battle was won
         * @return false  if the battle was lost
         */
        bool getResult ();

        /**
         * @brief Get the DamagePC value
         * 
         * @return int 
         */
        int getDamagePc ();

        /**
         * @brief Get the DamageNPC value
         * 
         * @return int 
         */
        int getDamageNpc ();

        /**
         * @brief Set the DamagePC value, it corresponds to the value of the NPC attack minus
         * the defense of PC;
         * 
         * @param damage 
         */
        void setDamagePc (int damage);

        /**
         * @brief Set the DamageNPC value, it corresponds to the value of the PC attack minus
         * the defense of NPC
         * 
         * @param damage 
         */
        void setDamageNpc (int damage);
        
        /**
         * @brief returns a string with all the statistcs of the battle: who is the adversary
         * (witch NPC), PC and NPC life, whose turn is it to attack, is the battle over or not?,
         * if the battle is over who won? and the total damage inflicted in PC and NPC until 
         * that moment.
         * 
         * @return std::string 
         */
        std::string statistcs ();

        void fight (Pc*, Npc*);
        
        Attack* readCommand();
};

#endif