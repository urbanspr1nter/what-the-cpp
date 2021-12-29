#include "NodeQueue.h"
#include "Node.h"

using namespace std;

Node* NodeQueue::dequeue() {
	Node *n = this->_vector.front();
	this->_vector.erase(this->_vector.begin());

	return n;
}

void NodeQueue::queue(Node* n) {
	this->_vector.push_back(n);
}

bool NodeQueue::empty() {
	return this->_vector.size() == 0;
}
