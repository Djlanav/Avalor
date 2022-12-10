#pragma once

#include "world.h"
#include <array>

class Game {
public:
	World* m_avalor;
	std::array<std::string, 5> classes = { "mage", "warlock", "warrior", "thief", "archer" };

public:
	Game();

	void play();

	void gameMenu();
	void createCharMenu();

	void prestart();
	void cleanUp();
};