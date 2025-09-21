#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        auto ok = [](int x, int y) {
            int M = max(x,y), m = min(x,y);
            return M <= 2 * (m + 1);
        };
        bool first = ok(a, b);
        bool second = ok(c - a, d - b);
        cout << (first && second ? "YES" : "NO") << '\n';
    }
    return 0;
}
