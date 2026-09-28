//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include <memory>
#include "game_state.hpp"

struct Action
{
    explicit Action(Game_State& state);
    [[nodiscard]] virtual bool validate() const = 0;
    virtual void execute() = 0;

    virtual ~Action() = default;

protected:
    std::shared_ptr<Game_State> _state;
};