#include <string>
#include <sstream>

#include "Parser.h"

Event Parser::parse(unsigned int depth, std::ifstream& teams, std::ifstream& matches) {
	Event event(depth);

	std::string line;

	while (std::getline(teams, line)) {

		std::stringstream linestream(line);

		std::string temp;

		unsigned short number, qs, firstSort, secondSort, thirdSort, fourthSort, fifthSort;

		std::getline(linestream, temp, ',');
		std::stringstream numberStream(temp);
		numberStream >> number;

		std::getline(linestream, temp, ',');
		std::stringstream qsStream(temp);
		qsStream >> firstSort;
		qs = (unsigned char) firstSort;

		std::getline(linestream, temp, ',');
		std::stringstream firstSortStream(temp);
		firstSortStream >> firstSort;

		std::getline(linestream, temp, ',');
		std::stringstream secondSortStream(temp);
		secondSortStream >> secondSort;

		std::getline(linestream, temp, ',');
		std::stringstream thirdSortStream(temp);
		thirdSortStream >> thirdSort;

		std::getline(linestream, temp, ',');
		std::stringstream fourthSortStream(temp);
		fourthSortStream >> fourthSort;

		event.addTeam(number, qs, firstSort, secondSort, thirdSort, fourthSort);
	}

	while (std::getline(matches, line)) {

		std::stringstream linestream(line);

		std::string temp;

		unsigned short red1, red2, red3, blue1, blue2, blue3;
		double redWinProbability;

		std::getline(linestream, temp, ',');
		std::stringstream red1stream(temp);
		red1stream >> red1;

		std::getline(linestream, temp, ',');
		std::stringstream red2stream(temp);
		red2stream >> red2;

		std::getline(linestream, temp, ',');
		std::stringstream red3stream(temp);
		red3stream >> red3;

		std::getline(linestream, temp, ',');
		std::stringstream blue1stream(temp);
		blue1stream >> blue1;

		std::getline(linestream, temp, ',');
		std::stringstream blue2stream(temp);
		blue2stream >> blue2;

		std::getline(linestream, temp, ',');
		std::stringstream blue3stream(temp);
		blue3stream >> blue3;

		std::getline(linestream, temp, ',');
		std::stringstream redWinProbabilityStream(temp);
		redWinProbabilityStream >> redWinProbability;

		event.addMatch(red1, red2, red3, blue1, blue2, blue3, redWinProbability);
	}

	return event;
}