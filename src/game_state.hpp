//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include <span>
#include <map>
#include <optional>

#include "player.hpp"
#include "unit.hpp"
#include "vector.hpp"
#include "objective.hpp"

struct Closest_Model
{
    uint32_t player_id;
    uint32_t unit_idx;
    uint32_t model_idx;
    Vector position;
};

struct Game_State
{
    std::optional<Closest_Model> find_closest_enemy_model(uint32_t current_player, Vector origin);
    uint32_t find_closest_model(Unit& unit, Vector origin);

    std::map<Player, std::vector<Unit>> units;
    std::vector<Objective> objectives;
};