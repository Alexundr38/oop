#include "OutputManager.h"

void OutputManager::printMessage(std::string message) {
	os << message;
}

char OutputManager::conditionToChar(PlayingField::Condition symbol) {
	switch (symbol) {
	case PlayingField::unknown:
	case PlayingField::hide:
		return '*';
	case PlayingField::damaged:
		return 'x';
	case PlayingField::destroyed:
		return 'X';
	case PlayingField::empty:
		return '0';
	}
}

void OutputManager::printField(std::pair<int, int> sizes, std::vector<std::vector<PlayingField::Condition>> field) {
	std::ostringstream oss;
	oss << std::setw(2) << "0" << "|";
	for (int j = 0; j < sizes.first; j++) {
		oss << std::setw(2) << j + 1 << " ";
	}
	oss << '\n' << "--|";
	for (int j = 0; j < sizes.first; j++) {
		oss << "---";
	}
	oss << '\n';
	for (int i = 0; i < sizes.second; i++) {
		oss << std::setw(2) << i + 1 << "|";
		for (int j = 0; j < sizes.first; j++) {
			oss << std::setw(2) << conditionToChar(field[i][j]) << " ";
		}
		oss << '\n';
	}
	oss << '\n';
	printMessage(oss.str());
}

void OutputManager::printFieldIndex(std::pair<int, int> sizes, std::vector<std::vector<std::pair<int, int>>> field) {
	std::ostringstream oss;
	oss << std::setw(2) << "0" << "|";
	for (int j = 0; j < sizes.first; j++) {
		oss << std::setw(2) << j + 1 << " ";
	}
	oss << '\n' << "--|";
	for (int j = 0; j < sizes.first; j++) {
		oss << "---";
	}
	oss << '\n';
	for (int i = 0; i < sizes.second; i++) {
		oss << std::setw(2) << i + 1 << "|";
		for (int j = 0; j < sizes.first; j++) {
			oss << std::setw(2) << field[i][j].first << " ";
		}
		oss << '\n';
	}
	oss << '\n';
	printMessage(oss.str());
}

void OutputManager::showField(PlayingField* player_field, PlayingField* bot_field) {
	std::pair<int, int> sizes = bot_field->getSize();
	printMessage("Ваше поле:\n");
	printField(sizes, player_field->getView());
	printMessage("Поле соперника:\n");
	printField(sizes, bot_field->getView());
}