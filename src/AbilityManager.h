#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include "Ability.h"
#include "DoubleDamage.h"
#include "Bombing.h"
#include "Scaner.h"
#include "Exception.h"

class AbilityManager {
private:
	int number;
	std::vector<Ability*> ability_queue;

	std::pair<int, int> inputYX(int height, int width);

public:
	AbilityManager();

	void createAbility();

	std::string infoAbility();

	bool useAbility(PlayingField*& field, ShipManager*& manager);

	int getNumber() const;

	~AbilityManager();
};

#endif