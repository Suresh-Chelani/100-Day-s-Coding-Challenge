class Solution {
public:
    int mx = 0;
    int dp[1001][1001];
    int solve(string& s1, string& s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int rst = 0;
        if (s1[i] == s2[j]) {
            rst = 1+solve(s1, s2, i + 1, j + 1); 
            mx = max(mx, rst);
        } 
        dp[i][j] = rst;
        int ex1 = solve(s1, s2, i + 1, j); 
        int ex2 = solve(s1, s2, i, j + 1); 
        return dp[i][j];
    }
    
    int longestCommonSubstr(string str1, string str2) {
        memset(dp, -1, sizeof(dp));
        solve(str1, str2, 0, 0);   
        return mx;
    }
};
