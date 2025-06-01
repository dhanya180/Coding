// 371. Sum of Two Integers

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (unsigned)(a & b);  // carry
            a = a ^ b;                           // sum without carry
            b = (int)(carry << 1);               // carry added to the next higher bit
        }
        return a;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    pair<int, int> testCases[] = {
        {1, 2},
        {2, 3}
    };

    for (auto& test : testCases) {
        int a = test.first;
        int b = test.second;
        int result = sol.getSum(a, b);
        cout << "Input: a = " << a << ", b = " << b << endl;
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
