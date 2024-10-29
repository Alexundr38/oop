#ifndef ABILITY_H
#define ABILITY_H

#include "PlayingField.h"
#include "ShipManager.h"

class Ability {
public:
	virtual std::string printInfo() = 0;

	virtual std::pair<bool,bool> useAbility() = 0;
};

#endif