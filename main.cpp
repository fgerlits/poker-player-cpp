#include<iostream>
#include<string>
#include "json.h"
#include "player.h"

using namespace std;

int main(int argc, char* argv[])
{
    string action = argv[1];
	//cerr << "### arg: " << action << endl;
    string game_state_json;
    std::getline(cin, game_state_json);

	//cerr << "### input string: " << game_state_json << endl;
	//game_state_json = "{\"players\":[{\"name\":\"Current\",\"stack\":1000,\"status\":\"active\",\"bet\":10,\"hole_cards\":[{\"rank\":\"7\",\"suit\":\"spades\"},{\"rank\":\"K\",\"suit\":\"clubs\"}],\"version\":\"Default C++ folding player\",\"id\":0},{\"name\":\"Old\",\"stack\":970,\"status\":\"active\",\"bet\":20,\"version\":\"Default C++ folding player\",\"id\":1}],\"small_blind\":10,\"orbits\":0,\"dealer\":1,\"community_cards\":[],\"current_buy_in\":20,\"pot\":30,\"in_action\":0,\"minimum_raise\":10}";
    json::Value game_state = json::Deserialize(game_state_json);
	//cerr << "### input json: " << json::Serialize(game_state) << endl;

    if(action == "bet_request")
    {
        cout << Player::betRequest(game_state);
    }
    else if(action == "showdown")
    {
        Player::showdown(game_state);
    }
    else if(action == "version")
    {
        cout << Player::VERSION;
    }

    return 0;
}
