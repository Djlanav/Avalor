#include "section.h"
#include <random>

Section::Section() : m_id(0)
{
	
}

uint64_t Section::getID() const 
{
	return m_id;
}

void Section::randomize()
{
	uint64_t maxID = static_cast<uint64_t>(pow(2, 32));
	size_t maxMat = m_materials.size();

	m_id = rand() % maxID;
	m_material = m_materials[rand() % maxMat];

}

std::string Section::getMat() const 
{
	return m_material;
}