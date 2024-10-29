#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Exception.h"

class Input {
public:
	Input() = default;

	std::pair<int, int> inputSize();

	int inputValue();

	std::pair<int, int> inputYX(int height, int width);

	std::vector<int> inputYXOrient(int height, int width);

	~Input() = default;
};

#endif