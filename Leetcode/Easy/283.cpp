// 283. Move Zeroes

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int flag = nums.size();
        for (int i=0 ; i<flag ; i++){
            if (nums[i] == 0){
                nums.push_back(0);
                nums.erase(nums.begin() + i);
                i--;
                flag--;
            }
        }
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {0, 1, 0, 3, 12},
        {0}
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        printVector(nums);
        sol.moveZeroes(nums);
        cout << "Output: ";
        printVector(nums);
        cout << endl;
    }

    return 0;
}
