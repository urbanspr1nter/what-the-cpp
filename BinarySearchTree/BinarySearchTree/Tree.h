#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class Tree {
	Node* _root;
	void _insertInternal(Node* curr, Node* n);
	string _recursivePreorderInternal(Node* curr);
	string _recursivePostorderInternal(Node* curr);
	string _recursiveInorderInternal(Node* curr);
	string _bfsInternal(Node* curr);
	string _levelBfsInternal(Node* curr);
	string _iterativePreorderInternal(Node* curr);
	string _iterativePostorderInternal(Node* curr);
	string _iterativeInorderInternal(Node* curr);

public:
	Tree(Node *root): _root(root) {}
	void insert(Node* n);
	string recursivePreorder();
	string recursivePostorder();
	string recursiveInorder();
	string bfs();
	string levelBfs();
	string iterativePreorder();
	string iterativePostorder();
	string iterativeInorder();
};
