#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    vector<int> results(t);
    int count = 0;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }

        int j = 0;
        while (j <= n - k) {
            bool canHike = true;

            for (int m = j; m < j + k; ++m) {
                if (a[m] != 0) {
                    canHike = false;
                    break;
                }
            }

            if (canHike) {
                count++;
                j += k + 1; // Skip k days 
            } else {
                j++; 
            }
        }
        results[i] = count;
        count = 0;
    }
    for (int i = 0; i < t; ++i) {
        cout << results[i] << endl;
    }
    return 0;
}