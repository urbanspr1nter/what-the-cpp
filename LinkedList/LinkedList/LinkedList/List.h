#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class List {
	Node* _head;
	Node* _tail;
	int _size;

public:
	class ListIterator {
		Node* _initial;
		Node* _current;
	public:
		Node* current();
		Node* next();
		bool has_next();
		ListIterator(List* list);
	};

	List();
	~List();
	List(Node* head) : _head(head), _tail(head) {
		this->_size = 0;
		this->_size++;
	}

	void add(Node* next);
	void display();
	void reverse();
	Node* get(int index);
	ListIterator* iterator();
};
