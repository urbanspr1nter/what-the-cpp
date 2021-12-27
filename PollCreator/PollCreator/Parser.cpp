#include "Parser.h"
#include "json.hpp"

using json = nlohmann::json;

Poll *db2poll(string filename) {
	ifstream file(filename);
	json j;

	try {
		file >> j;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}

	if (!file.is_open()) {
		cout << "Invalid filename. It does not exist." << endl;
		return NULL;
	}

	file.close();

	int total_choices = j["total_choices"];
	string question = j["question"];


	Poll* p = new Poll(total_choices);
	p->question = question;

	for (int i = 0; i < total_choices; i++) {
		json c = j["choices"][i];

		PollChoice* choice = new PollChoice(c["description"], c["votes"]);
		p->choices[i] = choice;
	}

	return p;
}