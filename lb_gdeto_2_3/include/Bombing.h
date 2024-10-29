#ifndef BOMBING_H
#define BOMBING_H

#include "Ability.h"

class Bombing : public Ability {
private:
	PlayingField* field;
	ShipManager* manager;

public:
	Bombing(PlayingField*& field, ShipManager*& manager);

	std::string printInfo() override;

	std::pair<bool,bool> useAbility() override;

	~Bombing() = default;
};

#endif