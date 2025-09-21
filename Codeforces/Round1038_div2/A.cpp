#include <bits/stdc++.h>
using namespace std;

int floor_log2(unsigned long long x) {
    int d = -1;
    while (x) {
        x >>= 1;
        ++d;
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long c;
        cin >> n >> c;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            if (a[i] > c) {
                d[i] = -1;
            } else {
                unsigned long long ratio = c / a[i];
                d[i] = floor_log2(ratio);
            }
        }

        sort(d.begin(), d.end());
        int free = 0;
        for (int di : d) {
            if (free <= di) {
                free++;
            }
        }
        cout << (n - free) << "\n";
    }
    return 0;
}
