/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "model.hpp"

#include <algorithm>
#include <iterator>

#include "datasheet.hpp"
#include "optional_ref.hpp"
#include "weapon.hpp"

Model::Model(const Datasheet& datasheet)
: base_radius{ static_cast<uint16_t>(datasheet._base_diameter / 2)}, move { datasheet._move }, toughness { datasheet._toughness },
    save { datasheet._save }, wounds{ datasheet._wounds } {}

// qtils::OptionalRef<const Weapon> Model::getWeapon(const std::string& weaponName) const {
//     auto weapon = std::find_if(std::begin(weapons), std::end(weapons), 
//                                [&weaponName](const Weapon& w) { 
//                                    return weaponName == w.name; 
//                                });
    
//     if (weapon != std::end(weapons)) {
//         return qtils::OptionalRef<const Weapon>(*weapon);
//     }
    
//     return std::nullopt;
// }


bool Model::is_dead() const {
    return this->wounds == 0;
}

void Model::take_damage(uint16_t& damage) {
    if (this->is_dead()) return;

    if (this->wounds >= damage)
        this->wounds -= damage;
    else 
        this->wounds = 0;
}