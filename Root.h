#pragma once

#include <map>

#include "Node.h"

class Root {
private:
	std::vector<Node*> children;
public:
	Root();
	~Root();
	
	Node* getChild(unsigned short key);
	void addChild(unsigned short key, double probability);

	void log();
};
