#include "Ranking.h"
#include <iostream>

Ranking::Ranking(json::Value cards_) : cards{cards_.ToArray()} {}

namespace {
	bool isFaceCard(std::string rank) {
		return (rank == "J" || rank == "Q" || rank == "K" || rank == "A");
	}
	
	const std::string RANK = "rank";

	bool isPair(const std::string& one, const std::string& two) {
		return one == two;
	}

	int value(const std::string& rank) {
		if ("2" <= rank && rank <= "9") {
			return rank[0] - '0';
		} else if ("10" == rank) {
			return 10;
		} else if ("J" == rank) {
			return 11;
		} else if ("Q" == rank) {
			return 12;
		} else if ("K" == rank) {
			return 13;
		} else if ("A" == rank) {
			return 14;
		}
	}
}

bool Ranking::isGood() {
	std::string card1 = cards[0][RANK];
	std::string card2 = cards[1][RANK];
//std::cerr << "### cards: " << card1 << ", " << card2 << std::endl;
	int value1 = value(card1);
	int value2 = value(card2);
//std::cerr << "### card values: " << value1 << ", " << value2 << std::endl;

	if (isFaceCard(card1) && isFaceCard(card2) &&
			(card1 == "A" || card2 == "A")) {
		return true;
	} else if (isPair(card1, card2) && value1 >= 8) {
		return true;
	} else {
		return false;
	}
}

bool Ranking::isMedium() {
        std::string card1 = cards[0][RANK];
        std::string card2 = cards[1][RANK];
//std::cerr << "### cards: " << card1 << ", " << card2 << std::endl;
        int value1 = value(card1);
        int value2 = value(card2);
//std::cerr << "### card values: " << value1 << ", " << value2 << std::endl;

	if (isFaceCard(card1) && isFaceCard(card2)) {
		return true;
	} else if (isPair(card1, card2)) {
		return true;
	} else {
		return false;
	}
}

