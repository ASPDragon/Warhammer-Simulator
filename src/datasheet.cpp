/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "datasheet.hpp"

Datasheet::Datasheet(const uint16_t unitId, const std::string_view unitName, const uint16_t baseDiameter, const uint16_t move, const uint16_t toughness,
              const uint16_t save, const uint16_t wounds, const uint16_t leadership,
              const uint16_t objectiveControl, const uint16_t modelsNum, const uint16_t cost)
: _unit_id{ unitId }, _unit_name{ unitName }, _base_diameter{ baseDiameter }, _move{ move }, _toughness{ toughness }, _save{ save }, _wounds{ wounds },
    _leadership{ leadership }, _objective_control{ objectiveControl }, _models_num{ modelsNum }, _cost{ cost } {}