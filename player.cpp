#include "player.h"
#include "GameState.h"
#include <iostream>

const char* Player::VERSION = "1.5";

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
	int badCardLimit = gs.small_blind() * 3;
	int mediumLimit = gs.myStack() / 4;

	int result = 0;
	if (ranking.isGood()) {
		result = 10000; //gs.minimumRaisedBet();
	} else if (ranking.isMedium()) {
	//	if (numberOfNotOut == 1) {
	//		result = 10000;
	//	} else {
		result = std::min(mediumLimit, gs.current_buy_in());
	//	}
	} else if (positionAfterDealer == 1 || positionAfterDealer == 2) {
		result = std::min(badCardLimit, gs.current_buy_in());
	}
	std::cerr << "### result: " << result << std::endl;
	return result;
}

void Player::showdown(json::Value game_state)
{
}
