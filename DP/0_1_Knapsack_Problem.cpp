#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    // int dp[1001][1001];
    // int solve(int W, vector<int>& wt, vector<int>& val, int n, int ans){  // Recursion + Memo
        
    //     if (W == 0)
    //         return 0;
    //     if (n == 0) 
    //         return 0;
    //     if (dp[W][n] != -1) return dp[W][n];
        
    //     if (W >= wt[n-1]){
    //         ans = max(val[n-1]+solve(W-wt[n-1],wt, val, n-1,ans), solve(W,wt, val, n-1,ans));
    //     }
    //     else{
    //         ans = solve(W,wt, val, n-1,ans);   
    //     }
        
    //     return dp[W][n] = ans;
    // }
    // int knapSack(int W, vector<int>& wt, vector<int>& val) {
    //     memset(dp, -1, sizeof(dp));
    //     int n = wt.size();
    //     return solve(W, wt, val, n,0);
        
    // }
    int knapSack(int W, vector<int>& wt, vector<int>& val) { // Bottom Up DP
        int n = wt.size();
        vector<vector<int>>dp(W+1, vector<int>(n+1,-1));
        
        for (int i=0; i<=W; i++){
            for (int j=0; j<= n; j++){
                if (i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for (int i=1 ;i<=W; i++){
            for (int j=1; j<= n; j++){
                if (i >= wt[j-1]){
                    dp[i][j] = max(val[j-1]+dp[i-wt[j-1]][j-1], dp[i][j-1]);
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[W][n];
    }
};

//W = 4, val[] = {1,2,3}, wt[] = {4,5,1}

// 1 ->  
