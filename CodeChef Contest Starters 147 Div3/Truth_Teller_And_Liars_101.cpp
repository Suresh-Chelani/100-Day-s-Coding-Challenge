#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        if (N <= M) cout << "-1"<< endl;
        else{
            cout << 2*M+1 << endl;
        }
    }

    return 0;
}
