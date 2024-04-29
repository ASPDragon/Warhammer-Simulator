#include "datasheet.hpp"

Datasheet::Datasheet(std::string&& unitName, int&& move, int&& toughness, int&& save, int&& wounds, int&& leadership, int&& objectiveControl)
: unitName{std::move(unitName)}, move{std::move(move)}, toughness{std::move(toughness)}, save{std::move(save)},
wounds{std::move(wounds)}, leadership{std::move(leadership)}, objectiveControl{std::move(objectiveControl)} {}

bool Datasheet::isDead() {
    return wounds == 0;
}