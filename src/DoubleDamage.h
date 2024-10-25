#ifndef DOUBLEDAMAGE_H
#define DOUBLEDAMAGE_H

#include "Ability.h"

class DoubleDamage : public Ability {
private:
	int x;
	int y;
	bool needs = true;

public:
	DoubleDamage() = default;

	std::string printInfo() override;

	void printInput() override;

	bool useAbility(PlayingField*& field, ShipManager*& manager) override;

	void setCoordinates(int y, int x) override;

	bool needCoordinates() override;

	~DoubleDamage() = default;
};

#endif