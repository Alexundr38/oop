#ifndef PLAYER_H
#define PLAYER_H

#include "PlayingField.h"
#include "ShipManager.h"
#include "AbilityManager.h"
#include "RandomValues.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "json.hpp"
using json = nlohmann::json;

class Player {
private:
	PlayingField* field;
	ShipManager* ship_manager;
	AbilityManager* ability_manager;
	InputManager* input_manager;
	OutputManager* output_manager;
	bool is_player;
	bool is_double = false;

public:
	
	Player(bool is_player, InputManager* input_manager, OutputManager* output_manager) :
		is_player(is_player), input_manager(input_manager), output_manager(output_manager) {};

	void setField(int width, int height);

	void setShipManager(std::vector <int> info);

	void setAbilityManager(AbilityManager* ability_manager = nullptr);

	PlayingField* getField();

	ShipManager* getShipManager();

	AbilityManager* getAbilityManager();

	InputManager* getInputManager();

	OutputManager* getOutputManager();

	void setDouble();

	std::pair<bool, bool> playerMove(bool first_action = true);

	bool hit(int x, int y, int index, bool is_hide = false);

	~Player();
	
};

#endif