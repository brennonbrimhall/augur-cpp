#pragma once

#include <map>

class Node {
private:
	double probability;
public:
	std::map<unsigned short, Node*> children;
	Node(double probability = 0);
	~Node();

	Node* getChild(unsigned short key);
	void addChild(unsigned short key, double probability);
	
	double getProbability() const;
	void updateProbability(double delta);

	void softDelete();

	void log(
		unsigned short level = 0,
		double initialProbabilty = 1
		);
};