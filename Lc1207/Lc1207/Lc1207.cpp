/*
1207. Unique Number of Occurrences

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique,
or false otherwise.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Input: arr = [1,2]
Output: false

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

*/
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occ;
        set<int> s;

        for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
            int element = *it;
            if (occ.find(element) == occ.end()) {
                occ.insert(pair<int, int>(element, 1));
            }
            else {
                occ.find(element)->second++;
            }
        }

        for (map<int, int>::iterator it = occ.begin(); it != occ.end(); it++) {
            int element = it->second;
            if (s.find(element) != s.end()) {
                return false;
            }
            s.insert(element);
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

    vector<int> v1 = { 1, 2, 2, 1, 1, 3 };
    bool e1 = true;
    bool s1 = sol.uniqueOccurrences(v1);
    b = e1 == s1;
    cout << "test case 1: " << btostr(b) << endl;

    vector<int> v2 = { 1, 2 };
    bool e2 = false;
    bool s2 = sol.uniqueOccurrences(v2);
    b = e2 == s2;
    cout << "test case 2: " << btostr(b) << endl;

    vector<int> v3 = { -3,0,1,-3,1,1,1,-3,10,0 };
    bool e3 = true;
    bool s3 = sol.uniqueOccurrences(v3);
    b = e3 == s3;
    cout << "test case 3: " << btostr(b) << endl;

    return 0;
}
