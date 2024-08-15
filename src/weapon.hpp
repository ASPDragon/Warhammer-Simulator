#pragma once

#include <string>
#include <optional>

enum class WeaponType {
    Pistol
};

struct Weapon {
    std::string name;
    int attacks;
    enum { Melee, Ranged };
    uint16_t skill;
    int strength;
    int armourPenetration;
    int damage;
};