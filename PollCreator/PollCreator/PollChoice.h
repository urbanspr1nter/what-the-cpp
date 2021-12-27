#pragma once
#include <string>

using namespace std;

class PollChoice {
public:
	string description;
	int votes;
	PollChoice(string description, int votes);
};
