#include <optional>

enum class WeaponType {
    
}

class Weapon {
public:
    Weapon(int&& attack, bool&& canShot, std::optional<int>&& weaponSkill,
           std::optional<int> ballisticSkill, int&& strength, int&& armourPenetration, int& damage);
           
    inline int getAttacks() const { return attacks; }
    int getWeaponSkill() const;
    int getBallisticSkill() const;
    inline int getStrength() const { return strength; }
    inline int getArmourPenetratiom() const { return armourPenetration; }
    inline int getDamage() const { return damage; }
    
protected:
    int attacks;
    bool canShot;
    std::optional<int> weaponSkill;
    std::optional<int> ballisticSkill;
    int strength;
    int armourPenetration;
    int damage;
};