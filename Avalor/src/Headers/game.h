#pragma once

#include "world.h"
#include "player.h"
#include <vector>

class Game {
public:
	World* avalor;
	Player* player;

	std::vector<std::string> classes = { "mage", "warlock", "warrior", "thief", "archer" };

private:
	std::string selected_class;

private:
	void setCustomClassAttribs();
	void setClass();

public:
	Game();

	void play();
	void mainPlay();

	void gameMenu();

	void createCharMenu();
	void customClass();

	std::string checkPlayerClass(Player* player);

	void prestart();
	void cleanUp();
};