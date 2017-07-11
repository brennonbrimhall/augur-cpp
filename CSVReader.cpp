// #include <ifstream>

// class CSVReader {
// public:
// 	static Event parseCSV(ifstream infile);
// };

#include "CSVReader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

CSVReader::CSVReader() : event(Event(12)) {};
CSVReader::~CSVReader() {};

Event& CSVReader::parseCSV(std::ifstream& infile) {
	this->event = Event(12);

	std::string line;

	while (std::getline(infile, line)) {
        this->parseLine(line);
    }

    return this->event;
}

void CSVReader::parseLine(std::string line) {
	std::stringstream linestream;
	linestream.str(line);

	std::string prefix;

	std::getline(linestream, prefix, ',');

	if (prefix == "#") {
		return;
	} else if (prefix == "T") {
		std::string numberToken;
		std::string qsToken;
		std::string firstSortToken;
		std::string secondSortToken;
		std::string thirdSortToken;
		std::string fourthSortToken;
		std::string fifthSortToken;

		unsigned short number;
		unsigned char qs;
		unsigned short firstSort;
		unsigned short secondSort;
		unsigned short thirdSort;
		unsigned short fourthSort;
		unsigned short fifthSort;

		std::getline(linestream, numberToken, ',');
		std::getline(linestream, qsToken, ',');
		std::getline(linestream, firstSortToken, ',');
		std::getline(linestream, secondSortToken, ',');
		std::getline(linestream, thirdSortToken, ',');
		std::getline(linestream, fourthSortToken, ',');
		std::getline(linestream, fifthSortToken, ',');

		std::stringstream temporary;
		temporary.str(numberToken);
		temporary >> number;

		temporary.str(qsToken);
		temporary >> qs;

		temporary.str(firstSortToken);
		temporary >> firstSort;

		temporary.str(secondSortToken);
		temporary >> secondSortToken;

		temporary.str(thirdSortToken);
		temporary >> thirdSort;

		temporary.str(fourthSortToken);
		temporary >> fourthSort;

		temporary.str(fifthSortToken);
		temporary >> fifthSort;

		this->event.addTeam(number,
							qs,
							firstSort,
							secondSort,
							thirdSort,
							fourthSort,
							fifthSort);

		std::cout << "Added team #" << numberToken << std::endl;
	} else {
		std::string red1Token;
		std::string red2Token;
		std::string red3Token;
		std::string blue1Token;
		std::string blue2Token;
		std::string blue3Token;
		std::string redWinProbabilityToken;

		unsigned short red1;
		unsigned short red2;
		unsigned short red3;
		unsigned short blue1;
		unsigned short blue2;
		unsigned short blue3;
		double redWinProbability;

		std::getline(linestream, red1Token, ',');
		std::getline(linestream, red2Token, ',');
		std::getline(linestream, red3Token, ',');
		std::getline(linestream, blue1Token, ',');
		std::getline(linestream, blue2Token, ',');
		std::getline(linestream, blue3Token, ',');
		std::getline(linestream, redWinProbabilityToken, ',');

		std::stringstream temporary;
		temporary.str(red1Token);
		temporary >> red1;

		temporary.str(red2Token);
		temporary >> red2;

		temporary.str(red3Token);
		temporary >> red3;

		temporary.str(blue1Token);
		temporary >> blue1;

		temporary.str(blue1Token);
		temporary >> blue2;

		temporary.str(blue1Token);
		temporary >> blue3;

		temporary.str(redWinProbabilityToken);
		temporary >> redWinProbability;

		this->event.addTeam(red1,
							red2,
							red3,
							blue1,
							blue2,
							blue3,
							redWinProbability);

		std::cout << "Added match (" 
				<< red1Token << "," 
				<< red2Token << "," 
				<< red3Token << " | " 
				<< blue1Token << "," 
				<< blue2Token << "," 
				<< blue3Token << ")" 
				<< std::endl;
	}
}