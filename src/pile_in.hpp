//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "action.hpp"

struct Vector;

using distance_t = float;

class PileInAction : public Action {
public:
    PileInAction(const std::shared_ptr<GameState>&, const std::shared_ptr<Player>&, const std::shared_ptr<Unit>&,
        const std::vector<std::pair<size_t, Vector>>&, distance_t);
    [[nodiscard]] ValidationReport validate() const override;
    void execute() override;

private:
    std::shared_ptr<Player> player;
    std::shared_ptr<Unit> unit;
    std::vector<std::pair<size_t, Vector>> destinations;
    distance_t maximum_distance;
};
