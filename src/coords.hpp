/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <cmath>

struct Coords {
    double calculateDistance(const Coords& rhs) const {
        return std::sqrt(pow(rhs.x - this->x, 2) + pow(rhs.y - this->y, 2));
    }

    float x;
    float y;
};