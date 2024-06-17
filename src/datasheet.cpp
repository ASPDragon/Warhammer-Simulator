#include "datasheet.hpp"

Datasheet::Datasheet(const std::string_view unitName, const unsigned int move, const unsigned int toughness,
              const unsigned int save, const unsigned int wounds, const unsigned int leadership,
              const unsigned int objectiveControl, const unsigned int modelsNum, const unsigned int cost)
: _unitName{unitName}, _move{move}, _toughness{toughness}, _save{save}, _wounds{wounds}, _leadership{leadership}, 
  _objectiveControl{objectiveControl}, _modelsNum{modelsNum}, _cost{cost} {}