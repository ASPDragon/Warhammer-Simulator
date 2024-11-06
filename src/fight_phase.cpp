#include "fight_phase.hpp"
#include "player.hpp"
#include "unit.hpp"

bool FightPhase::canFight(const Unit& unit) const {
    return unit.isAlive();
}