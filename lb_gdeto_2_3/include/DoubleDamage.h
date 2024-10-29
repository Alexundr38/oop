#ifndef DOUBLEDAMAGE_H
#define DOUBLEDAMAGE_H

#include "Ability.h"
#include "Input.h"

class DoubleDamage : public Ability {
public:
	DoubleDamage() = default;

	std::string printInfo() override;

	std::pair<bool,bool> useAbility() override;

	~DoubleDamage() = default;
};

#endif