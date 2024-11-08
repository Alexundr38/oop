#ifndef SCANER_H
#define SCANER_H

#include "Ability.h"
#include "InputManager.h"

class Scaner : public Ability {
public:
	Scaner() = default;

	std::string printInfo() override;

	bool useAbility(Player* player) override;

	~Scaner() = default;
};

#endif