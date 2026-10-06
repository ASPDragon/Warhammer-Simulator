//
// Created by sergeiavdoshkin on 10/6/26.
//

#pragma once

#include <gtest/gtest.h>
#include "pile_in.hpp"
#include "vector.hpp"

const auto base_to_base_vector =
    closest_enemy.value().position - current_model.coords;

const auto new_coords =
    current_model.coords +
    base_to_base_vector.normalized() *
        (base_to_base_vector.length() -
         current_model.base_radius -
         enemy_base_radius);

class PileInActionTest : public ::testing::Test {
protected:
    std::shared_ptr<GameState> state;
    const std::shared_ptr<Player> player;
    const std::shared_ptr<Unit> unit;

    void SetUp() override {
        // Construct state/player/unit here
    }

    ValidationReport validate(
        const std::vector<std::pair<size_t, Vector>>& destinations)
    {
        PileInAction action(
            state,
            player,
            unit,
            destinations,
            3.0f
        );

        return action.validate();
    }
};

TEST_F(PileInActionTest, ValidPileIn)
{
    const auto report = validate({
        {0, Vector{1.0f, 0.0f}}
    });

    EXPECT_TRUE(report.ok());
}

TEST_F(PileInActionTest, RejectsInvalidDestinationCount)
{
    const auto report = validate({});

    EXPECT_FALSE(report.ok());
    ASSERT_TRUE(report.report().has_value());
    EXPECT_EQ(*report.report(), "Error: Invalid destination count");
}

TEST_F(PileInActionTest, RejectsMovementGreaterThanMaximumDistance)
{
    const auto report = validate({
        {0, Vector{4.0f, 0.0f}}
    });

    EXPECT_FALSE(report.ok());
    ASSERT_TRUE(report.report().has_value());
    EXPECT_EQ(*report.report(), "Error: Unit Is Too Far");
}

TEST_F(PileInActionTest, RejectsWhenThereIsNoEnemy)
{
    // State contains only `player`'s units.

    const auto report = validate({
        {0, Vector{1.0f, 0.0f}}
    });

    EXPECT_FALSE(report.ok());
    ASSERT_TRUE(report.report().has_value());
    EXPECT_EQ(*report.report(), "Error: No Enemy Unit");
}

TEST_F(PileInActionTest, MustEndCloserToEnemy)
{
    // Friendly model starts at (0, 0)
    // Enemy model is at (5, 0)
    //
    // Destination (1, 0) => closer
    // Destination (-1, 0) => farther

    const auto report = validate({
        {0, Vector{-1.0f, 0.0f}}
    });

    EXPECT_FALSE(report.ok());
    ASSERT_TRUE(report.report().has_value());
    EXPECT_EQ(*report.report(), "Error: Not Closer To Enemy");
}

TEST_F(PileInActionTest, AcceptsMovementThatEndsCloserToEnemy)
{
    const auto report = validate({
        {0, Vector{1.0f, 0.0f}}
    });

    EXPECT_TRUE(report.ok());
}

TEST_F(PileInActionTest, RejectsIncoherentUnit)
{
    // Two friendly models whose proposed positions violate coherency.

    const auto report = validate({
        {0, Vector{1.0f, 0.0f}},
        {1, Vector{20.0f, 0.0f}}
    });

    EXPECT_FALSE(report.ok());
    ASSERT_TRUE(report.report().has_value());
    EXPECT_EQ(*report.report(), "Error: Unit Is Not Coherent");
}