#include <set>
#include "Tree.h"
#include "NodeQueue.h"
#include "NodeStack.h"

using namespace std;

void Tree::insert(Node* n) {
	this->_insertInternal(this->_root, n);
}

string Tree::recursivePreorder() {
	return this->_recursivePreorderInternal(this->_root);
}

string Tree::recursivePostorder() {
	return this->_recursivePostorderInternal(this->_root);
}

string Tree::recursiveInorder() {
	return this->_recursiveInorderInternal(this->_root);
}

string Tree::bfs() {
	return this->_bfsInternal(this->_root);
}

string Tree::levelBfs() {
	return this->_levelBfsInternal(this->_root);
}

string Tree::iterativePreorder() {
	return this->_iterativePreorderInternal(this->_root);
}

string Tree::iterativeInorder() {
	return this->_iterativeInorderInternal(this->_root);
}

string Tree::iterativePostorder() {
	return this->_iterativePostorderInternal(this->_root);
}

void Tree::_insertInternal(Node* curr, Node* n) {
	if (n->value < curr->value && curr->left == nullptr) {
		curr->left = n;
	}
	else if (n->value >= curr->value && curr->right == nullptr) {
		curr->right = n;
	}
	else if (n->value < curr->value) {
		this->_insertInternal(curr->left, n);
	}
	else {
		this->_insertInternal(curr->right, n);
	}
}

string Tree::_recursivePreorderInternal(Node* curr) {
	string built = "";
	if (curr == nullptr) {
		return "";
	}

	built += to_string(curr->value);

	if (curr->left) {
		built += ",";
	}
	built += this->_recursivePreorderInternal(curr->left);

	if (curr->right) {
		built += ",";
	}
	built += this->_recursivePreorderInternal(curr->right);

	return built;
}

string Tree::_recursivePostorderInternal(Node* curr) {
	string built = "";
	if (curr == nullptr) {
		return "";
	}

	built += _recursivePostorderInternal(curr->left);
	if (curr->left) {
		built += ",";
	}

	built += _recursivePostorderInternal(curr->right);
	if (curr->right) {
		built += ",";
	}

	built += to_string(curr->value);
	return built;
}

string Tree::_recursiveInorderInternal(Node* curr) {
	string built = "";

	if (curr == nullptr) {
		return "";
	}

	built += this->_recursiveInorderInternal(curr->left);
	if (curr->left) {
		built += ",";
	}

	built += to_string(curr->value);

	if (curr->right) {
		built += ",";
	}
	built += this->_recursiveInorderInternal(curr->right);


	return built;
}

string Tree::_bfsInternal(Node* curr) {
	if (curr == nullptr) {
		return "";
	}

	string built = "";

	NodeQueue* q = new NodeQueue();

	q->queue(curr);

	while (!q->empty()) {
		Node* n = q->dequeue();

		built += to_string(n->value);

		if (n->left) {
			q->queue(n->left);
		}
		if (n->right) {
			q->queue(n->right);
		}

		if (!q->empty()) {
			built += ",";
		}
	}

	return built;
}

string Tree::_levelBfsInternal(Node* curr) {
	if (curr == nullptr) {
		return "";
	}

	string built = "";

	NodeQueue* q = new NodeQueue();
	NodeQueue* t = new NodeQueue();

	q->queue(curr);

	while (!q->empty()) {
		Node* n = q->dequeue();

		built += to_string(n->value) + ",";

		if (n->left) {
			t->queue(n->left);
		}
		if (n->right) {
			t->queue(n->right);
		}

		if (q->empty()) {
			built += "\n";
			while (!t->empty()) {
				q->queue(t->dequeue());
			}
		}
	}

	return built;
}

string Tree::_iterativePreorderInternal(Node* curr) {
	string built = "";

	NodeStack* s = new NodeStack();

	Node* t = curr;

	while (t != nullptr) {
		s->push(t);
		built += to_string(t->value) + ",";
		t = t->left;
	}

	while (!s->empty()) {
		Node* popped = s->pop();

		if (popped->right) {
			popped = popped->right;
			while (popped != nullptr) {
				s->push(popped);
				built += to_string(popped->value) + ",";
				popped = popped->left;
			}
		}
	}

	return built;
}

string Tree::_iterativeInorderInternal(Node* curr) {
	string built = "";

	NodeStack* s = new NodeStack();

	Node* t = curr;

	while (t != nullptr) {
		s->push(t);
		t = t->left;
	}

	while (!s->empty()) {
		Node* popped = s->pop();
		built += to_string(popped->value) + ",";

		if (popped->right) {
			popped = popped->right;
			while (popped != nullptr) {
				s->push(popped);
				popped = popped->left;
			}
		}
	}

	return built;
}

string Tree::_iterativePostorderInternal(Node* curr) {
	string built = "";

	NodeStack* s = new NodeStack();
	set<Node*> nodeSet;

	Node* t = curr;

	while (t != nullptr) {
		s->push(t);
		t = t->left;
	}

	while (!s->empty()) {
		Node* popped = s->pop();

		if (popped->left == nullptr && popped->right == nullptr) {
			built += to_string(popped->value) + ",";
		}
		else {
			set<Node*>::iterator maybeFound = nodeSet.find(popped);
			if (maybeFound == nodeSet.end()) {
				s->push(popped);
				nodeSet.insert(popped);

				if (popped->right) {
					popped = popped->right;
					while (popped != nullptr) {
						s->push(popped);
						popped = popped->left;
					}
				}
			}
			else {
				built += to_string(popped->value) + ",";
			}
		}
	}


	return built;
}
