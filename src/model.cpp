#include "model.hpp"

#include "model.hpp"
#include "datasheet.hpp"
#include "weapon.hpp"

Model::Model(const Datasheet& datasheet)
: wounds{ datasheet.getWounds() } {}

bool Model::isDead() {
    return this->wounds == 0;
}