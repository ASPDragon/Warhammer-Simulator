#pragma once

#include <string_view>
#include <string>

class Datasheet {
public:
    Datasheet(const std::string_view unitName, const unsigned int move, const unsigned int toughness,
              const unsigned int save, const unsigned int wounds, const unsigned int leadership,
              const unsigned int objectiveControl, const unsigned int modelsNum, const unsigned int cost);

    uint16_t getModelsNum() const { return _modelsNum; }
    uint16_t getWounds() const { return _wounds; }
    uint16_t getToughness() const { return _toughness; }

protected:
    std::string _unitName;
    // std::string image;
    const unsigned int _move;
    const unsigned int _toughness;
    const unsigned int _save;
    const unsigned int _wounds;
    const unsigned int _leadership;
    const unsigned int _objectiveControl;

    // fields related to unit
    const unsigned int _modelsNum;
    const unsigned int _cost;
    
};