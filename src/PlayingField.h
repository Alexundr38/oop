#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include "Warship.h"


class PlayingField {
public:
	enum Condition {
		unknown,
		hide,
		damaged,
		destroyed,
		empty
	};

private:
	std::vector <std::vector <Condition>> field_view;
	std::vector <std::vector <std::pair<int, int>>> field_value;
	int height;
	int width;

	void createField();

	bool checkNeighbors(int length, int y, int x, bool orientation);

	bool checkCorrect(int length, int y, int x, bool orientation);

public:
	PlayingField(int height, int width);

	PlayingField();

	PlayingField(const PlayingField& other);

	PlayingField(PlayingField&& other) noexcept;

	PlayingField& operator=(const PlayingField& other);

	PlayingField& operator=(PlayingField&& other) noexcept;

	std::pair <int, int> getSize();

	bool setShip(Warship* ship, int y, int x, bool orientation, int value);

	int cellAtack(int y, int x, bool is_hide = false);

	void killDeck(int y, int x);

	int getDeckIndex(int y, int x);

	std::vector<std::vector<Condition>> getView();

	std::vector<std::vector<std::pair<int, int>>> getViewIndex();

};

#endif