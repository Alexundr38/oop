#ifndef PLAYERWINSTATE_H
#define PLAYERWINSTATE_H

#include "GameState.h"
#include "CreatePlayer.h"
#include "PlayerMoveState.h"

class PlayerWinState : public GameState {
	Game* game;

public:

	PlayerWinState(Game* game);

	void doState() override;
};

#endif