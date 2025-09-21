#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<string> results;

    while (t--){
        long long n, a, b;
        cin >> n >> a >> b;

        if ((n % 2) != (b % 2)) {
            results.push_back("NO");
        } else {
            if ((n % 2) == (a % 2) || (a <= b)) {
                results.push_back("YES");
            } else {
                results.push_back("NO");
            }
        }
    }

    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}