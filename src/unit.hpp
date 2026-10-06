/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include "weapon.hpp"
#include <vector>

struct Datasheet;
struct Model;
struct Weapon;

struct Unit {
    explicit Unit(Datasheet& datasheet);

    // Datasheet& getDatasheet() const { return _datasheet; }
    [[nodiscard]] int attack(const Unit& enemyUnit, const Weapon& currentWeapon) const;

    [[nodiscard]] bool is_coherent() const;
    [[nodiscard]] bool is_alive() const;

    void casualty_handling();

    Datasheet& _datasheet;
    std::vector<Model> models;
    bool hasCharged = false;
};