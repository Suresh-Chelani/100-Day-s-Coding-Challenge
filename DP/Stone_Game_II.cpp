#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int dp[2][101][101];
    int solve(int player_type, int i, int m, vector<int>& piles, int n){
        if (i >= n) return 0;

        if (dp[player_type][i][m] != -1) return dp[player_type][i][m];

        int curr_stones = 0;
        int total_stones = player_type ? -1 : INT_MAX;

        for (int x=1; x <= min(2*m, n-i); x++){
            curr_stones += piles[i+x-1];
            if (player_type == 1){
                total_stones = max(total_stones, curr_stones + solve(0, i+x, max(x,m), piles, n));
            }
            else{
                total_stones = min(total_stones, solve(1, i+x, max(x,m), piles, n));
            }
        }

        return dp[player_type][i][m] = total_stones;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, 1, piles, piles.size());
    }
};






