#include "Warship.h"

Warship::Warship(int length) {
	this->length = length;
	damage_ship.resize(length);
	for (int i = 0; i < length; i++) {
		damage_ship[i] = whole;
	}
}

Warship::Warship() = default;

void Warship::causeDamage(int index_deck) {
	switch (damage_ship[index_deck]) {
	case whole:
		damage_ship[index_deck] = damaged;
		break;
	case damaged:
		damage_ship[index_deck] = destroyed;
		break;
	}
}

void Warship::setOrientation(bool orientation) {
	this->orientation = orientation;
}

bool Warship::getOrientation() {
	return orientation;
}

bool Warship::isDestroyed() {
	for (int i = 0; i < length; i++) {
		if (damage_ship[i] != destroyed) {
			return false;
		}
	}
	return true;
}

int Warship::shipLength() {
	return length;
}

Warship::Damage Warship::getDegree(int index_deck) {
	return damage_ship[index_deck];
}

Warship::~Warship() {
	damage_ship.clear();
}