#include <gtest/gtest.h>
#include "../fight_phase.hpp"
#include "../unit.hpp"
#include "../datasheet.hpp"
#include "../model.hpp"
#include "../vector.hpp"

Unit createTestUnit() {
    Datasheet datasheet("Terminator Assault Squad", 40, 5, 5, 2, 3, 6, 1, 3, 108);
    Unit unit(datasheet);
    unit.unit[0].coords = {0.0, 0.0};
    unit.unit[1].coords = {0.5, 0.5};
    unit.unit[2].coords = {1.0, 0.5};
    return unit;
}

Unit createEnemyUnit(Datasheet& datasheet, const std::vector<Vector>& coordinates) {
    Unit unit(datasheet);
    
    for (size_t i = 0; i < unit.unit.size() && i < coordinates.size(); ++i) {
        unit.unit[i].coords = coordinates[i];
    }
    return unit;
}

std::vector<Unit> createEnemyUnits() {
    // Define coordinates for multiple enemy units
    std::vector<Vector> chaosTerminatorSquadCoords = {{0.8, 0.8}, {1.5, 0.5}, {0.3, 0.3}};
    std::vector<Vector> sorcererCoords = {{2.0, 2.0}};
    
    // Create units with provided coordinates
    Datasheet chaosTerminatorSquadDatasheet("Chaos Terminator Squad", 40, 5, 5, 2, 3, 6, 1, 3, 108);
    Datasheet sorcererDatasheet("Sorcerer", 40, 6, 4, 3, 4, 6, 1, 1, 60);
    Unit chaosTerminatorSquad = createEnemyUnit( chaosTerminatorSquadDatasheet,chaosTerminatorSquadCoords);
    Unit sorcerer = createEnemyUnit(sorcererDatasheet, sorcererCoords);

    // Push them into a vector
    std::vector<Unit> enemyUnits;
    enemyUnits.push_back(chaosTerminatorSquad);
    enemyUnits.push_back(sorcerer);
    
    return enemyUnits;
}

TEST(FightPhaseTest, PileIn_MoveExceedsMaximumDistance_ReturnsFalse) {
    FightPhase fightPhase;
    Unit currentUnit = createTestUnit();
    std::vector<Unit> enemyUnits = createEnemyUnits();
    std::vector<std::pair<size_t, Vector>> destination = {{0, Vector(10, 10)}}; // Too far

    EXPECT_FALSE(fightPhase.pileIn(currentUnit, destination, enemyUnits, 4.0f)); // Maximum 5.0f
}

// Test the pile-in functionality with valid movement
TEST(FightPhaseTest, PileIn_ValidMovementToEnemy_ReturnsTrue) {
    // Create a FightPhase object
    FightPhase fightPhase;

    // Create a test unit
    Unit testUnit = createTestUnit();

    // Create enemy units
    std::vector<Unit> enemyUnits = createEnemyUnits();

    // Define valid destination coordinates for the test unit within range
    std::vector<std::pair<size_t, Vector>> destinations = {
        {0, {0.5, 0.5}}, // Model 0 moves slightly
        {1, {1.0, 1.0}}, // Model 1 moves within range
        {2, {1.5, 1.0}}  // Model 2 moves closer to enemy
    };

    // Maximum movement range
    float maximumRange = 4.0f;

    // Call the pileIn method and verify the result
    bool result = fightPhase.pileIn(testUnit, destinations, enemyUnits, maximumRange);

    // Assert that the method returns true
    ASSERT_TRUE(result);
}


TEST(FightPhaseTest, PileIn_CoherenceMaintained_ReturnsTrue) {
    // Arrange
    FightPhase fightPhase;
    Unit currentUnit = createTestUnit(); // Create a test unit with predefined positions
    std::vector<Unit> enemyUnits = createEnemyUnits(); // Create enemy units with predefined positions

    // Define valid destinations for each model, ensuring coherence
    std::vector<std::pair<size_t, Vector>> destinations = {
        {0, {0.2, 0.2}}, // Model 0 moves closer to the center
        {1, {0.7, 0.7}}, // Model 1 moves within range of model 0
        {2, {1.2, 0.8}}  // Model 2 moves within range of model 1
    };

    float maximumRange = 5.0f; // Allowable maximum movement range

    // Act
    bool result = fightPhase.pileIn(currentUnit, destinations, enemyUnits, maximumRange);

    // Assert
    EXPECT_TRUE(result) << "The pile-in method failed to maintain unit coherence.";
}


TEST(FightPhaseTest, PileIn_InvalidDestinationIndex_ReturnsFalse) {
    FightPhase fightPhase;
    Unit currentUnit = createTestUnit();  // Mock a unit
    std::vector<Unit> enemyUnits = createEnemyUnits();
    std::vector<std::pair<size_t, Vector>> destination = {
        {1, Vector(2.0f, 3.0f)}  // Incorrect index (should be 0 for first model)
    };

    EXPECT_FALSE(fightPhase.pileIn(currentUnit, destination, enemyUnits, 4.0f));
}

TEST(FightPhaseTest, PileIn_MoveAtMaximumDistance_ReturnsTrue) {
    FightPhase fightPhase;
    Unit currentUnit = createTestUnit();
    std::vector<Unit> enemyUnits = createEnemyUnits();
    std::vector<std::pair<size_t, Vector>> destination = {
        {0, Vector(4.0, 0.0)}, // Exactly at max distance
        {1, Vector(4.0, 0.5)},
        {2, Vector(3.5, 1.0)}
    };

    EXPECT_TRUE(fightPhase.pileIn(currentUnit, destination, enemyUnits, 4.0f));
}

TEST(FightPhaseTest, PileIn_NoEnemies_ReturnsFalse) {
    FightPhase fightPhase;
    Unit currentUnit = createTestUnit();
    std::vector<Unit> enemyUnits; // No enemies
    std::vector<std::pair<size_t, Vector>> destination = {
        {0, Vector(0.5, 0.5)},
        {1, Vector(1.0, 1.0)},
        {2, Vector(1.5, 1.0)}
    };

    EXPECT_FALSE(fightPhase.pileIn(currentUnit, destination, enemyUnits, 4.0f));
}
