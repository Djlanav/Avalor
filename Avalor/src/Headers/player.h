#pragma once

#include "entity.h"

class Player : public Entity {
private:
	std::string name;

	int attackPower;
	int arcane;
	int armor;
	
	int currentWeapon; // Gets weapon by ID

public:
	Player();

	int attack();
	int castSpell();
};