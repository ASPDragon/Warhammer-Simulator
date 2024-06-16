#pragma once

#include <vector>
#include <string>
#include "utils.cpp"

class Datasheet;
class Weapon;

class Model {
public:
    Model();

    Weapon& getWeapon(std::string& weaponName);
private:
    Datasheet& _datasheet;
    Coords coords;
    std::vector<Weapon> someName;
};