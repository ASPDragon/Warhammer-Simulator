/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "utils.hpp"
#include "vector.hpp"

#include <cmath>

namespace utils {
    bool nearlyEqual(float a, float b, float epsilon) {
        return fabs(a - b) <= epsilon;
    }

    float distanceBetweenBases(const Vector& a, const Vector& b, float r1, float r2) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) - (r1 + r2);
    }
}