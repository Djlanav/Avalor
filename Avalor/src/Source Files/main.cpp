#include <iostream>
#include "game.h"

bool running = true;
Game game;

int main()
{
	game.prestart();

	while (running) {
		game.play();
	}
	
	game.cleanUp();
}