//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "game_state.hpp"

struct Action
{
    virtual bool validate() const = 0;
    virtual void execute() = 0;

protected:
    GameState& state;
};