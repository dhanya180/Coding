// 88. Merge Sorted Array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (nums2[j] < nums1[i]) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
                m++; 
                nums1.pop_back();
            }
            i++;    
        }
        while (j < n) {
            nums1.insert(nums1.begin() + m, nums2[j]);
            nums1.pop_back();
            j++;
            m++;
        }
    }
};


void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2_1 = {2, 5, 6};
    sol.merge(nums1_1, 3, nums2_1, 3);
    cout << "Merged array 1: ";
    printVector(nums1_1);

    // Example 2
    vector<int> nums1_2 = {1};
    vector<int> nums2_2 = {};
    sol.merge(nums1_2, 1, nums2_2, 0);
    cout << "Merged array 2: ";
    printVector(nums1_2);

    // Example 3
    vector<int> nums1_3 = {0};
    vector<int> nums2_3 = {1};
    sol.merge(nums1_3, 0, nums2_3, 1);
    cout << "Merged array 3: ";
    printVector(nums1_3);

    return 0;
}
