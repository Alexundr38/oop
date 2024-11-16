#ifndef PLAYERMOVESTATE_H
#define PLAYERMOVESTATE_H

#include "GameState.h"
#include "PlayerWinState.h"
#include "BotMoveState.h"

class PlayerMoveState : public GameState {
	Game* game;

public:

	PlayerMoveState(Game* game);

	void doState() override;
};

#endif