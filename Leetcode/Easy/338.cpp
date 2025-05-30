// 338. Counting Bits

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        answer.push_back(0);
        int temp, count;
        for (int i=1 ; i<=n ; i++){
            count = 0;
            temp = i;
            while (temp > 0) {
                int bit = (temp % 2);
                if(bit == 1)
                    count++;
                temp /= 2;
            }
            answer.push_back(count);
        }
        return answer;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<int> testCases = {2, 5};

    for (int n : testCases) {
        cout << "Input: n = " << n << endl;
        vector<int> output = sol.countBits(n);
        cout << "Output: ";
        printVector(output);
        cout << endl;
    }

    return 0;
}
