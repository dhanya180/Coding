// 7. Reverse Integer

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int check = 1;
        long long lx = x; // To avoid overflow
        if (lx < 0) {
            check = -1;
            lx = -lx;
        }
        while (lx!=0){
            int temp = lx % 10;
            // Check for overflow before mutiplying
            if (result > (INT_MAX - temp) / 10) {
                return 0;
            }
            result = (result * 10) + temp;
            lx/=10;
        }
        if (check == -1){
            result *= (-1);
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> testCases = {
        123,     
        -123,    
        120
    };

    for (int x : testCases) {
        cout << "Input: x = " << x << endl;
        int result = sol.reverse(x);
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
