// 238. Product of Array Except Self


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int product_from_start = 1;
        int product_from_end = 1;
        for (int i=0 ; i<nums.size() ; i++){
            if (i == 0){
                answer.push_back(product_from_start);
                continue;
            }
            product_from_start *= nums[i-1];
            answer.push_back((product_from_start));
        }

        for (int j=nums.size()-1 ; j>=0 ; j--){
            if (j == nums.size()-1){
                answer[j] *= product_from_end;
                continue;
            }
            product_from_end *= nums[j+1];
            answer[j] *= product_from_end;
        }
        return answer;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 3, 4},
        {-1, 1, 0, -3, 3}
    };

    for (const auto& nums : testCases) {
        cout << "Input: nums = ";
        printVector(nums);
        cout << endl;

        vector<int> result = sol.productExceptSelf(const_cast<vector<int>&>(nums));
        cout << "Output: ";
        printVector(result);
        cout << endl << endl;
    }

    return 0;
}
