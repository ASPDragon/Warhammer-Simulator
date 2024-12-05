/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "fight_phase.hpp"
#include "player.hpp"
#include "unit.hpp"

void FightPhase::pileIn(const Unit& unit) {}

bool FightPhase::canFight(const Unit& unit) const {
    return unit.isAlive();
}