/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include "weapon.hpp"
#include <vector>

class Datasheet;
class Model;
class Weapon;

struct Unit {
    Unit(Datasheet& datasheet);

    // Datasheet& getDatasheet() const { return _datasheet; }
    int attack(const Unit& enemyUnit, const Weapon& currentWeapon) const;

    bool isCoherent() const;
    bool isAlive() const;

    void casualtyHandling();

    Datasheet& _datasheet;
    std::vector<Model> models;
    bool hasCharged = false;
};