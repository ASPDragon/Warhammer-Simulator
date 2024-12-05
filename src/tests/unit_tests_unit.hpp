#include <gtest/gtest.h>
#include "../coords.hpp"
#include "../unit.hpp"
#include "../model.hpp"
#include "../datasheet.hpp"

TEST(UnitTest, EmptyUnit) {
    Datasheet datasheet("Terminator Assault Squad", 5, 5, 2, 3, 6, 1, 0, 0);
    Unit unit(datasheet);
    
    ASSERT_TRUE(unit.isCoherent()); // Define: Empty unit is trivially coherent
}

TEST(UnitTest, SingleModelUnit) {
    Datasheet datasheet("Terminator Assault Squad", 5, 5, 2, 3, 6, 1, 1, 36);
    Unit unit(datasheet);
    unit.unit[0].coords = {0, 0};

    ASSERT_TRUE(unit.isCoherent()); // Single model is coherent by default
}

TEST(UnitTest, AllModelsCoherent) {
    Datasheet datasheet("Terminator Assault Squad", 5, 5, 2, 3, 6, 1, 3, 108);
    Unit unit(datasheet);
    unit.unit[0].coords = {0.0, 0.0};
    unit.unit[1].coords = {0.5, 0.5};
    unit.unit[2].coords = {1.0, 0.5};
    
    ASSERT_TRUE(unit.isCoherent()); // All models within coherentDistance
}

TEST(UnitTest, SomeModelsIncoherent) {
    Datasheet datasheet("Terminator Assault Squad", 5, 5, 2, 3, 6, 1, 3, 108);
    Unit unit(datasheet);
    unit.unit[0].coords = {0.0, 0.0};
    unit.unit[1].coords = {2.0, 2.0};
    unit.unit[2].coords = {0.5, 0.5};
    
    ASSERT_FALSE(unit.isCoherent()); // At least one model not coherent
}

TEST(UnitTest, BoundaryCase) {
    Datasheet datasheet("Terminator Assault Squad", 5, 5, 2, 3, 6, 1, 2, 72);
    Unit unit(datasheet);
    unit.unit[0].coords = {0.0, 0.0};
    unit.unit[1].coords = {1.0, 0.0}; // Exactly at coherentDistance

    ASSERT_TRUE(unit.isCoherent()); // Models at boundary are still coherent
}
