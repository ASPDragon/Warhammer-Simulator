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
    for (size_t num = 0; num < _datasheet.models_num; ++num)
        models.push_back(_datasheet);
}

int Unit::attack(const Unit& enemyUnit, const Weapon& currentWeapon) const {
    int wounds = 0;
    int totalAttacksNum = 0;

    while (totalAttacksNum < currentWeapon.attacks)   {
        int rate = Dice::throw_dice();

        if (currentWeapon.strength >= 2 * enemyUnit._datasheet.toughness && rate >= 2) {
            wounds += currentWeapon.damage;
        }
        else if (currentWeapon.strength > enemyUnit._datasheet.toughness && rate >= 3) {
            wounds += currentWeapon.damage;
        }
        else if (currentWeapon.strength == enemyUnit._datasheet.toughness && rate >= 4) {
            wounds += currentWeapon.damage;
        } 
        else if (currentWeapon.strength < enemyUnit._datasheet.toughness) {
            if (currentWeapon.strength <= 0.5 * enemyUnit._datasheet.toughness && rate >= 6) {
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

bool Unit::is_coherent() const {
    if (models.empty() || models.size() == 1) return  true;

    double coherentDistance = 1.0;

    for (auto current = models.begin(); current != std::prev(models.end()); ++current) {
        bool hasNeighbor = false;

        for (auto other = std::next(current); other != models.end(); ++other) {
            if (current->coords.calculate_distance(other->coords) <= coherentDistance) {
                hasNeighbor = true;
                break;
            }
        }

        if (hasNeighbor == false) return false;
    }
    return true;
}

bool Unit::is_alive() const  { 
    return !models.empty();
}

void Unit::casualty_handling() {
    models.erase(std::remove_if(std::begin(models), std::end(models),
                [](const Model& m) { return m.is_dead(); }),
                models.end());
}