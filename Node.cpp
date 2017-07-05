#include <algorithm>
#include <iostream>

#include "Node.h"

Node::Node(unsigned short team, double probability) {
	this->team = team;
	this->probability = probability;
}

Node::~Node() {
	for (auto &child : children) {
		delete child;
	}
}

unsigned short Node::getTeam() const {
	return this->team;
} 

Node* Node::getChild(unsigned short key) {
	for (auto &child : children) {
		if (child->team == key) {
			return child;
		}
	}

	return nullptr;
}

void Node::addChild(unsigned short key, double probability) {
	for (auto &child : children) {
		if (child->team == key) {
			return;
		}
	}

	children.push_back(new Node(key, probability));
}

double Node::getProbability() const {
	return probability;
}

void Node::updateProbability(double delta) {
	probability += delta;
}

bool compareNodePointers(Node* a, Node* b) {
	return (a->getProbability() > b->getProbability());
}

void Node::log(
		unsigned short level,
		double initialprobability
		) {

	std::sort(
		children.begin(), 
		children.end(), 
		compareNodePointers);

	std::cout.precision(4);
	for (auto &child : children) {
		for (int i = 0; i < level; i++) {
			std::cout << "\t";
		}

		std::cout << "Rank " << level + 1 << ": " 
				  << child->team
				  << " @ " 
				  << (child->probability / initialprobability * 100) 
				  << "%" << std::endl;
		child->log(level + 1, child->probability);
	}
}