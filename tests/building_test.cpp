#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/match.hpp"
#include "../include/building.hpp"
#include "../include/entities/pc.hpp"
#include "../third_party/doctest.h"

TEST_CASE("Construtor de Building que lê de arquivo"){
    Match a;
    a.setPlayer(0);
    Pc* player = a.getPlayer();
    Building b = Building(player, "lib/buildings/Fafich.txt");
    CHECK(b.get_name() = "FAFICH");
    CHECK(b.get_desc() = "Seja bem-vind@ à Fafich! Espero que você tenha um bom tempo enquanto anda por aqui :)");
    CHECK(b.get_number() = 4);
}


TEST_CASE("Função isComplete"){
    Match a;
    a.setPlayer(0);
    a.setBuildingStack();
    std::stack<Building*>* buildings = a.getBuildingStack();
    std::stack<Battle*>* battles = (buildings->top())->getBattleStack();
    CHECK_EQ(false, (buildings->top())->isComplete());
    battles->pop();
    CHECK_EQ(true, (buildings->top())->isComplete());
}
