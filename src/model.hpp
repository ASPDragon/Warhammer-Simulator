#pragma once

#include <vector>
#include <string>
#include "utils.hpp"

class Weapon;

class Model {
public:
    Model();

    Weapon& getWeapon(std::string& weaponName) const;

    bool isDead();
    
private:
    Coords coords;
    unsigned int wounds;
    std::vector<Weapon> someName;
};