// src/tests/pile_in_action_test.cpp
#pragma once

#include <gtest/gtest.h>

#include <memory>
#include <utility>
#include <vector>

#include "datasheet.hpp"
#include "game_state.hpp"
#include "pile_in.hpp"
#include "player.hpp"
#include "unit.hpp"
#include "vector.hpp"
#include "model.hpp"

namespace unit_tests {

// ---------------------------------------------------------------------------
// ADAPTERS: the only place that touches APIs I had to guess. Fix these first.
// ---------------------------------------------------------------------------
    constexpr distance_t kPileInDistance = 3.0f;

    inline Vector position_of(const std::shared_ptr<Unit>& unit, const size_t model_index) {
        return unit->models[model_index].coords;            // assumed
    }

    inline void place_model(const std::shared_ptr<Unit>& unit, const size_t model_index, const Vector pos) {
        unit->models[model_index].coords = pos;            // assumed
    }

    inline bool is_valid(const ValidationReport& report) {
        return report.ok();                                    // assumed
    }

    inline float dist(const Vector& a, const Vector& b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); // assumed x/y members
    }
    // ---------------------------------------------------------------------------

    class PileInActionTest : public ::testing::Test {
    protected:
        void SetUp() override {
            Datasheet player_sheet(1, "Terminator Assault Squad", 40, 5, 5, 2, 3, 6, 1, 5, 180);
            Datasheet enemy_sheet(2, "Terminator Assault Squad", 40, 5, 5, 2, 3, 6, 1, 5, 180);

            game_state   = std::make_shared<GameState>();                       // assumed
            player       = std::make_shared<Player>(123);                 // assumed
            enemy_player = std::make_shared<Player>(456);                 // assumed
            unit         = std::make_shared<Unit>(player_sheet);                // assumed
            enemy_unit   = std::make_shared<Unit>(enemy_sheet);                 // assumed

            // register units with the game state / players as your API requires
            // game_state->add_unit(player, unit);
            // game_state->add_unit(enemy_player, enemy_unit);

            // Baseline layout (inches): our model 0 at origin, enemy model 0 is 10" to the right.
            place_model(unit, 0, {0.0f, 0.0f});
            place_model(enemy_unit, 0, {10.0f, 0.0f});
        }

        PileInAction make_action(const std::vector<std::pair<size_t, Vector>>& destinations,
                                 distance_t max_distance = kPileInDistance)
        {
            return { game_state, player, unit, destinations, max_distance };
        }

        std::shared_ptr<GameState> game_state;
        std::shared_ptr<Player> player;
        std::shared_ptr<Player> enemy_player;
        std::shared_ptr<Unit> unit;
        std::shared_ptr<Unit> enemy_unit;
    };

    // ------------------------------- validate() --------------------------------

    TEST_F(PileInActionTest, ValidWhenMovingTowardsEnemyWithinDistance) {
        const auto action = make_action({{0, Vector{2.0f, 0.0f}}});
        EXPECT_TRUE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, ValidWhenMovingExactlyMaximumDistance) {
        const auto action = make_action({{0, Vector{3.0f, 0.0f}}});
        EXPECT_TRUE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, InvalidWhenMovingFurtherThanMaximumDistance) {
        const auto action = make_action({{0, Vector{3.5f, 0.0f}}});
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, InvalidWhenJustOverMaximumDistance) {
        const auto action = make_action({{0, Vector{3.01f, 0.0f}}});
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, InvalidWhenMovingAwayFromClosestEnemy) {
        const auto action = make_action({{0, Vector{-2.0f, 0.0f}}});
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, InvalidWhenNotMoving) {
        // Staying put does not end the model closer to the enemy.
        const auto action = make_action({{0, Vector{0.0f, 0.0f}}});
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, InvalidWhenMovingSidewaysKeepingSameDistance) {
        // Enemy at (10,0); moving to (0,3) makes the distance larger, not smaller.
        const auto action = make_action({{0, Vector{0.0f, 3.0f}}});
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, ValidWhenMovingDiagonallyAndEndingCloser) {
        // (2,2) is ~2.83" from origin and closer to (10,0) than the start.
        const auto action = make_action({{0, Vector{2.0f, 2.0f}}});
        EXPECT_TRUE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, InvalidWhenModelIndexOutOfRange) {
        const auto action = make_action({{unit->models.size() + 5, Vector{1.0f, 0.0f}}});
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, MustEndCloserToClosestEnemyModelNotJustAnyEnemyModel) {
        // Add a second enemy model near the left side. It becomes the closest enemy,
        // so moving right (away from it) is no longer "closer to the closest enemy".
        ASSERT_GE(enemy_unit->models.size(), 2u);
        place_model(enemy_unit, 1, {-4.0f, 0.0f});

        auto action = make_action({{0, Vector{2.0f, 0.0f}}});
        EXPECT_FALSE(is_valid(action.validate()));

        auto toward_closest = make_action({{0, Vector{-2.0f, 0.0f}}});
        EXPECT_TRUE(is_valid(toward_closest.validate()));
    }

    TEST_F(PileInActionTest, AllModelsMustSatisfyRules) {
        ASSERT_GE(unit->models.size(), 2u);
        place_model(unit, 1, {0.0f, 1.0f});

        const auto action = make_action({
            {0, Vector{2.0f, 0.0f}},    // fine
            {1, Vector{-3.0f, 1.0f}},   // moves away: invalid
        });
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, ValidWhenAllModelsMoveLegally) {
        ASSERT_GE(unit->models.size(), 2u);
        place_model(unit, 1, {0.0f, 1.0f});

        auto action = make_action({
            {0, Vector{2.0f, 0.0f}},
            {1, Vector{2.5f, 1.0f}},
        });
        EXPECT_TRUE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, RespectsCustomMaximumDistance) {
        const auto action = make_action({{0, Vector{2.0f, 0.0f}}}, 1.0f);
        EXPECT_FALSE(is_valid(action.validate()));
    }

    TEST_F(PileInActionTest, ValidateDoesNotMoveModels) {
        const auto action = make_action({{0, Vector{2.0f, 0.0f}}});
        (void)action.validate();

        const auto [x, y] = position_of(unit, 0);
        EXPECT_FLOAT_EQ(x, 0.0f);
        EXPECT_FLOAT_EQ(y, 0.0f);
    }

    // -------------------------------- execute() --------------------------------

    TEST_F(PileInActionTest, ExecuteMovesModelToDestination) {
        auto action = make_action({{0, Vector{2.0f, 0.0f}}});
        ASSERT_TRUE(is_valid(action.validate()));

        action.execute();

        const Vector pos = position_of(unit, 0);
        EXPECT_FLOAT_EQ(pos.x, 2.0f);
        EXPECT_FLOAT_EQ(pos.y, 0.0f);
    }

    TEST_F(PileInActionTest, ExecuteLeavesModelsWithoutDestinationUntouched) {
        ASSERT_GE(unit->models.size(), 2u);
        place_model(unit, 1, {0.0f, 1.0f});

        auto action = make_action({{0, Vector{2.0f, 0.0f}}});
        ASSERT_TRUE(is_valid(action.validate()));
        action.execute();

        const Vector untouched = position_of(unit, 1);
        EXPECT_FLOAT_EQ(untouched.x, 0.0f);
        EXPECT_FLOAT_EQ(untouched.y, 1.0f);
    }

    TEST_F(PileInActionTest, ExecuteEndsCloserToEnemyThanBefore) {
        const Vector enemy = position_of(enemy_unit, 0);
        const float before = dist(position_of(unit, 0), enemy);

        auto action = make_action({{0, Vector{3.0f, 0.0f}}});
        ASSERT_TRUE(is_valid(action.validate()));
        action.execute();

        EXPECT_LT(dist(position_of(unit, 0), enemy), before);
    }

    TEST_F(PileInActionTest, ExecuteDoesNotMoveEnemyUnit) {
        auto action = make_action({{0, Vector{2.0f, 0.0f}}});
        action.execute();

        const auto [x, y] = position_of(enemy_unit, 0);
        EXPECT_FLOAT_EQ(x, 10.0f);
        EXPECT_FLOAT_EQ(y, 0.0f);
    }
}  // namespace