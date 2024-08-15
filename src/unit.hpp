#pragma once

#include "weapon.hpp"
#include <vector>

class Datasheet;
class Model;
class Weapon;

class Unit {
public:
    Unit(Datasheet& datasheet);

    Datasheet& getDatasheet() const { return _datasheet; }

    int Attack(const Unit& enemyUnit, const Weapon& currentWeapon);
    
private:
    Datasheet& _datasheet;
    std::vector<Model> unit;
};