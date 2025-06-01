#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& height) {
        int maxArea = 0;
        int i = 0;
        int j = height.size() - 1;

        while (j > i) {
            if (height[i] < height[j]) {
                maxArea = max(maxArea, ((j - i) * height[i]));
                i++;
            }
            else if (height[i] > height[j]) {
                maxArea = max(maxArea, ((j - i) * height[j]));
                j--;
            }
            else {
                maxArea = max(maxArea, ((j - i) * height[j]));
                if (height[i + 1] >= height[j - 1])
                    i++;
                else
                    j--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testInputs = {
        {1, 8, 6, 2, 5, 4, 8, 3, 7},
        {1, 1}
    };

    for (const auto& heights : testInputs) {
        cout << "Input: [";
        for (size_t i = 0; i < heights.size(); ++i) {
            cout << heights[i];
            if (i < heights.size() - 1) cout << ", ";
        }
        cout << "]\n";

        int result = sol.maxArea(heights);
        cout << "Output: " << result << "\n\n";
    }

    return 0;
}
