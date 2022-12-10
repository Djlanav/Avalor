#include <iostream>
#include "game.h"

bool running = true;

int main()
{
	Game game;
	game.prestart();

	while (running) {
		game.play();
	}
	
	game.cleanUp();
}