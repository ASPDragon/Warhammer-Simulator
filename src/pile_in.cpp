//
// Created by sergeiavdoshkin on 7/7/25.
//

#include "pile_in.hpp"

#include "model.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include "unit.hpp"

PileInAction::PileInAction(const std::shared_ptr<GameState>& state, const std::shared_ptr<Player>& player,
    const std::shared_ptr<Unit>& unit, const std::vector<std::pair<size_t, Vector>>& destinations, const distance_t maximum_distance)
: Action(state), player(player), unit(unit), destinations(destinations), maximum_distance(maximum_distance) {};

ValidationReport PileInAction::validate() const {
    if (destinations.size() != unit->models.size())
        return ValidationReport("Error: Invalid destination count");

    for (size_t model_index = 0; model_index < unit->models.size(); ++model_index) {
        const size_t destination_model_index = destinations[model_index].first;

        const auto &current_model = unit->models[model_index];

        if (current_model.coords.calculate_distance(destinations[model_index].second) >
            maximum_distance)
        {
            return ValidationReport("Error: Unit Is Too Far");
        }

        std::vector<Unit> enemy_units = {};

        for (auto& [player_key, player_units] : state.get()->units) {
            if (player_key != player->id)
                enemy_units = std::move(player_units);
        }

        auto closest_enemy =
            state.get()->find_closest_enemy_model(unit->models[destination_model_index].id,
                                         current_model.coords);

        if (!closest_enemy)
            return ValidationReport("Error: No Enemy Unit");

        float old_distance =
            unit->models[destination_model_index]
                .coords.calculate_distance(closest_enemy.value().position);

        const float distance_between_bases =
            utils::distance_between_bases(
                unit->models[destination_model_index].coords,
                closest_enemy.value().position,
                unit->models[destination_model_index].base_radius,
                state->units[closest_enemy.value().player_id][closest_enemy.value().unit_idx].models[closest_enemy.value().model_idx].base_radius);

        if (distance_between_bases <= maximum_distance) {
            auto base_to_base_vector =
                closest_enemy.value().position - current_model.coords;

            auto new_coords =
                base_to_base_vector.normalized() *
                (base_to_base_vector.length() -
                 current_model.base_radius -
                 state.get()->units[closest_enemy.value().player_id][closest_enemy.value().unit_idx].models[closest_enemy.value().model_idx].base_radius);

            const float new_distance =
                new_coords.calculate_distance(current_model.coords);

            if (new_distance >= old_distance && !utils::nearly_equal(new_distance, old_distance))
            {
                return ValidationReport("Error: Not Closer To Enemy");
            }

            if (new_distance <= maximum_distance) {
                const auto final_position_to_enemy_distance =
                    destinations[model_index]
                        .second.calculate_distance(closest_enemy.value().position);

                const auto new_coords_to_destination_distance =
                    new_coords.calculate_distance(closest_enemy.value().position);

                if (!utils::nearly_equal(final_position_to_enemy_distance,
                                        new_coords_to_destination_distance))
                {
                    return ValidationReport("Unit Is Too Far");
                }
            }
        }
    }

    if (!unit->is_coherent())
        return ValidationReport("Error: Unit Is Not Coherent");

    return ValidationReport("");
}

void PileInAction::execute(){
}