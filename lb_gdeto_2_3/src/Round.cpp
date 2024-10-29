#include "Round.h"

Round::Round(Player* player, Player* bot) :player(player), bot(bot) {};

void Round::game() {
	bool value = true;
	bool* flag = &value;
	while (value == true) {
		playerMove(flag);
		if (value == false) {
			std::cout << "�� ��������!\n";
			continue;
		}
		botMove(flag);
		if (value == false) {
			std::cout << "�� ���������..\n����� ����\n";
			continue;
		}
	}

}

bool Round::playerMove(bool* flag, bool first_action, bool is_double) {
	if (*flag == true) {
		//showField();
		std::cout << "------------------------\n";
		std::cout << "��� ���!\n";
		int player_answer = 0;
		AbilityManager* ability_manager = player->getAbilityManager();
		PlayingField* field = bot->getField();
		ShipManager* ship_manager = bot->getShipManager();
		if (first_action == true) {
			std::cout << "���� ������ ��������� ����������� ������� [1], � ��������� ������ ������� [0].\n";
			Input* input = new Input;
			player_answer = input->inputValue();
			delete input;
			try {
				int number_abilitys = ability_manager->getNumber();
				if (player_answer == 1 && number_abilitys == 0) {
					throw UseAbilityException();
				}
			}
			catch (UseAbilityException& e) {
				std::cout << e.what() << '\n';
				player_answer = 0;
			}
		}
		if (player_answer == 0) {
			std::cout << "������� ����� ����� � ������� [y x]\n";
			std::pair <int, int> sizes;
			sizes = field->getSize();
			Input* input = new Input;
			std::pair <int, int> coordinates = input->inputYX(sizes.first, sizes.second);
			delete input;
			int y = coordinates.first, x = coordinates.second;
			y--;
			x--;
			int check;
			check = field->cellAtack(y, x);
			if (check != 0) {
				bool check_hit;
				if (is_double == true) {
					field->cellAtack(y, x);
					check_hit = hit(y, x, check - 1, true, true);
					if (check_hit == false) {
						playerMove(flag, false, true);
						return true;
					}
				}
				check_hit = hit(y, x, check - 1, true);
				if (check_hit == false) {
					playerMove(flag, false);
					return true;
				}

				bool check_win = ship_manager->checkWin();
				if (check_win == true) {
					*flag = false;
				}
			}
			else {
				std::cout << "������!\n";
			}
		}
		else {
			std::cout << "������������ ����������� " << ability_manager->infoAbility() << '\n';
			bool is_double = ability_manager->useAbility(field, ship_manager);
			if (is_double == true) {
				playerMove(flag, false, true);
				return true;
			}
			bool check_win = ship_manager->checkWin();
			if (check_win == true) {
				*flag = false;
			}
			playerMove(flag, false);
		}
	}
	return true;

}

void Round::botMove(bool* flag) {
	if (*flag == true) {
		//showField();
		std::cout << "------------------------\n";
		std::cout << "��� ���������!\n";
		std::pair <int, int> coordinates;
		PlayingField* field = player->getField();
		ShipManager* ship_manager = player->getShipManager();
		std::pair <int, int> sizes = field->getSize();
		coordinates = getRandomCoordinates(sizes);
		coordinates.second--;
		coordinates.first--;
		int check;
		check = field->cellAtack(coordinates.first, coordinates.second);
		if (check != 0) {
			hit(coordinates.first, coordinates.second, check - 1, false);

			bool check_win;
			check_win = ship_manager->checkWin();
			if (check_win == true) {
				*flag = false;
			}
		}
		else {
			std::cout << "������!\n";
		}
	}
}

bool Round::hit(int y, int x, int index, bool is_player, bool is_hide) {
	if (is_player == true) {
		int index_deck = bot_field->getDeckIndex(y, x);
		bool degree = bot_manager->checkDegree(index, index_deck);
		if (degree == true) {
			if (is_hide == false) { std::cout << "��������� � ������������ ������� �������!\n"; }
			return false;
		}
		else {
			bot_manager->setDamage(index, index_deck);

			bool check = bot_manager->checkDestroyed(index);

			if (is_hide == false) { std::cout << "���������!\n"; }
			if (degree == false) {
				if (is_hide == false) { std::cout << "������ ���������!\n"; }
			}
			else {
				if (is_hide == false) { std::cout << "������ ���������!\n"; }
				bot_field->killDeck(y, x);
			}

			if (check == true) {
				ability_manager->createAbility(bot_field, bot_manager);
				if (is_hide == false) { std::cout << "������� ���������!\n"; }
			}
		}
	}
	else {
		int index_deck = player_field->getDeckIndex(y, x);
		bool degree = player_manager->checkDegree(index, index_deck);
		if (degree == true) {
			std::cout << "��������� � ������������ ������� �������!\n";
			return false;
		}
		else {
			player_manager->setDamage(index, index_deck);

			bool check = player_manager->checkDestroyed(index);

			std::cout << "���������!\n";
			if (degree == false) {
				std::cout << "������ ���������!\n";
			}
			else {
				std::cout << "������ ���������!\n";
			}

			if (check == true) {
				std::cout << "������� ���������!\n";
				player_field->killDeck(y, x);
			}
		}
	}
	return true;
}

Round::~Round() {
	delete player;
	delete bot;
}