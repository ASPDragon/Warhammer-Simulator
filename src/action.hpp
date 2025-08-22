//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "game_state.hpp"

struct Action
{
    explicit Action(GameState& state);
    [[nodiscard]] virtual bool validate() const = 0;
    virtual void execute() = 0;

    virtual ~Action() = default;

protected:
    GameState& _state;
};