#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;

    int padovanSequence(int n)
    {
        if (n == 0 || n == 1 || n == 2) return 1;

        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i - 2] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};

