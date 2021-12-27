#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "PollChoice.h"

using namespace std;

class Poll {
public:
	string question;
	PollChoice* choices[10];
	int total_choices;

	Poll(int total_choices);
	void add_question();
	void add_choices();
	void write_serialized();
	void display();
};
