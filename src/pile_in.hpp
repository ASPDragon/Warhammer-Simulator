//
// Created by sergeiavdoshkin on 7/7/25.
//

#pragma once

#include "action.hpp"

class PileInAction : public Action {
    bool validate() const override;
    void execute() override;
};
