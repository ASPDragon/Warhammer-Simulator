#pragma once

#include <gmock/gmock.h>
#include <string_view>
#include <cstdint>

#include "../datasheet.hpp"

class DatasheetMock : public Datasheet {
public:
    DatasheetMock() : Datasheet("Terminator Assault Squad", 5, 5, 2, 3, 6, 1, 5, 180) {}

    MOCK_METHOD(std::string_view, getUnitName, (), (const, override));
    
    MOCK_METHOD(uint16_t, getLeadership, (), (const, override));
    MOCK_METHOD(uint16_t, getObjectiveControl, (), (const, override));
    MOCK_METHOD(uint16_t, getModelsNum, (), (const, override));
    MOCK_METHOD(uint16_t, getMove, (), (const, override));
    MOCK_METHOD(uint16_t, getToughness, (), (const, override));
    MOCK_METHOD(uint16_t, getSave, (), (const, override));
    MOCK_METHOD(uint16_t, getWounds, (), (const, override));
    MOCK_METHOD(uint16_t, getCost, (), (const, override));
};