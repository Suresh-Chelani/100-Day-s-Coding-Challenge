#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    // int dp[10001];
    // int solve(int n, int x, int y, int z){ // Recursion + Memo
    //     if (n == 0) return 0;
    //     if (n < 0) return INT_MIN;
            
    //     if (dp[n] != -1) return dp[n];
        
    //     int temp1 = 1 + solve(n-x, x, y, z);
    //     int temp2 = 1 + solve(n-y, x, y, z);
    //     int temp3 = 1 + solve(n-z, x, y, z);
        
    //     return dp[n] = max(temp1, max(temp2, temp3));
    // }
    // int solve(int n, int x, int y, int z){ // Recursion
    //     if (n == 0) return 0;
    //     if (n < 0) return INT_MIN;
        
    //     int temp1 = 1 + solve(n-x, x, y, z);
    //     int temp2 = 1 + solve(n-y, x, y, z);
    //     int temp3 = 1 + solve(n-z, x, y, z);
        
    //     return max(temp1, max(temp2, temp3));
    // }
    // int maximizeTheCuts(int n, int x, int y, int z)
    // {
    //     memset(dp, -1, sizeof(dp));
    //     int ans = solve(n,x,y,z);
    //     return ans < 0 ? 0 : ans;
    // }
    int maximizeTheCuts(int n, int x, int y, int z) // Bottom Up DP
    {
        vector<int>dp(n+1, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= x) {
                dp[i] = max(dp[i], 1 + dp[i - x]);
            }
            if (i >= y) {
                dp[i] = max(dp[i], 1 + dp[i - y]);
            }
            if (i >= z) {
                dp[i] = max(dp[i], 1 + dp[i - z]);
            }
        }
        
        return dp[n] < 0 ? 0 : dp[n];
    }
};