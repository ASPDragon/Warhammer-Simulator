#pragma once

#include <vector>
#include "utils.cpp"

class Datasheet;
class Weapon;

class Model {
public:
    Model();

    Weapon& getWeapon() {}
private:
    Datasheet& datasheet;
    Coords coords;
    std::vector<Weapon> someName;
};