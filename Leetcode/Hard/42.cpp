// 42. Trapping Rain Water

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            if (height[left] <= height[right]) {
                int minHeight = height[left];
                left++;  // move inwards first
                while (left < right && height[left] < minHeight) {
                    trappedWater += minHeight - height[left];
                    left++;
                }
            } else {
                int minHeight = height[right];
                right--;  // move inwards first
                while (left < right && height[right] < minHeight) {
                    trappedWater += minHeight - height[right];
                    right--;
                }
            }
        }

        return trappedWater;
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
        {0,1,0,2,1,0,1,3,2,1,2,1},
        {4,2,0,3,2,5}
    };

    for (const auto& nums : testCases) {
        vector<int> input = nums;
        cout << "Input: nums = ";
        printVector(input);
        int result = sol.trap(input);
        cout << "\nOutput: " << result << "\n\n";
    }

    return 0;
}
