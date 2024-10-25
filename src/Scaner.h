#ifndef SCANER_H
#define SCANER_H

#include "Ability.h"

class Scaner : public Ability {
private:
	int x;
	int y;
	bool needs = true;

public:
	Scaner() = default;

	std::string printInfo() override;

	void printInput() override;

	bool useAbility(PlayingField*& field, ShipManager*& manager) override;

	void setCoordinates(int y, int x) override;

	bool needCoordinates() override;

	~Scaner() = default;
};

#endif