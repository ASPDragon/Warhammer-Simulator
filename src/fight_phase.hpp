/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <cstdint>
#include <vector>

// class Player;
class Unit;
class Model;
struct Vector;
struct Weapon;

class FightPhase {
public:
    // FightPhase();
    bool pileIn(const Unit& currentUnit, const std::vector<std::pair<size_t, Vector>>& destination, const std::vector<Unit>& enemyUnits, const float maximumDistance) const;
    bool isWithinEngagementRange(const Model& model, const std::vector<Unit>& enemyUnits, double range) const;

    const Model* findClosestEnemy(const Model& model, const std::vector<Unit>& enemyUnits) const;

    size_t calculateAttacks(const Unit& unit) const;

    void fight(const Unit& currentUnit, const std::vector<std::pair<size_t, Weapon&>> selectedWeapons, const Unit& enemyUnit, const uint16_t maximumDistance);

protected:
    bool hasCharged(const Unit& unit) const;
    bool canFight(const Unit& unit) const;
    
private:
    // std::vector<Player> players;
};