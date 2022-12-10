#pragma once

#include "entity.h"
#include <vector>

class Player : public Entity {
private:
	std::string name;
	std::string player_class;

	std::vector<std::string> spells;
	std::vector<std::string> attacks;

	int attackPower;
	int arcane;
	int armor;
	
	int currentWeapon; // Gets weapon by ID

private:
	std::string checkClass();

public:
	Player();

	int attack();
	int castSpell();

	// Overrides
	void move() override;
	void die() override;
	int eat() override;
	int drink() override;
	std::string scanSection() override;
};