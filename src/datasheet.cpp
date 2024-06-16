#include "datasheet.hpp"

Datasheet::Datasheet(std::string& unitName, unsigned int& move, unsigned int& toughness, unsigned int& save, unsigned int& wounds,
              unsigned int& leadership, unsigned int& objectiveControl, unsigned int& unitComposition, unsigned int& cost)
: _unitName{unitName}, _move{move}, _toughness{toughness}, _save{save}, _wounds{wounds}, _leadership{leadership}, 
  _objectiveControl{objectiveControl}, _unitsComposition{unitComposition}, _cost{cost} {}

bool Datasheet::isDead() {
    return _wounds == 0;
}