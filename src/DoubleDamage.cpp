#include "DoubleDamage.h"

std::string DoubleDamage::printInfo() {
	return "������� ����";
}

void DoubleDamage::printInput() {
	std::cout << "������� ���������� ����� ����� � ������� [y x]\n";
}

bool DoubleDamage::useAbility(PlayingField*& field, ShipManager*& manager) {
	int index;
	for (int i = 0; i < 2; i++) {
		index = field->cellAtack(y, x) - 1;
		if (index != -1) {
			bool check = manager->checkDestroyed(index);
			if (check == false) {
				int index_deck = field->getDeckIndex(y, x);
				manager->setDamage(index, index_deck);
			}
		}
	}
	if (index == -1) {
		std::cout << "������!\n";
	}
	else {
		std::cout << "���������!\n������ ���������!\n";
		field->killDeck(y, x);
		bool check = manager->checkDestroyed(index);
		if (check == true) {
			std::cout << "������� ���������!\n";
			return true;
		}
	}
	return false;
}

void DoubleDamage::setCoordinates(int y, int x) {
	this->y = y;
	this->x = x;
}

bool DoubleDamage::needCoordinates() {
	return needs;
}