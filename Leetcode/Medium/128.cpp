// 128. Longest Consecutive Sequence

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hashMap;
        int longestLength = 0;
        for (int num : nums) {
            hashMap[num] = false;
        }

        for (int num : nums) {
            if (hashMap[num])
                continue;
            int currentLength = 1;

            // Check in forward direction
            int nextNum = num + 1;
            while (hashMap.count(nextNum) && !hashMap[nextNum]) {
                currentLength++;
                hashMap[nextNum] = true;
                nextNum++;
            }

            // Check in reverse direction
            int prevNum = num - 1;
            while (hashMap.count(prevNum) && !hashMap[prevNum]) {
                currentLength++;
                hashMap[prevNum] = true;
                prevNum--;
            }

            hashMap[num] = true;
            longestLength = max(longestLength, currentLength);
        }

        return longestLength;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {100, 4, 200, 1, 3, 2},
        {0, 3, 7, 2, 5, 8, 4, 6, 0, 1},
        {1, 0, 1, 2}
    };

    for (const auto& nums : testCases) {
        cout << "Input: [";
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ", ";
        }
        cout << "]" << endl;

        int result = sol.longestConsecutive(const_cast<vector<int>&>(nums));
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}