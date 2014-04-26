#include "json.h"
#include <string>

class GameState {
  public:
	GameState(json::Value game_state);

	//std::vector<Card> holeCards();
	//std::string player_id();
	int current_buy_in();
	

  private:
	json::Value game_state;
};
