/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "datasheet.hpp"

Datasheet::Datasheet(const uint16_t unit_id, const std::string_view unit_name, const float base_diameter, const uint16_t move, const uint16_t toughness,
              const uint16_t save, const uint16_t wounds, const uint16_t leadership,
              const uint16_t objective_control, const uint16_t models_num, const uint16_t cost)
: unit_id{ unit_id }, unit_name{ unit_name }, base_diameter{ base_diameter }, move{ move }, toughness{ toughness }, save{ save }, wounds{ wounds },
    leadership{ leadership }, objective_control{ objective_control }, models_num{ models_num }, cost{ cost } {}