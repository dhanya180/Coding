// 2348. Number of Zero-Filled Subarrays

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long count = 0;
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i] == 0){
                count++;
                result += count;
            }
            else
                count = 0;
        }
        return result;
    }
};

void printInput(const vector<int>& nums) {
    cout << "Input: nums = [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 3, 0, 0, 2, 0, 0, 4},
        {0, 0, 0, 2, 0, 0}
    };

    for (const auto& nums : testCases) {
        printInput(nums);
        long long result = sol.zeroFilledSubarray(const_cast<vector<int>&>(nums));
        cout << "Output: " << result << "\n\n";
    }

    return 0;
}
