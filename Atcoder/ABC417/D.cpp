#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Present {
    int P, A, B;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Present> presents(N);
    int P_max = 0;
    long long sumB = 0;
    for (int i = 0; i < N; ++i) {
        cin >> presents[i].P >> presents[i].A >> presents[i].B;
        P_max = max(P_max, presents[i].P);
        sumB += presents[i].B;
    }

    int Q;
    cin >> Q;
    vector<long long> X(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> X[i];
    }

    // Precompute answers for all initial moods in [0..P_max]
    vector<int> res_small(P_max + 1);
    for (int start = 0; start <= P_max; ++start) {
        long long m = start;
        for (int i = 0; i < N; ++i) {
            if (m <= presents[i].P) {
                m += presents[i].A;
            } else {
                m = max<long long>(0, m - presents[i].B);
            }
        }
        res_small[start] = int(m);
    }

    // Threshold beyond which he is always disappointed
    long long T0 = (long long)P_max + sumB;

    for (int i = 0; i < Q; ++i) {
        long long x = X[i];
        if (x <= P_max) {
            cout << res_small[x] << "\n";
        }
        else if (x > T0) {
            // Always disappointed for each present
            cout << (x - sumB) << "\n";
        }
        else {
            // Must simulate full sequence
            long long m = x;
            for (int j = 0; j < N; ++j) {
                if (m <= presents[j].P) {
                    m += presents[j].A;
                } else {
                    m = max<long long>(0, m - presents[j].B);
                }
            }
            cout << m << "\n";
        }
    }

    return 0;
}
