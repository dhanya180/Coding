#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> results(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        vector<int> digits;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        std::sort(digits.begin(), digits.end());

        results[i] = digits[0];
    }
    for (int i = 0; i < n; ++i) {
        cout << results[i] << endl;
    }
    return 0;
}
