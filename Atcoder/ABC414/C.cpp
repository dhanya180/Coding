#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

string convertToBaseA(long long num, int base) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        int digit = num % base;
        result += to_string(digit);
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int A;
    long long N;
    cin >> A >> N;

    long long result = 0;

    // 1. Odd-length palindromes
    for (int len = 1; ; ++len) {
        for (long long half = 1;; ++half) {
            string halfStr = to_string(half);
            string revPart = halfStr.substr(0, (int)halfStr.size() - 1);
            reverse(revPart.begin(), revPart.end());
            string fullStr = halfStr + revPart;
            long long val = stoll(fullStr);
            if (val > N) goto next;

            if (isPalindrome(convertToBaseA(val, A))) {
                result += val;
            }
        }
    }

next:

    // 2. Even-length palindromes
    for (long long half = 1; ; ++half) {
        string halfStr = to_string(half);
        string revPart = halfStr;
        reverse(revPart.begin(), revPart.end());
        string fullStr = halfStr + revPart;
        long long val = stoll(fullStr);
        if (val > N) break;

        if (isPalindrome(convertToBaseA(val, A))) {
            result += val;
        }
    }

    cout << result << endl;
    return 0;
}
