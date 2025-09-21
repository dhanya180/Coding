#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<long long> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    sort(g.begin(), g.end());
    
    long long total_emeralds = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        total_emeralds += g[i];
    }
    
    return total_emeralds;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    vector<long long> answers;
    answers.reserve(t); 
    
    while (t--) {
        answers.push_back(solve());
    }
    
    for (long long ans : answers) {
        cout << ans << endl;
    }
    
    return 0;
}