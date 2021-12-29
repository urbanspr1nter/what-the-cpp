#pragma once
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class NodeStack {
	vector<Node*> _vector;
public:
	void push(Node* n);
	Node* pop();
	bool empty();
};
