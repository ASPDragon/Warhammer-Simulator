/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

struct Vector;

namespace utils
{
    bool nearlyEqual(float a, float b, float epsilon = 1e-4);

    float distanceBetweenBases(const Vector& x, const Vector& y, float r1, float r2);
}