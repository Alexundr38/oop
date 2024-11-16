#include "SaveState.h"
#include "Game.h"

void SaveState::doState() {
	std::ofstream output_file("Game.json");
	output_file << game;
	output_file.close();
	//сохранение
}

SaveState::SaveState(Game* game) : game(game) {};