#pragma once

class Team {
private:
	unsigned short number;

	unsigned char qs;
	
	unsigned short firstSort;
	unsigned short secondSort;
	unsigned short thirdSort;
	unsigned short fourthSort;
	unsigned short fifthSort;

public:
	Team(
		unsigned short number,
		unsigned char qs,
		unsigned short firstSort,
		unsigned short secondSort,
		unsigned short thirdSort,
		unsigned short fourthSort,
		unsigned short fifthSort
		);
	~Team();
	
	unsigned short getNumber() const;

	unsigned char getQS() const;

	unsigned short getFirstSort() const;
	unsigned short getSecondSort() const;
	unsigned short getThirdSort() const;
	unsigned short getFourthSort() const;
	unsigned short getFifthSort() const;

	void win();

	bool operator < (const Team &t2) const;
};