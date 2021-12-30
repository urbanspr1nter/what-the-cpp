/*
1512. Number of Good Pairs

Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Input: nums = [1,2,3]
Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int results = 0;

        for (size_t i = 0; i < nums.size() - 1; i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums.at(i) == nums.at(j)) {
                    results++;
                }
            }
        }

        return results;
    }
};

string btostr(bool b) {
    return b ? "true" : "false";
}

int main()
{
    Solution sol;

    vector<int> v1 = { 1, 2, 3, 1, 1, 3 };
    int e1 = 4;
    int r1 = sol.numIdenticalPairs(v1);
    cout << "test case 1: " << btostr(e1 == r1) << endl;

    vector<int> v2 = { 1, 1, 1, 1 };
    int e2 = 6;
    int r2 = sol.numIdenticalPairs(v2);
    cout << "test case 2: " << btostr(e2 == r2) << endl;

    vector<int> v3 = { 1, 2, 3 };
    int e3 = 0;
    int r3 = sol.numIdenticalPairs(v3);
    cout << "test case 3: " << btostr(e3 == r3) << endl;

    return 0;
}
