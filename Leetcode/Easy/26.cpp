// 26. Remove Duplicates from Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i + 1);
            } else {
                i++;
            }
        }
        return nums.size();
    }
};

void printVector(const vector<int>& nums, int k) {
    cout << "[";
    for (int i = 0; i < k; ++i) {
        cout << nums[i];
        if (i != k - 1)
            cout << ",";
    }
    for (int i = k; i < nums.size(); ++i)
        cout << ",_";
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 1, 2},
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
    };

    for (auto& nums : testCases) {
        cout << "Input: nums = [";
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i != nums.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;

        int k = sol.removeDuplicates(nums);
        cout << "Output: " << k << ", nums = ";
        printVector(nums, k);
        cout << endl;
    }

    return 0;
}
