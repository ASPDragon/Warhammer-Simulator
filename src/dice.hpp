#pragma once

class Dice {
public:
    Dice(unsigned int&& maxValue);
    unsigned int throwDice();

private:
    unsigned int maxValue;
};