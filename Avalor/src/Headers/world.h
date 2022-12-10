#pragma once

#include "section.h"
#include "FileHandler.h"
#include <vector>
#include <memory>

class World {
private:
	std::shared_ptr<std::vector<Section>> m_sectionArray;
	uint32_t m_maxSections;

public:
	World();

	void generateWorld();

	void getSectionValidity();
	std::shared_ptr<std::vector<Section>> getSectionArray();
};