#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>
#include <vector>
#include <stack>

class Building {

    private:
    //std::stack<Battle*> _battles;
    std::string _desc;
    std::string _name;
    int _number;

    public:
    Building(std::string desc, std::string name, int number);

    std::string get_desc();

    std::string get_name();

    int get_number();

    void start_battle();

    void add_battle();
    
    void remove_battle();

    //bool play_battles(Battle* battle);

};

#endif