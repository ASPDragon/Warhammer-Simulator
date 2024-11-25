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

bool Model::isDead() {
    return this->wounds == 0;
}