#include "unit.hpp"
#include "datasheet.hpp"
#include "model.hpp"
#include "dice.hpp"
#include "weapon.hpp"

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

bool Unit::isAlive() const  { 
    return _datasheet.getWounds() > 0;
}