#include "Bombing.h"

std::string Bombing::printInfo() {
	return "Бомбардировка";
}

bool Bombing::useAbility(PlayingField*& field, ShipManager*& manager) {
	int index;
	int index_deck;
	bool flag = true;
	bool deck_flag = true;
	bool flag_atack = true;
	while (flag == true) {
		index = rand() % manager->getNumber();
		if (manager->checkDestroyed(index) == false) {

			while (deck_flag == true) {

				index_deck = rand() % manager->getShipLength(index);
				if (manager->checkDegree(index, index_deck) == false) {
					manager->setDamage(index, index_deck);
					
					std::pair <int, int> sizes = field->getSize();
					std::vector<std::vector<std::pair<int,int>>> index_field = field->getViewIndex();
					for (int i = 0; i < sizes.first && flag_atack == true; i++) {
						for (int j = 0; j < sizes.second && flag_atack == true; j++) {
							if (index_field[i][j].first == index + 1 && index_field[i][j].second == index_deck) {
								field->cellAtack(i, j, true);
								if (manager->checkDegree(index, index_deck) == true) {
									field->killDeck(i, j);
								}
								if (manager->checkDestroyed(index) == true) {
									std::cout << "Корабль уничтожен!\n";
									return true;
								}
								flag_atack = false;
								deck_flag = false;	
							}
						}
					}
				}
			}
			flag = false;
		}
	}
	return false;
}

bool Bombing::needCoordinates() {
	return needs;
}