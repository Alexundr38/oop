#include "GameOperation.h"

void GameOperation::inputSizes() {
	std::cout << "Введите размер поля в формате: [высота ширина]\n";
	Input* input = new Input;
	std::pair<int, int> sizes = input->inputSize();
	delete input;
	int height = sizes.first, width = sizes.second;
	this->player_field = new PlayingField{ height, width };
	this->bot_field = new PlayingField{ height, width };
	this->view = new FieldView;
	setManager();
	inputAnswer();
}

void GameOperation::inputAnswer() {
	std::cout << "Если хотите расставить корабли вручную, введите [1].\nЕсли хотите, чтобы корабли были расставлены автоматически, введите [0].\n";
	Input* input = new Input();
	int value = input->inputValue();
	delete input;

	srand(time(0));
	if (value == 1) {
		inputCoordinates();
	}
	else {
		randomCoordinates(true);
	}
	std::pair<int, int> sizes = player_field->getSize();
	view->printFieldIndex(sizes, player_field->getViewIndex());

	randomCoordinates(false);

	view->printFieldIndex(sizes, bot_field->getViewIndex());

	game();
}

void GameOperation::inputCoordinates() {
	std::vector <int> lenghts = player_manager->getLengths();
	int i = 0;
	while (i < lenghts.size()) {
		std::cout << "Введите координаты корабля размера " << lenghts[i] << " и его ориентацию на поле в формате: [y x orientation]\n";
		std::cout << "y и x - координаты левого верхнего угла коробля, orientation - его ориентация на поле, при этом 1 - горизонтально, 0 - вертикально.\n";
		int x, y, orient;
		std::pair <int, int> sizes = player_field->getSize();
		Input* input = new Input();
		std::vector <int> input_values = input->inputYXOrient(sizes.first, sizes.second);
		delete input;
		y = input_values[0];
		x = input_values[1];
		orient = input_values[2];
		bool orientation;
		if (orient == 1) {
			orientation = true;
		}
		else {
			orientation = false;
		}
		Warship* ship = player_manager->getWarship(i);

		bool check;
		try {
			check = player_field->setShip(ship, y, x, orientation, i + 1);
			if (check == false) {
				throw SetShipException();
			}
			player_manager->setOrientation(i, orientation);
			i++;
			view->printFieldIndex(sizes, player_field->getViewIndex());
		}
		catch (SetShipException& e) {
			std::cout << e.what() << '\n';
		}
	}
}

std::pair <int, int> GameOperation::getRandomCoordinates(std::pair <int, int> sizes) {
	std::pair <int, int> coordinates;
	coordinates.second = rand() % (sizes.second) + 1;
	coordinates.first = rand() % (sizes.first) + 1;
	return coordinates;
}

void GameOperation::randomCoordinates(bool flag) {
	std::vector <int> lenghts = player_manager->getLengths();
	int i = 0;
	std::pair <int, int> sizes;
	sizes = player_field->getSize();
	auto begin = std::chrono::steady_clock::now();

	while (i < lenghts.size()) {
		try {
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration<double>(end - begin);
			if (elapsed_ms.count() > 2) {
				throw RandomSetShipException();
			}
		}
		catch (RandomSetShipException& e) {
			if (flag == true) {
				delete player_field;
				delete player_manager;
				this->player_field = new PlayingField{ sizes.first, sizes.second };
				setManager(true, true);
			}
			else {
				delete bot_field;
				delete bot_manager;
				this->bot_field = new PlayingField{ sizes.first, sizes.second };
				setManager(true, false);
			}
			i = 0;
			begin = std::chrono::steady_clock::now();
		}
		int orient;
		orient = rand() % 2;
		std::pair <int, int> coordinates;
		coordinates = getRandomCoordinates(sizes);
		bool orientation;

		if (orient == 1) {
			orientation = true;
		}
		else {
			orientation = false;
		}

		if (flag == true) {
			bool check;
			check = pseudoRandom(coordinates.first, coordinates.second, orientation, i, flag);
			if (check == true) {
				player_manager->setOrientation(i, orientation);
				i++;
			}
		}
		else {
			bool check;
			check = pseudoRandom(coordinates.first, coordinates.second, orientation, i, flag);
			if (check == true) {
				bot_manager->setOrientation(i, orientation);
				i++;
			}
		}
	}

}

bool GameOperation::pseudoRandom(int y, int x, bool orientation, int number, bool flag) {
	std::pair <int, int> sizes;
	sizes = player_field->getSize();
	for (int i = y; i <= sizes.first; i++) {
		for (int j = x; j <= sizes.second; j++) {
			if (flag == true) {
				Warship* ship = player_manager->getWarship(number);
				bool check = player_field->setShip(ship, i, j, orientation, number + 1);
				if (check == true) {
					return true;
				}
			}
			else {
				Warship* ship = bot_manager->getWarship(number);

				bool check = bot_field->setShip(ship, i, j, orientation, number + 1);
				if (check == true) {
					return true;
				}
			}
		}
	}
	return false;
}

void GameOperation::setManager(bool is_hide, bool is_player) {
	std::vector <int> info;
	std::pair <int, int> sizes;
	sizes = player_field->getSize();
	info = countShip(sizes.first, sizes.second);
	int number = info[4];
	info.pop_back();
	std::vector <int> lenghts;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < info[i]; j++) {
			lenghts.push_back(4 - i);
		}
	}
	if (is_hide == false) {
		this->player_manager = new ShipManager{ number, lenghts };
		this->bot_manager = new ShipManager{ number, lenghts };
	}
	else if (is_player == true) {
		this->player_manager = new ShipManager{ number, lenghts };
	}
	else {
		this->bot_manager = new ShipManager{ number, lenghts };
	}
	this->ability_manager = new AbilityManager(bot_field, bot_manager);
	if (is_hide == false) {
		infoManager(number, info);
	}
}

void GameOperation::infoManager(int number, std::vector <int> lenghts) {
	std::cout << "В игре будет " << number << " кораблей.\n";
	for (int i = 0; i < 4; i++) {
		std::cout << lenghts[i] << " " << 4 - i << "-палубных кораблей;\n";
	}
	std::cout << "\n";
}

std::vector <int> GameOperation::countShip(int height, int width) {
	int area = height * width;
	int count = ceil(area * 0.2);
	std::vector <int> arr;
	int number;
	int first = 0, second = 0, third = 0, fourth = 0;
	if (area <= 100) {
		for (int f = 1; f < 5; f++) {
			for (int s = 0; s < ceil(count * 0.5 / 2); s++) {
				for (int t = 0; t < ceil(count * 0.45 / 3); t++) {
					for (int fr = 0; fr < ceil(count * 0.26 / 4); fr++) {
						if (f + s * 2 + t * 3 + fr * 4 == count) {
							if (fr <= t && t <= s && s <= f) {
								arr.push_back(fr);
								arr.push_back(t);
								arr.push_back(s);
								arr.push_back(f);
								number = fr + t + s + f;
							}
						}
					}
				}
			}
		}
	}
	else {
		for (int f = 1; f < ceil(count * 0.25); f++) {
			for (int s = 0; s < ceil(count * 0.4 / 2); s++) {
				for (int t = 0; t < ceil(count * 0.4 / 3); t++) {
					for (int fr = 0; fr < ceil(count * 0.31 / 4); fr++) {
						if (f + s * 2 + t * 3 + fr * 4 == count) {
							if (fr <= t && t <= s && s <= f) {
								arr.push_back(fr);
								arr.push_back(t);
								arr.push_back(s);
								arr.push_back(f);
								number = fr + t + s + f;
							}
						}
					}
				}
			}
		}
	}
	arr.push_back(number);
	return arr;
}

void GameOperation::game() {
	bool value = true;
	bool* flag = &value;
	while (value == true) {
		playerMove(flag);
		if (value == false) {
			std::cout << "Вы победили!\n";
			continue;
		}
		botMove(flag);
		if (value == false) {
			std::cout << "Вы проиграли..\nНовая игра\n";
			continue;
		}
	}

}

bool GameOperation::playerMove(bool* flag, bool first_action, bool is_double) {
	if (*flag == true) {
		showField();
		std::cout << "------------------------\n";
		std::cout << "Ваш ход!\n";
		int player_answer = 0;
		if (first_action == true) {
			std::cout << "Если хотите применить способность введите [1], в противном случае введите [0].\n";
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
			std::cout << "Укажите точку удара в формате [y x]\n";
			std::pair <int, int> sizes;
			sizes = player_field->getSize();
			Input* input = new Input;
			std::pair <int, int> coordinates = input->inputYX(sizes.first, sizes.second);
			delete input;
			int y = coordinates.first, x = coordinates.second;
			y--;
			x--;
			int check;
			check = bot_field->cellAtack(y, x);
			if (check != 0) {
				bool check_hit;
				if (is_double == true) {
					bot_field->cellAtack(y, x);
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

				bool check_win = bot_manager->checkWin();
				if (check_win == true) {
					*flag = false;
				}
			}
			else {
				std::cout << "Промах!\n";
			}
		}
		else {
			std::cout << "Активируется способность " << ability_manager->infoAbility() << '\n';
			bool is_double = ability_manager->useAbility(bot_field, bot_manager);
			if (is_double == true) {
				playerMove(flag, false, true);
				return true;
			}
			bool check_win = bot_manager->checkWin();
			if (check_win == true) {
				*flag = false;
			}
			playerMove(flag, false);
		}
	}
	return true;

}

void GameOperation::botMove(bool* flag) {
	if (*flag == true) {
		showField();
		std::cout << "------------------------\n";
		std::cout << "Ход соперника!\n";
		std::pair <int, int> coordinates;
		std::pair <int, int> sizes = player_field->getSize();
		coordinates = getRandomCoordinates(sizes);
		coordinates.second--;
		coordinates.first--;
		int check;
		check = player_field->cellAtack(coordinates.first, coordinates.second);
		if (check != 0) {
			hit(coordinates.first, coordinates.second, check - 1, false);

			bool check_win;
			check_win = player_manager->checkWin();
			if (check_win == true) {
				*flag = false;
			}
		}
		else {
			std::cout << "Промах!\n";
		}
	}
}

bool GameOperation::hit(int y, int x, int index, bool is_player, bool is_hide) {
	if (is_player == true) {
		int index_deck = bot_field->getDeckIndex(y, x);
		bool degree = bot_manager->checkDegree(index, index_deck);
		if (degree == true) {
			if (is_hide == false) { std::cout << "Попадание в уничтоженный сегмент корабля!\n"; }
			return false;
		}
		else {
			bot_manager->setDamage(index, index_deck);

			bool check = bot_manager->checkDestroyed(index);

			if (is_hide == false) { std::cout << "Попадание!\n"; }
			if (degree == false) {
				if (is_hide == false) { std::cout << "Сектор поврежден!\n"; }
			}
			else {
				if (is_hide == false) { std::cout << "Сектор уничтожен!\n"; }
				bot_field->killDeck(y, x);
			}

			if (check == true) {
				ability_manager->createAbility(bot_field, bot_manager);
				if (is_hide == false) { std::cout << "Корабль уничтожен!\n"; }
			}
		}
	}
	else {
		int index_deck = player_field->getDeckIndex(y, x);
		bool degree = player_manager->checkDegree(index, index_deck);
		if (degree == true) {
			std::cout << "Попадание в уничтоженный сегмент корабля!\n";
			return false;
		}
		else {
			player_manager->setDamage(index, index_deck);

			bool check = player_manager->checkDestroyed(index);

			std::cout << "Попадание!\n";
			if (degree == false) {
				std::cout << "Сектор поврежден!\n";
			}
			else {
				std::cout << "Сектор уничтожен!\n";
			}

			if (check == true) {
				std::cout << "Корабль уничтожен!\n";
				player_field->killDeck(y, x);
			}
		}
	}
	return true;
}

void GameOperation::showField() {
	std::cout << "Ваше поле:\n";
	std::pair<int, int> sizes = player_field->getSize();
	view->printField(sizes, player_field->getView());
	std::cout << "Поле соперника:\n";
	view->printField(sizes, bot_field->getView());
}


GameOperation::GameOperation() {
	std::cout << "Начало игры\n";
	inputSizes();
}

GameOperation::~GameOperation() {
	delete player_field;
	delete player_manager;
	delete bot_field;
	delete bot_manager;
	delete view;
	delete ability_manager;
}