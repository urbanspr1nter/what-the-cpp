/*
1941. Check if All Characters Have Equal Number of Occurrences

Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        if (s.length() == 0) {
            return true;
        }

        map<char, int> occ;

        for (int i = 0; i < s.length(); i++) {
            char c = s.at(i);

            if (occ.find(c) == occ.end()) {
                occ.insert(pair<char, int>(c, 1));
            }
            else {
                occ.find(c)->second++;
            }
        }

        int reference_value = occ.find(s.at(0))->second;
        for (map<char, int>::iterator it = occ.begin(); it != occ.end(); it++) {
            int v = it->second;

            if (v != reference_value) {
                return false;
            }
        }

        return true;
    }
};

string btostr(bool b) {
    return b ? "true" : "false";
}

int main()
{
    Solution sol;
    bool b;

    string s1 = "abacbc";
    bool e1 = true;
    bool b1 = sol.areOccurrencesEqual(s1);
    cout << "test case 1: " << btostr(b1 == e1) << endl;


    string s2 = "aaabb";
    bool e2 = false;
    bool b2 = sol.areOccurrencesEqual(s2);
    cout << "test case 2: " << btostr(b2 == e2) << endl;

    return 0;
}
