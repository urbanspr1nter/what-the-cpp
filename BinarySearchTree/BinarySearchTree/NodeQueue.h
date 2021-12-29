#pragma once
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class NodeQueue {
	vector<Node*> _vector;

public:
	Node* dequeue();
	void queue(Node* n);
	bool empty();
};