#ifndef BOTMOVESTATE_H
#define BOTMOVESTATE_H

#include "GameState.h"
#include "BotWinState.h"
#include "PlayerMoveState.h"


class BotMoveState : public GameState {
	Game* game;

public:

	BotMoveState(Game* game);

	void doState() override;
};

#endif