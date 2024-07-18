#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int win = 0;
        int c = 1;
        int loss = 0;
        for (int i = n; i >= 1; i--)
        {
            if (c <= x)
            {
                win += pow(2, i);
            }
            else
            {
                loss += pow(2, i);
            }
            c++;
        }

        cout << win - loss << endl;
    }
}
