/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "fight_phase.hpp"
#include "player.hpp"
#include "unit.hpp"
#include "model.hpp"
#include "vector.hpp"
#include "utils.hpp"

#include <limits>
#include <utility>
#include <algorithm>
// #include <exception>

bool FightPhase::pileIn(const Unit& currentUnit, const std::vector<std::pair<size_t, Vector>>& destination,
    const std::vector<Unit>& enemyUnits, const float maximumDistance) const {
    if (destination.size() != currentUnit.models.size()) return false;
    
    for (size_t i = 0; i < currentUnit.models.size(); ++i) {
        size_t idx = destination[i].first; // Ensure destination aligns with the current model

        auto currentModel = currentUnit.models[i];
        if (currentModel.coords.calculateDistance(destination[i].second) > maximumDistance)
            return false;

        auto closestEnemy = findClosestEnemy(currentUnit.models[idx], enemyUnits);
        if (!closestEnemy) return false;
        float oldCoordsToDestinationDistance = currentUnit.models[idx].coords.calculateDistance(closestEnemy->coords);

        float distanceBetweenBases = utils::distanceBetweenBases(currentUnit.models[idx].coords, closestEnemy->coords,
            currentUnit.models[idx].baseRadius, closestEnemy->baseRadius);
        if (distanceBetweenBases <= maximumDistance) {
            auto baseToBaseVector = closestEnemy->coords - currentModel.coords;
            auto newCoords = baseToBaseVector.normalized() * (baseToBaseVector.length() - currentModel.baseRadius - closestEnemy->baseRadius);
            float newCoordsToModelDistance = newCoords.calculateDistance(currentModel.coords);

            if (newCoordsToModelDistance <= maximumDistance) {
                auto finalPositionToEnemyDistance = destination[i].second.calculateDistance(closestEnemy->coords);
                auto newCoordsToDestinationDistance = newCoords.calculateDistance(closestEnemy->coords);
                if (!utils::nearlyEqual(finalPositionToEnemyDistance, newCoordsToDestinationDistance)) {
                    return false;
                }
            }
        }
    }

    if (!currentUnit.isCoherent())
        return false;
    return true;
}

bool FightPhase::isWithinEngagementRange(const Model& model, const std::vector<Unit>& enemyUnits, double range) const {
    for (const auto& enemyUnit : enemyUnits) {
        for (const auto& enemyModel : enemyUnit.models) {
            if (model.coords.calculateDistance(enemyModel.coords) <= range)
                return true;
        }
    }

    return false;
}

const Model* FightPhase::findClosestEnemy(const Model& model, const std::vector<Unit>& enemyUnits) const {
    double minimalDistance = std::numeric_limits<double>::max();
    const Model* nearestEnemyModel = nullptr;

    for (auto& enemyUnit : enemyUnits) {
        for (auto& enemyModel : enemyUnit.models) {
            if (double currentDistance = model.coords.calculateDistance(enemyModel.coords); currentDistance < minimalDistance) {
                minimalDistance = currentDistance;
                nearestEnemyModel = &enemyModel;
            }
        }
    }
    return nearestEnemyModel;
}

bool FightPhase::canFight(const Unit& unit) const {
    bool hasMelee = std::ranges::any_of(unit.models,
        [](Model const& m){
            return std::ranges::any_of(m.weapons, &Weapon::isMelee);
        });
    return unit.isAlive() && hasMelee;
}