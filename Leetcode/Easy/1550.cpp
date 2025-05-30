// 1550. Three Consecutive Odds

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int check=0;
        int i=0;
        while(i<arr.size()){
            if (arr[i]%2 != 0){
                check+=1;
                i++;
            }
            else{
                check=0;
                i++;
            }
            if (check == 3){
                return true;
            }
        }
        return false;  
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {2, 6, 4, 1},                   
        {1, 2, 34, 3, 4, 5, 7, 23, 12}  
    };

    for (const auto& arr : testCases) {
        cout << "Input: arr = [";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i != arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;

        bool result = sol.threeConsecutiveOdds(const_cast<vector<int>&>(arr));
        cout << "Output: " << (result ? "true" : "false") << endl << endl;
    }

    return 0;
}
