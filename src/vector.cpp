/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "vector.hpp"

bool Vector::check_collision_circular(const Vector& center1, float radius1, const Vector& center2, float radius2)
{
    const auto distanceX = center2.x - center1.x;
    const auto distanceY = center2.y - center1.y;
    auto distance = sqrt(distanceX * distanceX + distanceY * distanceY);

    return distance <= radius1 + radius2;

}
