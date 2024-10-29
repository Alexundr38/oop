#ifndef SCANER_H
#define SCANER_H

#include "Ability.h"
#include "Input.h"

class Scaner : public Ability {
private:
	int x;
	int y;
	PlayingField* field;

public:
	Scaner(PlayingField* fieldr);

	std::string printInfo() override;

	std::pair<bool,bool> useAbility() override;

	~Scaner() = default;
};

#endif