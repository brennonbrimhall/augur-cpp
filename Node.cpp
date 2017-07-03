#include <algorithm>
#include <iostream>
#include <vector>

#include "Node.h"

Node::Node(double probability) {
	this->probability = probability;
}

Node::~Node() {
	for (auto &child : children) {
		delete child.second;
	}
};

Node* Node::getChild(unsigned short key) {
	return children[key];
}

void Node::addChild(unsigned short key, double probability) {
	if (children.find(key) == children.end()) {
		this->children[key] = new Node(probability);
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
		double initialprobability
		) {

	std::cout.precision(4);
	for (auto &child : children) {
		for (int i = 0; i < level; i++) {
			std::cout << "\t";
		}

		std::cout << "Rank " << level + 1 << ": " 
				  << child.first 
				  << " @ " 
				  << (child.second->probability / initialprobability * 100) 
				  << "%" << std::endl;
		child.second->log(level + 1, child.second->probability);
	}
}