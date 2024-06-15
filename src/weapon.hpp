#pragma once

#include <string>
#include <optional>

enum class WeaponType {
    Pistol
};

struct Weapon {
    std::string name;
    int attacks;
    bool canShot;
    std::optional<int> weaponSkill;
    std::optional<int> ballisticSkill;
    int strength;
    int armourPenetration;
    int damage;
};