#include "json.h"

class Ranking {
public:
	Ranking(json::Value cards);
	bool isGood();
	bool isMedium();

private:
	json::Array cards;
};
