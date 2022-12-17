#pragma once

#include "world.h"
#include "player.h"
#include <vector>

class Game {
public:
	World* avalor;
	Player* player;

	std::vector<std::string> classes;

private:
	std::string selected_class;

private:
	void setCustomClassAttribs();
	void setClassByInput();
	void getGameMenuInput();

public:
	Game();

	void play();
	void mainPlay();

	void gameMenu();

	void createCharMenu();
	void customClass();
	void readClassFile();

	void setPlayerClass();

	void prestart();
	void cleanUp();
};