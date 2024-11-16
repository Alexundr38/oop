#include "PlayerMoveState.h"
#include "Game.h"

void PlayerMoveState::doState() {
	Player* player = game->getPlayer();
	Player* bot = game->getPlayer(false);
	std::pair<bool, bool> value = player->playerMove();
	OutputManager* output_manager = player->getOutputManager();
	output_manager->showField(player->getField(), bot->getField());

	if (value.second == true) {
		game->changeState(new PlayerWinState(game), true);
		//return true;   switch PlayerWinState
	}

	if (value.first == true) {
		value = player->playerMove(false);
		output_manager->showField(player->getField(), bot->getField());

		if (value.second == true) {
			game->changeState(new PlayerWinState(game), true);
			//return true;		switch PlayerWinState
		}
		else {
			game->changeState(new BotMoveState(game));
		}
	}
	else {
		game->changeState(new BotMoveState(game));
	}
}

PlayerMoveState::PlayerMoveState(Game* game) : game(game) {};