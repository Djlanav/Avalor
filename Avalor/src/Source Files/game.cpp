#include "game.h"
#include "FileHandler.h"
#include <iostream>
#include <Windows.h>

// *** BEGIN EXTERN ***
extern bool running;
// *** END EXTERN ***

Game::Game() : avalor(nullptr),  player(nullptr) {}

// Setup stuff
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
		avalor->generateWorld();
		createCharMenu();
	}
	else if (option == "Exit" || option == "exit") {
		system("cls");
		running = false;
	}
}

void Game::prestart() 
{
	avalor = new World();
}

void Game::gameMenu() 
{

}

void Game::createCharMenu()
{
	FileHandler fh;
	uint32_t choice = 0;
	fh.readFile(".\\src\\files\\create_toon_menu.txt");

	std::cout << "\nEnter option: ";
	std::cin >> choice;

	// REMINDER: There are 4 choices
	// 1. Name
	// 2. Class
	// 3. Custom class
	// 4. Begin playing
	
	switch (choice)
	{
	case 1:
	{
		std::string name;

		std::cout << "What would your name be? : ";
		std::cin >> name;

		std::cout << "Your name is " << name << "\n";

		Sleep(3000);
		createCharMenu();
	}
	case 2:
	{
		setClass();
		break;
	}
	case 3:
	{
		customClass();
		break;
	}

	default:
	{
		std::cout << "Invalid option!\n";
		system("cls");
		running = false;
	}
	}
}

void Game::customClass()
{
	std::string custom_name;
	std::cout << "Provide your custom class with a unique name: ";
	std::cin >> custom_name;
	
	std::cout << "Now to set your custom class' attributes!\n";
	setCustomClassAttribs();

	classes.push_back(custom_name);
	std::cout << "You're all set!\n";
}

void Game::setClass()
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

	this->selected_class = select_class;

	createCharMenu();
}

void Game::setCustomClassAttribs()
{
	std::string nAttackPower;
	std::string nArcane;

	std::cout << "Set your class' attack power: ";
	std::cin >> nAttackPower;

	std::cout << "\n";

	std::cout << "Set your class' starting arcane: ";
	std::cin >> nArcane;

	std::cout << "\n";
}

std::string Game::checkPlayerClass(Player* player)
{
	for (size_t i = 0; i < classes.size(); i++)
	{
		if (classes.at(i) == selected_class)
		{
			player->setClass(classes.at(i));
		}
	}
}

// Most of the actual gameplay code calling stuff goes here
void Game::mainPlay()
{
	checkPlayerClass(player);
}

void Game::cleanUp() 
{
	std::cout << "Cleaning...\n";

	delete player;
	delete avalor;
	
	std::cout << "Compelete. Exiting...";
	Sleep(4000);
}