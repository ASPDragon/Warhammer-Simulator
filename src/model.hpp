#pragma once

#include <vector>
#include <string>
#include "utils.hpp"

class Datasheet;
class Weapon;

class Model {
public:
    Model();

    Weapon& getWeapon(std::string& weaponName);

    bool isDead();
    
private:
    Datasheet& _datasheet;
    Coords coords;
    std::vector<Weapon> someName;
};