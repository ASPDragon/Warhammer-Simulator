#pragma once

#include <string>
#include <vector>
#include "weapon.hpp"

class Datasheet {
public:
    Datasheet(std::string&& unitName, int&& move, int&& toughness, int&& save, int&& wounds, int&& leadership, int&& objectiveControl);

    bool isDead();

    void attack();
protected:
    std::string unitName;
    // std::string image;
    int move;
    int toughness;
    int save;
    int wounds;
    int leadership;
    int objectiveControl;

    std::vector<Weapon> armoury;
};