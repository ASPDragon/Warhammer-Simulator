#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include "coords.hpp"
#include "optional_ref.hpp"

class Weapon;
class Datasheet;

class Model {
public:
    Model(const Datasheet& datasheet);

    qtils::OptionalRef<const Weapon> getWeapon(std::string& weaponName) const;
    Coords getCoords() const { return coords; }

    bool isDead() const;

    void takeDamage(uint16_t& damage);
    
private:
    Coords coords;
    uint16_t wounds;
    std::vector<Weapon> weapons;
};