// 1512. Number of Good Pairs

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        map<int, int> hashMap;
        for(auto i : nums){
            auto it = hashMap.find(i);
            if (it != hashMap.end())
                it->second++;
            else
                hashMap.insert({i, 1});
        }
        for (const auto& [key, value] : hashMap)
            result += (value*(value-1))/2;

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 2, 3, 1, 1, 3},
        {1, 1, 1, 1},
        {1, 2, 3}
    };

    for (const auto& nums : testCases) {
        cout << "Input: nums = [";
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i != nums.size() - 1) cout << ",";
        }
        cout << "]" << endl;

        int result = sol.numIdenticalPairs(const_cast<vector<int>&>(nums));
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
