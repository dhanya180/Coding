#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int cur = 0;
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                cur++;
                if (cur >= k) { bad = true; break; }
            } else cur = 0;
        }

        if (bad) {
            cout << "NO\n";
            continue;
        }

        vector<int> order;
        order.reserve(n);
        for (int i = 0; i < n; ++i) if (s[i] == '1') order.push_back(i);
        for (int i = 0; i < n; ++i) if (s[i] == '0') order.push_back(i);

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[order[i]] = i + 1; 
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }
    return 0;
}
