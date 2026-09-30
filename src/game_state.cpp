//
// Created by sergeiavdoshkin on 8/3/25.
//

#include <ranges>
#include <iterator>

#include "game_state.hpp"

#include "datasheet.hpp"
#include "model.hpp"

uint32_t Game_State::find_closest_model(Unit& unit, Vector origin)
{
    Model closestModel = *unit.models.begin();
    for (auto it = std::next(unit.models.begin()); it != unit.models.end(); ++it)
    {
        if (closestModel.coords.calculate_distance(origin) > it->coords.calculate_distance(origin))
            closestModel = *it;
    }
    return closestModel.id;
}

std::optional<Closest_Model> Game_State::find_closest_enemy_model(uint32_t current_player, Vector origin) {
    std::optional<Closest_Model> closest_model;
    for (auto& [player, playerUnits] : units) {
        if (player.id == current_player) continue;
        for (auto [unit_idx, unit] : playerUnits | std::views::enumerate) {
            // option because they all could be dead
            std::optional<uint32_t> model_id  = find_closest_model(unit, origin);
            if (model_id && (!closest_model || closest_model->position.calculate_distance(origin) > unit.models[*model_id].coords.calculate_distance(origin))) {
                closest_model = {player.id, unit._datasheet.unit_id, *model_id, unit.models[*model_id].coords};
            }
        }
    }
    return closest_model;
}
