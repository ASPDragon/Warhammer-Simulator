/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "vector.hpp"

double Vector::calculateDistance(const Vector& rhs) const {
    return std::sqrt(pow(rhs.x - this->x, 2) + pow(rhs.y - this->y, 2));
}

const Vector Vector::operator-(const Vector& vector) const {
    return {this->x - vector.x, this->y - vector.y};
}
Vector Vector::operator*(float scalar) const{
    return {this->x * scalar, this->y * scalar};
}

float Vector::length() const{
    return sqrt(this->x * this->x + this->y * this->y);
}

Vector Vector::normalized() const{
    return Vector{ this->x / this->length(), this->y / this->length() };
}
