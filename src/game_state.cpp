//
// Created by sergeiavdoshkin on 8/3/25.
//

#include "game_state.hpp"

#include "model.hpp"

// const Model* GameState::findClosestEnemy(const Model& model, const std::span<Unit> enemyUnits) const {
//     double minimalDistance = std::numeric_limits<double>::max();
//     const Model* nearestEnemyModel = nullptr;
//
//     for (auto& enemyUnit : enemyUnits) {
//         for (auto& enemyModel : enemyUnit.models) {
//             if (double currentDistance = model.coords.calculateDistance(enemyModel.coords); currentDistance < minimalDistance) {
//                 minimalDistance = currentDistance;
//                 nearestEnemyModel = &enemyModel;
//             }
//         }
//     }
//     return nearestEnemyModel;
// }

uint32_t GameState::findClosestModel(Unit& unit, Vector origin)
{
    Model closestModel = *unit.models.begin();
    for (auto it = std::next(unit.models.begin()); it != unit.models.end(); ++it)
    {
        if (closestModel.coords.calculateDistance(origin) > it->coords.calculateDistance(origin))
            closestModel = *it;
    }
    return closestModel.id;
}

std::optional<ClosestModel> GameState::findClosestEnemyModel(uint32_t currentPlayer, Vector origin) {
    std::optional<ClosestModel> closest_model;
    for (auto& [player, playerUnits] : units) {
        if (player == currentPlayer) continue;
        for (auto [unit_idx, unit] : playerUnits | std::views::enumerate) {
            // option cause they all could be dead
            std::optional<uint32_t> modelId  = findClosestModel(unit, origin);
            if (modelId && (!closest_model || distance(closest_model->position, origin) > distance(unit[*modelId].position, origin))) {
                closest_model = {player, unit_id, *modelId, unit[*modelId].position};
            }
        }
    }
    return closest_model;
}