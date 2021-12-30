/*
760. Find Anagram Mappings

You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. Both arrays may contain duplicates.

Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means the ith element in nums1 appears in nums2 at index j. If there are multiple answers, return any of them.

An array a is an anagram of an array b means b is made by randomizing the order of the elements in a.

Input: nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
Output: [1,4,3,2,0]
Explanation: As mapping[0] = 1 because the 0th element of nums1 appears at nums2[1], and mapping[1] = 4 because the 1st element of nums1 appears at nums2[4], and so on.

Input: nums1 = [84,46], nums2 = [84,46]
Output: [0,1]
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> results;
        map<int, int> occ;
        
        // Just choose any occurrence since we can return any solution
        for (int i = 0; i < nums2.size(); i++) {
            if (occ.find(nums2[i]) == occ.end()) {
                occ.insert(pair<int, int>(nums2[i], i));
            }
            else {
                occ.find(nums2[i])->second = i;
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            results.push_back(occ.find(nums1[i])->second);
        }

        return results;
    }
};

bool is_vector_pair_equal(vector<int> v1, vector<int> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for (int i = 0; i < v2.size(); i++) {
        if (v1.at(i) != v2.at(i)) {
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

    vector<int> v1_1 = {20, 66, 21, 6, 11, 75, 7, 94, 41, 65};
    vector<int> v1_2 = {66, 94, 11, 21, 7, 6, 41, 20, 75, 65};
    vector<int> e1 = {7, 0, 3, 5, 2, 8, 4, 1, 6, 9};
    vector<int> s1 = sol.anagramMappings(v1_1, v1_2);

    cout << "test case 1: " << btostr(is_vector_pair_equal(e1, s1)) << endl;

    return 0;
}

