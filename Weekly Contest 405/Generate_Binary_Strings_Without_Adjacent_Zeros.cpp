#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void solve(string current, int n, vector<string> &result)
    {
        if (current.length() == n)
        {
            result.push_back(current);
            return;
        }

        solve(current + "1", n, result);

        if (current.empty() || current.back() != '0')
        {
            solve(current + "0", n, result);
        }
    }
    vector<string> validStrings(int n)
    {
        vector<string> ans;
        solve("", n, ans);
        return ans;
    }
};
