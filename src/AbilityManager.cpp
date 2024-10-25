#include "AbilityManager.h"

AbilityManager::AbilityManager() {
	ability_queue.push_back(new Bombing);
	ability_queue.push_back(new DoubleDamage);
	ability_queue.push_back(new Scaner);

	std::mt19937 g(static_cast<unsigned int>(time(0)));
	std::shuffle(ability_queue.begin(), ability_queue.end(), g);

	this->number = 3;
}

std::pair<int, int> AbilityManager::inputYX(int height, int width) {
	int y, x;
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> y >> x) || !ss.eof() || y < 1 || x < 1 || y > height || x > width) {
				throw InputCoordinatesException();
			}
			break;
		}
		catch (InputCoordinatesException& e) {
			std::cout << e.what() << '\n';
		}
	}
	return std::make_pair(y, x);
}

void AbilityManager::createAbility() {
	std::vector<Ability*> new_abilitys = { new DoubleDamage, new Scaner, new Bombing };

	std::mt19937 g(static_cast<unsigned int>(time(0)));
	std::shuffle(new_abilitys.begin(), new_abilitys.end(), g);

	this->ability_queue.push_back(new_abilitys[0]);
	this->number++;
}

std::string AbilityManager::infoAbility() {
	return ability_queue[0]->printInfo();
}

bool AbilityManager::useAbility(PlayingField*& field, ShipManager*& manager) {
	bool needs_coordinates = ability_queue[0]->needCoordinates();
	int x = 0;
	int y = 0;
	ability_queue[0]->printInput();
	if (needs_coordinates == true) {
		std::pair <int, int> sizes;
		sizes = field->getSize();
		std::pair <int, int> coordinates = inputYX(sizes.first, sizes.second);
		y = coordinates.first - 1;
		x = coordinates.second - 1;
	}
	bool check;
	ability_queue[0]->setCoordinates(y, x);
	check = ability_queue[0]->useAbility(field, manager);
	ability_queue.erase(ability_queue.begin());
	this->number--;
	if (check == true) {
		createAbility();
	}
	return true;
}

int AbilityManager::getNumber() const {
	return this->number;
}

AbilityManager::~AbilityManager() {
	ability_queue.clear();
}