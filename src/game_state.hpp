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

struct ClosestModel
{
    uint32_t playerId;
    uint32_t unitIdx;
    uint32_t modelIdx;
    Vector position;
};

struct GameState
{
    std::optional<ClosestModel> findClosestEnemyModel(uint32_t currentPlayer, Vector origin);
    uint32_t findClosestModel(Unit& unit, Vector origin);

    std::map<Player, std::vector<Unit>> units;
    std::vector<Objective> objectives;
};