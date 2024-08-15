#include "dice.hpp"
#include <random>

uint16_t Dice::throwDice() {
    std::random_device random;
    std::mt19937_64 mt { random() };
    std::uniform_int_distribution<unsigned int> rngNumber{0, 6};
    return rngNumber(mt) + 1;
}