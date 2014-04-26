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
