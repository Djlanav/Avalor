#include "game.h"
#include "player.h"

#include <random>
#include <iostream>

extern Game game; // pointer to the main game object/instance

Player::Player() 
	: name("Default"), attack_power(1), arcane(1), armor(1), current_weapon(0)
{
	// Default attacks
	this->attacks = {{1, "Punch"},
					 {2, "Stab"},
					 {3, "Kick"}};
}

// This method is for physical attacks such as with a weapon
int Player::attack()
{
	int damageDealt = null;

	std::string selectedAttack;
	std::cout << "Choose an attack to use: ";
	std::cin >> selectedAttack;

	if (selectedAttack == attacks.at(1))
	{
		std::cout << "You used " << attacks.at(1) << "!";
		damageDealt += 1;
	}
	else if (selectedAttack == attacks.at(2))
	{
		std::cout << "You used " << attacks.at(2) << "!";
		damageDealt += rand() % 7;
	}
	else if (selectedAttack == attacks.at(3)) {
		std::cout << "You used " << attacks.at(3) << "!";
		damageDealt = 5;
	}

	return damageDealt;
}

void Player::selectSpell()
{
	size_t size = spells.size();
	std::string spell;

	std::cout << "Cast a spell (";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << spells.at(i) << ", ";
	}
	std::cout << "): ";

	std::cin >> spell;
	for (size_t i = 0; i < size; i++)
	{
		if (spells.at(i) == spell)
		{
			current_spell = spell;
		}
	}
}

int Player::castSpell()
{
	int damageDealt = 0;
	
	for (size_t i = 0; i < game.classes.size(); i++)
	{
		if (player_class == game.classes.at(i))
		{

		}
	}

	return damageDealt;
}

// Overrides
void Player::move()
{

}

void Player::die()
{

}

int Player::eat()
{
	return 5;
}

int Player::drink()
{
	return 5;
}

std::string Player::scanSection()
{
	return "Default";
}

// Setters
void Player::setterSetClass(const std::string& name)
{
	player_class = name;
}

void Player::setterSetName(const std::string& name)
{
	this->name = name;
}

// Getters
std::map<int, std::string>& Player::getSpells()
{
	std::map<int, std::string>& spells_ref = spells;
	return spells_ref;
}

std::string& Player::getClass()
{
	return player_class;
}

std::string& Player::getName()
{
	return name;
}