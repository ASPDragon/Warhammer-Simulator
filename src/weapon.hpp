#pragma once

#include <string>
#include <cstdint>

enum class WeaponType {
    Pistol
};

struct Weapon {
    std::string name;
    uint16_t attacks;
    enum { Melee, Ranged };
    uint16_t skill;
    uint16_t strength;
    uint16_t armourPenetration;
    uint16_t damage;
};