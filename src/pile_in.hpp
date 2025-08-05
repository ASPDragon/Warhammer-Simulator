//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "action.hpp"

class Vector;

class PileInAction : public Action {
public:
    bool validate() const override;
    void execute() override;

private:
    Player player;
    Unit unit;
    std::vector<Vector> destinations;
    size_t maximumDistance;
};
