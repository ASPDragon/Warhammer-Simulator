#include "model.hpp"

#include <algorithm>
#include <iterator>

#include "datasheet.hpp"
#include "weapon.hpp"

Model::Model(const Datasheet& datasheet)
: wounds{ datasheet.getWounds() } {}

const Weapon* Model::getWeapon(std::string& weaponName) const {
    auto weapon = std::find_if(std::begin(weapons), std::end(weapons), [&](const Weapon& w) { 
        return weaponName == w.name; 
    });
    if (weapon != std::end(weapons))
        return &(*weapon);
    return nullptr;
}

bool Model::isDead() const {
    return this->wounds == 0;
}

void Model::takeDamage(uint16_t& damage) {
    if (this->isDead()) return;

    if (this->wounds >= damage)
        this->wounds -= damage;
    else 
        this->wounds = 0;
}