//  1470. Shuffle the Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> vec;
        for (int i=0 ; i<n ; i++){
            vec.push_back(nums[i]);
            vec.push_back(nums[i+n]);
        }
        return vec;
    }
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
        {{2, 5, 1, 3, 4, 7}, 3},
        {{1, 2, 3, 4, 4, 3, 2, 1}, 4},
        {{1, 1, 2, 2}, 2}
    };

    for (const auto& testCase : testCases) {
        const vector<int>& nums = testCase.first;
        int n = testCase.second;

        cout << "Input: nums = ";
        printVector(nums);
        cout << ", n = " << n << endl;

        vector<int> result = sol.shuffle(const_cast<vector<int>&>(nums), n);

        cout << "Output: ";
        printVector(result);
        cout << endl << endl;
    }

    return 0;
}
