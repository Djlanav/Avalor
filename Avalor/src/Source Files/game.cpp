#include "game.h"
#include "FileHandler.h"
#include <iostream>
#include <Windows.h>

// *** BEGIN EXTERN ***
extern bool running;
// *** END EXTERN ***

Game::Game() : avalor(nullptr),  player(nullptr) 
{
	classes = { "C_MAGE", "C_WARLOCK", "C_WARRIOR", "C_THIEF", "C_ARCHER" };
}

void Game::prestart() 
{
	avalor = new World();
}

void Game::createCharMenu()
{
	if (player == nullptr)
	{
		player = new Player();
	}

	FileHandler fh;
	uint32_t choice = 0;
	bool completed = false;

	while (completed != true)
	{
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
			system("cls");
			std::string name;

			std::cout << "What would your name be? : ";
			std::cin >> name;

			player->setterSetName(name);
			std::cout << "Your name is " << name << "\n";

			Sleep(2000);
			system("cls");
			break;
		}
		case 2:
		{
			setClassByInput();
			break;
		}
		case 3:
		{
			customClass();
			break;
		}

		case 4:
		{
			completed = true;
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

// method for setting the selected class
void Game::setClassByInput()
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

	selected_class = select_class;
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

void Game::setPlayerClass()
{
	std::string& select_class_ref = selected_class;
	for (size_t i = 0; i < classes.size(); i++)
	{
		if (classes.at(i) == select_class_ref)
		{
			player->setterSetClass(selected_class);
			break;
		}
	}
}


void Game::readClassFile()
{
	std::ifstream spells_list;

	spells_list.open(".\\src\\files\\spells_list.txt");

	if (!spells_list.is_open()) // if the file fails to open
	{
		std::ofstream spells_list_output(".\\src\\files\\spells_list.txt");

		spells_list_output << "C_MAGE:\nFireball\nIcebolt\nArcane Protection\n\n";
		spells_list_output << "C_WARLOCK:\nVoidbolt\nCorruption\nDemonic Protection\n\n";
		spells_list_output << "C_THIEF:\nSlic3\nStun\n\n";
		spells_list_output << "C_WARRIOR:\nBlade Stab\nSwift Barrage\nWarrior's Defense\n\n";
		spells_list_output << "C_ARCHER:\nShoot\nQuick Fire\n\n";

		spells_list_output.close();
	}

	std::string line;
	int id_counter = 1;
	
	while (std::getline(spells_list, line))
	{
		if (line == player->getClass())
		{
			std::string spell_to_insert;
			if (line.at(0) == 's' && line.at(1) == '_')
			{
				std::string spell_subtr = line.substr(line.size(), 2);
				player->getSpells().insert(std::make_pair(id_counter, spell_subtr));
				id_counter++;
			}
		}
	}
}

// Shows what the player can do
void Game::gameMenu()
{
	system("cls");
	FileHandler fh;

	std::cout << "========== " << player->getName() << "==========\n";
	fh.readFile(".\\\src\\files\\game_menu.txt");
	std::cout << "\n========================";

	Sleep(4000);
	running = false;
}

void Game::getGameMenuInput()
{
	int choice = -1;
	switch (choice)
	{
	case 1:
	{
		// TODO
	}

	case 2:
	{
		player->move();
	}

	}
}

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
		mainPlay();
	}
	else if (option == "Exit" || option == "exit") {
		system("cls");
		running = false;
	}
}

// Most of the actual gameplay code calling stuff goes here
void Game::mainPlay()
{
	createCharMenu();
	setPlayerClass();
	gameMenu();
}

void Game::cleanUp() 
{
	system("cls");
	std::cout << "Cleaning...\n";

	delete player;
	delete avalor;
	
	std::cout << "Compelete. Exiting...";
	Sleep(2000);
}