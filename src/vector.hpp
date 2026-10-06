/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <cmath>

struct Vector {
    [[nodiscard]] float calculate_distance(const Vector& rhs) const { return std::sqrtf(powf(rhs.x - this->x, 2.0) + powf(rhs.y - this->y, 2.0)); }
    [[nodiscard]] float length() const { return std::sqrt(this->x * this->x + this->y * this->y); }

    Vector operator-(const Vector& vector) const {return { .x = this->x - vector.x, .y = this->y - vector.y }; }
    Vector operator*(const float scalar) const { return { .x = this->x * scalar, .y = this->y * scalar }; }
    Vector operator+(const Vector& vector) const { return { .x = this->x + vector.x, .y = this->y + vector.y }; }
    [[nodiscard]] Vector normalized() const { return Vector{ .x = this->x / this->length(), .y = this->y / this->length() }; }

    float x;
    float y;
};