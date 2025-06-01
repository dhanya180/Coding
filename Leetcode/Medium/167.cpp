// 167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) 
                return {left + 1, right + 1};
            else if (sum < target) 
                left++;
            else 
                right--;
        }
        return {};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testInputs = {
        {2, 7, 11, 15},
        {2, 3, 4},
        {-1, 0}
    };
    vector<int> targets = {9, 6, -1};

    for (int i = 0; i < testInputs.size(); ++i) {
        vector<int>& numbers = testInputs[i];
        int target = targets[i];

        vector<int> result = sol.twoSum(numbers, target);

        cout << "Input: numbers = [";
        for (size_t j = 0; j < numbers.size(); ++j) {
            cout << numbers[j];
            if (j < numbers.size() - 1) cout << ", ";
        }
        cout << "], target = " << target << "\n";

        cout << "Output: [";
        for (size_t j = 0; j < result.size(); ++j) {
            cout << result[j];
            if (j < result.size() - 1) cout << ", ";
        }
        cout << "]\n\n";
    }

    return 0;
}
