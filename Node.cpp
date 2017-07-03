#include <algorithm>
#include <iostream>
#include <vector>

#include "Node.h"

Node::Node(double probability) {
	this->probability = probability;
}

Node::~Node() {};

Node* Node::getChild(unsigned short key) {
	return children[key];
}

void Node::addChild(unsigned short key, double probabilty) {
	if (children.find(key) == children.end()) {
		this->children[key] = new Node(probabilty);
	}
}

double Node::getProbability() const {
	return probability;
}

void Node::updateProbability(double delta) {
	probability += delta;
}

void Node::log(
		unsigned short level,
		double initialProbabilty
		) {

	std::cout.precision(4);
	for (auto &child : children) {
		for (int i = 0; i < level; i++) {
			std::cout << "\t";
		}

		std::cout << "Rank " << level + 1 << ": " 
				  << child.first 
				  << " @ " 
				  << (child.second->probability / initialProbabilty * 100) 
				  << "%" << std::endl;
		child.second->log(level + 1, child.second->probability);
	}
}