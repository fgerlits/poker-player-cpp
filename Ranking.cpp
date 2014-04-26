#include "Ranking.h"

Ranking::Ranking(json::Value cards_) : cards{cards_.ToArray()} {}

namespace {
	bool isFaceCard(std::string rank) {
		return (rank == "J" || rank == "Q" || rank == "K" || rank == "A");
	}
	
	const std::string RANK = "rank";
}

bool Ranking::isGood() {
	json::Value card1 = cards[0];
	json::Value card2 = cards[1];

	return isFaceCard(card1[RANK]) || isFaceCard(card2[RANK]);
}
