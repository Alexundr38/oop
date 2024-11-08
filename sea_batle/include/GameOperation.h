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
#include "Player.h"
#include "Round.h"
#include "PlayingField.h"
#include "ShipManager.h"
#include "AbilityManager.h"
#include "Exception.h"
#include "InputManager.h"
#include "OutputManager.h"

class GameOperation {
private:

	Player* player;
	Player* bot;
	Round* round;
	InputManager* input_manager;
	OutputManager* output_manager;
	int round_number = 1;

	void inputSizes();

	void createPlayer(bool is_player, int width, int height, bool is_hide = false);

	void inputAnswer(bool new_iteration = false);

	void inputCoordinates();

	void game();

	std::pair <int, int> getRandomCoordinates(std::pair <int, int> sizes);

	void randomCoordinates(bool is_player);

	bool pseudoRandom(int x, int y, bool orientation, int number, bool is_player);

	//void setManager(bool is_hide = false, bool is_player = true);
	void setManager(bool is_player, bool is_hide = false);

	void infoManager(int number, std::vector <int> lengths);

	std::vector <int> countShip(int width, int height);

	//bool playerMove(bool* flag, bool first_action = true, bool is_double = false);

	//void botMove(bool* flag);

	//bool hit(int x, int y, int index, bool is_player, bool is_hide = false);

public:
	GameOperation();

	~GameOperation();
};

#endif