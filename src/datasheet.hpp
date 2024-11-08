#pragma once

#include <string_view>
#include <string>
#include <cstdint>

class Datasheet {
public:
    Datasheet(const std::string_view unitName, const uint16_t move, const uint16_t toughness,
              const uint16_t save, const uint16_t wounds, const uint16_t leadership,
              const uint16_t objectiveControl, const uint16_t modelsNum, const uint16_t cost);

    uint16_t getModelsNum() const { return _modelsNum; }
    uint16_t getWounds() const { return _wounds; }
    uint16_t getToughness() const { return _toughness; }

protected:
    std::string _unitName;
    // std::string image;
    const uint16_t _move;
    const uint16_t _toughness;
    const uint16_t _save;
    const uint16_t _wounds;
    const uint16_t _leadership;
    const uint16_t _objectiveControl;

    // fields related to unit
    const uint16_t _modelsNum;
    const uint16_t _cost;
    
};