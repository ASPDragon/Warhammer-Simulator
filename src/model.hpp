/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

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

    virtual qtils::OptionalRef<const Weapon> getWeapon(const std::string& weaponName) const;
    virtual Coords getCoords() const { return coords; }

    virtual bool isDead() const;

    virtual void takeDamage(uint16_t& damage);
    
private:
    Coords coords;
    uint16_t wounds;
    std::vector<Weapon> weapons;
};