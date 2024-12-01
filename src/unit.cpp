#include "unit.hpp"
#include "datasheet.hpp"
#include "model.hpp"
#include "dice.hpp"
#include "weapon.hpp"

#include <algorithm>

Unit::Unit(Datasheet& datasheet)
: _datasheet{datasheet} {}

int Unit::attack(const Unit& enemyUnit, const Weapon& currentWeapon) const {
    int wounds = 0;
    int totalAttacksNum = 0;

    while (totalAttacksNum < currentWeapon.attacks)   {
        int rate = Dice::throwDice();

        if (currentWeapon.strength >= 2 * enemyUnit.getDatasheet().getToughness() && rate >= 2) {
            wounds += currentWeapon.damage;
        }
        else if (currentWeapon.strength > enemyUnit.getDatasheet().getToughness() && rate >= 3) {
            wounds += currentWeapon.damage;
        }
        else if (currentWeapon.strength == enemyUnit.getDatasheet().getToughness() && rate >= 4) {
            wounds += currentWeapon.damage;
        } 
        else if (currentWeapon.strength < enemyUnit.getDatasheet().getToughness()) {
            if (currentWeapon.strength <= 0.5 * enemyUnit.getDatasheet().getToughness() && rate >= 6) {
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

// bool Unit::isCoherent() const {
//     size_t modelsWithNeighbors = 0;
//     for (const auto& model : unit) {
//         size_t numberOfNeighbors = 0;
//         for (const auto& modelToCheck : unit) {
//             if (model.getCoords().calculateDistance(modelToCheck.getCoords()) <= 1.0)
//             numberOfNeighbors++;
//         }

//         if ((this->_datasheet.getModelsNum() < 6 && numberOfNeighbors >= 1) || (this->_datasheet.getModelsNum() >= 6 && numberOfNeighbors >= 2))
//             modelsWithNeighbors++;
//     }

//     if (modelsWithNeighbors == unit.size())
//         return true;
//     return false;
// }

bool Unit::isCoherent() const {
    double coherentDistance = 1.0;
    auto it = unit.begin() + 1;
    for (const auto& model : unit) {
        bool hasNeighbor = false;

        for ( ; it != std::end(unit); ++it) {
            if (model.getCoords().calculateDistance(it->getCoords()) <= coherentDistance) {
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