#include "player.h"
#include "GameState.h"
#include <iostream>

const char* Player::VERSION = "Default C++ folding player";

int Player::betRequest(json::Value game_state)
{
	//std::cerr << "###> " << game_state.GetType() << std::endl;
	GameState gs(game_state);
	Ranking ranking = gs.hole_cards_ranking();
	return ranking.isGood() ? 10000 : 100;
}

void Player::showdown(json::Value game_state)
{
}
