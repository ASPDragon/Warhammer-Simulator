/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "unit.hpp"

#include <algorithm>

#include "datasheet.hpp"
#include "model.hpp"
#include "dice.hpp"
#include "weapon.hpp"

Unit::Unit(Datasheet& datasheet)
: _datasheet{datasheet} {
    for (size_t num = 0; num < _datasheet._modelsNum; ++num)
        unit.push_back(_datasheet);
}

int Unit::attack(const Unit& enemyUnit, const Weapon& currentWeapon) const {
    int wounds = 0;
    int totalAttacksNum = 0;

    while (totalAttacksNum < currentWeapon.attacks)   {
        int rate = Dice::throwDice();

        if (currentWeapon.strength >= 2 * enemyUnit._datasheet._toughness && rate >= 2) {
            wounds += currentWeapon.damage;
        }
        else if (currentWeapon.strength > enemyUnit._datasheet._toughness && rate >= 3) {
            wounds += currentWeapon.damage;
        }
        else if (currentWeapon.strength == enemyUnit._datasheet._toughness && rate >= 4) {
            wounds += currentWeapon.damage;
        } 
        else if (currentWeapon.strength < enemyUnit._datasheet._toughness) {
            if (currentWeapon.strength <= 0.5 * enemyUnit._datasheet._toughness && rate >= 6) {
                wounds += currentWeapon.damage;
            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
        totalAttacksNum++;
    }

    return wounds;
}

bool Unit::isCoherent() const {
    if (unit.empty() || unit.size() == 1) return  true;

    double coherentDistance = 1.0;

    for (auto current = unit.begin(); current != std::prev(unit.end()); ++current) {
        bool hasNeighbor = false;

        for (auto other = std::next(current); other != unit.end(); ++other) {
            if (current->coords.calculateDistance(other->coords) <= coherentDistance) {
                hasNeighbor = true;
                break;
            }
        }

        if (hasNeighbor == false) return false;
    }
    return true;
}

bool Unit::isAlive() const  { 
    return !unit.empty();
}

void Unit::casualtyHandling() {
    unit.erase(std::remove_if(std::begin(unit), std::end(unit),
                [](const Model& m) { return m.isDead(); }),
                unit.end());
}