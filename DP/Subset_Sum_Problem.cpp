#include <iostream>
#include <vector>
using namespace std;


// using simple recursion only 

bool solve(vector<int>& arr, int n, int target, int curr) {
    if (target == curr) return true;  
    if (n == 0) return false;        
    bool include = solve(arr, n-1, target, curr + arr[n-1]);
    bool exclude = solve(arr, n-1, target, curr);
    
    return include || exclude;        
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    solve(arr, n, target, 0) ? cout << "YES" : cout << "NO";

    return 0;
}



// Using Top Down Approach (Recursion + Memo)

/*

class Solution{   
public:
    int dp[101][10001];
    bool solve(vector<int>& arr, int n, int target) {
        if (target == 0) return true;  
        if (n == 0) return false;      
        if (dp[n][target] != -1) return dp[n][target];
        bool include = solve(arr, n-1, target - arr[n-1]);
        bool exclude = solve(arr, n-1, target);
        
        return dp[n][target] = include || exclude;        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp, -1, sizeof(dp));
        return solve(arr, arr.size(), sum) ? 1 : 0;
         
    }
};

*/

/// Using Bottom UP DP Approach:

/*

class Solution{   
 public:
     bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        
        for (int i=1; i<n+1; i++){
            for (int j=1; j<sum+1; j++){
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
     }
};

*/
