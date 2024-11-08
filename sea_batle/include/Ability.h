#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include "ShipManager.h"
#include "PlayingField.h"

class Player;
class Ability {
public:
	virtual std::string printInfo() = 0;

	virtual bool useAbility(Player* player) = 0;
};

#endif