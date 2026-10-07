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

struct Weapon;
struct Datasheet;

struct Model {
    explicit Model(uint32_t, const Datasheet&, const Vector& coords);
    virtual ~Model() = default;

    uint32_t id;
    float base_radius;
    uint16_t move;
    uint16_t toughness;
    uint16_t save;
    uint16_t wounds;
    Vector coords;
    std::vector<Weapon> weapons;

    [[nodiscard]] virtual bool is_dead() const;
    virtual void take_damage(uint16_t& damage);
};