#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    string result = "";
    long long totalLength = 0;

    for (int i = 0; i < N; ++i) {
        char c;
        int l;
        cin >> c >> l;

        totalLength += l;
        if (totalLength > 100) {
            cout << "Too Long" << endl;
            return 0;
        }

        result += string((int)l, c); 
    }

    cout <<  result << endl;
    return 0;
}
