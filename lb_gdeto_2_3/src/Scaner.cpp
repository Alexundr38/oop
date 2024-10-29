#include "Scaner.h"

Scaner::Scaner(PlayingField* field) {
	this->field = field;
}

std::string Scaner::printInfo() {
	return "C�����";
}

std::pair<bool,bool> Scaner::useAbility() {
	std::pair<int, int> sizes = field->getSize();
	std::cout << "������� ���������� ����� ������ �������� ���� ������� 2x2 � ������� [y x]\n";
	Input* input = new Input();
	std::pair<int, int> coordinates = input->inputYX(sizes.first, sizes.second);
	delete input;
	int y = coordinates.first - 1, x = coordinates.second - 1;
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
		std::cout << "� ������ ������� ���� ������� �������\n";
	}
	else {
		std::cout << "� ������ ������� ��� ��������\n";
	}
	return std::make_pair(false, false);
}
