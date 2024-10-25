#ifndef BOMBING_H
#define BOMBING_H

#include "Ability.h"

class Bombing : public Ability {
private:
	bool needs = false;

public:
	Bombing() = default;

	std::string printInfo() override;

	void printInput() override {};

	bool useAbility(PlayingField*& field, ShipManager*& manager) override;

	void setCoordinates(int y = 0, int x = 0) override {};

	bool needCoordinates() override;

	~Bombing() = default;
};

#endif