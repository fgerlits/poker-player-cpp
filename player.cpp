#include "player.h"
#include "GameState.h"
#include <iostream>

const char* Player::VERSION = "1.1";

namespace {
	bool isAllIn(const json::Value& player) {
		std::string status = player["status"];
		int stack = player["stack"].ToInt();
		return (status == "active" && stack == 0);
	}

	bool isActive(const json::Value& player) {
		std::string status = player["status"];
		int stack = player["stack"].ToInt();
		return status == "active";
	}

	int countAllIns(const std::vector<json::Value> players) {
		int result = 0;
		for (const auto& player : players) {
			if (isAllIn(player)) {
				++result;
			}
		}
		return result;
	}

	int countActives(const std::vector<json::Value> players) {
		int result = 0;
		for (const auto& player : players) {
			if (isActive(player)) {
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
	int numberOfOtherPlayers = countActives(otherPlayers);
	int numberOfAllIns = countAllIns(otherPlayers);

	int result = 0;
	if (ranking.isGood() && numberOfAllIns < 2) {
		result = 10000;
	} else if (numberOfOtherPlayers == 1) {
		result = 10000;
	}
	std::cerr << "### result: " << result << std::endl;
	return result;
}

void Player::showdown(json::Value game_state)
{
}
