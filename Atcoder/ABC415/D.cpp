#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    vector<pair<ll, ll>> exchanges(M); 

    for (int i = 0; i < M; ++i) {
        cin >> exchanges[i].first >> exchanges[i].second;
    }

    sort(exchanges.begin(), exchanges.end(), [](pair<ll, ll>& x, pair<ll, ll>& y) {
        return (x.first - x.second) < (y.first - y.second);
    });

    ll bottled = N;
    ll empty = 0;
    ll stickers = 0;

    while (true) {
        empty += bottled;
        bottled = 0;

        bool exchanged = false;

        for (auto [A, B] : exchanges) {
            while (empty >= A) {
                ll times = empty / A;
                stickers += times;
                bottled += B * times;
                empty -= A * times;
                exchanged = true;
            }
        }

        if (!exchanged) break; 
    }

    cout << stickers << '\n';

    return 0;
}
