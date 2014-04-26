#include "GameState.h"
#include <iostream>

GameState::GameState(json::Value game_state_) : game_state(game_state_) {
	std::cerr << "### " << json::Serialize(game_state_) << std::endl;
}

int GameState::current_buy_in() {
	std::cerr << "### " << game_state.GetType() << std::endl;
//	json::Object object = game_state.ToObject();
//	json::Object::ValueMap::iterator it = object.find("current_buy_in");
	json::Value val = game_state["current_buy_in"];
	return val.ToInt();
}

int GameState::player_number() {
	json::Value val = game_state["in_action"];
	return val.ToInt();
}

json::Value GameState::myPlayer() {
	json::Value val = game_state["players"];
	return val[player_number()];
}

json::Value GameState::hole_cards() {
	json::Value val = myPlayer()["hole_cards"];
	return val;
}

Ranking GameState::hole_cards_ranking() {
	return Ranking(hole_cards());
}

std::vector<json::Value> GameState::otherPlayers() {
	json::Array players = game_state["players"].ToArray();
	int myId = player_number();
	std::vector<json::Value> result{};
	for (const auto& player : players) {
		int id = player["id"].ToInt();
		if (id != myId) {
			result.push_back(player);
		}
	}
	return result;
}

int GameState::minimumRaisedBet() {
	int current_buy_in = game_state["current_buy_in"].ToInt();
	int minimum_raise = game_state["minimum_raise"].ToInt();
	int myBet = myPlayer()["bet"].ToInt();
	return current_buy_in - myBet + minimum_raise;
}

int GameState::positionAfterDealer() {
	int dealer = game_state["dealer"].ToInt();
	int numberOfPlayers = game_state["players"].ToArray().size();
	return (player_number() - dealer) % numberOfPlayers;
}

int GameState::small_blind() {
	return game_state["small_blind"].ToInt();
}
