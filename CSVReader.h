#pragma once

#include <fstream>
#include "Event.h"

class CSVReader {
private:
	Event event;
	void parseLine(std::string line);
public:
	CSVReader();
	~CSVReader();

	Event& parseCSV(std::ifstream& infile);
};