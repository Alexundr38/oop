#include "InputManager.h"

std::pair<int, int> InputManager::inputSize() {
	int first, second;
	std::string input;
	while (true) {
		std::getline(is, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> first >> second) || !ss.eof() || first <= 0 || first > 10 || second <= 0 || second > 10) {
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

Answer InputManager::inputSaveAns() {
	char ans;
	Answer answer;
	std::string input;
	while (true) {
		std::getline(is, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> ans) || input.size() != 1 || (ans != 's' && ans != 'l' && ans != 'g' && ans != 'q' && ans != 'n')) {
				throw InputSaveAnsException();
			}
			break;
		}
		catch (InputSaveAnsException& e){
			std::cout << e.what() << '\n';
		}
	}
	if (ans == 's') answer.is_save = true;
	if (ans == 'l') answer.is_load = true;
	if (ans == 'g') answer.is_new = true;
	if (ans == 'q') answer.is_quit = true;
	return answer;
}

bool InputManager::inputLoadAns() {
	char ans;
	std::string input;
	while (true) {
		std::getline(is, input);
		std::stringstream ss(input);
		try {
			if (!(ss >> ans) || input.size() != 1 || (ans != 'y' && ans != 'n')) {
				throw InputLoadException();
			}
			break;
		}
		catch (InputLoadException& e) {
			std::cout << e.what() << '\n';
		}
	}
	if (ans == 'y') {
		return true;
	}
	return false;
}