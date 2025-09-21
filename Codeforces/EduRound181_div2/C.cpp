#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> singleDigitPrimes = {2, 3, 5, 7};

    while (t--) {
        long long l, r;
        cin >> l >> r;

        int count = 0;

        for (long long num = l; num <= r; ++num) {
            bool divisible = false;

            for (int p : singleDigitPrimes) {
                if (num % p == 0) {
                    divisible = true;
                    break;
                }
            }

            if (!divisible) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
