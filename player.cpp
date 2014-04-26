#include "player.h"
#include "GameState.h"
#include <iostream>

const char* Player::VERSION = "Default C++ folding player";

int Player::betRequest(json::Value game_state)
{
	//std::cerr << "###> " << game_state.GetType() << std::endl;
	GameState gs(game_state);
	return 10000;
}

void Player::showdown(json::Value game_state)
{
}
