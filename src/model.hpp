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

struct Weapon;
class Datasheet;

struct Model {
    explicit Model(const Datasheet& datasheet);
    virtual ~Model() = default;
    
    Vector coords;
    uint32_t id;
    float base_radius;
    uint16_t move;
    uint16_t toughness;
    uint16_t save;
    uint16_t wounds;
    std::vector<Weapon> weapons;

protected:
    [[nodiscard]] virtual bool is_dead() const;
    virtual void take_damage(uint16_t& damage);
};