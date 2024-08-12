#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
// Top-Down DP Approach
// class Solution {
// public:
//     int solve(vector<int>& dice, int target, vector<int>& memo) {
//         if (target < 0) return 0; 
//         if (target == 0) return 1; 
        
//         if (memo[target] != -1) return memo[target]; 

//         int ans = 0;
//         for (int d : dice) {
//             ans = (ans + solve(dice, target - d, memo)) % mod; 
//         }

//         memo[target] = ans; 
//         return ans;
//     }

//     int totalWay(vector<int>& dice, int target) {
//         vector<int> memo(target + 1, -1); 
//         return solve(dice, target, memo);
//     }
// };

// Bottom-Up DP Approach
class Solution {
public:
    int totalWay(vector<int>& dice, int& n) {
        vector<int>dp(n+1, 0);
        dp[0] = 1;

        for (int i=1; i<=n; i++){
            for (int j=1; j < 7; j++){
                if (j <= i){
                    dp[i] = (dp[i] + dp[i - j])%mod;
                }
            }
        }
        return dp[n];
    }
};


int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<int> dice = {1, 2, 3, 4, 5, 6};
    cout << obj.totalWay(dice, n) << endl;
    return 0;
}
