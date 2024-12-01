#ifndef PLAYER_H
#define PLAYER_H

#include "PlayingField.h"
#include "ShipManager.h"
#include "../Abilitys/include/AbilityManager.h"
#include "RandomValues.h"
#include "../InputManager/include/InputManager.h"
#include "../OutputManager/include/OutputManager.h"
#include "json.hpp"
using json = nlohmann::json;

class Player {
private:
	PlayingField* field = nullptr;
	ShipManager* ship_manager = nullptr;
	AbilityManager* ability_manager = nullptr;
	InputManager* input_manager;
	OutputManager<Output>* output_manager;
	bool is_player;
	bool is_double = false;

public:
	//Player(InputManager* input_manager, OutputManager* output_manager);

	Player(bool is_player, InputManager* input_manager, OutputManager<Output>* output_manager);

	json to_json() const;

	void from_json(const json& j);

	void setField(int width, int height);

	void setShipManager(std::vector <int> info);

	void setAbilityManager(bool is_new = false);

	PlayingField* getField();

	ShipManager* getShipManager();

	AbilityManager* getAbilityManager();

	InputManager* getInputManager();

	OutputManager<Output>* getOutputManager();

	void setDouble();

	bool playerMove(bool is_use = false);

	bool hit(int x, int y, int index, bool is_hide = false);

	~Player();
	
};

#endif