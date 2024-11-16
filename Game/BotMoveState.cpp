#include "BotMoveState.h"
#include "Game.h"

void BotMoveState::doState() {
	Player* player = game->getPlayer();
	Player* bot = game->getPlayer(false);
	std::pair<bool,bool> value = bot->playerMove();
	OutputManager* output_manager = player->getOutputManager();
	output_manager->showField(player->getField(), bot->getField());

	if (value.second == true) {
		game->changeState(new BotWinState(game), true);
		//return true;   switch BotWinState
	}
	else {
		game->changeState(new PlayerMoveState(game));
	}
}

BotMoveState::BotMoveState(Game* game) : game(game) {};