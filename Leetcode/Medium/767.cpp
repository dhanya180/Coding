// 767. Reorganize String

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> hashMap;
        for(char ch : s)
            hashMap[ch]++;

        // Max heap
        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, count] : hashMap)
            maxHeap.push({count, ch});

        string result = "";
        pair<int, char> prev = {0, '#'};
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result += ch;
            if (prev.first > 0)
                maxHeap.push(prev);
            prev = {count - 1, ch};
        }

        if(result.length() == s.length())
            return result;
        else
            return "";

    }
};

int main() {
    Solution solution;
    vector<string> testCases = {"aab", "aaab"};

    for (const string& s : testCases) {
        cout << "Input: " << s << endl;
        string output = solution.reorganizeString(s);
        if (!output.empty()) {
            cout << "Output: " << output << endl << endl;
        } else {
            cout << "Output: \"\" (not possible to reorganize)" << endl << endl;
        }
    }

    return 0;
}
