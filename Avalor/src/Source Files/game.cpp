#include "game.h"
#include "FileHandler.h"
#include <iostream>
#include <Windows.h>

extern bool running;

Game::Game() : m_avalor(nullptr) {}

void Game::play() 
{
	std::string option;

	std::cout << "========== AVALOR ==========\n";
	std::cout << "1. Start\n";
	std::cout << "2. Exit\n";

	std::cout << "Enter: ";
	std::cin >> option;

	if (option == "Start" || option == "start") 
	{
		system("cls");
		m_avalor->generateWorld();
		createCharMenu();
	}
	else if (option == "Exit" || option == "exit") {
		system("cls");
		running = false;
	}
}

void Game::prestart() 
{
	m_avalor = new World();
}

void Game::gameMenu() 
{

}

void Game::createCharMenu()
{
	FileHandler fh;
	uint32_t choice = 0;
	fh.readFile("create_toon_menu.txt");

	std::cout << "\nEnter option: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
	{
		std::string name;

		std::cout << "What would your name be? : ";
		std::cin >> name;

		running = false;
	}
	case 2:
	{
		system("cls");
		std::string select_class;

		std::cout << "Select a class: ";
		for (uint32_t i = 0; i < classes.size(); i++)
		{
			std::cout << classes.at(i) << ", ";
		}
		std::cout << std::endl;
		std::cin >> select_class;

		std::cout << "You chose " << select_class << "!\n";
		Sleep(3000);

		system("cls");
		createCharMenu();
	}

	default:
	{
		std::cout << "Invalid option!\n";
		system("cls");
		running = false;
	}
	}
}

void Game::cleanUp() 
{
	std::cout << "Cleaning...\n";

	delete m_avalor;
	
	std::cout << "Compelete. Exiting...";
	Sleep(4000);
}