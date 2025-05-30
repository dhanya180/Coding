// 151. Reverse Words in a String

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        vector<string> vec;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            vec.push_back(word);
        }

        for (int i = (int)vec.size() - 1; i >= 0; i--) {
            result += vec[i];
            if (i != 0)
                result += ' ';
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> testCases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example"
    };

    for (const auto& s : testCases) {
        cout << "Input: \"" << s << "\"" << endl;
        cout << "Output: \"" << sol.reverseWords(s) << "\"" << endl << endl;
    }
    
    return 0;
}
