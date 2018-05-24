#include "Event.h"
#include "Parser.h"

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {

	if (argc == 4 || argc == 5) {

		std::ifstream teams(argv[1]);
		std::ifstream matches(argv[2]);

		unsigned int depth = atoi(argv[3]);

		Event event = Parser::parse(depth, teams, matches);

		std::cerr << "Successfully parsed event." << std::endl;

		if (argc == 4) {
			event.calculate();
		} else if (argc == 5) {
			unsigned int numSims = atoi(argv[4]);
			
			std::cerr << "Monte Carlo: " << numSims << " num Sims" << std::endl;
			event.calculate(numSims);
		}

	} else {
		std::cout << "Usage: augur <teams.csv> <matches.csv> <depth> [numMonteCarloSims]" << std::endl;
	}

	return 0;
}
