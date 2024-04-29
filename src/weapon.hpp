#pragma once

#include <optional>

enum class WeaponType {
    Pistol
};

struct Weapon {
    int attacks;
    bool canShot;
    std::optional<int> weaponSkill;
    std::optional<int> ballisticSkill;
    int strength;
    int armourPenetration;
    int damage;
};