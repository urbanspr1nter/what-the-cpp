#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int value;
	Node(int value) {
		this->left = nullptr;
		this->right = nullptr;
		this->value = value;
	}
	Node(const Node& o) {
		this->left = o.left;
		this->right = o.right;
		this->value = o.value;
	}
};
