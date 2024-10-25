#ifndef ABILITY_H
#define ABILITY_H

#include "PlayingField.h"
#include "ShipManager.h"

class Ability {
public:
	virtual std::string printInfo() = 0;

	virtual void printInput() = 0;

	virtual bool useAbility(PlayingField*& field, ShipManager*& manager) = 0;

	virtual void setCoordinates(int y, int x) = 0;

	virtual bool needCoordinates() = 0;
};

#endif