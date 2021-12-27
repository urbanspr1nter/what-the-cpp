#include "Poll.h"

using namespace std;

Poll::Poll(int total_choices) {
	if (total_choices < 2) {
		this->total_choices = 2;
	}
	if (total_choices > 10) {
		this->total_choices = 10;
	}

	this->total_choices = total_choices;
	for (int i = 0; i < this->total_choices; i++) {
		this->choices[i] = new PollChoice("", 0);
	}
}

void Poll::add_question() {
	cout << "What is the question?\n> ";
	getline(cin, this->question);
}

void Poll::add_choices() {
	for (int i = 0; i < this->total_choices; i++) {
		PollChoice* choice = new PollChoice("", 0);

		cout << "Enter choice " + to_string(i + 1) + "\n> ";
		getline(cin, choice->description);

		this->choices[i] = choice;
	}
}

void Poll::write_serialized() {
	string serialized;
	serialized += "{";
	serialized += "\"total_choices\": " + to_string(this->total_choices) + ",";
	serialized += "\"question\": \"" + this->question + "\"" + ",";
	serialized += "\"choices\": [";
	for (int i = 0; i < this->total_choices; i++) {
		PollChoice* a = this->choices[i];

		serialized += "{";
		serialized += "\"description\": \"" + a->description + "\",";
		serialized += "\"votes\": " + to_string(a->votes);

		if (i == this->total_choices - 1) {
			serialized += "}";
		}
		else {
			serialized += "},";
		}
	}
	serialized += "]";
	serialized += "}";

	ofstream db;
	db.open("db.json");
	db << serialized << endl;
	db.close();

	cout << "The data has been saved." << endl;
}

void Poll::display() {
	cout << "\n\nThe current poll is:" << endl;
	cout << "\t" << this->question << endl;
	for (int i = 0; i < this->total_choices; i++) {
		cout << "\t\t" << this->choices[i]->description << ": " << this->choices[i]->votes << endl;
	}
}
