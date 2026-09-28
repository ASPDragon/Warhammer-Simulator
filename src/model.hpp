/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include "vector.hpp"
#include "optional_ref.hpp"

class Weapon;
class Datasheet;

struct Model {
    Model(const Datasheet& datasheet);

    // virtual qtils::OptionalRef<const Weapon> getWeapon(const std::string& weaponName) const;
    // virtual Coords getCoords() const { return coords; }
    
    Vector coords;
    uint32_t id;
    uint16_t base_radius;
    uint16_t move;
    uint16_t toughness;
    uint16_t save;
    uint16_t wounds;
    std::vector<Weapon> weapons;

protected:
    [[nodiscard]] virtual bool is_dead() const;
    virtual void take_damage(uint16_t& damage);
};