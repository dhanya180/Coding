// 383. Ransom Note

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;

        map<char, int> hashMap1;
        map<char, int> hashMap2;

        for(char ch : ransomNote)
            hashMap1[ch]++;

        for(char ch : magazine)
            hashMap2[ch]++;

        for (const auto& [key, value] : hashMap1) {
            if (hashMap2[key] < value)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<pair<string, string>> testCases = {
        {"a", "b"},
        {"aa", "ab"},
        {"aa", "aab"}
    };

    for (const auto& [ransomNote, magazine] : testCases) {
        cout << "Input: ransomNote = \"" << ransomNote << "\", magazine = \"" << magazine << "\"" << endl;
        bool result = sol.canConstruct(ransomNote, magazine);
        cout << "Output: " << (result ? "true" : "false") << endl << endl;
    }

    return 0;
}
