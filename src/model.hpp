#pragma once

#include <vector>
#include <string>
#include "coords.hpp"

class Weapon;

class Model {
public:
    Model();

    Weapon& getWeapon(std::string& weaponName) const;
    Coords getCoords() const { return coords; }

    bool isDead();
    
private:
    Coords coords;
    unsigned int wounds;
    std::vector<Weapon> weapons;
};