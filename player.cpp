#include "player.h"
#include "GameState.h"
#include <iostream>

const char* Player::VERSION = "1.3";

namespace {
	bool isLive(const json::Value& player) {
		std::string status = player["status"];
		return status != "out";
	}

	int countNotOut(const std::vector<json::Value> players) {
		int result = 0;
		for (const auto& player : players) {
			if (isLive(player)) {
				++result;
			}
		}
		return result;
	}
		
}

int Player::betRequest(json::Value game_state)
{
	//std::cerr << "###> " << game_state.GetType() << std::endl;
	GameState gs(game_state);
	Ranking ranking = gs.hole_cards_ranking();

	std::vector<json::Value> otherPlayers = gs.otherPlayers();
	int numberOfNotOut = countNotOut(otherPlayers);
	int positionAfterDealer = gs.positionAfterDealer();

	int result = 0;
	if (numberOfNotOut == 1) {
		result = 10000;
	} else if (ranking.isGood()) {
		result = 10000; //gs.minimumRaisedBet();
	} else if (ranking.isMedium()) {
		result = gs.current_buy_in();
	} else if (positionAfterDealer == 1 || positionAfterDealer == 2) {
		result = gs.current_buy_in();
	}
	std::cerr << "### result: " << result << std::endl;
	return result;
}

void Player::showdown(json::Value game_state)
{
}
