// 509. Fibonacci Number

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution sol;
    vector<int> testCases = {2, 3, 4};

    for (int n : testCases) {
        cout << "Input: n = " << n << endl;
        int result = sol.fib(n);
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
