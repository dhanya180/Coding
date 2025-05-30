// 392. Is Subsequence

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j])
                i++;
            j++;
        }

        return i == s.length();
    }
};

int main() {
    Solution sol;

    vector<pair<string, string>> testCases = {
        {"abc", "ahbgdc"},
        {"axc", "ahbgdc"}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const string& s = testCases[i].first;
        const string& t = testCases[i].second;

        cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        bool result = sol.isSubsequence(s, t);
        cout << "Output: " << (result ? "true" : "false") << "\n\n";
    }

    return 0;
}
