// 191. Number of 1 Bits

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            int bit = (n % 2);
            if(bit == 1)
                count++;
            n = n / 2;
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> testCases = {11, 128, 2147483645};

    for (size_t i = 0; i < testCases.size(); ++i) {
        int input = testCases[i];
        int output = sol.hammingWeight(input);
        cout << "Input: n = " << input << endl;
        cout << "Output: " << output << endl << endl;
    }

    return 0;
}
