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

void OutputManager::printFieldTwo(std::pair<int, int> sizes, std::vector<std::vector<PlayingField::Condition>> player_field, std::vector<std::vector<PlayingField::Condition>> bot_field) {
	std::ostringstream oss;
	oss << std::setw(std::max((sizes.first + 1) * 3, 9)) << "Ваше поле" << "    " << std::setw(std::max((sizes.first + 1) * 3, 15)) << "Поле соперника" << '\n';
	oss << std::setw(2) << "0" << "|";
	for (int j = 0; j < sizes.first; j++) {
		oss << std::setw(2) << j + 1 << " ";
	}
	oss << "    ";
	oss << std::setw(2) << "0" << "|";
	for (int j = 0; j < sizes.first; j++) {
		oss << std::setw(2) << j + 1 << " ";
	}

	oss << '\n' << "--|";
	for (int j = 0; j < sizes.first; j++) {
		oss << "---";
	}
	oss << "    " << "--|";
	for (int j = 0; j < sizes.first; j++) {
		oss << "---";
	}
	oss << '\n';

	for (int i = 0; i < sizes.second; i++) {
		oss << std::setw(2) << i + 1 << "|";
		for (int j = 0; j < sizes.first; j++) {
			oss << std::setw(2) << conditionToChar(player_field[i][j]) << " ";
		}
		oss << "    " << std::setw(2) << i + 1 << "|";
		for (int j = 0; j < sizes.first; j++) {
			oss << std::setw(2) << conditionToChar(bot_field[i][j]) << " ";
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
	printFieldTwo(sizes, bot_field->getView(), player_field->getView());
	/*printMessage("Ваше поле:\n");
	printField(sizes, bot_field->getView());
	printMessage("Поле соперника:\n");
	printField(sizes, player_field->getView());*/
}