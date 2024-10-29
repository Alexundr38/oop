#ifndef PLAYER_H
#define PLAYER_H

#include "PlayingField.h"
#include "ShipManager.h"
#include "AbilityManager.h"

class Player {
private:

	PlayingField* field;
	ShipManager* ship_manager;
	AbilityManager* ability_manager;

public:
	
	Player() = default;

	void setField(int y, int x);

	void setShipManager();

	void setAbilityManager();

	PlayingField* getField();

	ShipManager* getShipManager();

	AbilityManager* getAbilityManager();
};

#endif