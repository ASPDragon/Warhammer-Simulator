#pragma once

#include <vector>
#include <string>
#include "utils.hpp"

class Datasheet;
class Weapon;

class Model {
public:
    Model(const Datasheet& datasheet);

    Weapon& getWeapon(std::string& weaponName) const;

    bool isDead();
    
private:
    const Datasheet& _datasheet;
    Coords coords;
    unsigned int wounds;
    std::vector<Weapon> someName;
};