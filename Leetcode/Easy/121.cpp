// 121. Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                profit = max(profit, prices[i] - min_price);
            }
        }

        return profit;
    }
};

void printPrices(const vector<int>& prices) {
    cout << "[";
    for (size_t i = 0; i < prices.size(); ++i) {
        cout << prices[i];
        if (i != prices.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {7, 1, 5, 3, 6, 4},
        {7, 6, 4, 3, 1}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& prices = testCases[i];

        cout << "Input: prices = ";
        printPrices(prices);
        cout << endl;

        int result = sol.maxProfit(const_cast<vector<int>&>(prices));
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
