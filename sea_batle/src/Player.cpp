#include "Player.h"

void Player::setField(int width, int height) {
	this->field = new PlayingField{ width, height };
}

void Player::setShipManager(std::vector <int> info) {
	std::pair <int, int> sizes;
	sizes = field->getSize();
	int number = info[4];
	info.pop_back();
	std::vector <int> lenghts;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < info[i]; j++) {
			lenghts.push_back(4 - i);
		}
	}
	ship_manager = new ShipManager{ number, lenghts };
	/*if (is_player == false) {
		infoManager(number, info);
	}*/
}

void Player::setAbilityManager(AbilityManager* ability_manager) {
	if (ability_manager != nullptr) {
		this->ability_manager = ability_manager;
	}
	else {
		this->ability_manager = new AbilityManager();
	}
}

PlayingField* Player::getField() {
	return this->field;
}

ShipManager* Player::getShipManager() {
	return this->ship_manager;
}

AbilityManager* Player::getAbilityManager() {
	return this->ability_manager;
}

InputManager* Player::getInputManager() {
	return this->input_manager;
}

OutputManager* Player::getOutputManager() {
	return this->output_manager;
}

void Player::setDouble() {
	this->is_double = true;
}

std::pair<bool, bool> Player::playerMove(bool first_action) {
	output_manager->printMessage("------------------------\n");
	if (is_player == true) {
		output_manager->printMessage("��� ���!\n");
	}
	else {
		output_manager->printMessage("��� ����������!\n");
	}
	int player_answer = 0;
	if (first_action == true && is_player == true) {
		output_manager->printMessage("���� ������ ��������� ����������� ������� [1], � ��������� ������ ������� [0].\n");
		player_answer = input_manager->inputValue();
		try {
			int number_abilitys = ability_manager->getNumber();
			if (player_answer == 1 && number_abilitys == 0) {
				throw UseAbilityException();
			}
		}
		catch (UseAbilityException& e) {
			std::ostringstream oss;
			oss << e.what() << '\n';
			output_manager->printMessage(oss.str());
			player_answer = 0;
		}
	}
	if (player_answer == 0) {
		std::pair <int, int> sizes;
		int y, x;
		sizes = field->getSize();
		if (is_player == true) {
			output_manager->printMessage("������� ����� ����� � ������� [x y]\n");
			std::pair <int, int> coordinates = input_manager->inputXY(sizes.first, sizes.second);
			x = --coordinates.first;
			y = --coordinates.second;
		}
		else {
			std::pair <int, int> coordinates;
			RandomValues* random_values = new RandomValues();
			coordinates = random_values->getRandomCoordinates(sizes);
			delete random_values;
			y = --coordinates.second;
			x = --coordinates.first;
		}
		int check;
		check = field->cellAtack(x, y);
		if (check != 0) {
			bool check_hit;
			if (is_double == true) {
				field->cellAtack(x, y);
				check_hit = hit(x, y, check - 1, true);
			}
			check_hit = hit(x, y, check - 1);
			if (check_hit == false) {
				return playerMove(false);
			}
			bool check_win = ship_manager->checkWin();
			if (check_win == true) {
				return std::make_pair(true,false);
			}
		}
		else {
			output_manager->printMessage("������!\n");
		}
		is_double = false;
	}
	else {
		std::ostringstream oss;
		oss << "������������ ����������� " << ability_manager->infoAbility() << '\n';
		output_manager->printMessage(oss.str());
		ability_manager->useAbility(this);
		bool check_win = ship_manager->checkWin();
		if (check_win == true) {
			return std::make_pair(true, true);
		}
		return std::make_pair(false, true);
		//playerMove(flag, false);
	}
	return std::make_pair(false, false);
}

bool Player::hit(int x, int y, int index, bool is_hide) {
	int index_deck = field->getDeckIndex(x, y);
	bool degree = ship_manager->checkDegree(index, index_deck);
	if (degree == true) {
		if (is_hide == false) { output_manager->printMessage("��������� � ������������ ������� �������!\n"); }
		return false;
	}
	else {
		ship_manager->setDamage(index, index_deck);

		bool check = ship_manager->checkDestroyed(index);
		bool degree = ship_manager->checkDegree(index, index_deck);

		if (is_hide == false) { output_manager->printMessage("���������!\n"); }
		if (degree == false) {
			if (is_hide == false) { output_manager->printMessage("������ ���������!\n"); }
		}
		else {
			if (is_hide == false) { output_manager->printMessage("������ ���������!\n"); };
			field->killDeck(x, y);
		}

		if (check == true) {
			if (is_player == true) { ability_manager->createAbility(); }
			if (is_hide == false) { output_manager->printMessage("������� ���������!\n"); }
		}
	}
	return true;
}

Player::~Player() {
	delete field;
	delete ship_manager;
	if (is_player == true) { delete ability_manager; }
}