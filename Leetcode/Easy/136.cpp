// 136. Single Number

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // x ^ x = 0
    // x ^ 0 = x
    // XOR(^) is Commutative and Associative
    // XORing all numbers will cancel the duplicates and leave the single one
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i=0 ; i<nums.size() ; i++){
            result ^= nums[i];
        }
        return result;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {2, 2, 1},
        {4, 1, 2, 1, 2},
        {1}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Input: nums = ";
        printVector(testCases[i]);
        cout << endl;
        int result = sol.singleNumber(testCases[i]);
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
