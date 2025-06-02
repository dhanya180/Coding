// 205. Isomorphic Strings

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        map<char, char> map1;  // s -> t
        map<char, char> map2;  // t -> s

        for (int i = 0; i < s.size(); ++i) {
            char a = s[i], b = t[i];

            if (map1.count(a) && map1[a] != b)
                return false;
            if (map2.count(b) && map2[b] != a)
                return false;

            map1[a] = b;
            map2[b] = a;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<pair<string, string>> testCases = {
        {"egg", "add"},
        {"foo", "bar"},
        {"paper", "title"}
    };

    for (const auto& [s, t] : testCases) {
        cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
        bool result = sol.isIsomorphic(s, t);
        cout << "Output: " << (result ? "true" : "false") << endl << endl;
    }

    return 0;
}
