//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "action.hpp"

class Vector;

using distance_t = float;

class PileInAction : public Action {
public:
    bool validate() const override;
    void execute() override;

private:
    Player player;
    Unit unit;
    std::vector<std::pair<distance_t, Vector>> destinations;
    distance_t maximum_distance;
};
