#include "PlayingField.h"

void PlayingField::createField() {
	field_view.resize(height, std::vector <Condition>(width, Condition::unknown));
	field_value.resize(height, std::vector <std::pair<int,int>>(width, std::make_pair(0,-1)));
}

bool PlayingField::checkNeighbors(int length, int y, int x, bool orientation) {
	if (orientation == true) {
		for (int i = std::max(0, y - 1); i < std::min(y + 2, height); i++) {
			for (int j = std::max(0, x - 1); j - x <= int(length) && j < width; j++) {
				if (field_value[i][j].first != 0) {
					return false;
				}
			}
		}
	}
	else {
		for (int i = std::max(0, y - 1); i - y <= int(length) && i < height; i++) {
			for (int j = std::max(0, x - 1); j < std::min(x + 2, width); j++) {
				if (field_value[i][j].first != 0) {
					return false;
				}
			}
		}
	}
	return true;
}

bool PlayingField::checkCorrect(int length, int y, int x, bool orientation) {
	if (x < 0 || y < 0 || x > width || y > height) {
		return false;
	}
	int count = 0;
	if (orientation == true) {
		for (int j = x; j < x + length && j < width; j++) {
			count++;
		}
	}
	else {
		for (int i = y; i < y + length && i < height; i++) {
			count++;
		}
	}
	if (count != length) {
		return false;
	}
	return true;
}

PlayingField::PlayingField(int height, int width) {
	this->height = height;
	this->width = width;
	createField();
}

PlayingField::PlayingField() = default;

PlayingField::PlayingField(const PlayingField& other) : //копирование
	field_value(other.field_value), field_view(other.field_view),
	height(other.height), width(other.width) {}

PlayingField::PlayingField(PlayingField&& other) noexcept : //перемещение	
	field_value(std::move(other.field_value)), field_view(std::move(other.field_view)),
	height(other.height), width(other.width) {
	other.height = 0;
	other.width = 0;
}

PlayingField& PlayingField::operator=(const PlayingField& other) {
	if (this != &other) {
		field_view = other.field_view;
		field_value = other.field_value;
		height = other.height;
		width = other.width;
	}
	return *this;
}

PlayingField& PlayingField::operator=(PlayingField&& other) noexcept {
	if (this != &other) {
		field_value = std::move(other.field_value);
		field_view = std::move(other.field_view);
		height = other.height;
		width = other.width;

		other.height = 0;
		other.width = 0;
	}
	return *this;
}

std::pair <int, int> PlayingField::getSize() {
	std::pair <int, int> sizes(height, width);
	return sizes;
}

bool PlayingField::setShip(Warship* ship, int y, int x, bool orientation, int value) {
	x--;
	y--;
	int length = ship->shipLength();																		//заменить flag на нормальную обработку
	if (checkCorrect(length, y, x, orientation) == false) {																				//error
		return false;
	}
	if (checkNeighbors(length, y, x, orientation) == false) {																				//error
		return false;
	}

	if (orientation == true) {
		for (int j = x; j < x + length; j++) {
			field_value[y][j].first = value;
			field_value[y][j].second = j - x;
		}
	}
	else {
		for (int i = y; i < y + length; i++) {
			field_value[i][x].first = value;
			field_value[i][x].second = i - y;
		}
	}
	return true;
}

int PlayingField::cellAtack(int y, int x, bool is_hide) {
	if (field_value[y][x].first == 0) {
		field_view[y][x] = empty;
		return 0;
	}
	else {
		switch(field_view[y][x]) {
		case unknown:
			if (is_hide == true) {
				field_view[y][x] = hide;
			}
			else {
				field_view[y][x] = damaged;
			}
			break;
		case damaged:
		case hide:
			field_view[y][x] = destroyed;
			break;
		default:
			break;
		}
		return field_value[y][x].first;
	}
}

void PlayingField::killDeck(int y, int x) {
	field_value[y][x].second = -1;
}

int PlayingField::getDeckIndex(int y, int x) {
	return field_value[y][x].second;
}

std::vector<std::vector<PlayingField::Condition>> PlayingField::getView() {
	return this->field_view;
}

std::vector<std::vector<std::pair<int, int>>> PlayingField::getViewIndex() {
	return this->field_value;
}