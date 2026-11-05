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
    bool is_nearly_equal(float a, float b, float epsilon = 1e-4);
    bool is_edge_hits_circle(float dist_sq, float radius);
    bool is_center_inside_polygon(const Vector& center, const BoundingPolygon& poly);
    bool circle_intersects_polygon(const Vector& center, float radius, const BoundingPolygon& poly);
    bool check_collision_polygon(const BoundingPolygon& polygon1, const BoundingPolygon& polygon2);

    float distance_between_bases(const Vector& x, const Vector& y, float r1, float r2);
    float dist_sq_to_edge(const Vector& center, const Vector& corner_a, const Vector& corner_b);
    float clamp(float value, float min, float max);
}