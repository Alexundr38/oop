#include "PlayerWinState.h"
#include "Game.h"

void PlayerWinState::doState() {
	Player* player = game->getPlayer();

	OutputManager<Output>* output_manager = player->getOutputManager();
	std::pair<int, int> sizes = player->getField()->getSize();
	output_manager->printMessage("Âû ïîáåäèëè!\n");
	CreatePlayer first = CreatePlayer(player, false, sizes.first, sizes.second);
	output_manager->printMessage("Íîâûé ðàóíä!\n");
	game->changeNextState(new PlayerUseAbilityState(game));
}

PlayerWinState::PlayerWinState(Game* game) : game(game) {};