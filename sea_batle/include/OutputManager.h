#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include <ostream>
#include <sstream>
#include "PlayingField.h"

class OutputManager {
private:
	std::ostream& os;
public:
	OutputManager(std::ostream& os) : os(os) {};

	void printMessage(std::string);

	char conditionToChar(PlayingField::Condition symbol);

	void printField(std::pair<int, int> sizes, std::vector<std::vector<PlayingField::Condition>> field);

	void printFieldIndex(std::pair<int, int> sizes, std::vector<std::vector<std::pair<int, int>>> field);

	void showField(PlayingField* player_field, PlayingField* bot_field);

	~OutputManager() = default;
};

#endif