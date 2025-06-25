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

class FightPhase {
public:
    // FightPhase();
    bool pileIn(const Unit& currentUnit, std::span<std::pair<size_t, Vector>> destination, const std::span<Unit> enemyUnits, float maximumDistance) const;
    bool isWithinEngagementRange(const Model& model, std::span<Unit> enemyUnits, double range) const;
    bool validateFight() const;

    const Model* findClosestEnemy(const Model& model, const std::span<Unit> enemyUnits) const;

    size_t calculateAttacks(const Unit& unit) const;

    void fight(const Unit& currentUnit, std::span<std::pair<size_t, Weapon&>> selectedWeapons, const Unit& enemyUnit, uint16_t maximumDistance);

protected:
    bool hasCharged(const Unit& unit) const;
    bool canFight(const Unit& unit) const;
    
private:
    // std::vector<Player> players;
};