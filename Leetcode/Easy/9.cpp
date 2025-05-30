// 9. Palindrome Number

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        int tempX = x;
        int reverseX = 0;
        while(tempX!=0){
            int temp = tempX % 10;
            // Check for overflow before mutiplying
            if (reverseX > (INT_MAX - temp) / 10) {
                return 0;
            }
            reverseX = (reverseX * 10) + temp;
            tempX/=10;
        }
        if (x == reverseX)
            return true;
        else
            return false;
    }
};

int main() {
    Solution sol;
    
    vector<int> testCases = {
        121,     
        -121,     
        10     
    };

    for (int x : testCases) {
        cout << "Input: x = " << x << endl;
        bool result = sol.isPalindrome(x);
        cout << "Output: " << (result ? "true" : "false") << endl << endl;
    }

    return 0;
}
