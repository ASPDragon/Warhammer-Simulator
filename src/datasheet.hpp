#pragma once

#include <string>

class Datasheet {
public:
    Datasheet(std::string& unitName, unsigned int& move, unsigned int& toughness, unsigned int& save, unsigned int& wounds,
              unsigned int& leadership, unsigned int& objectiveControl, unsigned int& unitComposition, unsigned int& cost);

    unsigned int getUnitComposition() { return _unitsComposition; }

    bool isDead();

protected:
    std::string _unitName;
    // std::string image;
    unsigned int& _move;
    unsigned int& _toughness;
    unsigned int& _save;
    unsigned int& _wounds;
    unsigned int& _leadership;
    unsigned int& _objectiveControl;

    // fields related to unit
    unsigned int& _unitsComposition;
    unsigned int& _cost;
    
};