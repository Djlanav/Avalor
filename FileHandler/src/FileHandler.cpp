// FileHandler.cpp : Defines the functions for the static library.
//

#include "FileHandler.h"

void FileHandler::readFile(const std::string& name) {
	std::ifstream fileToRead;
	std::string lines;

	fileToRead.open(name);
	if (!fileToRead.is_open()) {
		createFile(name);
		fileToRead.open(name);
	}

	while (std::getline(fileToRead, lines)) {
		std::cout << lines << "\n";
	}

	fileToRead.close();
}

void FileHandler::createFile(const std::string& name) {
	std::ofstream fileToCreate(name);

	fileToCreate << "1. Set name" << std::endl;
	fileToCreate << "2. Set class" << std::endl;
	fileToCreate << "3. Create custom class" << std::endl;

	fileToCreate.close();
}