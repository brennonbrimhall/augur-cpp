#include <iostream>

#include "Node.h"

Node::Node(double probability) {
	this->probability = probability;
}

Node::~Node() {};

Node& Node::getChild(unsigned short key) {
	return children[key];
}

void Node::addChild(unsigned short key, double probabilty) {
	if (children.find(key) == children.end()) {
		this->children[key] = Node(probabilty);
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
		double initalProbabilty
		) {

	for (int i = 0; i < level; i++) {
		std::cout << "\t";
	}

	std::cout.precision(2);
	for (auto &child : children) {
		std::cout << "Rank " << level + 1 << ": " 
				  << child.first 
				  << " @ " 
				  << (child.second.probability / initalProbabilty * 100) 
				  << "%" << std::endl;
		child.second.log(level + 1, child.second.probability);
	}
}