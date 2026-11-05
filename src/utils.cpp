/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "utils.hpp"
#include "vector.hpp"
#include "bounding_polygon.hpp"

#include <cmath>
#include <algorithm>


    bool is_nearly_equal(float a, float b, float epsilon) {
        return std::fabs(a - b) <= epsilon;
    }

    bool is_edge_hits_circle(const float dist_sq, const float radius)
    {
        return dist_sq <= radius * radius;
    }

    bool is_center_inside_polygon(const Vector& center, const BoundingPolygon& poly)
    {
        if (poly.vertices.size() < 3) return false;
        bool inside = false;
        for (size_t i = 0, j = poly.vertices.size() - 1; i < poly.vertices.size(); j = i++) {
            const Vector point_a = poly.vertices[j];
            const Vector point_b = poly.vertices[i];
            if (((point_a.y > center.y) != (point_b.y > center.y)) &&
                center.x < (point_b.x - point_a.x) * (center.y - point_a.y) / (point_b.y - point_a.y) + point_a.x)
                inside = !inside;
        }
        return inside;
    }

    bool circle_intersects_polygon(const Vector& center, float radius, const BoundingPolygon& poly) {}

    bool check_collision_polygon(const BoundingPolygon& polygon1, const BoundingPolygon& polygon2) {
        for (const auto normal : polygon1.normals) {
            return true; // placeholder
        }
        return false; // placeholder
    }

    float distance_between_bases(const Vector& a, const Vector& b, float r1, float r2) {
        return std::sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2)) - (r1 + r2);
    }

    float dist_sq_to_edge(const Vector& center, const Vector& corner_a, const Vector& corner_b)
    {
        const Vector ab = corner_b - corner_a;
        const Vector ac = center - corner_a;
        auto t = 0.0f;
        if (const float lenSq = ab.x * ab.x + ab.y * ab.y; lenSq > 0.0f)
        {
            t = std::clamp((ac.x * ab.x + ac.y * ab.y) / lenSq, 0.0f, 1.0f);
        }
        const Vector q { .x = corner_a.x + t * ab.x, .y = corner_a.y + t * ab.y };
        const auto d = center - q;
        const auto dist_sq = d.x * d.x + d.y * d.y;
        return dist_sq;
    }

    float clamp(const float value, const float min, const float max)
    {
        return std::min(std::max(min, value), max);
    }