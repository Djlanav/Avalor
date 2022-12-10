#include "world.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

extern bool running;

World::World() 
	: m_maxSections(100), m_sectionArray(nullptr) {}

void World::generateWorld()
{
	srand(time(0));

	std::cout << "Generating world... (" << m_maxSections << ")\n";
	m_sectionArray = std::make_shared<std::vector<Section>>(m_maxSections);

	for (uint32_t i = 0; i < m_sectionArray.get()->size(); i++)
	{
		m_sectionArray.get()->at(i).randomize();
	}

	getSectionValidity();
}

void World::getSectionValidity() 
{
	size_t size = m_sectionArray->size();
	int valid_counter = 0;

	for (uint32_t i = 0; i < size; i++) 
	{
		if (m_sectionArray->at(i).getMat().empty() == false) 
		{
			m_sectionArray->at(i).valid = true;
			valid_counter++;
		}
	}

	if (valid_counter == size) 
	{
		std::cout << "Sections generated!\n";
		Sleep(5000);
		system("cls");
	}
	else {
		std::cerr << "FAILED TO GENERATE! RETRYING...\n";
		system("cls");
		generateWorld();
	}
}

std::shared_ptr<std::vector<Section>> World::getSectionArray() 
{
	if (m_sectionArray == nullptr) 
	{
		std::cerr << "VITAL ARRAY IS NULLPTR. EXITING...\n";
		running = false;
	}

	return m_sectionArray;
}