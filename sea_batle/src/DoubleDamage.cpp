#include "DoubleDamage.h"
#include "Player.h"

std::string DoubleDamage::printInfo() {
	return "������� ����";
}

bool DoubleDamage::useAbility(Player* player) {
	/*std::pair<int, int> sizes = field->getsize();
	std::cout << "������� ���������� ����� ����� � ������� [y x]\n";
	input* input = new input();
	std::pair<int, int> coordinates = input->inputyx(sizes.first, sizes.second);
	int y = coordinates.first - 1, x = coordinates.second - 1;
	delete input;
	int index;
	for (int i = 0; i < 2; i++) {
		index = field->cellatack(y, x) - 1;
		if (index != -1) {
			bool check = manager->checkdestroyed(index);
			if (check == false) {
				int index_deck = field->getdeckindex(y, x);
				manager->setdamage(index, index_deck);
			}
		}
	}
	if (index == -1) {
		std::cout << "������!\n";
	}
	else {
		std::cout << "���������!\n������ ���������!\n";
		field->killdeck(y, x);
		bool check = manager->checkdestroyed(index);
		if (check == true) {
			std::cout << "������� ���������!\n";
			return true;
		}
	}
	return false;*/
	player->setDouble();
	return false;
}