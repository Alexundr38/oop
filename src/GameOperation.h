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

class GameOperation {
private:

	ShipManager* player_manager;
	PlayingField* player_field;
	ShipManager* bot_manager;
	PlayingField* bot_field;
	FieldView* view;
	AbilityManager* ability_manager;

	std::pair<int, int> inputSize();

	int inputValue();

	std::pair<int, int> inputYX(int height, int width);

	std::vector<int> inputYXOrient(int height, int width);

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

	bool playerMove(bool* flag);

	void botMove(bool* flag);

	void hit(int y, int x, int index, bool flag);

	void showField();

public:
	GameOperation();

	~GameOperation();
};

#endif