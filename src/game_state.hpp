//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "player.hpp"
#include "unit.hpp"

struct GameState
{
    std::vector<Player> players;
    std::vector<Unit> units;
    std::vector<Objective> objectives;
};