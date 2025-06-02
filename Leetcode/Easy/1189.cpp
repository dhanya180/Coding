// 1189. Maximum Number of Balloons

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> map;
        for (char ch : "balloon")
            map.insert({ch, 0});
        for (char ch : text){
            auto it = map.find(ch);
            if (it != map.end())
                it->second++;
        }
        int result = 0;
        while(true){
            for (const auto& [key, value] : map) {
                if(key == 'b' || key == 'a'|| key == 'n'){
                    if(value == 0)
                        return result;
                }
                else if(key == 'l' ||  key == 'o'){
                    if(value < 2)
                        return result;
                }
            }
            map['b']--;
            map['a']--;
            map['l']-=2;
            map['o']-=2;
            map['n']--;

            result++;
        }
        
    }
};

int main() {
    Solution sol;
    vector<string> testCases = {
        "nlaebolko",
        "loonbalxballpoon",
        "leetcode"
    };

    for (const string& text : testCases) {
        cout << "Input: text = \"" << text << "\"" << endl;
        int result = sol.maxNumberOfBalloons(text);
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
