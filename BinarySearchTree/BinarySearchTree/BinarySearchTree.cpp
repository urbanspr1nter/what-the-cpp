#include <iostream>
#include <string>
#include "Node.h"
#include "Tree.h"

using namespace std;

string bool2str(bool b) {
    return b == 1 ? "true" : "false";
}

void test_recursive_preorder() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));

    string expected = "42,21,15,27,63,56";
    string actual = t->recursivePreorder();

    bool result = expected.compare(actual) == 0;

    cout << "Recursive preorder traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

void test_recursive_postorder() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));

    string expected = "15,27,21,56,63,42";
    string actual = t->recursivePostorder();

    bool result = expected.compare(actual) == 0;

    cout << "Recursive postorder traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

void test_recursive_inorder() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));

    string expected = "15,21,27,42,56,63";
    string actual = t->recursiveInorder();

    bool result = expected.compare(actual) == 0;

    cout << "Recursive inorder traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

void test_bfs() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));

    string expected = "42,21,63,15,27,56";
    string actual = t->bfs();

    bool result = expected.compare(actual) == 0;

    cout << "Breadth first search traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

void test_level_bfs() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));

    string expected = "42,\n21,63,\n15,27,56,\n";
    string actual = t->levelBfs();

    bool result = expected.compare(actual) == 0;

    cout << "Breadth first search level traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

void test_iterative_preorder() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));
    t->insert(new Node(25));
    t->insert(new Node(32));
    t->insert(new Node(72));
    t->insert(new Node(68));
    t->insert(new Node(67));

    string expected = "42,21,15,27,25,32,63,56,72,68,67,";
    string actual = t->iterativePreorder();

    bool result = expected.compare(actual) == 0;

    cout << "Iteratrive preorder traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

void test_iterative_inorder() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));
    t->insert(new Node(25));
    t->insert(new Node(32));
    t->insert(new Node(72));
    t->insert(new Node(68));
    t->insert(new Node(67));

    string expected = "15,21,25,27,32,42,56,63,67,68,72,";
    string actual = t->iterativeInorder();

    bool result = expected.compare(actual) == 0;

    cout << "Iterative inorder traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

void test_iterative_postorder() {
    Node* root = new Node(42);
    Tree* t = new Tree(root);
    t->insert(new Node(21));
    t->insert(new Node(63));
    t->insert(new Node(15));
    t->insert(new Node(27));
    t->insert(new Node(56));
    t->insert(new Node(25));
    t->insert(new Node(32));
    t->insert(new Node(72));
    t->insert(new Node(68));
    t->insert(new Node(67));

    string expected = "15,25,32,27,21,56,67,68,72,63,42,";
    string actual = t->iterativePostorder();

    bool result = expected.compare(actual) == 0;

    cout << "Iterative postorder traversal test. Expected: [" << expected << "], Actual: [" << actual << "]. Result: " << bool2str(result) << endl;
}

int main()
{
    test_recursive_preorder();
    test_recursive_postorder();
    test_recursive_inorder();
    test_bfs();
    test_level_bfs();
    test_iterative_preorder();
    test_iterative_inorder();
    test_iterative_postorder();

    return 0;
}
