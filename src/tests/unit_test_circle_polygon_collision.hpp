#include <gtest/gtest.h>
#include "bounding_polygon.hpp"
#include "vector.hpp"
#include "utils.hpp"

namespace {

// Square 4x4, counterclockwise
BoundingPolygon make_square() {
    const Vector center{ .x = 2.0f, .y = 2.0f };
    const std::vector<Vector> corners{
        { .x = 0.0f, .y = 0.0f },
        { .x = 4.0f, .y = 0.0f },
        { .x = 4.0f, .y = 4.0f },
        { .x = 0.0f, .y = 4.0f }
    };
    return BoundingPolygon(center, corners);
}

// Square 4x4, clockwise
BoundingPolygon make_square_cw() {
    const Vector center{ .x = 2.0f, .y = 2.0f };
    const std::vector<Vector> corners{
        { .x = 0.0f, .y = 4.0f },
        { .x = 4.0f, .y = 4.0f },
        { .x = 4.0f, .y = 0.0f },
        { .x = 0.0f, .y = 0.0f }
    };
    return BoundingPolygon(center, corners);
}

// L-shape (concave), the region x>2, y>2 is empty
BoundingPolygon make_l_shape() {
    const Vector center{ .x = 1.0f, .y = 1.0f };
    const std::vector<Vector> corners{
        { .x = 0.0f, .y = 0.0f },
        { .x = 4.0f, .y = 0.0f },
        { .x = 4.0f, .y = 2.0f },
        { .x = 2.0f, .y = 2.0f },
        { .x = 2.0f, .y = 4.0f },
        { .x = 0.0f, .y = 4.0f }
    };
    return BoundingPolygon(center, corners);
}

} // namespace

// ---------- dist_sq_to_edge ----------
TEST(DistSqToEdge, PerpendicularFoot) {
    EXPECT_FLOAT_EQ(utils::dist_sq_to_edge({1,3}, {0,0}, {4,0}), 9.0f);
}
TEST(DistSqToEdge, ClampedToStart) {
    EXPECT_FLOAT_EQ(utils::dist_sq_to_edge({-3,4}, {0,0}, {4,0}), 25.0f);
}
TEST(DistSqToEdge, ClampedToEnd) {
    EXPECT_FLOAT_EQ(utils::dist_sq_to_edge({7,4}, {0,0}, {4,0}), 25.0f);
}
TEST(DistSqToEdge, PointOnEdge) {
    EXPECT_FLOAT_EQ(utils::dist_sq_to_edge({2,0}, {0,0}, {4,0}), 0.0f);
}
TEST(DistSqToEdge, DegenerateEdge) {
    EXPECT_FLOAT_EQ(utils::dist_sq_to_edge({4,5}, {1,1}, {1,1}), 25.0f);
}
TEST(DistSqToEdge, DiagonalEdge) {
    // Edge (0,0)->(4,4), point (0,4): distance = 4/sqrt2, squared = 8
    EXPECT_FLOAT_EQ(utils::dist_sq_to_edge({0,4}, {0,0}, {4,4}), 8.0f);
}

// ---------- is_center_inside_polygon ----------
TEST(CenterInside, InsideSquare)  { EXPECT_TRUE(utils::is_center_inside_polygon({2,2}, make_square())); }
TEST(CenterInside, OutsideSquare) { EXPECT_FALSE(utils::is_center_inside_polygon({5,2}, make_square())); }
TEST(CenterInside, AboveSquare)   { EXPECT_FALSE(utils::is_center_inside_polygon({2,5}, make_square())); }
TEST(CenterInside, ConcaveArm)    { EXPECT_TRUE(utils::is_center_inside_polygon({1,3}, make_l_shape())); }
TEST(CenterInside, ConcaveBase)   { EXPECT_TRUE(utils::is_center_inside_polygon({3,1}, make_l_shape())); }
TEST(CenterInside, ConcaveNotch)  { EXPECT_FALSE(utils::is_center_inside_polygon({3,3}, make_l_shape())); }

// ---------- circle_intersects_polygon ----------
TEST(CircleVsPolygon, FarOutside) {
    EXPECT_FALSE(utils::circle_intersects_polygon({10,10}, 1.0f, make_square()));
}
TEST(CircleVsPolygon, CircleFullyInside) {
    EXPECT_TRUE(utils::circle_intersects_polygon({2,2}, 1.0f, make_square()));
}
TEST(CircleVsPolygon, CrossingOneEdge) {
    EXPECT_TRUE(utils::circle_intersects_polygon({5,2}, 1.5f, make_square()));
}
TEST(CircleVsPolygon, PolygonFullyInsideCircle) {
    EXPECT_TRUE(utils::circle_intersects_polygon({5,2}, 10.0f, make_square()));
}
TEST(CircleVsPolygon, TouchingEdgeExactly) {
    EXPECT_TRUE(utils::circle_intersects_polygon({6,2}, 2.0f, make_square()));
}
TEST(CircleVsPolygon, JustOutsideEdge) {
    EXPECT_FALSE(utils::circle_intersects_polygon({6,2}, 1.99f, make_square()));
}
TEST(CircleVsPolygon, TouchingCornerExactly) {
    // Center (7,8) to corner (4,4): 3-4-5 triangle, distance exactly 5
    EXPECT_TRUE(utils::circle_intersects_polygon({7,8}, 5.0f, make_square()));
}
TEST(CircleVsPolygon, JustOutsideCorner) {
    EXPECT_FALSE(utils::circle_intersects_polygon({7,8}, 4.9f, make_square()));
}
TEST(CircleVsPolygon, ConcaveNotchMiss) {
    // Center in the empty notch, 1.0 away from both inner edges
    EXPECT_FALSE(utils::circle_intersects_polygon({3,3}, 0.5f, make_l_shape()));
}
TEST(CircleVsPolygon, ConcaveNotchHit) {
    EXPECT_TRUE(utils::circle_intersects_polygon({3,3}, 1.0f, make_l_shape()));
}
TEST(CircleVsPolygon, ClockwiseWindingSameResult) {
    BoundingPolygon cw({2,2}, {{0,4}, {4,4}, {4,0}, {0,0}});
    EXPECT_TRUE (utils::circle_intersects_polygon({2,2}, 1.0f, cw));
    EXPECT_TRUE (utils::circle_intersects_polygon({5,2}, 1.5f, cw));
    EXPECT_FALSE(utils::circle_intersects_polygon({10,10}, 1.0f, cw));
}

// ---------- constructor ----------
TEST(BoundingPolygonCtor, ThrowsOnTwoVertices) {
    EXPECT_THROW(BoundingPolygon({0,0}, {{0,0}, {1,1}}), std::invalid_argument);
}