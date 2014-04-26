#include "player.h"
#include "GameState.h"
#include <iostream>

const char* Player::VERSION = "1.0";

int Player::betRequest(json::Value game_state)
{
	//std::cerr << "###> " << game_state.GetType() << std::endl;
	GameState gs(game_state);
	Ranking ranking = gs.hole_cards_ranking();
	return ranking.isGood() ? 10000 : 0;
}

void Player::showdown(json::Value game_state)
{
}
