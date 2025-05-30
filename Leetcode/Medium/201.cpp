// Bitwise AND of Numbers Range

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & (right - 1); // Clears the rightmost set bit
        }
        return right;
    }
};

void printTestCase(int left, int right, int output) {
    cout << "Input: left = " << left << ", right = " << right << endl;
    cout << "Output: " << output << endl << endl;
}

int main() {
    Solution sol;

    vector<pair<int, int>> testCases = {
        {5, 7},
        {0, 0},
        {1, 2147483647}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        int left = testCases[i].first;
        int right = testCases[i].second;
        int result = sol.rangeBitwiseAnd(left, right);
        printTestCase(left, right, result);
    }

    return 0;
}
