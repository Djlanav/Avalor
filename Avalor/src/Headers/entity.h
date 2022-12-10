#pragma once

#include <stdint.h>
#include <string>

#define null 0

class Entity {
private:
	uint32_t m_initialSectionID;
	uint32_t m_currentSectionID;
	
	int m_health;
	int m_hunger;
	int m_thirst;

public:
	Entity();

	virtual void move() = 0;
	virtual void die() = 0;
	virtual int eat() = 0;
	virtual int drink() = 0;
	virtual std::string scanSection() = 0;
};