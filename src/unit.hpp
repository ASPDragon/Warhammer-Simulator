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
    Unit() = default;

    // Datasheet& getDatasheet() const { return _datasheet; }
    int attack(const Unit& enemyUnit, const Weapon& currentWeapon) const;

    bool is_coherent() const;
    bool is_alive() const;

    void casualty_handling();

    Datasheet& _datasheet;
    std::vector<Model> models;
    bool hasCharged = false;
};