#ifndef DOUBLEDAMAGE_H
#define DOUBLEDAMAGE_H

#include "Ability.h"
#include "InputManager.h"

class DoubleDamage : public Ability {
public:
	DoubleDamage() = default;

	std::string printInfo() override;

	bool useAbility(Player* player) override;

	~DoubleDamage() = default;
};

#endif