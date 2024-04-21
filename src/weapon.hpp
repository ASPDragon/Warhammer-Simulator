#include <optional>

class Weapon {
public:
    
protected:
    int attacks;
    std::optional<int> weaponSkill;
    std::optional<int> ballisticSkill;
    int strength;
};