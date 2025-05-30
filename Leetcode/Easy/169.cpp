// 169. Majority Element

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int check = nums.size() / 2;
        vector<int> unique_nums;

        for (int i = 0; i < nums.size(); i++) {
            if (find(unique_nums.begin(), unique_nums.end(), nums[i]) == unique_nums.end())
                unique_nums.push_back(nums[i]);
        }

        for (int i = 0; i < unique_nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (unique_nums[i] == nums[j])
                    count++;
            }
            if (count > check)
                return unique_nums[i];
        }

        return -1;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 2, 3},
        {2, 2, 1, 1, 1, 2, 2}
    };

    for (auto& nums : testCases) {
        cout << "Input: nums = ";
        printVector(nums);
        cout << endl;

        int result = sol.majorityElement(nums);
        cout << "Output: " << result << "\n\n";
    }

    return 0;
}
