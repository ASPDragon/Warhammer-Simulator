/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "datasheet.hpp"

Datasheet::Datasheet(const std::string_view unitName, const uint16_t move, const uint16_t toughness,
              const uint16_t save, const uint16_t wounds, const uint16_t leadership,
              const uint16_t objectiveControl, const uint16_t modelsNum, const uint16_t cost)
: _unitName{unitName}, _move{move}, _toughness{toughness}, _save{save}, _wounds{wounds}, _leadership{leadership}, 
  _objectiveControl{objectiveControl}, _modelsNum{modelsNum}, _cost{cost} {}