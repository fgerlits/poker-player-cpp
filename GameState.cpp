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
