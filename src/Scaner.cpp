#include "Scaner.h"

std::string Scaner::printInfo() {
	return "Cканер";
}

void Scaner::printInput() {
	std::cout << "Введите координаты точки левого верхнего угла области 2x2 в формате [y x]\n";
}

bool Scaner::useAbility(PlayingField*& field, ShipManager*& manager) {
	std::pair <int, int> sizes = field->getSize();
	bool is_deck = false;
	for (int i = y; i < std::min(y + 2, sizes.first); i++) {
		for (int j = x; j < std::min(x + 2, sizes.second); j++) {
			int index = field->getDeckIndex(i, j);
			if (index != -1) {
				is_deck = true;
			}
		}
	}
	if (is_deck == true) {
		std::cout << "В данной области есть сегмент корабля\n";
	}
	else {
		std::cout << "В данной области нет кораблей\n";
	}
	return false;
}

void Scaner::setCoordinates(int y, int x) {
	this->y = y;
	this->x = x;
}

bool Scaner::needCoordinates() {
	return needs;
}