//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "action.hpp"

class Vector;

using distance_t = float;

class PileInAction : public Action {
public:
    PileInAction(const std::shared_ptr<GameState>&, const Player&&, const Unit&&, distance_t);
    [[nodiscard]] ValidationReport validate() const override;
    void execute() override;

private:
    Player player;
    Unit unit;
    std::vector<std::pair<size_t, Vector>> destinations;
    std::pair<size_t, Vector> pile_in_coordinates = {};
    distance_t maximum_distance;
};
