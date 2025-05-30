// 334. Increasing Triplet Subsequence

#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= first) 
                first = nums[i];          
            else if (nums[i] <= second)
                second = nums[i];         
            else
                return true;
        }
        return false;
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 1, 5, 0, 4, 6}
    };

    for (const auto& nums : testCases) {
        cout << "Input: nums = ";
        printVector(nums);
        bool result = sol.increasingTriplet(const_cast<vector<int>&>(nums));
        cout << "\nOutput: " << (result ? "true" : "false") << "\n\n";
    }

    return 0;
}
