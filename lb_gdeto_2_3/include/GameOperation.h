#ifndef GAMEOPERATION_H
#define GAMEOPERATION_H

#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono>
#include "PlayingField.h"
#include "ShipManager.h"
#include "FieldView.h"
#include "AbilityManager.h"
#include "Exception.h"
#include "Input.h"

class GameOperation {
private:

	ShipManager* player_manager;
	PlayingField* player_field;
	ShipManager* bot_manager;
	PlayingField* bot_field;
	FieldView* view;
	AbilityManager* ability_manager;
	int round_number = 1;

	void inputSizes();

	void inputAnswer();

	void inputCoordinates();

	std::pair <int, int> getRandomCoordinates(std::pair <int, int> sizes);

	void randomCoordinates(bool flag);

	bool pseudoRandom(int y, int x, bool orientation, int number, bool flag);

	void setManager(bool is_hide = false, bool is_player = true);

	void infoManager(int number, std::vector <int> lengths);

	std::vector <int> countShip(int height, int width);

	void game();

	bool playerMove(bool* flag, bool first_action = true, bool is_double = false);

	void botMove(bool* flag);

	bool hit(int y, int x, int index, bool is_player, bool is_hide = false);

	void showField();

public:
	GameOperation();

	~GameOperation();
};

#endif