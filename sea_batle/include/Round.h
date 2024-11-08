#ifndef ROUND_H
#define ROUND_H

#include "Player.h"

class Round {
private:
	Player* player;
	Player* bot;
public:
	Round(Player* player, Player* bot) :player(player), bot(bot) {};

	bool game();

	~Round() = default;

};

#endif