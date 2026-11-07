//
// Created by sergeiavdoshkin on 10/10/26.
//

#pragma once

#include <cmath>
#include <vector>
#include "vector.hpp"

struct BoundingPolygon {
    BoundingPolygon(const Vector&, const std::vector<Vector>&);

    std::vector<Vector> vertices;
    Vector center;
    std::vector<Vector> normals;
};
