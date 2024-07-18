#include <iostream>
#include <vector>
using namespace std;


void solve()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int count = 0;
        int temp = N;
        while (temp > 0)
        {
            temp /= 2;
            count++;
        }
        cout << count << endl;

        int f = 2;
        int appen = 1;
        vector<int> output(N);

        for (int i = 1; i <= N; ++i)
        {
            if (i == f)
            {
                f *= 2;
                appen++;
            }
            output[i - 1] = appen;
        }

        for (int i = 0; i < N; ++i)
        {
            if (i > 0)
                cout << " ";
            cout << output[i];
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
