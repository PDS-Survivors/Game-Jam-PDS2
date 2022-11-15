#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>
#include <vector>
#include <stack>
#include "battle.hpp"

class Building {

    private:
    std::stack<Battle> _battles;
    std::string _desc;
    std::string _name;
    int _number;
    int _numBattle;

    public:
    /**
     * @brief Construct a new Building object
     * @param desc Complete descripition of the building
     * @param name Name of the building
     * @param number Number of the building
    */
    Building(std::string desc, std::string name, int number);

    ~Building();

    /**
     * @brief Return the descripition of the building 
    */
    std::string get_desc();

    /**
     * @brief Return the name of the building
    */
    std::string get_name();

    /**
     * @brief Return the number of the building
    */
    int get_number();

    /**
     * @brief Return the nuber of the battle
    */
    int get_numBattle();

    /**
     * @brief Set the nuber of the battle
    */
    void set_numBattle(int num);

    /**
     * @brief Starts a battle
    */
    void start_battle();

    /**
     * @brief Adds a battle on the stack
    */
    void add_battle();

    /**
     * @brief Removes a battle from the stack
    */
    void remove_battle();

    //bool play_battles(Battle* battle);

};

#endif