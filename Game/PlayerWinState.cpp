#include "PlayerWinState.h"
#include "Game.h"

void PlayerWinState::doState() {
	Player* player = game->getPlayer();
	OutputManager* output_manager = player->getOutputManager();
	std::pair<int, int> sizes = player->getField()->getSize();
	output_manager->printMessage("Вы победили!\n");
	CreatePlayer first = CreatePlayer(player, false, sizes.first, sizes.second);
	output_manager->printMessage("Новый раунд!\n");
	game->changeState(new PlayerMoveState(game));
}

PlayerWinState::PlayerWinState(Game* game) : game(game) {};