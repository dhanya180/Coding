// 219. Contains Duplicate II

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(nums[i]) && i - map[nums[i]] <= k)
                return true;
            map[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 1}, 3},
        {{1, 0, 1, 1}, 1},
        {{1, 2, 3, 1, 2, 3}, 2}
    };

    for (const auto& [nums, k] : testCases) {
        cout << "Input: nums = [";
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ", ";
        }
        cout << "], k = " << k << endl;

        bool result = sol.containsNearbyDuplicate(const_cast<vector<int>&>(nums), k);
        cout << "Output: " << (result ? "true" : "false") << endl << endl;
    }

    return 0;
}
