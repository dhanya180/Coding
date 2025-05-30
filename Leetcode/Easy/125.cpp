// 125. Valid Palindrome

#include <iostream>
#include <string>
#include <cctype> 
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string tempS = ""; //Empty string
        for ( int i=0 ; i< s.length() ; i++){
            if (isalnum(s[i])) {
                tempS += tolower(s[i]);
            }    
        }
        
        for (int j=0 ; j<(tempS.length()/2) ; j++){
            int k = tempS.length() - 1 - j;
            if (tempS[j] != tempS[k])
                return false;
        }
        return true;
    }
}; 

int main() {
    Solution sol;

    vector<string> testCases = {
        "A man, a plan, a canal: Panama",  
        "race a car",                      
        " "                                
    };

    for (const string& s : testCases) {
        cout << "Input: \"" << s << "\"" << endl;
        bool result = sol.isPalindrome(s);
        cout << "Output: " << (result ? "true" : "false") << endl << endl;
    }

    return 0;
}
