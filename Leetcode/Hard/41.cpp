// 41. First Missing Positive

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Place numbers in the right index (nums[i] = i+1)
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) 
                swap(nums[i], nums[nums[i]-1]);
            
        }
        //Check
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
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
        {1, 2, 0},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12}
    };

    for (const auto& nums : testCases) {
        vector<int> input = nums;
        cout << "Input: nums = ";
        printVector(input);
        int result = sol.firstMissingPositive(input);
        cout << "\nOutput: " << result << "\n\n";
    }

    return 0;
}
