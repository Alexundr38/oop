#ifndef GAME_H
#define GAME_H

#include <typeinfo>
#include <fstream>
#include "../include/Player.h"
#include "../InputManager/include/InputManager.h"
#include "../OutputManager/include/OutputManager.h"
#include "GameState.h"
#include "StartState.h"
#include "CreateGameState.h"
#include "BotMoveState.h"
#include "BotWinState.h"
#include "PlayerMoveState.h"
#include "PlayerWinState.h"
#include "LoadState.h"
#include "SaveState.h"

class Game {

	Player* player;
	Player* bot;
	InputManager* input_manager;
	OutputManager* output_manager;
	/*int round_number = 1;*/
	GameState* current_state;

	void stringToState(std::string str);

public:

	Game();

	void doState();

	Player* getPlayer(bool is_player = true);

	void changeState(GameState* new_state, bool is_hide = false); 

	json to_json() const;

	void from_json(const json& j);

	friend std::ofstream& operator<<(std::ofstream& out, Game* game);

	friend std::ifstream& operator>>(std::ifstream& in, Game* game);

	~Game();
};

std::ofstream& operator<<(std::ofstream& out, Game* game);

std::ifstream& operator>>(std::ifstream& in, Game* game);

#endif