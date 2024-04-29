#include "dice.hpp"
#include <random>

Dice::Dice(unsigned int&& maxValue)
    : maxValue{std::move(maxValue)} {}

unsigned int Dice::throwDice() {
    std::random_device random;
    std::mt19937_64 mt { random() };
    std::uniform_int_distribution<unsigned int> rngNumber{0, maxValue};
    return rngNumber(mt);
}