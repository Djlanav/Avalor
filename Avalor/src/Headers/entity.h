#pragma once

#include <stdint.h>
#include <string>
#include <array>
#include <tuple>
#include "section.h"

#define null 0

class Entity {
private:
	uint32_t m_initialSectionID = 0;
	uint32_t m_currentSectionID = 0;
	
	int m_health = 100;
	int m_hunger = 10;
	int m_thirst = 10;

public:
	virtual void move() = 0;
	virtual void die() = 0;
	virtual int eat() = 0;
	virtual int drink() = 0;

	virtual std::string scanSection() = 0;
	virtual std::array<std::tuple<uint64_t, std::string>, 8> scanSections() = 0;
};