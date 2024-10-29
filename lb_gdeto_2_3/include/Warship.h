#ifndef WARSHIP_H
#define WARSHIP_H

#include <iostream>
#include <vector>

class Warship {
public:
	enum Damage {
		whole,
		damaged,
		destroyed
	};

private:

	std::vector <Damage> damage_ship;

	bool orientation; // True == horizontal; False == vertical

	int length;

public:

	Warship(int length);

	Warship();

	void causeDamage(int index_deck);

	void setOrientation(bool orientation);

	bool getOrientation();

	bool isDestroyed();

	Damage getDegree(int index_deck);

	int shipLength();

	~Warship();
};

#endif