#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    vector<int> results;

    while (t--) {
        int n;
        cin >> n;
        map<int, int> counts;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            counts[x]++;
        }

        if (counts.empty()) {
            results.push_back(0);
            break;
        }

        vector<int> freqs;
        for (auto const& pair : counts) {
            freqs.push_back(pair.second);
        }

        sort(freqs.begin(), freqs.end());

        int max_len = 0;
        int m = freqs.size();
        for (int i = 0; i < m; ++i) {
            int current_len = freqs[i] * (m - i);
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
        results.push_back(max_len);
    }

    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}