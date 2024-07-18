#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s, t;
        cin >> s >> t;

        int ones_s = count(s.begin(), s.end(), '1');
        int ones_t = count(t.begin(), t.end(), '1');

        if (ones_s != ones_t)
        {
            cout << "NO" << endl;
        }
        else
        {
            int diff = 0;

            for (int i = 0; i < n; ++i)
            {
                if (s[i] != t[i])
                {
                    diff++;
                }
            }

            if (diff / 2 > k)
                cout << "NO" << endl;
            else
            {
                if (n == 2)
                {
                    if (s[0] == s[1])
                        cout << "YES" << endl;
                    else if ((k - diff / 2) % 2 == 1)
                        cout << "NO" << endl;
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
                else
                {
                    cout << "YES" << endl;
                }
            }
        }
    }

    return 0;
}
