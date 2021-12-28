#include "Node.h"

Node::Node(string value) {
	this->next = nullptr;
	this->value = value;
}

Node::Node() {
	this->next = nullptr;
}
