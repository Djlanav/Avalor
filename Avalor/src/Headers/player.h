#pragma once

#include "entity.h"
#include <vector>
#include <map>

class Player : public Entity {
private:
	std::string name;
	std::string player_class;
	std::string current_spell;

	std::map<int, std::string> spells;
	std::map<int, std::string> attacks;

	int attack_power;
	int arcane;
	int armor;
	int level;
	int xp;
	
	int current_weapon; // Gets weapon by ID

private:
	void selectSpell();

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
	std::array<std::tuple<uint64_t, std::string>, 8> scanSections() override;

// Setters
public:
	void setterSetClass(const std::string& name);
	void setterSetName(const std::string& name);

// Getters
public:
	std::map<int, std::string>& getSpells();
	std::string& getClass();
	std::string& getName();
};