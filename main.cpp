#include <iostream>
#include <fstream>
#include "CSVReader.h"
#include "Event.h"


int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "No file given!" << std::endl;
		return 1;
	}

	CSVReader reader;

	std::ifstream infile(argv[1]);

	Event event = reader.parseCSV(infile);
	event.calculate();

	return 0;
}