#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string value;
	Node* next;

	Node();
	Node(string value);
};
