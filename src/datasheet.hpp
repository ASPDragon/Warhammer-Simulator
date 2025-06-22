/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <string_view>
#include <string>
#include <cstdint>

struct Datasheet {
    Datasheet(const uint16_t unitId, const std::string_view unitName, const uint16_t baseDiameter, const uint16_t move, const uint16_t toughness,
              const uint16_t save, const uint16_t wounds, const uint16_t leadership,
              const uint16_t objectiveControl, const uint16_t modelsNum, const uint16_t cost);

    const uint16_t _unitId;
    const std::string _unitName;
    // std::string image;

    // fields related to unit
    const uint16_t _leadership;
    const uint16_t _objectiveControl;
    const uint16_t _modelsNum;

    // fields related to model
    const uint16_t _baseDiameter;
    const uint16_t _move;
    const uint16_t _toughness;
    const uint16_t _save;
    const uint16_t _wounds;
    
    // shared responsibility
    const uint16_t _cost;
};