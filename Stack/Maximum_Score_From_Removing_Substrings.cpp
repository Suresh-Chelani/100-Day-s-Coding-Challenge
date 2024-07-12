#include <iostream>
using namespace std;

class Solution
{
public:
    int calculateScore(string &s, char first, char second, int &points, string &st)
    {
        int score = 0;
        for (char c : s)
        {
            if (!st.empty() && st.back() == first && c == second)
            {
                st.pop_back();
                score += points;
            }
            else
            {
                st.push_back(c);
            }
        }
        s = st;
        st = "";
        return score;
    }
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        string st = "";
        if (x >= y)
        {
            ans += calculateScore(s, 'a', 'b', x, st);
            ans += calculateScore(s, 'b', 'a', y, st);
        }
        else
        {
            ans += calculateScore(s, 'b', 'a', y, st);
            ans += calculateScore(s, 'a', 'b', x, st);
        }

        return ans;
    }
};
