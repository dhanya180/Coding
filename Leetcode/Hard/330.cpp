// 330. Patching Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;  // The smallest sum that we cannot form yet
        int patches = 0, i = 0;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
            // Use nums[i] to extend the range of sums we can form
                miss += nums[i];
                i++;
            }
            else {
            // Patch the number `miss` to extend the sum coverage
                miss += miss;
                patches++;
            }
        }
    
        return patches;
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
        {{1, 3}, 6},         // Output: 1
        {{1, 5, 10}, 20},    // Output: 2
        {{1, 2, 2}, 5}       // Output: 0
    };

    for (const auto& [nums, n] : testCases) {
        cout << "Input: nums = ";
        printVector(nums);
        cout << ", n = " << n << endl;

        int result = sol.minPatches(const_cast<vector<int>&>(nums), n);
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
