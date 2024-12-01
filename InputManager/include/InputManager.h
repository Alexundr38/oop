#ifndef INPUT_H
#define INPUT_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../Exception/include/Exception.h"
#include "../OutputManager/include/Output.h"
#include "../include/json.hpp"
using json = nlohmann::json;

enum Commands {
	CREATE_GAME,
	SAVE_GAME,
	LOAD_GAME,
	NEXT_STATE,
	QUIT,
	ATTACK,
	USE_ABILITY,
	HELP
};

class InputManager {
private:
	std::istream& is;

	Commands stringToCommand(std::string str);
public:
	InputManager(std::istream& is) : is(is) {};

	std::pair<int, int> inputSize();

	int inputValue();

	std::pair<int, int> inputXY(int width, int height);

	std::vector<int> inputXYOrient(int width, int height);

	~InputManager() = default;

	Commands inputCommand();
};

#endif