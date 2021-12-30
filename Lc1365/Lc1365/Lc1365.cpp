/*
* 1365. How Many Numbers Are Smaller Than the Current Number
* 
* Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i]. 
* Return the answer in an array.
* 
* Input: nums = [8,1,2,2,3]
* Output: [4,0,1,1,3]
* 
* Input: nums = [6,5,4,8]
* Output: [2,1,0,3]
* 
* Input: nums = [7,7,7,7]
* Output: [0,0,0,0]
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> occ;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int element = *it;

            if (occ.find(element) == occ.end()) {
                occ.insert(pair<int, int>(element, 1));
            }
            else {
                occ.find(element)->second++;
            }
        }

        vector<int>* result = new vector<int>();

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int count = 0;

            int element = *it;
            for (map<int, int>::iterator it2 = occ.begin(); it2 != occ.end(); it2++) {
                int key = it2->first;

                if (key < element) {
                    count += it2->second;
                }
            }

            result->push_back(count);
        }


        return *result;
    }
};

bool is_vector_pair_equal(vector<int> first, vector<int> second) {
    if (first.size() != second.size()) {
        return false;
    }

    for (int i = 0; i < first.size(); i++) {
        if (first.at(i) != second.at(i)) {
            return false;
        }
    }

    return true;
}

string btostr(bool b) {
    return b ? "true" : "false";
}

int main()
{
    Solution sol;
    bool b;

    vector<int> v1 = { 8, 1, 2, 2, 3 };
    vector<int> e1 = { 4, 0, 1, 1, 3 };
    vector<int> s1 = sol.smallerNumbersThanCurrent(v1);

    b = is_vector_pair_equal(e1, s1);
    cout << "test case 1: " << btostr(b) << endl;

    vector<int> v2 = { 6, 5, 4, 8 };
    vector<int> e2 = { 2, 1, 0, 3 };
    vector<int> s2 = sol.smallerNumbersThanCurrent(v2);

    b = is_vector_pair_equal(e2, s2);
    cout << "test case 2: " << btostr(b) << endl;

    vector<int> v3 = { 7, 7, 7, 7 };
    vector<int> e3 = { 0, 0, 0, 0 };
    vector<int>s3 = sol.smallerNumbersThanCurrent(v3);
    
    b = is_vector_pair_equal(e3, s3);
    cout << "test case 3: " << btostr(b) << endl;

    return 0;
}
