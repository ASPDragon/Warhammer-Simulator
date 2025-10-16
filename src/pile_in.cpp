//
// Created by sergeiavdoshkin on 7/7/25.
//

#include "pile_in.hpp"

#include "model.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include "unit.hpp"

bool PileInAction::validate() const{
    if (destinations.size() != unit.models.size()) return false;

    for (size_t i = 0; i < unit.models.size(); ++i) {
        size_t idx = destinations[i].first; // Ensure destination aligns with the current model

        auto currentModel = unit.models[i];
        if (currentModel.coords.calculateDistance(destinations[i].second) > maximumDistance)
            return false;

        std::vector<Unit> enemyUnits = {};

        for (auto& [key, value] : _state.units)
        {
            if (key != player)
                enemyUnits = std::move(value);
        }

        auto closestEnemy = _state.findClosestEnemyModel(unit.models[idx].id, currentModel.coords);
        if (!closestEnemy) return false;
        float oldCoordsToDestinationDistance = unit.models[idx].coords.calculateDistance(closestEnemy.value().position);

        float distanceBetweenBases = utils::distanceBetweenBases(unit.models[idx].coords, closestEnemy.value().position,
            unit.models[idx].baseRadius, closestEnemy->baseRadius);
        if (distanceBetweenBases <= maximumDistance) {
            auto baseToBaseVector = closestEnemy.value().position - currentModel.coords;
            auto newCoords = baseToBaseVector.normalized() * (baseToBaseVector.length() - currentModel.baseRadius - closestEnemy->baseRadius);
            float newCoordsToModelDistance = newCoords.calculateDistance(currentModel.coords);

            if (newCoordsToModelDistance <= maximumDistance) {
                auto finalPositionToEnemyDistance = destinations[i].calculateDistance(closestEnemy.value().position);
                auto newCoordsToDestinationDistance = newCoords.calculateDistance(closestEnemy.value().position);
                if (!utils::nearlyEqual(finalPositionToEnemyDistance, newCoordsToDestinationDistance)) {
                    return false;
                }
            }
        }
    }

    if (!unit.isCoherent())
        return false;
    return true;
}

void PileInAction::execute(){
}