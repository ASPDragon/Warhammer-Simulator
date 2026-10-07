//
// Created by sergeiavdoshkin on 8/3/25.
//

#include <ranges>
#include <iterator>

#include "game_state.hpp"

#include "datasheet.hpp"
#include "model.hpp"
#include "vector.hpp"

GameState::GameState(std::unordered_map<player_id_t, std::vector<Unit>>& units, std::vector<Objective>& objectives)
    : units{ units }, objectives{ objectives } {}

model_idx_t GameState::find_closest_model(Unit& unit, const std::shared_ptr<Vector>& origin)
{
    Model closestModel = *unit.models.begin();
    for (auto it = std::next(unit.models.begin()); it != unit.models.end(); ++it)
    {
        if (closestModel.coords.calculate_distance(*origin) > it->coords.calculate_distance(*origin))
            closestModel = *it;
    }
    return closestModel.id;
}

std::optional<Closest_Model> GameState::find_closest_enemy_model(player_id_t current_player, const std::shared_ptr<Vector>& origin) {
    std::optional<Closest_Model> closest_model;
    for (auto& [player, playerUnits] : units) {
        if (player == current_player) continue;
        for (auto [unit_idx, unit] : playerUnits | std::views::enumerate) {
            // option because they all could be dead
            std::optional model_id  = find_closest_model(unit, origin);
            if (model_id && (!closest_model || closest_model->position.calculate_distance(*origin) > unit.models[*model_id].coords.calculate_distance(*origin))) {
                closest_model = {player, unit._datasheet.unit_id, *model_id, unit.models[*model_id].coords};
            }
        }
    }
    return closest_model;
}
