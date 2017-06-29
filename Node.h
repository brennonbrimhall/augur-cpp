#pragma once

#include <map>

class Node {
private:
	double probability;
	std::map<unsigned short, Node> children;
public:
	Node(double probability = 0);
	~Node();

	Node& getChild(unsigned short key);
	void addChild(unsigned short key, double probability);
	
	double getProbability() const;
	void updateProbability(double delta);

	void log(
		unsigned short level = 0,
		double initalProbabilty = 1
		);
};