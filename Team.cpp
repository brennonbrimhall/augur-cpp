#include "Team.h"

Team::Team(
		unsigned short number,
		unsigned short qs,
		unsigned short firstSort,
		unsigned short secondSort,
		unsigned short thirdSort,
		unsigned short fourthSort
		) {
	this->number = number;

	this->qs = qs;

	this->firstSort = firstSort;
	this->secondSort = secondSort;
	this->thirdSort = thirdSort;
	this->fourthSort = fourthSort;
}

Team::~Team() {};

unsigned short Team::getNumber() const {
	return this->number;
}

unsigned short Team::getQS() const {
	return this->qs;
}

unsigned short Team::getFirstSort() const {
	return this->firstSort;
}

unsigned short Team::getSecondSort() const {
	return this->secondSort;
}

unsigned short Team::getThirdSort() const {
	return this->thirdSort;
}

unsigned short Team::getFourthSort() const {
	return this->fourthSort;
}

void Team::win() {
	qs += 2;
}

bool Team::lessThan (const Team &team2) const {
	if (qs < team2.qs) {
		return true;
	} else if (qs > team2.qs) {
		return false;
	} else {
		if (firstSort < team2.firstSort) {
			return true;
		} else if (firstSort > team2.firstSort) {
			return false;
		} else {
			if (secondSort < team2.secondSort) {
				return true;
			} else if (secondSort > team2.secondSort) {
				return false;
			} else {
				if (thirdSort < team2.thirdSort) {
					return true;
				} else if (thirdSort > team2.thirdSort) {
					return false;
				} else {
					if (fourthSort < team2.fourthSort) {
						return true;
					} else {
						return false;
					}
				}
			}
		}
	}
}

bool Team::operator < (const Team &t2) const {
	return !lessThan(t2);
}