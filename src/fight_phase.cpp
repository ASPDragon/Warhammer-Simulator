#include "fight_phase.hpp"
#include "player.hpp"
#include "unit.hpp"
#include "model.hpp"

bool FightPhase::canFight(const Unit& unit) const {
    return unit.isUnitAlive();
}