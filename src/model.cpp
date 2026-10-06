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

Model::Model(const uint32_t id, const Datasheet& datasheet, const Vector& coords)
: id{ id }, base_radius{ datasheet.base_diameter / 2.0f }, move { datasheet.move }, toughness { datasheet.toughness },
    save { datasheet.save }, wounds{ datasheet.wounds }, coords{ coords } {}


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