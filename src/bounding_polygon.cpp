//
// Created by sergeiavdoshkin on 10/10/26.
//

#include <vector.hpp>

#include "bounding_polygon.hpp"

#include <memory>

BoundingPolygon::BoundingPolygon(const Vector& center, const std::vector<Vector>& corners)
        : vertices(corners), center(center)
{
    if (this->vertices.size() < 3) {
        throw std::invalid_argument(
            "A polygon must have at least three corners"
        );
    }

    normals.reserve(this->vertices.size());

    // Edge from the last corner to the first corner.
    Vector edge = this->vertices[this->vertices.size() - 1] - this->vertices[0];

    Vector normal{.x = -edge.x, .y = edge.y};
    normals.push_back(normal.normalized());

    // Edges between consecutive corners.
    for (std::size_t i = 1; i < this->vertices.size(); ++i) {
        edge = this->vertices[i] - this->vertices[i - 1];

        normal = Vector{edge.y, -edge.x};
        normals.push_back(normal.normalized());
    }
}