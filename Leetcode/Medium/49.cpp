// 49. Group Anagrams

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> map;
        for(string s : strs){
            string temp_s = s;
            sort(temp_s.begin(), temp_s.end());
            map[temp_s].push_back(s);
        }

        vector<vector<string>> answer;
        for (auto& [_, val] : map)
            answer.push_back(val);

        return answer;
    }
};

void printGroupedAnagrams(const vector<vector<string>>& groups) {
    cout << "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < groups[i].size(); ++j) {
            cout << "\"" << groups[i][j] << "\"";
            if (j < groups[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < groups.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<string>> testCases = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {""},
        {"a"}
    };

    for (const auto& strs : testCases) {
        cout << "Input: [";
        for (size_t i = 0; i < strs.size(); ++i) {
            cout << "\"" << strs[i] << "\"";
            if (i < strs.size() - 1) cout << ", ";
        }
        cout << "]" << endl;

        vector<string> copy = strs;
        auto result = sol.groupAnagrams(copy);
        cout << "Output: ";
        printGroupedAnagrams(result);
        cout << endl;
    }

    return 0;
}
