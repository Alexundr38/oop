#include "Input.h"

std::pair<int, int> Input::inputSize() {
	int first, second;
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> first >> second) || !ss.eof() || first <= 0 || first > 16 || second <= 0 || second > 16) {
				throw InputSizeException();
			}
			break;
		}
		catch (InputSizeException& e) {
			std::cout << e.what() << '\n';
		}

	}
	return std::make_pair(first, second);
}

int Input::inputValue() {
	std::string input;
	int value;
	while (true) {
		std::getline(std::cin, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> value) || !ss.eof() || (value != 1 && value != 0)) {
				throw InputValueException();
			}
			break;
		}
		catch (InputValueException& e) {
			std::cout << e.what() << '\n';
		}
	}
	return value;
}

std::pair<int, int> Input::inputYX(int height, int width) {
	int y, x;
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> y >> x) || !ss.eof() || y < 1 || x < 1 || y > height || x > width) {
				throw InputCoordinatesException();
			}
			break;
		}
		catch (InputCoordinatesException& e) {
			std::cout << e.what() << '\n';
		}
	}
	return std::make_pair(y, x);
}

std::vector<int> Input::inputYXOrient(int height, int width) {
	int y, x, orient;
	std::string input;
	while (true) {
		std::getline(std::cin, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> y >> x >> orient) || !ss.eof() || y < 1 || x < 1 ||
				y > height || x > width || (orient != 0 && orient != 1)) {
				throw InputCoordAndOrientException();
			}
			break;
		}
		catch (InputCoordAndOrientException& e) {
			std::cout << e.what() << '\n';
		}
	}

	std::vector <int> res = { y, x, orient };
	return res;
}