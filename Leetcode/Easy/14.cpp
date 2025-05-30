// 14. Longest Common Prefix

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest_common_prefix = "";
        char str = '\0';
        int index=0;
        while(true){
            for (int i=0 ; i< strs.size() ; i++){
                if (index == strs[i].length()){
                    return longest_common_prefix;
                }
                if(i==0){
                    str = strs[0][index];
                    continue;
                }
                if (strs[i][index] != str)
                    return longest_common_prefix;
            }
            longest_common_prefix += str;
            str = '\0';
            index++;
        }
    }
};

void printInput(const vector<string>& strs) {
    cout << "Input: strs = [";
    for (size_t i = 0; i < strs.size(); ++i) {
        cout << "\"" << strs[i] << "\"";
        if (i != strs.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<string>> testCases = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"}
    };

    for (const auto& strs : testCases) {
        printInput(strs);
        string result = sol.longestCommonPrefix(const_cast<vector<string>&>(strs));
        cout << "Output: \"" << result << "\"\n\n";
    }

    return 0;
}
