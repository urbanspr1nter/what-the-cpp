#include <iostream>
#include "List.h"
#include "Node.h"

string bool2str(bool value) {
    return value == 1 ? "true" : "false";
}

// This tests to see if the list deallocates memory correctly. Use VS profiler to confirm.
void memory_test() {
    List* list = new List();

    cout << "STAGE: BEFORE LIST ALLOCATION. (Take heapsnapshot now) Press ENTER to allocate list." << endl;
    cin.get();

    string very_long_string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~!@#$%^&*()_+-=[];',./\\";
    for (int i = 0; i < 1000000; i++) {
        list->add(new Node(very_long_string + "_" + to_string(i)));
    }

    cout << "STAGE: AFTER LIST ALLOCATION. (Take heapsnapshot now) Press ENTER to deallocate list." << endl;
    cin.get();

    delete list;

    cout << "STAGE: DEALLOCATED LIST. (Take heapsnapshot now) Press ENTER to exit." << endl;
    cin.get();
}

void iterator_test() {
    List* list = new List();

    list->add(new Node("H"));
    list->add(new Node("E"));
    list->add(new Node("L"));
    list->add(new Node("L"));
    list->add(new Node("O"));
    list->add(new Node(" "));
    list->add(new Node("W"));
    list->add(new Node("o"));
    list->add(new Node("r"));
    list->add(new Node("l"));
    list->add(new Node("d"));
    list->add(new Node("!"));

    string expected = "HELLO World!";
    string built = "";
    // Use the iterator
    List::ListIterator* iterator = list->iterator();
    while (iterator->has_next()) {
        Node* n = iterator->next();
        built += n->value;
    }

    bool result = expected.compare(built) == 0;

    cout << "Iterator test: expected: [" << expected << "], actual: [" << built << "], " << bool2str(result) << endl;
}

void reverse_test_1() {
    List* list = new List();

    list->add(new Node("H"));
    list->add(new Node("E"));
    list->add(new Node("L"));
    list->add(new Node("L"));
    list->add(new Node("O"));
    list->add(new Node(" "));
    list->add(new Node("W"));
    list->add(new Node("o"));
    list->add(new Node("r"));
    list->add(new Node("l"));
    list->add(new Node("d"));
    list->add(new Node("!"));

    list->reverse();

    string expected = "!dlroW OLLEH";
    string built = "";

    // Use the iterator
    List::ListIterator* iterator = list->iterator();
    while (iterator->has_next()) {
        Node* n = iterator->next();
        built += n->value;
    }

    bool result = expected.compare(built) == 0;

    cout << "Reverse test 1: expected: [" << expected << "], actual: [" << built << "], " << bool2str(result) << endl;
}

void reverse_test_2() {
    List* list = new List();
    list->reverse();

    string expected = "";
    string built = "";

    bool result = expected.compare(built) == 0;
    cout << "Reverse test 2: expected: [" << expected << "], actual: [" << built << "], " << bool2str(result) << endl;
}

void reverse_test_3() {
    List* list = new List();

    list->add(new Node("H"));

    list->reverse();

    string expected = "H";
    string built = "";

    // Use the iterator
    List::ListIterator* iterator = list->iterator();
    while (iterator->has_next()) {
        Node* n = iterator->next();
        built += n->value;
    }

    bool result = expected.compare(built) == 0;

    cout << "Reverse test 3: expected: [" << expected << "], actual: [" << built << "], " << bool2str(result) << endl;
}

void reverse_test_4() {
    List* list = new List();

    list->add(new Node("H"));
    list->add(new Node("E"));

    list->reverse();

    string expected = "EH";
    string built = "";

    // Use the iterator
    List::ListIterator* iterator = list->iterator();
    while (iterator->has_next()) {
        Node* n = iterator->next();
        built += n->value;
    }

    bool result = expected.compare(built) == 0;

    cout << "Reverse test 4: expected: [" << expected << "], actual: [" << built << "], " << bool2str(result) << endl;
}

int main()
{
    iterator_test();
    reverse_test_1();
    reverse_test_2();
    reverse_test_3();
    reverse_test_4();

    memory_test();
    return 0;
}
