#include <vector>

class Player;
class Unit;
class Model;

class FightPhase {
public:
    FightPhase();
    void pileIn(const Unit& unit);
    size_t calculateAttacks(const Model& model) const;

protected:
    bool hasCharged(const Unit& unit) const;
    bool canFight(const Model& model) const;
private:
    std::vector<Player> players;
};