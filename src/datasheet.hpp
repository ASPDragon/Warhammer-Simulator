#include <string>
#include <array>
#include "weapon.hpp"

class Character {
public:
    
protected:
    std::string unitName;
    int move;
    int toughness;
    int save;
    int wounds;
    int leadership;
    int objectiveControl;

    std::array<Weapon, 4> armoury;
};