#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<long long> results;

        for (int k = 1; k <= 18; k++) {  
            long long divisor = (long long)pow(10, k) + 1;
            if (divisor > n){
                break;
            }
            if (n % divisor == 0) {
                results.push_back(n / divisor);
            }
        }

        if (results.empty()) {
            cout << 0 << "\n";
        } else {
            sort(results.begin(), results.end());
            cout << results.size() << "\n";
            for (int i = 0; i < (int)results.size(); i++) {
                cout << results[i] << (i + 1 == (int)results.size() ? '\n' : ' ');
            }
        }
    }

    return 0;
}
