#include "GameOperation.h"

GameOperation::GameOperation() {
	input_manager = new InputManager(std::cin);
	output_manager = new OutputManager(std::cout);
	std::cout << "Начало игры\n";
	inputSizes();
}

void GameOperation::inputSizes() {
	std::cout << "Введите размер поля в формате: [ширина высота]\n";
	srand(time(0));
	std::pair<int, int> sizes = input_manager->inputSize();
	int width = sizes.first, height = sizes.second;
	createPlayer(true, width, height);
	createPlayer(false, width, height, true);
	inputAnswer();
}

void GameOperation::createPlayer(bool is_player, int width, int height, bool is_hide) {
	if (is_player == true) {
		this->bot = new Player(false, input_manager, output_manager);
		this->bot->setField(width, height);
		setManager(true, is_hide);
	}
	else {
		this->player = new Player(true, input_manager, output_manager);
		this->player->setField(width, height);
		setManager(false, is_hide);
	}
}

void GameOperation::inputAnswer(bool new_iteration) {
	output_manager->printMessage("Если хотите расставить корабли вручную, введите [1].\nЕсли хотите, чтобы корабли были расставлены автоматически, введите [0].\n");
	int value = input_manager->inputValue();

	if (value == 1) {
		inputCoordinates();
	}
	else {
		randomCoordinates(true);
	}
	/*std::pair<int, int> sizes = player_field->getSize();
	view->printFieldIndex(sizes, player_field->getViewIndex());
	*/
	if (new_iteration == false) {
		randomCoordinates(false);

		//view->printFieldIndex(sizes, bot_field->getViewIndex());
		std::pair<int, int> sizes = player->getField()->getSize();
		output_manager->printFieldIndex(sizes, bot->getField()->getViewIndex());
		output_manager->printFieldIndex(sizes, player->getField()->getViewIndex());

		game();
	}
}

void GameOperation::game() {
	while (true) {
		std::ostringstream oss;
		oss << "Раунд " << round_number << '\n';
		output_manager->printMessage(oss.str());
		round = new Round(player, bot);
		bool check = round->game();
		std::pair<int, int> sizes = player->getField()->getSize();
		if (check == true) {
			std::cout << player->getAbilityManager()->getNumber() << '\n';
			AbilityManager* old_ability_manager = new AbilityManager(std::move(*player->getAbilityManager()));
			delete player;

			createPlayer(false, sizes.first, sizes.second, true);
			randomCoordinates(false);
			player->setAbilityManager(old_ability_manager);
			std::cout << player->getAbilityManager()->getNumber() << '\n';
		}
		else {
			delete bot;
			createPlayer(true, sizes.first, sizes.second, true);
			inputAnswer(true);
		}
		round_number++;
	}
}

void GameOperation::inputCoordinates() {
	ShipManager* player_manager = bot->getShipManager();
	PlayingField* player_field = bot->getField();
	std::vector <int> lenghts = player_manager->getLengths();
	int i = 0;
	std::pair <int, int> sizes = player_field->getSize();
	while (i < lenghts.size()) {
		std::ostringstream oss;
		oss << "Введите координаты корабля размера " << lenghts[i] << " и его ориентацию на поле в формате: [y x orientation]\n";
		output_manager->printMessage(oss.str());
		output_manager->printMessage("y и x - координаты левого верхнего угла коробля, orientation - его ориентация на поле, при этом 1 - горизонтально, 0 - вертикально.\n");
		int x, y, orient;
		std::vector <int> input_values = input_manager->inputXYOrient(sizes.first, sizes.second);
		x = input_values[0];
		y = input_values[1];
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
			check = player_field->setShip(ship, x, y, orientation, i + 1);
			if (check == false) {
				throw SetShipException();
			}
			player_manager->setOrientation(i, orientation);
			i++;
			output_manager->printFieldIndex(sizes, player_field->getViewIndex());
		}
		catch (SetShipException& e) {
			std::ostringstream oss;
			oss << e.what() << '\n';
			output_manager->printMessage(oss.str());
		}
	}
}

/*std::pair <int, int> GameOperation::getRandomCoordinates(std::pair <int, int> sizes) {
	std::pair <int, int> coordinates;
	coordinates.second = rand() % (sizes.second) + 1;
	coordinates.first = rand() % (sizes.first) + 1;
	return coordinates;
}*/

void GameOperation::randomCoordinates(bool is_player) {
	PlayingField* field = bot->getField();
	ShipManager* ship_manager = bot->getShipManager();
	if (is_player == false) {
		field = player->getField();
		ship_manager = player->getShipManager();
	}
	std::vector <int> lenghts = ship_manager->getLengths();
	int i = 0;
	auto begin = std::chrono::steady_clock::now();
	std::pair<int, int> sizes = field->getSize();
	while (i < lenghts.size()) {
		try {
			auto end = std::chrono::steady_clock::now();
			auto elapsed_ms = std::chrono::duration<double>(end - begin);
			if (elapsed_ms.count() > 2) {
				throw RandomSetShipException();
			}
		}
		catch (RandomSetShipException& e) {
			if (is_player == true) {
				delete bot;
				createPlayer(true, sizes.first, sizes.second, true);
			}
			else {
				delete player;
				createPlayer(false, sizes.first, sizes.second, true);
			}
			i = 0;
			begin = std::chrono::steady_clock::now();
		}
		int orient;
		orient = rand() % 2;
		RandomValues* random_values = new RandomValues;
		std::pair <int, int> coordinates = random_values->getRandomCoordinates(sizes);
		delete random_values;
		bool orientation;

		if (orient == 1) {
			orientation = true;
		}
		else {
			orientation = false;
		}

		bool check;
		check = pseudoRandom(coordinates.first, coordinates.second, orientation, i, is_player);
		if (check == true) {
			ship_manager->setOrientation(i, orientation);
			i++;
			//std::pair<int, int> sizes = field->getSize();
			//view->printFieldIndex(sizes, field->getViewIndex());
		}
	}
}


bool GameOperation::pseudoRandom(int x, int y, bool orientation, int number, bool is_player) {
	PlayingField* field = bot->getField();
	ShipManager* ship_manager = bot->getShipManager();
	if (is_player == false) {
		field = player->getField();
		ship_manager = player->getShipManager();
	}
	std::pair <int, int> sizes = field->getSize();
	for (int i = x; i <= sizes.first; i++) {
		for (int j = y; j <= sizes.second; j++) {
			Warship* ship = ship_manager->getWarship(number);
			bool check = field->setShip(ship, i, j, orientation, number + 1);
			if (check == true) {
				return true;
			}
		}
	}
	return false;
}

void GameOperation::setManager(bool is_player, bool is_hide) {
	std::pair<int, int> sizes = bot->getField()->getSize();
	std::vector <int> info;
	info = countShip(sizes.first, sizes.second);
	if (is_player == true) {
		bot->setShipManager(info);
	}
	else {
		player->setShipManager(info);
		player->setAbilityManager();
	}
	int number = info[4];
	info.pop_back();
	if (is_hide == false) {
		infoManager(number, info);
	}
}

/*void GameOperation::setManager(bool is_hide, bool is_player) {
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
*/
void GameOperation::infoManager(int number, std::vector <int> lenghts) {
	std::ostringstream oss;
	oss << "В игре будет " << number << " кораблей.\n";
	output_manager->printMessage(oss.str());
	for (int i = 0; i < 4; i++) {
		oss.str("");
		oss.clear();
		oss << lenghts[i] << " " << 4 - i << "-палубных кораблей;\n";
		output_manager->printMessage(oss.str());
	}
}

std::vector <int> GameOperation::countShip(int width, int height) {
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

/*void GameOperation::game() {
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
}*/


GameOperation::~GameOperation() {
	delete player;
	delete bot;
	delete round;
}