#include <optional>

class Character {
public:
    
protected:
    int move;
    std::optional<int> weaponSkill;
    std::optional<int> ballisticSkill;
    int strength;
    int toughness;
    int wounds;
    int attacks;
    int leadership;
    int save;
};