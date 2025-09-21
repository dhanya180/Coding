#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    int t; 
    cin >> t;

    while(t--) {
        long long a, b, k;
        cin >> a >> b >> k;

       // Compute gcd
        int64 g = gcd(a, b);

        // If (a/g, b/g) fits within [0..k], we can use that pair g times, cost = 1
        if (a/g <= k && b/g <= k) {
            cout << 1 << "\n";
        }
        else {
            // Otherwise we need at least two distinct move-vectors
            cout << 2 << "\n";
        }
    }

    return 0;
}
