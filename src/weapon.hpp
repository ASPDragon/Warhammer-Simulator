/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <string>
#include <cstdint>

enum class WeaponType {
    Pistol,
    Rapid_Fire,
    Assault,
    Heavy,
    Grenades,
    Flame_Weapons,
    Blast_Weapons,
    Ordnance,
    Lexicanum
};

struct Weapon {
    bool isMelee() const { return range == 0.0; }
    bool isRanged() const { return !isMelee(); }
    std::string name;
    float range;
    uint16_t attacks;
    uint16_t skill;
    uint16_t strength;
    uint16_t armourPenetration;
    uint16_t damage;
};