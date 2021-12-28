#include "List.h"

using namespace std;

List::List() {
	this->_head = nullptr;
	this->_tail = nullptr;
	this->_size = 0;
}

List::~List() {
	while (this->_head != nullptr) {
		Node* tNext = this->_head->next;
		delete this->_head;
		this->_head = tNext;
	}
}

void List::add(Node* next) {
	if (this->_head == nullptr && this->_tail == nullptr) {
		this->_head = next;
		this->_tail = this->_head;
		this->_size++;

		return;
	}

	this->_tail->next = next;
	this->_tail = next;
	this->_size++;
}

Node* List::get(int index) {
	Node* result = this->_head;
	for (int i = 0; i < index; i++) {
		result = result->next;
	}

	return result;
}

void List::display() {
	Node* tHead = this->_head;

	while (tHead != nullptr) {
		cout << tHead->value;
		if (tHead->next != nullptr) {
			cout << " -> ";
		}
		else {
			cout << " -> NULL " << endl;
		}
		tHead = tHead->next;
	}
}

void List::reverse()  {
	if (this->_head == nullptr || this->_head->next == nullptr) {
		return;
	}

	Node* t1 = this->_head;
	Node* t2 = t1->next;
	Node* t3 = t2->next;
	this->_tail = t1;

	while (t2 != nullptr) {
		t2->next = t1;
		t1 = t2;
		t2 = t3;
		if (t3 != nullptr) {
			t3 = t2->next;
		}
	}

	this->_head = t1;
	this->_tail->next = nullptr;
}

List::ListIterator* List::iterator() {
	return new ListIterator(this);
}


List::ListIterator::ListIterator(List* list) {
	this->_current = nullptr;
	this->_initial = list->_head;
}

Node* List::ListIterator::current() {
	return this->_current;
}

Node* List::ListIterator::next() {
	if (this->_current == nullptr) {
		this->_current = this->_initial;
	}
	else {
		this->_current = this->_current->next;
	}

	return this->_current;
}

bool List::ListIterator::has_next() {
	if (this->_initial != nullptr && this->_current == nullptr) {
		return true;
	}

	return (bool)(this->_current->next != nullptr);
}