// 1. Two Sum

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {
        vector<int> output;
        for (int i=0 ; i<vec.size() ; i++){
            for(int j=i+1 ; j<vec.size() ; j++){
                if(vec[i]+vec[j]==target){
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }
        }
        return output;
    }
};

void printResult(const vector<int>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& nums = testCases[i].first;
        int target = testCases[i].second;
        cout << "Input: nums = [";
        for (size_t j = 0; j < nums.size(); ++j) {
            cout << nums[j];
            if (j != nums.size() - 1) cout << ", ";
        }
        cout << "], target = " << target << endl;

        vector<int> result = sol.twoSum(const_cast<vector<int>&>(nums), target);
        cout << "Output: ";
        printResult(result);
        cout << endl;
    }

    return 0;
}
