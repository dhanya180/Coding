#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int main(){
    int N;
    cin >> N;
    long long R, C;
    long long rmin=LLONG_MAX, rmax=LLONG_MIN, cmin=LLONG_MAX, cmax=LLONG_MIN;
    for(int i=0 ; i<N ; i++){
        cin >> R >> C;
        rmin=min(rmin,R);
        rmax=max(rmax,R);
        cmin=min(cmin,C);
        cmax=max(cmax,C);
    }
    long long dr = rmax - rmin;
    long long dc = cmax - cmin;
    long long tr = (dr + 1) / 2;
    long long tc = (dc + 1) / 2;

    cout << max(tr, tc) << '\n';
    return 0;
}
