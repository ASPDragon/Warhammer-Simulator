/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <cstdint>
#include <span>

// class Player;
class Unit;
class Model;
struct Vector;
struct Weapon;

class Fight_Phase {
public:
    // FightPhase();
    bool pileIn(const Unit& currentUnit, std::span<std::pair<size_t, Vector>> destination, const std::span<Unit> enemyUnits, float maximumDistance) const;
    bool is_within_engagement_range(const Model& model, std::span<Unit> enemyUnits, double range) const;

    const Model* find_closest_enemy(const Model& model, const std::span<Unit> enemyUnits) const;

    size_t calculate_attacks(const Unit& unit) const;

    void fight(const Unit& currentUnit, std::span<std::pair<size_t, Weapon&>> selectedWeapons, const Unit& enemyUnit, uint16_t maximumDistance);

protected:
    bool has_charged(const Unit& unit) const;
    bool can_fight(const Unit& unit) const;
    
private:
};