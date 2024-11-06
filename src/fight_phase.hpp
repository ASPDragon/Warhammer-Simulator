#include <vector>

class Player;
class Unit;
class Model;

class FightPhase {
public:
    FightPhase();
    void pileIn(const Unit& unit);
    size_t calculateAttacks(const Unit& unit) const;

protected:
    bool hasCharged(const Unit& unit) const;
    bool canFight(const Unit& unit) const;
    
private:
    std::vector<Player> players;
};