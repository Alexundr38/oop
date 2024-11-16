#include "BotWinState.h"
#include "Game.h"

void BotWinState::doState() {
	game->getPlayer()->getOutputManager()->printMessage("�� ���������..\n����� ����\n");
	
	game->changeState(new StartState(game), true);
	//switch StartState
}

BotWinState::BotWinState(Game* game) : game(game) {};