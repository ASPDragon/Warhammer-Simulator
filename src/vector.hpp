/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once


#include <cmath>

struct Vector {
    // Coords() = default;
    // Coords(double x, double y);

    double calculateDistance(const Vector& rhs) const;

    const Vector operator-(const Vector& vector) const;
    Vector operator*(float scalar) const;

    float length() const;

    Vector normalized() const;

    float x;
    float y;
};