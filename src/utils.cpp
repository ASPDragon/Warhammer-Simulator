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

namespace utils {
    bool nearly_equal(float a, float b, float epsilon) {
        return std::fabs(a - b) <= epsilon;
    }

    bool check_collision_polygon(const BoundingPolygon& polygon1, const BoundingPolygon& polygon2) {
        for (const auto normal : polygon1.normals) {
            
        }
    }

    bool edge_hits_circle(const float dist_sq, const float radius)
    {
        return dist_sq <= radius * radius;
    }

    float distance_between_bases(const Vector& a, const Vector& b, float r1, float r2) {
        return std::sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2)) - (r1 + r2);
    }

    float poly_edge_hits_circle(const Vector& center, const Vector& a, const Vector& b)
    {
        const Vector ab = b - a;
        const Vector ac = center - a;
        auto t = 0.0f;
        if (const float lenSq = ab.x * ab.x + ab.y * ab.y; lenSq > 0.0f)
        {
            t = std::clamp((ac.x * ab.x + ac.y * ab.y) / lenSq, 0.0f, 1.0f);
        }
        const Vector q { .x = a.x + t * ab.x, .y = a.y + t * ab.y };
        const auto d = center - q;
        const auto dist_sq = d.x * d.x + d.y * d.y;
        return dist_sq;
    }

    float clamp(const float value, const float min, const float max)
    {
        return std::min(std::max(min, value), max);
    }
}