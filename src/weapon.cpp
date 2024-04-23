#include "weapon.hpp"

int Weapon::getWeaponSkill() const {
        return weaponSkill.value_or(0);
}

int Weapon::getBallisticSkill() const {
        return ballisticSkill.value_or(0);
}