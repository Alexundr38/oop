#include "StartState.h"
#include "Game.h"

void StartState::doState() {
	Player* player = game->getPlayer();
	player->getOutputManager()->printMessage(" - Если хотите загрузить последнюю сохраненную игру, введите [y], иначе [n]\n");
	bool answer = player->getInputManager()->inputLoadAns();
	if (answer) {
		game->changeState(new LoadState(game), true);
		//switch LoadState
	}
	else {
		game->changeState(new CreateGameState(game), true);
		//switch CreateGameState
	}
}

StartState::StartState(Game* game) : game(game) {};