#include "player.h"

const char* Player::VERSION = "Default C++ folding player";

int Player::betRequest(json::Value game_state)
{
    return 1000;
}

void Player::showdown(json::Value game_state)
{
}
