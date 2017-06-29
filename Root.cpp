#include <iostream>

#include "Root.h"

Root::Root() {};
Root::~Root() {};

Node& Root::getChild(unsigned short key) {
	return children[key];
}

void Root::addChild(unsigned short key, double probability) {
	if (children.find(key) == children.end()) {
		this->children[key] = Node(probability);
	}
}

void Root::log() {
	std::cout.precision(2);
	for (auto &child : children) {
		std::cout << "Rank 1: " 
				  << child.first 
				  << " @ " 
				  << child.second.getProbability() * 100 
				  << "%" << std::endl;
		child.second.log();
	}
}