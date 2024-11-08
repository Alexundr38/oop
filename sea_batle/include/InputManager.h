#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Exception.h"

class InputManager {
private:
	std::istream& is;
public:
	InputManager(std::istream& is) : is(is) {};

	std::pair<int, int> inputSize();

	int inputValue();

	std::pair<int, int> inputXY(int width, int height);

	std::vector<int> inputXYOrient(int width, int height);

	bool inputSaveAns();

	~InputManager() = default;
};

#endif