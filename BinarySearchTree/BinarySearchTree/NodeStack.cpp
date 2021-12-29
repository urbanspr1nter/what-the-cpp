#include "NodeStack.h"

using namespace std;

void NodeStack::push(Node* n) {
	this->_vector.push_back(n);
}

Node* NodeStack::pop() {
	Node* n = this->_vector.back();
	this->_vector.pop_back();
	return n;
}

bool NodeStack::empty() {
	return this->_vector.size() == 0;
}
