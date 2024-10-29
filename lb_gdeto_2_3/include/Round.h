#ifndef ROUND_H
#define ROUND_H

#include "Player.h"

class Round {
private:
	Player* player;
	Player* bot;

	Round(Player* player, Player* bot);

	void game();

	bool playerMove(bool* flag, bool first_action = true, bool is_double = false);

	void botMove(bool* flag);

	bool hit(int y, int x, int index, bool is_player, bool is_hide = false);

	~Round();
};

#endif