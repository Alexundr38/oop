#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../Exception/include/Exception.h"

typedef struct Answer {
	bool is_save = false;
	bool is_load = false;
	bool is_new = false;
	bool is_quit = false;
} Answer;

class InputManager {
private:
	std::istream& is;
public:
	InputManager(std::istream& is) : is(is) {};

	std::pair<int, int> inputSize();

	int inputValue();

	std::pair<int, int> inputXY(int width, int height);

	std::vector<int> inputXYOrient(int width, int height);

	Answer inputSaveAns();

	bool inputLoadAns();

	~InputManager() = default;
};

#endif