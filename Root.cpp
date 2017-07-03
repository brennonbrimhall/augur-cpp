#include <iostream>

#include "Root.h"

Root::Root() {};
Root::~Root() {
	for (auto &child : children) {
		delete child.second;
	}
};

Node* Root::getChild(unsigned short key) {
	return children[key];
}

void Root::addChild(unsigned short key, double probability) {
	if (children.find(key) == children.end()) {
		this->children[key] = new Node(probability);
	}
}

void Root::log() {
	std::cout.precision(4);
	
	for (auto &child : children) {
		std::cout << "Rank 1: " 
				  << child.first 
				  << " @ " 
				  << child.second->getProbability() * 100 
				  << "%" << std::endl;
		child.second->log(1, child.second->getProbability());
	}
}