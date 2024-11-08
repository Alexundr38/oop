#include "InputManager.h"

std::pair<int, int> InputManager::inputSize() {
	int first, second;
	std::string input;
	while (true) {
		std::getline(is, input);
		std::stringstream ss(input);
		std::cout << input << '\n';
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

int InputManager::inputValue() {
	std::string input;
	int value;
	while (true) {
		std::getline(is, input);
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

std::pair<int, int> InputManager::inputXY(int width, int height) {
	int y, x;
	std::string input;
	while (true) {
		std::getline(is, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> x >> y) || !ss.eof() || y < 1 || x < 1 || y > height || x > width) {
				throw InputCoordinatesException();
			}
			break;
		}
		catch (InputCoordinatesException& e) {
			std::cout << e.what() << '\n';
		}
	}
	return std::make_pair(x, y);
}

std::vector<int> InputManager::inputXYOrient(int width, int height) {
	int x, y, orient;
	std::string input;
	while (true) {
		std::getline(is, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> x >> y >> orient) || !ss.eof() || y < 1 || x < 1 ||
				y > height || x > width || (orient != 0 && orient != 1)) {
				throw InputCoordAndOrientException();
			}
			break;
		}
		catch (InputCoordAndOrientException& e) {
			std::cout << e.what() << '\n';
		}
	}

	std::vector <int> res = { x, y, orient };
	return res;
}

bool InputManager::inputSaveAns() {
	char ans;
	std::string input;
	while (true) {
		std::getline(is, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> ans) || input.size() != 1 || (ans != 'y' && ans != 'n')) {
				throw InputSaveAnsException();
			}
			break;
		}
		catch (InputSaveAnsException& e){
			std::cout << e.what() << '\n';
		}
	}
	if (ans == 'y') {
		return true;
	}
	else {
		return false;
	}
}