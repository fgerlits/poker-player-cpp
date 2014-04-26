#include "json.h"
#include <string>
#include "Ranking.h"

class GameState {
  public:
	GameState(json::Value game_state);

	//std::vector<Card> holeCards();
	//std::string player_id();
	int current_buy_in();
	int player_number();
	json::Value myPlayer();
	json::Value hole_cards();
	Ranking hole_cards_ranking();
	std::vector<json::Value> otherPlayers();
	int minimumRaisedBet();
	int positionAfterDealer();
	int small_blind();
	int myStack();

  private:
	json::Value game_state;
};
