#include <iostream>
#include <algorithm>

#include "Root.h"

Root::Root() {};
Root::~Root() {
	for (auto &child : children) {
		delete child;
	}
};

Node* Root::getChild(unsigned short key) {
	for (auto &child : children) {
		if (child->getTeam() == key) {
			return child;
		}
	}

	return nullptr;
}

void Root::addChild(unsigned short key, double probability) {
	for (auto &child : children) {
		if (child->getTeam() == key) {
			return;
		}
	}

	children.push_back(new Node(key, probability));
}

void Root::log() {
	
	std::sort(
		children.begin(),
		children.end(),
		compareNodePointers
	);

	std::cout.precision(4);
	
	for (auto &child : children) {
		std::cout << "Rank 1: " 
				  << child->getTeam() 
				  << " @ " 
				  << child->getProbability() * 100 
				  << "%" << std::endl;
		child->log(1, child->getProbability());
	}
}