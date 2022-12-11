#include "player.h"

#include <random>
#include <iostream>

Player::Player() 
	: name("Default"), attackPower(1), arcane(1), armor(1), currentWeapon(0)
{
	this->attacks = { "Punch", "Stab", "Kick" }; // Default attacks
}

// This method is for physical attacks such as with a weapon
int Player::attack()
{
	int damageDealt = null;

	std::string selectedAttack;
	std::cout << "Choose an attack to use: ";
	std::cin >> selectedAttack;

	if (selectedAttack == attacks.at(0))
	{
		std::cout << "You used " << attacks.at(0) << "!";
		damageDealt += 1;
	}
	else if (selectedAttack == attacks.at(1))
	{
		std::cout << "You used " << attacks.at(1) << "!";
		damageDealt += rand() % 7;
	}
	else if (selectedAttack == attacks.at(2)) {
		std::cout << "You used " << attacks.at(2) << "!";
		damageDealt = 5;
	}
}

int Player::castSpell()
{

}

// Setters
void Player::setClass(const std::string& name)
{
	player_class = name;
}