#ifndef BOMBING_H
#define BOMBING_H

#include "Ability.h"


class Bombing : public Ability {
public:
	Bombing() = default;

	std::string printInfo() override;

	bool useAbility(Player* player) override;

	~Bombing() = default;
};

#endif