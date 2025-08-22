//
// Created by sergeiavdoshkin on 8/3/25.
//

#include <ranges>
#include <iterator>

#include "game_state.hpp"

#include "datasheet.hpp"
#include "model.hpp"

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
        if (player.id == currentPlayer) continue;
        for (auto [unit_idx, unit] : playerUnits | std::views::enumerate) {
            // option cause they all could be dead
            std::optional<uint32_t> modelId  = findClosestModel(unit, origin);
            if (modelId && (!closest_model || closest_model->position.calculateDistance(origin) > unit.models[*modelId].coords.calculateDistance(origin))) {
                closest_model = {player.id, unit._datasheet._unitId, *modelId, unit.models[*modelId].coords};
            }
        }
    }
    return closest_model;
}
