// 6. Zigzag Conversion

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        if (numRows == 1)
            return s;
        for (int i=0 ; i<numRows ; i++){
            int next= (numRows -1) * 2;
            for (int j=i ; j<s.length() ; j+=next){
                result += s[j];
                if(i>0 && i<numRows-1 && (j+next)-2*i <s.length())
                    result += s[(j+next)-2*i];
            } 
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<pair<string, int>> testCases = {
        {"PAYPALISHIRING", 3},
        {"PAYPALISHIRING", 4}
    };

    for (auto& [s, numRows] : testCases) {
        cout << "Input: s = \"" << s << "\", numRows = " << numRows << endl;
        cout << "Output: \"" << sol.convert(s, numRows) << "\"\n\n";
    }

    return 0;
}
