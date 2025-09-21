#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        long long ans = 0;
        long long p = 1;
        int x = 0;

        while (n > 0) {
            int d = n % 3;
            long long cost_x = 3 * p + (x ? 1LL * x * (p / 3) : 0);
            ans += 1LL * d * cost_x;

            n /= 3;
            p *= 3;
            ++x;
        }

        cout << ans << '\n';
    }
    return 0;
}
