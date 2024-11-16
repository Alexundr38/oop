#include "Game.h"


Game::Game() {
	input_manager = new InputManager(std::cin);
	output_manager = new OutputManager(std::cout);
	player = new Player(true, input_manager, output_manager);
	bot = new Player(false, input_manager, output_manager);
	current_state = new StartState(this);
	doState();
}

void Game::doState() {
	current_state->doState();
}

Player* Game::getPlayer(bool is_player) {
	if (is_player) {
		return player;
	}
	else {
		return bot;
	}
}

void Game::changeState(GameState* new_state, bool is_hide) {
	delete current_state;
	current_state = new_state;
	if (!is_hide) {
		output_manager->printMessage(" - Если хотите сохранить текущую игру, нажмите [s]\n - Если хотите загрузить последнюю сохраненнную игру, нажмите [l]\n - Если хотите начать новую игру, нажмите [g]\n - Если хотите выйти из игры, нажмите [q]\n - Иначе нажмите [n]\n");
		Answer answer = input_manager->inputSaveAns();
		if (answer.is_save) {
			GameState* save = new SaveState(this);
			save->doState();
			delete save;
			//сохранение
		}
		if (answer.is_load) {
			GameState* load = new LoadState(this);
			load->doState();
			delete load;
			//загрузка
		}
		if (answer.is_new) {
			changeState(new CreateGameState(this), true);
		}
		if (answer.is_quit) {
			exit(0);
		}
	}
	doState();
	//вопрос про загрузку
}

json Game::to_json() const {
	json j;
	j["player"] = player->to_json();
	j["bot"] = bot->to_json();
	j["current_state"] = std::string(typeid(*current_state).name());
	return j;
}

void Game::from_json(const json& j) {
	player->from_json(j.at("player"));
	bot->from_json(j.at("bot"));
	stringToState(j.at("current_state"));
}

void Game::stringToState(std::string str) {
	if (str == "class CreateGameState") changeState(new CreateGameState(this));
	if (str == "class BotMoveState") changeState(new BotMoveState(this));
	if (str == "class BotWinState") changeState(new BotWinState(this));
	if (str == "class PlayerMoveState") changeState(new PlayerMoveState(this));
	if (str == "class PlayerWinState") changeState(new PlayerWinState(this));
}

std::ofstream& operator<<(std::ofstream& out, Game* game) {
	json j = game->to_json();
	out << j.dump();
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Game* game) {
	std::string json_str;
	std::getline(in, json_str);
	json j = json::parse(json_str);
	game->from_json(j);
	return in;
}

Game::~Game() {
	delete player;
	delete bot;
	delete current_state;
	delete input_manager;
	delete output_manager;
}