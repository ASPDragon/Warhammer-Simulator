//
// Created by sergeiavdoshkin on 7/7/25.
//

#include "pile_in.hpp"

#include "model.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include "unit.hpp"

std::string PileInAction::validate() const {
    if (destinations.size() != unit.models.size())
        return "Error: ";

    for (size_t model_index = 0; model_index < unit.models.size(); ++model_index) {
        const distance_t destination_model_index = destinations[model_index].first;

        auto current_model = unit.models[model_index];

        if (current_model.coords.calculate_distance(destinations[model_index].second) >
            maximum_distance)
        {
            return "Error: The target unit is too far";
        }

        std::vector<Unit> enemy_units = {};

        for (auto& [player_key, player_units] : _state.get()->units) {
            if (player_key != player.id)
                enemy_units = std::move(player_units);
        }

        auto closest_enemy =
            _state.get()->find_closest_enemy_model(unit.models[destination_model_index].id,
                                         current_model.coords);

        if (!closest_enemy)
            return "Error: There's no enemy unit!";

        float old_coords_to_destination_distance =
            unit.models[destination_model_index]
                .coords.calculate_distance(closest_enemy.value().position);

        float distance_between_bases =
            utils::distance_between_bases(
                unit.models[destination_model_index].coords,
                closest_enemy.value().position,
                unit.models[destination_model_index].base_radius,
                _state.get()->units[closest_enemy.value().player_id][closest_enemy.value().unit_idx].models[closest_enemy.value().model_idx].base_radius);

        if (distance_between_bases <= maximum_distance) {
            auto base_to_base_vector =
                closest_enemy.value().position - current_model.coords;

            auto new_coords =
                base_to_base_vector.normalized() *
                (base_to_base_vector.length() -
                 current_model.base_radius -
                 _state.get()->units[closest_enemy.value().player_id][closest_enemy.value().unit_idx].models[closest_enemy.value().model_idx].base_radius);

            float new_coords_to_model_distance =
                new_coords.calculate_distance(current_model.coords);

            if (new_coords_to_model_distance <= maximum_distance) {
                auto final_position_to_enemy_distance =
                    destinations[model_index]
                        .second.calculate_distance(closest_enemy.value().position);

                auto new_coords_to_destination_distance =
                    new_coords.calculate_distance(closest_enemy.value().position);

                if (!utils::nearly_equal(final_position_to_enemy_distance,
                                        new_coords_to_destination_distance))
                {
                    return "Error: ";
                }
            }
        }
    }

    if (!unit.is_coherent())
        return "Error: The unit is not coherent!";

    return "Time to Pile In!";
}


void PileInAction::execute(){
}