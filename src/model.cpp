#include "model.hpp"

#include <algorithm>
#include <iterator>

#include "datasheet.hpp"
#include "optional_ref.hpp"
#include "weapon.hpp"

Model::Model(const Datasheet& datasheet)
: wounds{ datasheet.getWounds() } {}

qtils::OptionalRef<const Weapon> Model::getWeapon(std::string& weaponName) const {
    auto weapon = std::find_if(std::begin(weapons), std::end(weapons), 
                               [&weaponName](const Weapon& w) { 
                                   return weaponName == w.name; 
                               });
    
    if (weapon != std::end(weapons)) {
        return qtils::OptionalRef<const Weapon>(*weapon);
    }
    
    return std::nullopt;
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