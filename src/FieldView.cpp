#include "FieldView.h"

FieldView::FieldView() = default;

char FieldView::conditionToChar(PlayingField::Condition symbol) {
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

void FieldView::printField(std::pair<int, int> sizes, std::vector<std::vector<PlayingField::Condition>> field) {
	std::cout << std::setw(2) << "0" << "|";
	for (int j = 0; j < sizes.second; j++) {
		std::cout << std::setw(2) << j + 1 << " ";
	}
	std::cout << '\n' << "--|";
	for (int j = 0; j < sizes.second; j++) {
		std::cout << "---";
	}
	std::cout << '\n';
	for (int i = 0; i < sizes.first; i++) {
		std::cout << std::setw(2) << i + 1 << "|";
		for (int j = 0; j < sizes.second; j++) {
			std::cout << std::setw(2) << conditionToChar(field[i][j]) << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void FieldView::printFieldIndex(std::pair<int, int> sizes, std::vector<std::vector<std::pair<int, int>>> field) {
	std::cout << std::setw(2) << "0" << "|";
	for (int j = 0; j < sizes.second; j++) {
		std::cout << std::setw(2) << j + 1 << " ";
	}
	std::cout << '\n' << "--|";
	for (int j = 0; j < sizes.second; j++) {
		std::cout << "---";
	}
	std::cout << '\n';
	for (int i = 0; i < sizes.first; i++) {
		std::cout << std::setw(2) << i + 1 << "|";
		for (int j = 0; j < sizes.second; j++) {
			std::cout << std::setw(2) << field[i][j].first << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}