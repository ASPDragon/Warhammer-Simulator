#include <cmath>

struct Coords {
    double calculateDistance(const Coords& rhs) const {
        return std::sqrt(pow(rhs.x - this->x, 2) + pow(rhs.y - this->y, 2));
    }

    size_t x;
    size_t y;
};