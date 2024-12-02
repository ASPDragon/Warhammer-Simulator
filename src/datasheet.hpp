/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#pragma once

#include <string_view>
#include <string>
#include <cstdint>

class Datasheet {
public:
    Datasheet(const std::string_view unitName, const uint16_t move, const uint16_t toughness,
              const uint16_t save, const uint16_t wounds, const uint16_t leadership,
              const uint16_t objectiveControl, const uint16_t modelsNum, const uint16_t cost);

    virtual std::string_view getUnitName() const { return _unitName; }
    
    virtual uint16_t getLeadership() const { return _leadership; }
    virtual uint16_t getObjectiveControl() const { return _objectiveControl; }
    virtual uint16_t getModelsNum() const { return _modelsNum; }

    virtual uint16_t getMove() const { return _move; }
    virtual uint16_t getToughness() const { return _toughness; }
    virtual uint16_t getSave() const { return _save; }
    virtual uint16_t getWounds() const { return _wounds; }
 
    virtual uint16_t getCost() const { return _cost; }

protected:
    const std::string _unitName;
    // std::string image;

    // fields related to unit
    const uint16_t _leadership;
    const uint16_t _objectiveControl;
    const uint16_t _modelsNum;

    // fields related to model
    const uint16_t _move;
    const uint16_t _toughness;
    const uint16_t _save;
    const uint16_t _wounds;
    
    // shared responsibility
    const uint16_t _cost;
};