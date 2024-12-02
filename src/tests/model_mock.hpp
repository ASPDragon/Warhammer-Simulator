/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <gmock/gmock.h>

#include "../model.hpp"
#include "../optional_ref.hpp"
#include "../datasheet.hpp"
#include "../weapon.hpp"

class ModelMock : public Model {
public:
    ModelMock(Datasheet& datasheet) : Model(datasheet) {}

    MOCK_METHOD(qtils::OptionalRef<const Weapon>, getWeapon, (const std::string& weaponName), (const, override));
    MOCK_METHOD(Coords, getCoords, (), (const, override));
    MOCK_METHOD(bool, isDead, (), (const, override));
    MOCK_METHOD(void, takeDamage, (uint16_t& damage), (override));
};