//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include <span>
#include <unordered_map>
#include <optional>

#include "unit.hpp"
#include "vector.hpp"
#include "objective.hpp"

using player_id_t = uint32_t;
using unit_idx_t = uint32_t;
using model_idx_t = uint32_t;

struct Closest_Model
{
    player_id_t player_id;
    unit_idx_t unit_idx;
    model_idx_t model_idx;
    Vector position;
};

struct GameState
{
    GameState(std::unordered_map<player_id_t, std::vector<Unit>>&, std::vector<Objective>&);
    model_idx_t find_closest_model(Unit&, const std::shared_ptr<Vector>&);
    std::optional<Closest_Model> find_closest_enemy_model(player_id_t current_player, const std::shared_ptr<Vector>&);

    std::unordered_map<player_id_t, std::vector<Unit>> units;
    std::vector<Objective> objectives;
};