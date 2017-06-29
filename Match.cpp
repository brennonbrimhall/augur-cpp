#include "Match.h"

Match::Match(
		unsigned short red1, 
		unsigned short red2,
		unsigned short red3,
		unsigned short blue1,
		unsigned short blue2,
		unsigned short blue3,
		double redWinProbability
		) {
	this->red1 = red1;
	this->red2 = red2;
	this->red3 = red3;

	this->blue1 = blue1;
	this->blue2 = blue2;
	this->blue3 = blue3;

	this->redWinProbability = redWinProbability;
}

Match::~Match() {};

unsigned short Match::getRed1() const {
	return red1;
}

unsigned short Match::getRed2() const {
	return red2;
}

unsigned short Match::getRed3() const {
	return red3;
}

unsigned short Match::getBlue1() const {
	return blue1;
}

unsigned short Match::getBlue2() const {
	return blue2;
}

unsigned short Match::getBlue3() const {
	return blue3;
}

double Match::getRedWinProbability() const {
	return redWinProbability;
}

double Match::getBlueWinProbability() const {
	return 1 - redWinProbability;
}