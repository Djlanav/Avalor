#pragma once

#include <string>
#include <iostream>
#include <fstream>

class FileHandler {
public:
	void readFile(const std::string& name);
	void createFile(const std::string& name);
};