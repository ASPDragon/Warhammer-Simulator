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
    Datasheet(uint16_t unitId, std::string_view unitName, uint16_t baseDiameter, uint16_t move, uint16_t toughness,
              uint16_t save, uint16_t wounds, uint16_t leadership, uint16_t objectiveControl, uint16_t modelsNum, uint16_t cost);

    const uint32_t _unit_id;
    const std::string _unit_name;
    // std::string image;

    // fields related to unit
    const uint16_t _leadership;
    const uint16_t _objective_control;
    const uint16_t _models_num;

    // fields related to model
    const uint16_t _base_diameter;
    const uint16_t _move;
    const uint16_t _toughness;
    const uint16_t _save;
    const uint16_t _wounds;
    
    // shared responsibility
    const uint16_t _cost;
};