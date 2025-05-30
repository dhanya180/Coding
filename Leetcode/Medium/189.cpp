// 189. Rotate Array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();  // if k > n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }

    // This doesnt handle infinitely large k
    // void rotate(vector<int>& nums, int k) {
    //     k = k % (nums.size());
    //     for (int i=0 ; i<k ; i++){
    //         nums.insert(nums.begin()+0, nums.back());
    //         nums.pop_back();
    //     }
    // }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5, 6, 7}, 3},
        {{-1, -100, 3, 99}, 2}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int k = testCases[i].second;

        cout << "Input: nums = ";
        printVector(nums);
        cout << ", k = " << k << endl;

        sol.rotate(nums, k);

        cout << "Output: ";
        printVector(nums);
        cout << endl << endl;
    }

    return 0;
}
