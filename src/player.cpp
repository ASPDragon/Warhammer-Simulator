/**
* Copyright Sergei Avdoshkin aka ASPDragon
* All Rights Reserved
* Warhammer-Simulator
*/

#include "player.hpp"

bool Player::operator==(const Player& player) const
{
    return player.id == this->id;
}