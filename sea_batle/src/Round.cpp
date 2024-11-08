#include "Round.h"

bool Round::game() {
	std::pair<bool, bool> value = { false, true };
	OutputManager* output_manager = player->getOutputManager();
	PlayingField* player_field = bot->getField();
	PlayingField* bot_field = player->getField();
	InputManager* input_manager = player->getInputManager();
	while (value.first == false) {
		output_manager->printMessage("Если хотите сохранить игру, введите [y], иначе введите [n]\n");
		bool val = input_manager->inputSaveAns();
		value = player->playerMove();
		output_manager->showField(player_field, bot_field);
		if (value.first == true) {
			output_manager->printMessage("Вы победили!\n");
			return true;
		}
		if (value.second == true) {
			value = player->playerMove(false);
			output_manager->showField(player_field, bot_field);
			if (value.first == true) {
				output_manager->printMessage("Вы победили!\n");
				return true;
			}
		}
		value = bot->playerMove();
		output_manager->showField(player_field, bot_field);
		if (value.first == true) {
			output_manager->printMessage("Вы проиграли..\n");
			return false;
		}
	}
}
