// 15. 3Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;  // skip duplicates
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;   // skip duplicates
                    while (left < right && nums[right] == nums[right - 1])
                        right--; // skip duplicates
                    left++;
                    right--;
                }
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return answer;
    }
};


void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 1, 1},
        {0, 0, 0}
    };

    for (const auto& nums : testCases) {
        cout << "Input: [";
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ", ";
        }
        cout << "]\nOutput: ";
        printResult(sol.threeSum(const_cast<vector<int>&>(nums)));
        cout << "\n";
    }

    return 0;
}
