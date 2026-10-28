/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

struct Vector;
struct BoundingPolygon;

namespace utils
{
    bool nearly_equal(float a, float b, float epsilon = 1e-4);

    bool check_collision_polygon(const BoundingPolygon& polygon1, const BoundingPolygon& polygon2);
    bool edge_hits_circle(float dist_sq, float radius);

    float distance_between_bases(const Vector& x, const Vector& y, float r1, float r2);
    float poly_edge_hits_circle(const Vector& center, const Vector& corner_a, const Vector& corner_b);
    float clamp(float value, float min, float max);
}