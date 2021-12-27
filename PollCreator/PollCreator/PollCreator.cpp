#include <iostream>
#include <string>
#include "Poll.h"
#include "Parser.h"

using namespace std;

string default_db_filename = "db.json";
string input_symbol = "> ";
string create_total_choice_prompt = "How many choices? (min = 2, max = 10)\n";
string create_enter_valid_total_choices = "\nPlease enter a valid number. (min = 2, max = 10)\n";
string participate_prompt = "\nWhich would you like to vote for?\n";
string participate_enter_valid_choice = "\nPlease enter a valid choice.\n";

enum PollCreatorOptions {
    PollCreate = 1,
    PollParticipate = 2
};

void create_poll() {
    string s_total_choices;
    int total_choices;

    while (true) {
        cout << create_total_choice_prompt;
        cout << input_symbol;
        cin >> s_total_choices;
        cin.ignore();

        try {
            total_choices = stoi(s_total_choices);
        }
        catch (invalid_argument& _e) {
            cout << create_enter_valid_total_choices;
            continue;
        }

        if (total_choices < 2 || total_choices > 10) {
            cout << create_enter_valid_total_choices;
            continue;
        }

        break;
    }

    Poll* p = new Poll(total_choices);
    p->add_question();
    p->add_choices();
    p->write_serialized();
    p->display();
}

void participate_poll() {
    Poll* current_poll = db2poll(default_db_filename);

    if (current_poll == NULL) {
        return;
    }

    string question = current_poll->question;
    int total_choices = current_poll->total_choices;

    cout << question << endl;
    for (int i = 0; i < total_choices; i++) {
        cout << "\t" << to_string(i + 1) << ". " << current_poll->choices[i]->description << endl;
    }

    string s_choice;

    // Make sure the user chooses a valid choice. The choice must be a valid integer,
    // or within the boundaries of [1, total_choices]
    while (true) {
        cout << participate_prompt;
        cout << input_symbol;
        cin >> s_choice;
        cin.ignore();

        int choice;

        try {
            choice = stoi(s_choice);
        }
        catch (invalid_argument& _e) {
            cout << participate_enter_valid_choice;
            continue;
        }

        if (choice > total_choices || choice < 1) {
            cout << participate_enter_valid_choice;
            continue;
        }

        cout << "\nYou voted for " + to_string(choice) + ". " + current_poll->choices[choice - 1]->description << endl;
        current_poll->choices[choice - 1]->votes++;
        break;
    }

    current_poll->write_serialized();
    current_poll->display();
}

/*
    Main
    How to execute the program:

    PollCreator [opt]

    Where opt can be:
    1 - Create a poll
    2 - Participate in the current poll

    If no opt is given, then the interactive menu will appear.
*/
int main(int argc, char * argv[])
{
    int input_choice;

    if (argc == 1) {
        input_choice = 0;
    }
    else {
        input_choice = atoi(argv[1]);
    }

    if (input_choice == 0) {
        cout << "What would you like to do?" << endl;
        cout << "\t1. Create a poll" << endl;
        cout << "\t2. Participate in the current poll" << endl;
        cout << input_symbol;
        cin >> input_choice;
        cin.ignore();
    }

    if (input_choice == PollCreate) {
        create_poll();
    }
    else if (input_choice == PollParticipate) {
        participate_poll();
    }

    cout << "\nPress RETURN key to exit.";
    cin.get();

    return 0;
}

