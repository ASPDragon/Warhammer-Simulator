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
    int attack(const Unit& enemyUnit, const Weapon& currentWeapon) const;

    bool isCoherent() const;
    bool isAlive() const;

    void casualtyHandling();
    
private:
    Datasheet& _datasheet;
    std::vector<Model> unit;
    bool hasCharged = false;
};