#pragma once

#include <stdint.h>
#include <string>
#include <array>

class Section {
private:
	uint64_t m_id;

	std::string m_material;
	std::array<std::string, 3> m_materials = { "grass", "dirt", "stone" };

public:
	bool valid = false;

public:
	Section();
	uint64_t getID() const;
	std::string getMat() const;
	void randomize();
};