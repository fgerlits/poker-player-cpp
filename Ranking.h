#include "json.h"

class Ranking {
public:
	Ranking(json::Value cards);
	bool isGood();

private:
	json::Array cards;
};
