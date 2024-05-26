#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Resursion + DP + Memo
class Solution1 {
public:
    int dp[100001][2][3];
    int mod = 1e9+7;
    int solve(int n, int absent, int late){
        if (absent >= 2 || late >= 3) return 0;

        if (n == 0) return 1;

        if (dp[n][absent][late] != -1) return dp[n][absent][late];

        int l = solve(n - 1, absent, late+1);
        int a = solve(n - 1, absent+1, 0);
        int p = solve(n - 1, absent, 0);

        return dp[n][absent][late] = ((l + p)%mod + a)%mod;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0);
    }
};

// Bottom UP DP
class Solution2 {
public:
    int checkRecord(int n) {
        const int MOD = 1e9+7;
        int dp[100001][2][3] = {0};

        // Initialize base cases
        for (int a = 0; a <= 1; a++) {
            for (int l = 0; l <= 2; l++) {
                dp[0][a][l] = 1;
            }
        }

        // Fill the dp array
        for (int i = 1; i <= n; i++) {
            for (int a = 0; a <= 1; a++) {
                for (int l = 0; l <= 2; l++) {
                    long ans = dp[i-1][a][0];  // P case
                    if (a+1 <= 1) ans = (ans + dp[i-1][a+1][0]) % MOD;  // A case
                    if (l+1 <= 2) ans = (ans + dp[i-1][a][l+1]) % MOD;  // L case
                    dp[i][a][l] = ans;
                }
            }
        }

        return dp[n][0][0];
    }
};


int main(){
    Solution2 obj;
    int l;
    cin >> l;
    cout << obj.checkRecord(l) << endl;
    return 0;
}


