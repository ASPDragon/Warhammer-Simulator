/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include <cstdint>
#include <vector>

struct Unit;

class Player {
    uint32_t id;
    bool operator==(const Player&) const;
};