#include "AbilityManager.h"

AbilityManager::AbilityManager(PlayingField* field, ShipManager* manager) {
	ability_queue.push_back(new Bombing(field, manager));
	ability_queue.push_back(new DoubleDamage());
	ability_queue.push_back(new Scaner(field));

	std::mt19937 g(static_cast<unsigned int>(time(0)));
	std::shuffle(ability_queue.begin(), ability_queue.end(), g);

	this->number = 3;
}

void AbilityManager::createAbility(PlayingField* field, ShipManager* manager) {
	std::vector<Ability*> new_abilitys = { new DoubleDamage(), new Scaner(field), new Bombing(field, manager)};

	std::mt19937 g(static_cast<unsigned int>(time(0)));
	std::shuffle(new_abilitys.begin(), new_abilitys.end(), g);

	this->ability_queue.push_back(new_abilitys[0]);
	this->number++;
}

std::string AbilityManager::infoAbility() {
	return ability_queue[0]->printInfo();
}

bool AbilityManager::useAbility(PlayingField* field, ShipManager* manager) {
	std::pair<bool,bool> check = ability_queue[0]->useAbility();
	ability_queue.erase(ability_queue.begin());
	this->number--;
	if (check.second == true) {
		createAbility(field, manager);
	}
	return check.first;
}

int AbilityManager::getNumber() const {
	return this->number;
}

AbilityManager::~AbilityManager() {
	ability_queue.clear();
}