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
    Datasheet(uint16_t unit_id, std::string_view unit_name, uint16_t base_diameter, uint16_t move, uint16_t toughness,
              uint16_t save, uint16_t wounds, uint16_t leadership, uint16_t objective_control, uint16_t models_num, uint16_t cost);

    const uint32_t unit_id;
    const std::string unit_name;

    // fields related to unit
    const uint16_t leadership;
    const uint16_t objective_control;
    const uint16_t models_num;

    // fields related to model
    const uint16_t base_diameter;
    const uint16_t move;
    const uint16_t toughness;
    const uint16_t save;
    const uint16_t wounds;
    
    // shared responsibility
    const uint16_t cost;
};