#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include "PlayingField.h"

class FieldView {
public:

	FieldView();
	
	char conditionToChar(PlayingField::Condition symbol);

	void printField(std::pair<int, int> sizes, std::vector<std::vector<PlayingField::Condition>> field);

	void printFieldIndex(std::pair<int, int> sizes, std::vector<std::vector<std::pair<int, int>>> field);

};

#endif