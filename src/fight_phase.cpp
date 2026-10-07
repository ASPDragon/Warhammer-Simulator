/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "fight_phase.hpp"

#include "datasheet.hpp"
#include "unit.hpp"
#include "model.hpp"
#include "vector.hpp"
#include "utils.hpp"

#include <limits>
#include <utility>
#include <algorithm>
#include <format>
#include <stdexcept>

bool Fight_Phase::pileIn(const Unit& currentUnit, const std::span<std::pair<size_t, Vector>> destination,
    const std::span<Unit> enemyUnits, const float maximumDistance) const {
    if (destination.size() != currentUnit.models.size()) return false;
    
    for (size_t i = 0; i < currentUnit.models.size(); ++i) {
        size_t idx = destination[i].first; // Ensure destination aligns with the current model

        auto currentModel = currentUnit.models[i];
        if (currentModel.coords.calculate_distance(destination[i].second) > maximumDistance)
            return false;

        auto closestEnemy = find_closest_enemy(currentUnit.models[idx], enemyUnits);
        if (!closestEnemy) return false;
        float oldCoordsToDestinationDistance = currentUnit.models[idx].coords.calculate_distance(closestEnemy->coords);

        float distanceBetweenBases = utils::distance_between_bases(currentUnit.models[idx].coords, closestEnemy->coords,
            currentUnit.models[idx].base_radius, closestEnemy->base_radius);
        if (distanceBetweenBases <= maximumDistance) {
            auto baseToBaseVector = closestEnemy->coords - currentModel.coords;
            auto newCoords = baseToBaseVector.normalized() * (baseToBaseVector.length() - currentModel.base_radius - closestEnemy->base_radius);
            float newCoordsToModelDistance = newCoords.calculate_distance(currentModel.coords);

            if (newCoordsToModelDistance <= maximumDistance) {
                auto finalPositionToEnemyDistance = destination[i].second.calculate_distance(closestEnemy->coords);
                auto newCoordsToDestinationDistance = newCoords.calculate_distance(closestEnemy->coords);
                if (!utils::nearly_equal(finalPositionToEnemyDistance, newCoordsToDestinationDistance)) {
                    return false;
                }
            }
        }
    }

    if (!currentUnit.is_coherent())
        return false;
    return true;
}

bool Fight_Phase::is_within_engagement_range(const Model& model, const std::span<Unit> enemyUnits, double range) const {
    for (const auto& enemyUnit : enemyUnits) {
        for (const auto& enemyModel : enemyUnit.models) {
            if (model.coords.calculate_distance(enemyModel.coords) <= range)
                return true;
        }
    }

    return false;
}


const Model* Fight_Phase::find_closest_enemy(const Model& model, const std::span<Unit> enemyUnits) const {
    double minimalDistance = std::numeric_limits<double>::max();
    const Model* nearestEnemyModel = nullptr;

    for (auto& enemyUnit : enemyUnits) {
        for (auto& enemyModel : enemyUnit.models) {
            if (double currentDistance = model.coords.calculate_distance(enemyModel.coords); currentDistance < minimalDistance) {
                minimalDistance = currentDistance;
                nearestEnemyModel = &enemyModel;
            }
        }
    }
    return nearestEnemyModel;
}

bool Fight_Phase::can_fight(const Unit& unit) const {
    bool hasMelee = std::ranges::any_of(unit.models,
        [](Model const& m){
            return std::ranges::any_of(m.weapons, &Weapon::is_melee);
        });
    return unit.is_alive() && hasMelee;
}

void Fight_Phase::fight(const Unit& currentUnit, const std::span<std::pair<size_t, Weapon&>> selectedWeapons, const Unit& enemyUnit, const uint16_t maximumDistance) const
{
    if (!can_fight(currentUnit) || selectedWeapons.size() != currentUnit.models.size())
        throw std::logic_error{std::format("Unit #{} can't fight", currentUnit._datasheet.unit_id)};

    for (const auto& model : currentUnit.models)
    {

    }
}